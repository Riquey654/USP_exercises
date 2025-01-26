import sys
from functools import reduce

def isprime(inicio, n):
    
    if n < 2:
        return False
    if(inicio * inicio > n):
        return True
        
    if(n % inicio == 0):
        return False
        
    return isprime(inicio + 1, n)
    
def lista_primos(inicio, fim):
    
    if(inicio > fim):
        return []
    elif(isprime(2, inicio)):
        return [inicio] + lista_primos(inicio + 1, fim)
    else:
        return lista_primos(inicio + 1, fim)
        
def subtrair_com_primo_anterior(num_inicial, n):
    
    if(isprime(2, n - 1)):
        return (num_inicial - (n - 1))
    else:
        return subtrair_com_primo_anterior(num_inicial, n - 1)
        
def lista_intervalos(lista_primos, inicio, fim):
    
    if(len(lista_primos) < 2):
        print('nao ha pelo menos 2 primos nesse intervalo')
        sys.exit()
    
    if(inicio >= fim):
        return []
    else:
        return [subtrair_com_primo_anterior((lista_primos[inicio + 1]),(lista_primos[inicio + 1]))] + lista_intervalos(lista_primos, inicio + 1, fim)
       
 

x = int(input('Digite um inteiro '))
y = int(input('Digite outro inteiro, sendo este maior que o primeiro '))

if x >= y:
    print('Erro, segundo numero menor ou igual ao primeiro')
    sys.exit()
    
print(reduce(lambda a, b: a if a > b else b, lista_intervalos(lista_primos(x, y), 0, len(lista_primos(x, y)) - 1)))
