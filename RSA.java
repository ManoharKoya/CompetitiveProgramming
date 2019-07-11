
    // pick 2 primes
    // m = p1*p2;
    // P(m) = (p1-1)*(p2-1)
    // 1<lock<P(m) and lock is coprime with m & P(m)
    // key*lock(mod P(m)) = 1

class RSA {
    int lock,key,m;
    int p1,p2;
    int Pm;
    public void process(int p1,int p2){
        this.p1 = p1; this.p2=p2;
        m = p1*p2;
        Pm = (p1-1)*(p2-1);
        lock = findLock(m, Pm);
        key = findKey(lock, Pm);
    }
    static int power(int a,int b){
        int res =1;
        for(int i=0;i<b;i++){
            res = res*a;
        }
        return res;
    }
    static int __gcd(int a, int b) 
    { 
        if (a == 0 || b == 0) 
            return 0; 
        if (a == b) 
            return a; 
        if (a > b) 
            return __gcd(a-b, b); 
                  
        return __gcd(a, b-a); 
    } 
    public int findLock(int m,int Pm){
        for(int i=2;i<Pm;i++){
            if(__gcd(i, m)==1 && __gcd(i, Pm)==1) return 1;
        }
        return 0;
    }
    public int findKey(int lock, int Pm){
        for(int i=1;i<=Pm;i++){
            if((i*lock)%Pm==1) return i;
        }
        return 0;
    }
    public int[] encrypt(String word){
        int sz = word.length();
        int[] arr = new int[sz];
        for(int i=0;i<sz;i++){
            int k = (int)(word.charAt(i));
            arr[i]=power(k, lock)%(m);
        }
        return arr;
    }
    public char[] deCrypt(int[] arr){
        int sz = arr.length;
        char[] S = new char[sz];
        for(int i=0;i<sz;i++){
            int k = power(arr[i], key)%(m);
            S[i] = (char)(k);
        }
        return S;
    }
    public static void main(String args[]){
        RSA object = new RSA();
        object.process(2, 7);
        System.out.print(object.key);
    }
}