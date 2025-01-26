contador = 0
linhas = 4
matriz = []
for i in range(linhas):
    linha = []
    for j in range(linhas):
        linha = linha + [i+j]
    matriz = matriz + [linha]
    
for k in range(linhas):
    for h in range(linhas):
        print(matriz[k][h])
        print(" ")
    print("\n")