public class NoLista<T> {
    
    public T thing;
    public NoLista<T> prox;
    
    public static void NoLista(T item) {
        thing = item;
        prox = null;
    }
    
    
}