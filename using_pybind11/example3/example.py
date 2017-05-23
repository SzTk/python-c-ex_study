# coding: utf-8
import numpy as np
import example

aaa = np.random.ranf([5,5])

# svd1はF-orderのデータしか受け取れない
# example.svd1(aaa)  # エラーになる
example.svd1(aaa.transpose())  

# svd2,svd3はC-order (numpyのデフォルト)のデータを受け取れる
example.svd2(aaa)
example.svd3(aaa)

# svd2は、numpy arrayでのスライスを引数にできる。
# svd3はできない。
example.svd2(aaa[0::2,0:5:2])
# example.svd3(aaa[0::2,0:5:2])  # エラーになる。

# 普通のスライスはsvd2でもsvd3でも受け取れる
example.svd2(aaa[0:2,0:5])
example.svd3(aaa[0::2,0:5])
