import java.util.Scanner;
import java.util.SortedSet;


/*NAO DA PRA USAR O 0 COMO VAZIO PQ NA HORA DE ORDENAR FERRA O ROLE*/

public class ArvBin {
    
    protected String array[];
    protected int length;
    
    public ArvBin(int tamanho) {
        
        this.array = new String[tamanho];
        for(int i = 0; i < tamanho; i++) {
            this.array[i] = "0";
        }
        
        this.length = tamanho;
    }
    
    
    
    public boolean find(String v) {
        
        for(int i = 0; i < len(); i++) {
            if((this.array[i]).compareTo(v) == 0) {
                
                System.out.println("elemento encontrado.");
                return true;
            }
        }
        return false;
    }
    
    
    public void insert(String palavra) {
        if(len() == this.length) {
            System.out.println("Arvore cheia");
            return;
        }
        
        for(int i = 0; i < this.length; i++) {
            if(this.array[i].compareTo("0") == 0) {
                this.array[i] = palavra;
                break;
            }
        }
    }

    
    
    public int len() {
        
        int contador = 0;
        
        for(int i = 0; i < this.length; i++) {
            if(this.array[i].compareTo("0") != 0) {
                contador++;
            }
        }
        return contador;
    }
    
    
    public boolean remover(String remove) {
        for(int i = 0; i < this.length; i++) {
            if((this.array[i]).compareTo(remove) == 0) {
                
                this.array[i] = "0"; //deixa vazio
                balanceiaArv();
                return true;
            }
        }
        return false;
    }
    
    public String toString() {
        StringBuilder sb = new StringBuilder();
        
        sb.append("digraph {\n");
        
        for(int i = 0; i < this.length; i++) {
            if(this.array[i].compareTo("0") != 0) {
                /*System.out.println(this.length);
                System.out.println(this.array[0]);
                System.out.println(this.array[1]);
                System.out.println(this.array[2]);*/
                if(2*i + 1 < this.length && this.array[2*i + 1].compareTo("0") != 0) {
                    
                    sb.append(String.format("\"%d %s\" ->\"%d %s\"\n", i, this.array[i], (2* i + 1), this.array[2* i + 1]));
                }
                if(2*i + 2 < this.length && this.array[2*i + 2].compareTo("0") != 0) {
                    
                    sb.append(String.format("\"%d %s\" ->\"%d %s\"\n", i, this.array[i], (2* i + 2), this.array[2* i + 2]));
                }
            }
        }
        sb.append("}\n");
        return sb.toString();
    }


    
    private void balanceiaArv() {
        
        int trocou = 0;
        
        for(int i = 0; i < this.length; i++) {
            if(this.array[i] == "0") {//se estiver vazio
                if(2*i + 1 < this.length) { //verifica se o filho da esq existe
                    if(this.array[2*i + 1].compareTo("0") != 0) { // se existe, ve se esta cheio
                    
                        this.array[i] = this.array[2*i + 1]; //se ta cheio, sobe o nó esquerdo
                        this.array[2*i + 1] = "0";
                        trocou = 1;
                    }
                }
                
                if(2*i + 2 < this.length && trocou == 0) { //verifica se o filho da dir existe e se ja nao houve a troca
                    if(this.array[2*i + 2].compareTo("0") != 0) { // se existe, ve se esta cheio
                    
                        this.array[i] = this.array[2*i + 2]; //se ta cheio, sobe o nó direito
                        this.array[2*i + 2] = "0";
                    }
                }
                //se trocou == 0 nao precisou trocar
            }
        }
    }
    
    
}