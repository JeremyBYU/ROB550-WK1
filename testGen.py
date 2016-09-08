#!/usr/bin/python
# Author: Jeremy Castagno
# Date: Sept 7 2016
# Summary: 
# 	This program will take two integer inputs and output a normally distributed
#	matrix of the the size of the two integers

import numpy as np
import sys
import common

m = 0 # this will be the rows of our matrix
n = 0 # this will be the columns of our matrix

# Ensure that we have 2 arguments
if (len(sys.argv)) < 3: 
	common.eprint('ERROR! Expected two integer arguments')
	sys.exit(0)

# Verify that the arguments are integers
try: 
	m = int(sys.argv[1])
	n = int(sys.argv[2])
	if not isinstance(m, int) or not isinstance(n, int):
		raise Exception
except Exception, e:
	common.eprint('ERROR! Expected two integer arguments')
	sys.exit(0)

# Generate the matrix using numpy	
matrix = np.random.rand(m, n)
common.printMatrix(matrix, m, n)







