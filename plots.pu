#Este archivo usa ecoding: utf-8
import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt("walk.dat", delimiter = " ", skip_header = 0)
datano = np.genfromtxt("walkno.dat", delimiter = " ", skip_header = 0)


plt.hist(data)
plt.hist(datano)

plt.savefig("walk.pdf")
