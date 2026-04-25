#!/usr/bin/env python
# coding: utf-8

# # Nanodegree Engenheiro de Machine Learning

# **Autor:** Alexandre Ray da Silva
# 
# **Data:** 04/08/2019

# ### Bibliotecas

# In[60]:


import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
import calendar
import lightgbm as lgb
from datetime import datetime
from sklearn.ensemble import GradientBoostingRegressor
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import GridSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
get_ipython().run_line_magic('matplotlib', 'inline')


# In[61]:


sns.set()


# ### Datasets

# In[62]:


dataset = 'bike-sharing-demand'
df_sample = pd.read_csv('data/{}/sampleSubmission.csv'.format(dataset))
df_test = pd.read_csv('data/{}/test.csv'.format(dataset))
df_train = pd.read_csv('data/{}/train.csv'.format(dataset))
df_benchmark = pd.read_csv('data/{}/bike_predictions_gbm_separate_without_fe.csv'.format(dataset))

df = df_train # dataset que será usado nesse projeto, inclusive para separação de treino e teste


# In[63]:


print(df_sample.shape)
print(df_test.shape)
print(df_benchmark.shape)
print(df.shape)


# In[64]:


df_sample.head()


# In[65]:


df_sample['count'].value_counts()


# In[66]:


df_test.head()


# In[67]:


df.head()


# In[68]:


df_benchmark.head()


# ### Tipos dos dados

# In[69]:


df.dtypes


# ### Root Mean Squared Logarithmic Error (RMSLE)

# In[70]:


def rmsle(y, y_,convertExp=True):
    if convertExp:
        y = np.exp(y),
        y_ = np.exp(y_)
    log1 = np.nan_to_num(np.array([np.log(v + 1) for v in y]))
    log2 = np.nan_to_num(np.array([np.log(v + 1) for v in y_]))
    calc = (log1 - log2) ** 2
    
    return np.sqrt(np.mean(calc))


# ### Análise Exploratória

# In[71]:


fig,(ax1,ax2)= plt.subplots(ncols=2)
fig.set_size_inches(14,6)

ax1 = sns.distplot(df['count'], ax=ax1)
ax1.set_title('Distribuição do # total de aluguéis')

ax2 = sns.distplot(np.log10(df['count']), ax=ax2)
ax2.set_title('Distribuição do # total de aluguéis (Log)');


# Podemos ver que existem alguns momentos que há mais de 800 bicicletas em aluguel. Porém, na maioria das vezes, há poucas bicicletas alugadas.

# Podemos fazer uma transformação logarítmica para observar melhor o comportamento da distribuição

# In[72]:


df.describe().T


# In[110]:


def trasform_features(df): # 2011-01-20 01:00:00
    # Transformação da data
    df["date"] = df.datetime.apply(lambda x : x.split()[0])
    
    # Hora
    df["hour"] = df.datetime.apply(lambda x : x.split()[1].split(":")[0])
    
    # Dia da semana
    df["weekday"] = df.date.apply(
        lambda dateString : calendar.day_name[datetime.strptime(dateString,"%Y-%m-%d").weekday()]
    )
    
    # Mês
    df["month"] = df.date.apply(
        lambda dateString : calendar.month_name[datetime.strptime(dateString,"%Y-%m-%d").month]
    )
    
    # Estação do ano
    df["season"] = df.season.map({1: "Spring", 2 : "Summer", 3 : "Fall", 4 :"Winter" })
    
    # Clima
    df["weather"] = df.weather.map({
        1: "Clear",\
        2: "Mist + Cloudy", \
        3: "Light Snow, Light Rain", \
        4: "Heavy Rain"
    })
    
    # Variáveis categóricas
    categoryVariableList = ["hour","weekday","month","season","weather","holiday","workingday"]
    for var in categoryVariableList:
        df[var] = df[var].astype("category")    
        
    df = df.drop(["date", "datetime"],axis=1)
    
    return df


# In[74]:


df = trasform_features(df)
df = df.drop(["casual", "registered"],axis=1)


# In[75]:


df.head()


# ### Missing Values

# In[76]:


print(df.isna().mean().sort_values(ascending=False))


# In[77]:


