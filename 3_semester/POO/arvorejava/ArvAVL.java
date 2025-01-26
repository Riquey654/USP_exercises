import java.util.Scanner;
import java.util.SortedSet;
import java.util.ArrayList;
import java.util.Collections;



public class ArvAVL extends ArvBin {
    
    public ArvAVL(int tamanho) {
        super(tamanho);
    }
    
    protected int countNodes(int i) { //conta nós de uma sub arvore
            
        //usar recursao;
        if(i >= this.length) {
            return 0;
        }
        
        return countNodes(2*i + 1) + countNodes(2*i + 2) + 1;
    }
    
    public boolean find(String v) {
        return super.find(v);
    }
    
    protected String getNode(int i) {
        if(this.array[i].compareTo("0") == 0) {
            System.out.println("Nó vazio");
        }
        
        return this.array[i];
    }
    
    public void insert(String value) {
        if(this.length == len()) {
            System.out.println("Arvore cheia");
            return;
        }
        
        int indice = 0;
        
        while(indice < this.length) {
            if(this.array[indice].compareTo("0") == 0) {
                //System.out.println(this.array[4]);
                this.array[indice] = value;
                if(isBalance() == true) {
                    return;
                } else {
                    System.out.println("Impossivel inserir");
                    balancearAVL();
                    return;
                }
            }
            
            if(this.array[indice].compareTo(value) > 0) {
                indice = indice*2 + 1;
            } else {
                indice = indice*2 + 2;
            }
        }
        System.out.println("Impossivel inserir");
        return;
    }


    
    protected boolean isBalance() {
        
        int indice = 0;
        
        while(indice < this.length) {
            if(height(2*indice + 1) - height(2*indice + 2) >= 2) {
                
                return false;
                
            }else if(height(2*indice + 1) - height(2*indice + 2) <= -2) {
                
                return false;
                
            }
            indice++;
        }
        return true;
    }
    
    public int len() {
        return super.len();
    }
    
    protected int nodeLeft(int i) {
        return i*2 + 1;
    }
    
    protected int nodeRight(int i) {
        return i*2 + 2;
    }
    
    public boolean remove(String v) {
        for(int i = 0; i < this.length; i++) {
            if((this.array[i]).compareTo(v) == 0) {
                
                this.array[i] = "0"; //deixa vazio
                balancearAVL();
                return true;
            }
        }
        return false;
    }
    
    protected void setNode(int i, String v) {
        this.array[i] = v;
    }
    
    public String toString() {
        return super.toString();
    }
    
    private int height(int i) {
        if(i >= this.length) {
            
            return 0;
            
        }
        if(this.array[i].compareTo("0") == 0) {
            
            return 0;
            
        } else {
            return Math.max(height(i*2 + 1), height(i*2 + 2)) + 1;
        }
    }

    
    private ArrayList<String> ordena() {
        
        ArrayList<String> nomes = new ArrayList<String>();
        
        for(int i = 0; i < this.length; i++) {
            if(this.array[i].compareTo("0") != 0) {
                nomes.add(this.array[i]);
            }
        }
        
        Collections.sort(nomes);
        
        return nomes;
    }
    
    private void balancearAVL() {
        
        //ordenar a atual arvore em um vetor
        //depois, heapificar
        
        ArrayList<String> ordenado = ordena();
        
        for(int i = ordenado.size(); i < this.length; i++) {
            ordenado.add("0");
        }
        
        ArvAVL newtree = new ArvAVL(this.length);
        
        System.out.println(newtree.length);
        
        //uma lista com todos os nomes em ordem alfabetica
        
        //insereAVL(newtree, ordenado, 0, newtree.length - 1);
        
        //copiar a nova arvore para a arvore antiga
        this.length = newtree.length;
        this.array = new String[this.length];
        for(int h = 0; h < this.length; h++) {
            this.array[h] = newtree.array[h];
        }
        
    }
    
    private void insereAVL(ArvAVL nova, ArrayList<String> vetor, int inicio, int fim) {
        
        if(inicio > fim) {
            return;
        }
        
        int meio = (inicio + fim)/2;
        nova.insert(vetor.get(meio));
        
        insereAVL(nova, vetor, inicio, meio - 1);
        insereAVL(nova, vetor, meio + 1, fim);
        
    }
}
