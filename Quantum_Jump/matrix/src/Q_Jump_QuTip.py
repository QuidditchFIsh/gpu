from qutip import *
import numpy as np


H = 0.6*(destroy(2) + destroy(2).dag())

time = np.linspace(0,20,2000)

psi0 = basis(2,1)

data = mcsolve(H,psi0,time,[0.1*destroy(2).dag()],[sigmaz()])

with open("data.dat",'w') as f:
	for j in range(0,len(time)):
		f.write(str(j) + " " + str(data.expect[0][j]) + "\n")