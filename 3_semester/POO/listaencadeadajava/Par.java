public class Par<Tipo1, Tipo2> {
    
    Tipo1 coisa1;
    Tipo2 coisa2;
    
    public static void Par(Tipo1 v1, Tipo2 v2) {
        coisa1 = v1;
        coisa2 = v2;
    }
    
    public Tipo1 getFirst() {
        return this.coisa1;
    }
    
    public tipo2 getSecond() {
        return this.coisa2;
    }
    
}