def plot_heatmap(df):
    plt.subplots(figsize=(10,10))
    corr = df.corr()
    mask = np.zeros_like(corr)
    mask[np.triu_indices_from(mask)] = True
    
    with sns.axes_style("white"):
        sns.heatmap(
            data=corr,
            mask=mask,
            annot=True,
            vmin=-1, 
            vmax=1
        )


# In[78]:


plot_heatmap(df)


# In[79]:


cols = ['temp', 'atemp', 'windspeed', 'humidity']

pp = sns.pairplot(df[cols],
                  diag_kws=dict(shade=True),
                  diag_kind="kde",
                  kind="reg")

fig = pp.fig 
fig.subplots_adjust(top=0.93, wspace=0.3)
fig.suptitle('Correlação das variáveis numéricas', fontsize=14, fontweight='bold')


# In[80]:


sns.boxplot(data=df[['temp', 'atemp', 'humidity', 'windspeed', 'count']], orient='h')
fig=plt.gcf()
fig.set_size_inches(12,6)
fig.suptitle('Análise de Outliers', fontsize=14, fontweight='bold');


# In[81]:


fig,(ax1,ax2,ax3)= plt.subplots(nrows=3)
fig.set_size_inches(12,18)

sns.factorplot(x="month",y="count",data=df,kind='bar',size=5,aspect=1.5,ax=ax1)
ax1.set(xlabel='Mês', ylabel='# de bicicletas alugadas',title="# de bicicletas alugadas por Mẽs",label='big');
plt.close()

sns.factorplot(x="weekday",y="count",data=df,kind='bar',size=5,aspect=1.5,ax=ax2)
ax2.set(xlabel='Dia da semana', ylabel='# de bicicletas alugadas',title="# de bicicletas alugadas por Semana",label='big');
plt.close()

sns.factorplot(x="hour",y="count",data=df,kind='bar',size=5,aspect=1.5,ax=ax3)
ax3.set(xlabel='Hora do dia', ylabel='# de bicicletas alugadas',title="# de bicicletas alugadas por Hora",label='big');
plt.close()


# In[82]:


fig,(ax1,ax2,ax3,ax4)= plt.subplots(nrows=4)
fig.set_size_inches(12,22)

sns.factorplot(x="weather",y="count",data=df,kind='bar',size=5,aspect=1.5, ax=ax1)
ax1.set(xlabel='Clima', ylabel='# de bicicletas alugadas',title="# de bicicletas alugadas para difierentes situações climáticas",label='big');
plt.close()

sns.factorplot(x="season",y="count",data=df,kind='bar',size=5,aspect=1.5, ax=ax2)
ax2.set(xlabel='Estação do ano', ylabel='# de bicicletas alugadas',title="# de bicicletas alugadas para diferentes estações do ano",label='big');
plt.close()

sns.factorplot(x="holiday",y="count",data=df,kind='bar',size=5,aspect=1.5, ax=ax3)
ax3.set(xlabel='Feriado', ylabel='# de bicicletas alugadas',title="# de bicicletas alugadas para feriados",label='big');
plt.close()

sns.factorplot(x="workingday",y="count",data=df,kind='bar',size=5,aspect=1.5, ax=ax4)
ax4.set(xlabel='Dia útil', ylabel='# de bicicletas alugadas',title="# de bicicletas alugadas para dias úteis",label='big');
plt.close()


# In[83]:


fig,((ax1,ax2),(ax3,ax4))= plt.subplots(nrows=2, ncols=2)
fig.set_size_inches(12,12)

ax1 = sns.regplot(x="count", y="temp", data=df, ax=ax1)
ax1.set_title('Temperatura X # de bicicletas alugadas')

ax2 = sns.regplot(x="count", y="atemp", data=df, ax=ax2)
ax2.set_title('Sensação Térmica X # de bicicletas alugadas')

ax3 = sns.regplot(x="count", y="humidity", data=df, ax=ax3)
ax3.set_title('Umidade X # de bicicletas alugadas')

ax4 = sns.regplot(x="count", y="windspeed", data=df, ax=ax4)
ax4.set_title('Velocidade do vento X # de bicicletas alugadas')

plt.show()


# In[84]:


