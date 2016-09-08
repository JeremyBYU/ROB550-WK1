#!/usr/bin/python
# Author: Jeremy Castagno
# Date: Sept 7 2016
# Summary: 
# 	This program will multpy two matrices (A, B) together.
#	The user will prompted for the sizes of A and B 
# 	The matrices are defined in two files (A.csv, B.csv).
#	
import numpy as np

import sys
import common # Common functions module

# Read matrices from files
matrixA = common.readCSVFile('A.csv')
matrixB = common.readCSVFile('B.csv')

# Ensure that we have 2 arguments
if (len(sys.argv)) < 2: 
	common.eprint('ERROR! Expected outpute filename as argument (e.g. C.csv)')
	sys.exit(0)
outFile = sys.argv[1]

# Get User Input of the matrix file size
try:	
	aDim = common.getMatrixDimensions('A')
	bDim = common.getMatrixDimensions('B')
except Exception, e:
	common.eprint('ERROR! The dimesions of the matrix must be positve and have the form n,m (e.g 2,2)')
	sys.exit(0)
# Check dimensions match and that the multiplication is valid
if not common.matchingDimensions(matrixA, aDim) or not common.matchingDimensions(matrixB, bDim) or not common.validMultiplication(aDim,bDim):
	common.eprint('ERROR! Dimension do not match file or invalid multiplication')
	sys.exit(0)

# At this point we have matrices and supplied dimenstions that are valid
time = common.utime_now() # initial timestamp
matrixAB = np.dot(matrixA, matrixB) # numpy matrix multiplication
elapsedTime = common.utime_now() - time # elapsed time from matrix mult
common.printMatrix(matrixAB, aDim[0], bDim[1])
common.writeCSVFile(outFile, matrixAB)
print 'Elapsed time: ' + str(elapsedTime) + ' microseconds'