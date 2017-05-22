import example
import numpy as np

mat = np.random.ranf([2,3])
mat = mat.transpose()

hoge = example.svd(mat)
print(hoge)