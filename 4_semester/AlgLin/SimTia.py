#formar uma lista de 0 ate o numero de dimensoes
#verificar se o vetor é elegivel para ser canonico
#se for, salvar o indice e verificar se esta na lista
#se estiver na lista, tirar
#ao fim, a lista deve estar vazia

flag = True

d,k = map(int, input().split())

vectorCheck = set()

for i in range (k):

    if d > k:
        flag = False
        break

    #contador = 0
    vetor = list(map(int, input().split()))
    for j in range (d):
        if vetor[j] == 1:   #verificar na list se tem o elemento j
            vectorCheck.add(j)
            break


if len(vectorCheck) == d:
    print("SimTia")
else:
    print("Não")