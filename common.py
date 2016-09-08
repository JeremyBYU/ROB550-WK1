#!/usr/bin/python
# Author: Jeremy Castagno
# Date: Sept 7 2016
# Summary: 
# 	This module contains common functions
#   That will be used across several programs
from __future__ import print_function
import time
import sys
import csv
import numpy as np
# Print Matrix Function to CSV Format
def printMatrix(matrix, m, n):
	# Print the matrix
	for i in range(m):
		for j in range(n):
			if j < n - 1: # dont print a comma on last column
				print(str(matrix[i][j]) + ',', end=' ')
			else:
				print(str(matrix[i][j]), end='')	
		print() # new row

# Read a CSV file from a specified csv file
def readCSVFile(fileName):
	with open(fileName, 'rb') as f:
		reader = csv.reader(f)
		matrix = list(reader)
	return np.array(matrix).astype('float')

def utime_now():
	return int(time.time()*1E6)

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def getMatrixDimensions(matrixName):
	dim = input('Enter the dimensions for matrix ' + matrixName + ' (e.g 2,2): ')
	if len(dim) != 2:
		raise Exception
	m = int(dim[0])
	n = int(dim[1])
	if n < 1 or m < 1:
		raise Exception
	return m,n

def matchingDimensions(matrix, dim):
	matrix_m = len(matrix)
	matrix_n = len(matrix[0])
	return matrix_m == dim[0] and matrix_n == dim[1]

def validMultiplication(aDim, bDim):
	return aDim[1] == bDim[0]

def writeCSVFile(fileName, data):
	np.savetxt(fileName, data, delimiter=',')