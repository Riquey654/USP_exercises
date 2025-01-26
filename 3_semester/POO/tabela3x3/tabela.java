import java.util.Scanner;

public class tabela {
	private int [][] matriz;
    Scanner texto = new Scanner(System.in);

	
	public tabela() {
	    matriz = new int[newsize][newsize];
	}
    
    //System.out.print(" ")
	
	public int printmatriz() {
	    int contador = 0;
	    for(int i = 0; i < newsize; i++) {
	        for(int k = 0; k < newsize; k++) {
	            System.out.print("+------");
	        }
	        System.out.print("+");
	        
	        System.out.print("\n");
	        for(int j = 0; j < newsize; j++) {
	            System.out.print("|   ");
	            if(matriz[i][j] == ((j)+(i*newsize))) {
	                contador = contador + 1;
	            }
	            System.out.print(matriz[i][j] + "  ");
	        }
	        System.out.print("|");
	        System.out.print("\n");
	    }
	    for(int h = 0; h < newsize; h++) {
	            System.out.print("+------");
	   }
	   System.out.print("+\n");
	    
	    return contador;
	    
	}
	
	public void comando() {
	    char strcomando;
	    int flag = 0;
	    flag = printmatriz();

	    //System.out.println("Digite u, d, l or r.");
	    while(true) {
	        int sai = 0;
	        strcomando = texto.next().charAt(0);
	        switch(strcomando) {
	           case 'u':
	                up();
	                break;
	           case 'd':
	                down();
	                break;
	           case 'l':
	                left();
	                break;
	           case 'r':
	                right();
	                break;
	           default: 
                    //System.out.println("Funcao invalida");
                    sai = 1;
                    break;
	        }
	        flag = printmatriz();
	        if(sai == 1) {
	            System.out.println("\n\n");
	            break;
	        }
	    }
	    if(flag == 9) {
	       System.out.println("Posicao final: true");
	   }else{
	       System.out.println("Posicao final: false");
	   }
	}
	
	public void up() {
	    
	    int troca_x = -1;
	    int troca_y = -1;
	    
	    //achar em que posicao o 0(vazio) está
		for(int i = 0; i < 3; i++) {
		    for(int j = 0; j < 3; j++) {
		        if(matriz[i][j] == 0) {
		            troca_x = i;
		            troca_y = j;
		        }
		    }
		}
		if(troca_x == 2) {
		    System.out.print("Nao é possivel ir pra cima\n");
		} else {
		    int temp = matriz[troca_x][troca_y];
		    matriz[troca_x][troca_y] = matriz[troca_x + 1][troca_y];
		    matriz[troca_x + 1][troca_y] = temp;
		}
		
	}
		
	public void down() {
	    
	    int troca_x = -1;
	    int troca_y = -1;
	    
	    //achar em que posicao o 0(vazio) está
		for(int i = 0; i < 3; i++) {
		    for(int j = 0; j < 3; j++) {
		        if(matriz[i][j] == 0) {
		            troca_x = i;
		            troca_y = j;
		        }
		    }
		}
		if(troca_x == 0) {
		    System.out.print("Nao é possivel ir pra baixo\n");
		} else {
		    int temp = matriz[troca_x][troca_y];
		    matriz[troca_x][troca_y] = matriz[troca_x - 1][troca_y];
		    matriz[troca_x - 1][troca_y] = temp;
		}
			
	}
		
	public void left() {
	    
	    int troca_x = -1;
	    int troca_y = -1;
	    
	    //achar em que posicao o 0(vazio) está
		for(int i = 0; i < 3; i++) {
		    for(int j = 0; j < 3; j++) {
		        if(matriz[i][j] == 0) {
		            troca_x = i;
		            troca_y = j;
		        }
		    }
		}
		if(troca_y == 2) {
		    System.out.print("Nao é possivel ir pra esquerda\n");
		} else {
		    int temp = matriz[troca_x][troca_y + 1];
		    matriz[troca_x][troca_y + 1] = matriz[troca_x][troca_y];
		    matriz[troca_x][troca_y] = temp;
		}
			
	}
		
	public void right() {
	    
	    int troca_x = -1;
	    int troca_y = -1;
	    
	    //achar em que posicao o 0(vazio) está
		for(int i = 0; i < 3; i++) {
		    for(int j = 0; j < 3; j++) {
		        if(matriz[i][j] == 0) {
		            troca_x = i;
		            troca_y = j;
		        }
		    }
		}
		if(troca_y == 0) {
		    System.out.print("Nao é possivel ir pra direita\n");
		} else {
		    int temp = matriz[troca_x][troca_y - 1];
		    matriz[troca_x][troca_y - 1] = matriz[troca_x][troca_y];
		    matriz[troca_x][troca_y] = temp;
		}
			
	}
}