# coding: utf-8
import example
import numpy as np
input = np.array([[1,2,3],[6,4,5],[8,9,7],[10,11,12]])
input = input.astype(np.float64)
Umat = example.svd(input)
print(Umat)

# get least square solution.
lh = np.array([1.,2.,4.,5.])
lsqq = example.lsq(input, lh)
print(lsqq)
