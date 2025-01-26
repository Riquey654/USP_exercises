import java.util.SortedSet;

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
public class Main
{
	public static void main(String[] args) {
	    
	    Object[] data = {"Kiwi","Banana","Mango","Aubergine","Strawberry"};
        List list = Arrays.asList(data);
        Collections.sort(list);
        System.out.println(list);
        
	}
}

