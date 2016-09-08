#!/usr/bin/python
# Author: Jeremy Castagno
# Date: Sept 7 2016
# Summary: 
# 	This program will take two integer inputs and output a normally distributed
#	matrix of the the size of the two integers

import numpy as np
import sys

# Print Matrix Function to CSV Format
def printMatrix(matrix, m, n):
	# Print the matrix
	for i in range(m):
		for j in range(n):
			if j < n -1: # dont print a comma on last column
				print str(matrix[i][j]) + ',',
			else:
				print str(matrix[i][j]),		
		print # new row


m = 0 # this will be the rows of our matrix
n = 0 # this will be the columns of our matrix

# Ensure that we have 2 arguments
if (len(sys.argv)) < 3: 
	print 'ERROR! Expected two integer arguments'
	sys.exit(0)

# Verify that the arguments are integers
try: 
	m = int(sys.argv[1])
	n = int(sys.argv[2])
	if not isinstance(m, int) or not isinstance(n, int):
		raise Exception
except Exception, e:
	print 'ERROR! Expected two integer arguments'
	sys.exit(0)

# Generate the matrix using numpy	
matrix = np.random.rand(m, n)
printMatrix(matrix, m, n)







