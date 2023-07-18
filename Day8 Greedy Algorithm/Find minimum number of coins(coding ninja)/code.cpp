#include <bits/stdc++.h> 
int findMinimumCoins(int amount){ 

    
    int coins[9] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int ans = 0;
    for(int i = 0;i < 9;i++){
        int temp = amount/coins[i]; //no of coins calculated maybe 0 also
          ans += temp;             
        amount = amount - (coins[i]*temp); //reducing the amount 
    }
    return ans;

}
