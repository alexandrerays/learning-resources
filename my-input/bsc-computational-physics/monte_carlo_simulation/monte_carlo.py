# https://www.maxwell.vrac.puc-rio.br/19632/19632_4.PDF

from random import randint

def simulate(n):
	counter = 0
	for i in range(n):
		a = randint(1,6)
		b = randint(1,6)
		c = a + b
		print('not checked: ' + str(c))
		if c == 3:
			print('checked: ' + str(c))
			counter += 1
	return counter

n = 50000
pos_result = simulate(n)
answer = 100 * (float(pos_result) / float(n))
print('prob: ' + str(answer) + '%')
