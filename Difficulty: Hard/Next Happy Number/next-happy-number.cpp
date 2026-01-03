class Solution {
  public:
    int sq(int n){
        return n*n;
    }
    int nxt(int n){
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
    bool is(int n){
        while(n!=1 && n!=4){
            n=nxt(n);
        }
        return n==1;
    }
    int nextHappy(int& N) {
        N++;
        while(!is(N)){
            N++;
        }
        return N;
    }
};