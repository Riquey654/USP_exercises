from numpy.linalg import inv
from numpy import dot

dim = (int(input()))

basis1 = []
basis2 = []


for i in range (dim):
 
  basis1.append(list(map(float, input().split())))

for j in range (dim):
 
  basis2.append(list(map(float, input().split())))

vector1 = list(map(float, input().split()))

transformationMatrix = dot(basis2, inv(basis1))

result = dot(transformationMatrix, vector1)

for value in result:
    print("{:.4f}".format(value), end = " ")