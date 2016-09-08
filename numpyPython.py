#!/usr/bin/python
# Author: Jeremy Castagno
# Date: Sept 7 2016
# Summary: 
# 	This program will multpy two matrices (A, B) together.
#	The user will prompted for the sizes of A and B 
# 	The matrices are defined in two files (A.csv, B.csv).
#	
import numpy as np
import csv
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

def readCSVFile(fileName):
	with open(fileName, 'rb') as f:
		reader = csv.reader(f)
		matrix = list(reader)
	return matrix


def getMatrixDimensions(matrixName):
	dim = input('Enter the dimensions for matrix ' + matrixName + ' (e.g 2,2): ')
	if len(dim) != 2:
		raise Exception
	m = int(dim[0])
	n = int(dim[1])
	print n,m
	if n < 1 or m < 1:
		raise Exception
	return m,n

def matchingDimensions(matrix, dim):
	matrix_m = len(matrix)
	matrix_n = len(matrix[0])

	return matrix_m == dim[0] and matrix_n == dim[1]

def validMultiplication(aDim, bDim):
	return aDim[1] == bDim[0]

# Read matrices from files
matrixA = np.array(readCSVFile('A.csv')).astype('float')
matrixB = np.array(readCSVFile('A.csv')).astype('float')

# Get User Input of the matrix file size
try:	
	aDim = getMatrixDimensions('A')
	bDim = getMatrixDimensions('B')
except Exception, e:
	print 'ERROR! The dimesions of the matrix must be positve and have the form n,m (e.g 2,2)'
	sys.exit(0)
# Check dimensions match and that the multiplication is valid
if not matchingDimensions(matrixA, aDim) or not matchingDimensions(matrixB, bDim) or not validMultiplication(aDim,bDim):
	print 'ERROR! Dimension do not match file or invalid multiplication'
	sys.exit(0)

# At this point we have matrices and supplied dimenstions that are valid
printMatrix(np.dot(matrixA, matrixB), aDim[0], bDim[1])