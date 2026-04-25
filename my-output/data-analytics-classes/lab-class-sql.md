# Roteiro da aula:

## 1) Baixar os dados

Para baixar os dados, usar [este link](https://www.kaggle.com/datasets/gabrielramos87/bike-trips) do Kaggle (é preciso fazer o login) ou [este link](https://drive.google.com/drive/folders/15ofaxgnRm-KfED7zyVaSzWqZKgS4gOHN?usp=sharing) do Google Drive.

## 2) Introdução

* Verificar familiaridade dos alunos com o SQL. Alguém já utilizou? Etc.
* Mostrar PDF do quero mais rapidamente.
* Explicar porque o SQL é importante (basicamente porque é a linguagem dos bancos de dados).
* Ex: empresa de e-commerce (dados de produtos, clientes).


## 3) Mostrar ferramenta para trabalhar online ([sqlitonline.com](https://sqliteonline.com/))

* Trata-se de uma ferramenta didática.
* Explicar principais elementos da ferramenta.
* Comentar sobre outras ferramentas de dw (data warehouse) corporativas (Ex: Redshift, Snowflake, GCP, Azure)

## 4) Fazer o upload dos dados na ferramenta ([sqlitonline.com](https://sqliteonline.com/))

* Para importar o arquivo .csv, basta ir em Import > Open e selecionar o caminho do arquivo .csv que foi baixado.
* Selecionar a opção `Column name` como sendo `First line`.

## 5) Fazer primeira query (testar)

```sql
SELECT * FROM trips
```



# Perguntas da aula

```
/*

Empresa de aluguel de bikes, a ideia é que a gente responda algumas perguntas de negócio.

1) Qual é a quantidade de corridas válidas realizadas?
2) Qual é a duração média das corridas válidas?
3) Qual foi a quantidade de corridas realizadas em cada ano? 

Corridas válidas: corridas com mais de 5 min de duração.

Plataforma: https://sqliteonline.com/

*/
```

# Perguntas adicionais (caso tenha tempo)

```
4) No ano de 2014, qual mês teve mais corridas?
5) Qual é o horário de pico para o início das corridas no melhor mês de corridas de 2015? (Considerar apenas a hora cheia)
6) Qual é o horário de pico para o fim das corridas no melhor mês de corridas de 2015? (Considerar apenas a hora cheia)
```

# 1) Qual é a quantidade de corridas válidas realizadas?

```sql
select count(id) 
from trips 
where DURATION >= 300
```

# 2) Qual é a duração média das corridas?

```sql
SELECT AVG(DURATION)
FROM trips
WHERE DURATION >= 300
```


# 3) Qual foi a quantidade de corridas realizadas em cada ano?

```sql
SELECT SUBSTRING(start_date, 1, 4) AS ANO, 
	   COUNT(ID) AS QTDE_CORRIDAS
FROM trips
-- WHERE DURATION >= 300
GROUP BY ANO
ORDER BY QTDE_CORRIDAS DESC
```



# Dicas para quem está iniciando no SQL


1. Verifique qual é a ferramenta de data warehouse da sua empresa.
2. Coloque a mão na massa, reproduza os exercícios vistos em aula e proponha novas perguntas.
3. Entender os dados a partir do negócio.
4. Quebrar a query em várias linhas para facilitar a leitura.
5. Fazer analogias com o que você já conhece (ex: tabela dinâmica do excel).
6. Aprender a ferramenta para não precisar se procupar com a ferramenta.
7. Ver o que faz sentido pro seu contexto (gestão vs não gestão)




# Principais aplicações do SQL

1. Colocar informação importante num ppt. Ex: duração média das corridas de bicicleta.
2. Exportar dados para uma planilha do excel e fazer gráficos.
3. Jogar o resultado de uma query para uma ferramenta de BI e criar uma dashboard (Ex: Tableau).



---








# 4) No ano de 2014, qual mês teve mais corridas?

```sql
SELECT SUBSTRING(start_date, 1, 4) AS ANO,
	   SUBSTRING(start_date, 6, 2) AS MES,
       COUNT(ID) AS QTDE_CORRIDAS
FROM trips
WHERE ANO = "2014" AND DURATION >= 300
GROUP BY MES
ORDER BY QTDE_CORRIDAS DESC
LIMIT 1
```





# 5) Qual é o horário de pico para o início das corridas no melhor mês de corridas de 2015? (Considerar apenas a hora cheia)

```sql
WITH MELHOR_MES AS (
  SELECT SUBSTRING(start_date, 1, 4) AS ANO,
         SUBSTRING(start_date, 6, 2) AS MES,
         COUNT(ID) AS QTDE_CORRIDAS
         --SUBSTRING(start_date, 9, 2) AS HORA
  FROM trips
  WHERE ANO = "2015" AND duration >= 300
  GROUP BY MES
  ORDER BY QTDE_CORRIDAS DESC
  LIMIT 1
)

SELECT SUBSTRING(start_date, 12, 2) AS HORA,
	   SUBSTRING(start_date, 6, 2) AS MES,
       SUBSTRING(start_date, 1, 4) AS ANO,
       COUNT(ID) AS QTDE_CORRIDAS
FROM TRIPS
WHERE duration >= 300 AND
	  ANO = "2015" AND
      MES = (SELECT MES FROM MELHOR_MES)
GROUP BY HORA
ORDER BY QTDE_CORRIDAS DESC
LIMIT 1

```

# 6) Qual é o horário de pico para o fim das corridas no melhor mês de corridas de 2015? (Considerar apenas a hora cheia)

```sql
WITH MELHOR_MES AS (
  SELECT SUBSTRING(start_date, 1, 4) AS ANO,
         SUBSTRING(start_date, 6, 2) AS MES,
         COUNT(ID) AS QTDE_CORRIDAS
         --SUBSTRING(start_date, 9, 2) AS HORA
  FROM trips
  WHERE ANO = "2015" AND duration >= 300
  GROUP BY MES
  ORDER BY QTDE_CORRIDAS DESC
  LIMIT 1
)
SELECT SUBSTRING(end_date, 12, 2) AS HORA,
	   SUBSTRING(end_date, 6, 2) AS MES,
       SUBSTRING(end_date, 1, 4) AS ANO,
       COUNT(ID) AS QTDE_CORRIDAS
FROM TRIPS
WHERE duration >= 300 AND
	  ANO = "2015" AND
      MES = (SELECT MES FROM MELHOR_MES)
GROUP BY HORA
ORDER BY QTDE_CORRIDAS DESC
LIMIT 1
```



# Forma alternativa de pegar a data

```sql
select start_date,
     strftime('%Y', start_date),
     strftime('%m', start_date),
       strftime('%H', start_date)
from trips limit 100
```

