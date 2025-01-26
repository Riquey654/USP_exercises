/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
public class Main
{
	public static void main(String[] args) {
		ListaLigada<Par<Integer, Double>> lista;
		lista = new ListaLigada<Par<Integer, Double>>();
		lista.insertInit(new Par<Integer, Double>(1, 1.0));
		lista.insertEnd(new Par<Integer, Double>(0, 0.0));
		System.out.println(lista);
	}
}
