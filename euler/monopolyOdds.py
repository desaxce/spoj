from random import *

cases = [0 for k in range(40)]
j = 0 # GO is the starting point

# CC: 1=>GO; 2=>JAIL
ccHitsCount = 0 # Number of time we reach a CC cell

# CH: 1=>GO; 2=>JAIL; 3=>C1; 4=>E3; 5=>H2; 6=>R1
#	  7&8=>next R; 9=>next U; 10<=3 cells
chHitsCount = 0 # Nb of time we reach CH

n = 4 # Number of sides on the die

# iteration: number of times we had a double before
# i: cell we start from
def jouer(iteration, i):
	global n
	a = randint(1, n)
	b = randint(1, n)

	if (a == b) and (iteration == 2):
		return 10 # three doubles in a row => JAIL
	
	i += a+b
	i = i%40

	if i in [2, 17, 33]: # Community Chest
		i = executeCC(i)
	elif i in [7, 22, 36]: # Chance
		i = executeCH(i)
	elif i == 30: # Go to Jail
		i = 10
	
	if a == b:
		i = jouer(iteration+1, i)
	
	return i

def executeCH(i):
	global chHitsCount
	chHitsCount += 1
	numero = (chHitsCount % 16)
	if numero == 1: # GO
		return 0
	elif numero == 2: # JAIL
		return 10
	elif numero == 3: # C1
		return 11
	elif numero == 4: # E3
		return 24
	elif numero == 5: # H2
		return 39
	elif numero == 6: # R1
		return 5
	elif numero in [7, 8]: # next railway station
		if i == 7:
			return 15
		elif i == 22:
			return 25
		else:
			return 5
	elif numero == 9: # next utility
		if i == 22:
			return 28
		else:
			return 12
	elif numero == 10: # back 3 cells
		return (i-3)%40

	return i

def executeCC(i):
	global ccHitsCount
	ccHitsCount += 1
	numero = (ccHitsCount % 16)
	if numero == 1: # GO
		return 0
	elif numero == 2: # JAIL
		return 10
	
	return i # No movement

def resoudre(N):
	global j, cases
	for k in range(N):
		j = jouer(0, j)
		cases[j] += 1
	cases = [100.*i/N for i in cases]

