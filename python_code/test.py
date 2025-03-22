import numpy as np
# （1）全0数组
zeros_array = np.zeros((3, 3))  # 创建一个3x3的全0数组
print("全0数组：")
print(zeros_array)

# （2）全1数组
ones_array = np.ones((3, 3))  # 创建一个3x3的全1数组
print("\n全1数组：")
print(ones_array)

# （3）随机数数组
random_array = np.random.rand(3, 3)  # 创建一个3x3的随机数数组，元素在[0, 1)之间
print("\n随机数数组：")
print(random_array)