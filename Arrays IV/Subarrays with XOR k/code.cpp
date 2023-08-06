#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    ///Optimal>>>>>>>
    unordered_map<int,int> mp;
    int xr = 0;
    int cnt = 0;
    mp[xr]++;
    for(auto& x : a){
      xr ^= x;
      mp[xr]++;
      cnt += mp[xr ^ b];
    }
    return cnt;
    
    // Brute force>>>>>>>>>>>>
    // int cnt = 0;
    // for(int i = 0;i < a.size();i++){
    //   int xr = 0;
    //   for (int j = i; j < a.size(); j++) {
    //        xr ^= a[j];
    //     if (xr == b)
    //       cnt++;
    //   }

    // }
    // return cnt;
}
