# coding: utf-8
import example
import numpy as np
import pandas as pd

irisdata = pd.read_csv('iris.data', header=None)
input = irisdata.loc[:,[0, 1, 2, 3]]
target = irisdata.loc[:,[4]] == 'Iris-setosa'

input = np.ascontiguousarray(input.as_matrix().astype(np.float64))
target = np.ascontiguousarray(target.as_matrix().astype(np.float64))
target = target.reshape(150)

lsq_coef = example.lsq(input, target)
print(lsq_coef)

print((np.dot(lsq_coef, input.T)>0).astype(np.float64))
print(target)
