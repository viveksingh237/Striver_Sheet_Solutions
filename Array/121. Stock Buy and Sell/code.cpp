class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        
       //*** optimal O(n) using DP(somewhat)
             int profit=0;
             int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            buy = min(buy,prices[i]);
            profit =max(profit, prices[i]-buy);
        }
        return profit;



        //******** Brute force O(n2)
        //      int profit=0;
        // for(int i=0;i<prices.size();i++){
        //     for(int j=i+1;j<prices.size();j++){
        //         if(prices[j] - prices[i] >= 0)
        //         profit = max(profit,prices[j] - prices[i]);
        //     }
        // }
        // return profit;
    }
};
