class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // //Optimized solution using set O(2n)
        // unordered_set<int> hash;
        // int l = 0,r = 0;
        // int maxi = 0;
        // while(r < s.size()){
        //     if(hash.find(s[r]) != hash.end()){
        //         while(l < r and hash.find(s[r]) != hash.end()){
        //         hash.erase(s[l]);
        //         l++;
        //     }
        //     }
        //     maxi = max(maxi, r - l + 1);
        //     hash.insert(s[r]);
        //         r++;
        // }
        // return maxi;


        ///** Optimized solution  O(n)
        vector<int> hash(256, -1);
        int l = 0,r = 0;
        int maxi = 0;
        while(r < s.size()){
            if(hash[s[r]] != -1) //if in hash already chech the range
              l = max(hash[s[r]] + 1, l);//if not in range no problem
            hash[s[r]] = r; //store next cha in hash

            maxi = max(maxi, r - l + 1);
            r++;  
        }
        return maxi;
    }
};
