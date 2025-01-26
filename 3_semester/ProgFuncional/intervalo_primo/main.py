import sys
from itertools import count, islice
from functools import reduce
    
def isprime(inicio, n):
    
    if n < 2:
        return True
    if(inicio * inicio > n):
        return True
        
    if(n % inicio == 0):
        return False
        
    return isprime(inicio + 1, n)
    
        
def subtrair_com_primo_anterior(n):
    lista_menores_n = list(range(n - 1, 1, -1))
    primos_menores_n = list(filter(isprime, lista_menores_n))
    return (n - primos_menores_n[0])
        

x = int(input('Digite um inteiro '))
y = int(input('Digite outro inteiro, sendo este maior que o primeiro '))

if x >= y:
    print('Erro, segundo numero menor ou igual ao primeiro')
    sys.exit()
    
#lista de x a y
#islice nao inclui primeiro valor, mas inclui o ultimo na lista
lista_intervalo = list(islice(count(1), x-1, y))

#filtrar o intervalo pra so primos
primos_intervalo = list(filter(isprime, lista_intervalo))

#usar map pra aplicar funcao pra cada elemento da lista
intervalo_entre_primos = list(map(subtrair_com_primo_anterior, primos_intervalo))

#verificar o maior valor, excluindo o primeiro valor porque o primeiro primo da lista nao pode ser incluido
maior_intervalo_entre_primos = reduce(lambda a, b: a if a > b else b, intervalo_entre_primos[1:])

print(maior_intervalo_entre_primos)
