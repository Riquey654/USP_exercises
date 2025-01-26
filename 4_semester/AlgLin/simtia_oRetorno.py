import numpy as np

d = int(input())
matriz = []

for i in range(d):
  linha = list(map(float, input().split()))
  matriz.append(linha)

if(np.linalg.det(matriz) != 0):
  print("SimTia, o Retorno")
else:
  print("Não")