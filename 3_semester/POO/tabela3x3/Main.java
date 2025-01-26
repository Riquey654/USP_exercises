import java.util.Scanner;
import java.util.ArrayList;

public class Main
{
    
	public static void main(String[] args) {
	    
        tabela flu = new tabela();

        flu.InicializaMatriz();
	    
	    flu.comando();
	}
	
	ArrayList<int> numeros = new ArrayList<int>();

    public void InicializaMatriz() {
        //System.out.print("O programa a seguir é uma tabela 3x3.\n");
	    //System.out.print("Digite números de 0 a 8, sendo que 0 significa um espaco vazio\n");
	    
    while(true) {
        numeros.add(texto.nextInt());
    }
    
    int size = arrayList.size();
    int newsize = Math.sqrt(size);
	    
	    for(int i = 0; i < newsize; i++) {
	        for(int j = 0; j < newsize; j++) {
	            matriz[i][j] = numeros.get((j)+(i*newsize));
	        }
	    }
	    
    }
	
	
}