g = sns.lmplot(data=df, x='temp', y='count', hue='workingday')
g.axes[0,0].set_xlim(0, 45)
g.axes[0,0].set_ylim(0, 1000)
g.fig.suptitle('Variação do aluguel de bicicletas X Temperatura para dias úteis')
g.fig.set_figwidth(20)
g.fig.set_figheight(10)
plt.ticklabel_format(style='plain', axis='both')


# In[85]:


g = sns.lmplot(data=df, x='temp', y='count', hue='holiday')
g.axes[0,0].set_xlim(0, 45)
g.axes[0,0].set_ylim(0, 1000)
g.fig.suptitle('Variação do aluguel de bicicletas X Temperatura para feriados')
g.fig.set_figwidth(20)
g.fig.set_figheight(10)
plt.ticklabel_format(style='plain', axis='both')


# In[86]:


fig,(ax1,ax2)= plt.subplots(nrows=2)
fig.set_size_inches(12,12)

hueOrder = ["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"]

hourAggregated = pd.DataFrame(df.groupby(["hour","season"],sort=True)["count"].mean()).reset_index()
sns.pointplot(x=hourAggregated["hour"], y=hourAggregated["count"],hue=hourAggregated["season"], data=hourAggregated, join=True,ax=ax1)
ax1.set(xlabel='Hora do dia', ylabel='# de usuários',title="# de usuários para diferentes estações do ano",label='big');

hourAggregated = pd.DataFrame(df.groupby(["hour","weekday"],sort=True)["count"].mean()).reset_index()
sns.pointplot(x=hourAggregated["hour"], y=hourAggregated["count"],hue=hourAggregated["weekday"],hue_order=hueOrder, data=hourAggregated, join=True,ax=ax2)
ax2.set(xlabel='Hora do dia', ylabel='# de usuários',title="# de usuários para diferentes dias da semana",label='big');


# ### Feature Engineering

# In[87]:


# Aplicação da técnica One Hot Encoding

def one_hot_encoding(df, categorical_features):
    for feature in categorical_features:
        one_hot_encoded_feature = pd.get_dummies(df[feature], drop_first=True, prefix=feature)
        df = df.join(one_hot_encoded_feature)

    return df.drop(columns=categorical_features)


# In[88]:


# Aplicação do StandardScaler

def standardize(df, numerical_features):
    scaler = StandardScaler()
    scaler.fit(df[numerical_features])
    df[numerical_features] = scaler.transform(df[numerical_features])

    return df


# In[89]:


categorical_features = ['season', 'weather', 'weekday', 'month']
numerical_features = ['temp', 'atemp', 'humidity', 'windspeed', 'hour']


# In[90]:


df_sanity_check = df.copy()


# Aplicando a técnica One Hot Encoding

# In[32]:


df = one_hot_encoding(df, categorical_features)


# Aplicando a técnica StandardScaler

# In[33]:


df = standardize(df, numerical_features)


# ### Separação dos dados em treino e teste

# In[34]:


# Função que separa dados de treino e teste

def split_df(df):
    target = df['count']
    features = df.drop(['count'], axis=1)
    
    X_train, X_test, y_train, y_test = train_test_split(
        features,
        target,
        train_size=0.7,
        test_size=0.3,
        random_state=42
    )
    
    return X_train, X_test, y_train, y_test


# In[35]:


# Separa dados em treino e teste
X_train, X_test, y_train, y_test = split_df(df)

# Faz transformação log na variável resposta
y_log_train = np.log1p(y_train)
y_log_test = np.log1p(y_test)


# Vamos verificar como ficaram os datasets após todos os pré-processamentos

# In[36]:


# Treino
print(X_train.shape)
print(y_train.shape)

# Teste
print(X_test.shape)
print(y_test.shape)


# ### Modelagem

# ### 1.1 Gradient Boosting (Baseline)

# In[37]:


model_gbr = GradientBoostingRegressor(
    n_estimators=100, 
    max_depth=3,
    learning_rate=0.3
)

model_gbr.fit(X_train, y_log_train)


# In[38]:


preds_train_gbr = model_gbr.predict(X=X_train)
preds_test_gbr = model_gbr.predict(X=X_test)


