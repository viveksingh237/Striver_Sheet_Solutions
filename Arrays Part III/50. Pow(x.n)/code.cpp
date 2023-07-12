class Solution {
public:
    double myPow(double x, int n) {
      ///using binary exponentiation
        double ans = 1.00;
        if(n < 0)
        x = 1/x;   // in case power is negative
        n = abs(n);

            while(n){
             if(n & 1)
                ans *= x ;
                
                x *= x;
                n = n/2;
            }

            return ans;
        }
};
