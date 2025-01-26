/******************************************************************************
filhos 2i + 1 e 2i + 2
*******************************************************************************/

import java.util.Scanner;
import java.util.SortedSet; //biblioteca que insere ordenado
//eu poderia fazer bubble sort, mas é lento

public class Main
{
	public static void main(String[] args) {
        
        ArvAVL teste = new ArvAVL(12);
        teste.insert("Henrique");
        teste.insert("Gustavo");
        teste.insert("Paulo");
        teste.insert("Irineu");
        teste.insert("Aline");
        System.out.print(teste.toString());
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*public class ArvBal extends ArvBin {
    
    public ArvBal() {
        
    }
    
    public ArvAVL(int len) {
        super(len);
    }
    
    private int countNodes(int i) { //conta nós de uma sub arvore
            
        //usar recursao;
        if(i < this.length) {
            return 0;
        }
        
        return countNodes(2*i + 1) + countNodes(2*i + 2) + 1;
    }
    
    public boolean find(String v) {
        super(v);
    }
    
    private String getNode(int i) {
        if(this.array[i] == "0") {
            System.out.println("Nó vazio");
        }
        
        return this.array[i];
    }
    
    public void insert(String value) {
        
        if(this.length == len()) {
            System.out.println("Árvore cheia");
        }
        
        int indice = 0;
        
        while(indice < this.length) {
            
            if(this.array[indice] == "0") {
                this.array[indice] = value;
                if(isbalance() == true) {
                    return;
                }else{
                    balancearAVL();
                    return;
                }
            }
            
            if(this.array[indice].compareTo(value) > 0) {
                indice = indice*2 + 1;
            }else{
                indice = indice*2 + 2;
            }
        }
        System.out.println("Impossivel inserir");
        return;
    }
    
    private boolean isBalance() {
        
        int indice = 0;
        
        while(indice < this.length) {
            if(height(2*i + 1) - height(2*i + 2) >= 2) {
                
                return false;
                
            }else if(height(2*i + 1) - height(2*i + 2) <= -2) {
                
                return false;
                
            }
            indice++;
        }
        return true;
    }
    
    public int len() {
        super();
    }
    
    private int nodeLeft(int i) {
        return i*2 + 1;
    }
    
    private int nodeRight(int i) {
        return i*2 + 2;
    }
    
    public boolean remove(String v) {
        ////////////////////////////////////
    }
    
    private void setNode(int i, String v) {
        this.array[i] = v;
    }
    
    public String toString() {
        super();
    }
    
    private int height(int i) {
        
        if(i < this.length) {
            return 0;
        }
        
        if(this.array[i] == "0") {
            
            return 0;
            
        }else{
            
            return max(height(i*2 + 1), height(i*2 + 2)) + 1;
            
        }
    }
    
}*/