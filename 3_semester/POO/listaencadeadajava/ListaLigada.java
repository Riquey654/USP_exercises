public class ListaLigada<NoLista> {
    
    NoLista<T> NO;
    //um NoLista tem um objeto e um ponteiro
    
    public static void ListaLigada() {
        NO = null;
    }
    
    //lista.insertInit(new Par<Integer, Double>(1, 1.0));
    public boolean insertInit(T valor) {
        NoLista<T> p = new NoLista<T>(valor);
        p.prox = cabeca;
        cabeca = p; 
    }
    
    public boolean insertEnd() {
        
    }
    
}