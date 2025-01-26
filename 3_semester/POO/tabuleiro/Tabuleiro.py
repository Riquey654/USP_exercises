import math

class tabuleiro:
    
    tabela = []
    linha = 0
    def __init__(self, tabela = [], l = 0):
        self.tabela = []
        self.linha = l
        
        
def print_matriz(self):
    contador = 0;
    for i in range(self.linha):
        for k in range(self.linha):
            print("+------", end = "")
        print("+", end = "")
        
        print("")
        for j in range(self.linha):
            if(self.tabela[i][j] < 10):
                print("|   ", end = "")
            else:
                print("|  ", end = "")
            if(self.tabela[i][j] == ((j)+(i*self.linha))):
                contador = contador + 1
            if(self.tabela[i][j] == 0):
                print(" ", end = "")
            else:
                print(self.tabela[i][j], end = "")
                
            print("  ", end = "")

        print("|", end = "")
        print("")

    for h in range(self.linha):
        print("+------", end = "")

    print("+")
    print("")
	    
    return contador

def comando(self, direcao):
    print_matriz(self)
    match(direcao):
        case 'u':
            up(self)
        case 'd':
            down(self)
        case 'r':
            right(self)
        case 'l':
            left(self)

def criar_tabuleiro(self, array_num):
    
    contador = 0
    self.linha = int(math.sqrt(len(array_num)))
    matriz = []
    for i in range(self.linha):
        vetor = []
        for j in range(self.linha):
            vetor = vetor + [array_num[contador]]
            contador = contador + 1
        matriz = matriz + [vetor]
        
    return matriz

def up(self):
	    
    troca_x = -1
    troca_y = -1
	
    #achar em que posicao o 0(vazio) está
    for i in range(self.linha):
        for j in range (self.linha):
            if(self.tabela[i][j] == 0):
                troca_x = i
                troca_y = j
                
    if(troca_x != (self.linha) - 1):
        temp = self.tabela[troca_x][troca_y]
        self.tabela[troca_x][troca_y] = self.tabela[troca_x + 1][troca_y]
        self.tabela[troca_x + 1][troca_y] = temp

def down(self):
	    
    troca_x = -1
    troca_y = -1
	    
    #achar em que posicao o 0(vazio) está
    for i in range(self.linha):
        for j in range(self.linha):
            if(self.tabela[i][j] == 0):
                troca_x = i
                troca_y = j
                
    if(troca_x != 0):
        temp = self.tabela[troca_x][troca_y]
        self.tabela[troca_x][troca_y] = self.tabela[troca_x - 1][troca_y]
        self.tabela[troca_x - 1][troca_y] = temp

def left(self):
	    
    troca_x = -1
    troca_y = -1
	    
    #achar em que posicao o 0(vazio) está
    for i in range(self.linha):
        for j in range(self.linha):
            if(self.tabela[i][j] == 0):
                troca_x = i
                troca_y = j
                
    if(troca_y != self.linha - 1):
        temp = self.tabela[troca_x][troca_y + 1]
        self.tabela[troca_x][troca_y + 1] = self.tabela[troca_x][troca_y]
        self.tabela[troca_x][troca_y] = temp
		
def right(self):
	    
    troca_x = -1;
    troca_y = -1;
	    
    #achar em que posicao o 0(vazio) está
    for i in range(self.linha):
        for j in range(self.linha):
            if(self.tabela[i][j] == 0):
                troca_x = i
                troca_y = j
                
    if(troca_y != 0):
        temp = self.tabela[troca_x][troca_y - 1]
        self.tabela[troca_x][troca_y - 1] = self.tabela[troca_x][troca_y]
        self.tabela[troca_x][troca_y] = temp