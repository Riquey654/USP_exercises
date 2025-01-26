import numpy as np

def semVerTia(tipo, parametros, matrizAtual):
  if(tipo == "R"):

    radiano = (float(parametros[0]))*np.pi/180
    matrizRot = [[np.around(np.cos(radiano)), np.around(-np.sin(radiano))], [np.around(np.sin(radiano)), np.around(np.cos(radiano))]]
    matrizResultante = np.dot(matrizAtual, matrizRot)

    return matrizResultante

  else:

    matrizEsc = [[float(parametros[0]), 0], [0, float(parametros[1])]]
    matrizResultante = np.dot(matrizAtual, matrizEsc)

    return matrizResultante


n = int(input())

matrizFinal = np.identity(2)

for i in range (n):
  linha = input().split()
  matrizFinal = semVerTia(linha[0], linha[1:], matrizFinal)

if(np.linalg.det(matrizFinal) != 0):
  print("SimTia, te vejo!")
else:
  print("SemVerTia")