# In[39]:


print("RMSLE para o Gradient Boost (Train): ", rmsle(np.exp(y_log_train), np.exp(preds_train_gbr), False))
print("RMSLE para o Gradient Boost (Test): ", rmsle(np.exp(y_log_test), np.exp(preds_test_gbr), False))


# ### 1.2 Gradient Boosting (GridSearch)

# In[40]:


X_train.head()


# In[41]:


param_grid = {
    'n_estimators': [100, 300, 500],
    'max_depth': [3, 6, 32],
    'learning_rate': [0.03, 0.1, 0.3]
}

gbr = GradientBoostingRegressor()

model_gbr = GridSearchCV(
    estimator=gbr, 
    param_grid=param_grid, 
    cv=3, 
    n_jobs=-1
)

model_gbr.fit(X_train, y_log_train)


# Melhores hiperparâmetros:

# In[42]:


model_gbr.best_params_


# In[43]:


preds_train_gbr = model_gbr.predict(X=X_train)
preds_test_gbr = model_gbr.predict(X=X_test)


# In[44]:


print("RMSLE para o Gradient Boost (Train): ", rmsle(np.exp(y_log_train), np.exp(preds_train_gbr), False))
print("RMSLE para o Gradient Boost (Test): ", rmsle(np.exp(y_log_test), np.exp(preds_test_gbr), False))


# ### 2.1 Random Forest (Baseline)

# In[45]:


rf = RandomForestRegressor(
    n_estimators=1000, 
    max_depth=3
)

rf.fit(X_train, y_log_train)


# In[46]:


preds_train_rf = rf.predict(X=X_train)
preds_test_rf = rf.predict(X=X_test)


# In[47]:


print("RMSLE para o Random Forest (Train): ", rmsle(np.exp(y_log_train), np.exp(preds_train_rf), False))
print("RMSLE para o Random Forest (Test): ", rmsle(np.exp(y_log_test), np.exp(preds_test_rf), False))


# ### 2.2 Random Forest (GridSearch)

# In[48]:


param_grid = {
    'n_estimators': [100, 300, 500],
    'max_depth': [3, 6, 32]
}

rf = RandomForestRegressor()

model_rf = GridSearchCV(
    estimator=rf, 
    param_grid=param_grid, 
    cv=3, 
    n_jobs=-1
)

model_rf.fit(X_train, y_log_train)


# Melhores hiperparâmetros:

# In[49]:


model_rf.best_params_


# In[50]:


preds_train_rf = model_rf.predict(X=X_train)
preds_test_rf = model_rf.predict(X=X_test)


# In[51]:


print("RMSLE para o Random Forest (Train): ", rmsle(np.exp(y_log_train), np.exp(preds_train_rf), False))
print("RMSLE para o Random Forest (Test): ", rmsle(np.exp(y_log_test), np.exp(preds_test_rf), False))


# ### Distribuições das predições (Gradient Boosting)

# In[52]:


preds_test_gbr = model_gbr.predict(X=X_test)
fig,(ax1,ax2)= plt.subplots(ncols=2)
fig.set_size_inches(14,6)
sns.distplot(df_train['count'], ax=ax1, bins=50)
sns.distplot(np.exp(preds_test_gbr), ax=ax2, bins=50)


# ### Distribuições das predições (Random Forest)

# In[53]:


preds_test_rf = model_rf.predict(X=X_test)
fig,(ax1,ax2)= plt.subplots(ncols=2)
fig.set_size_inches(14,6)
sns.distplot(df_train['count'], ax=ax1, bins=50)
sns.distplot(np.exp(preds_test_rf), ax=ax2, bins=50)


# ### Diferença entre as predições dos dois modelos (GB e RF)

# In[106]:


df_results = pd.DataFrame({'preds_gbr': preds_test_gbr, 'preds_rf': preds_test_rf})


# In[107]:


df_results.head()


# In[109]:


fig,ax1= plt.subplots(nrows=1)
fig.set_size_inches(12,12)

ax1 = sns.regplot(x="preds_gbr", y="preds_rf", data=df_results, ax=ax1)
ax1.set_title('Predições do Gradient Boosting vs Predições do Random Forest')

plt.show()

