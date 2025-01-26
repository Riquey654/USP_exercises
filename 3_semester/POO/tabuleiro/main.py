import math
from Tabuleiro import tabuleiro
import Tabuleiro

if __name__ == "__main__":    
    strespaconumeros = input('')
    strcomandos = input('')
    
    strnumeros = list(map(int, strespaconumeros.split()))
    
    t1 = tabuleiro()
    t1.tabela = Tabuleiro.criar_tabuleiro(t1, strnumeros)
    
    t1.linha = int(math.sqrt(len(strnumeros)))
    
    for i in list(strcomandos):
        Tabuleiro.comando(t1, i)
        
    flag = Tabuleiro.print_matriz(t1)
    
    if(flag == int(t1.linha**2)):
        print("Posicao final: True")
    else:
        print("Posicao final: False")
