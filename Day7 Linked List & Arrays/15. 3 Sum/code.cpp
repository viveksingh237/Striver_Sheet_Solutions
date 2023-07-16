class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // //********Brute force** O(n3)*O(3log3)
        // vector<vector<int>> ans;
        // set<vector<int>> s;
        // for(int i = 0;i < nums.size();i++)
        //     for(int j = i + 1;j < nums.size();j++)
        //         for(int k = j + 1;k < nums.size();k++)
        //             if(nums[i] + nums[j] + nums[k] == 0){
        //                 vector<int> v = {nums[i], nums[j], nums[k]};
        //                 sort(v.begin(),v.end());
        //             s.insert(v);
        //             }

        //  for(auto it = s.begin();it != s.end();it++){
        //     ans.push_back(*it);
        // }     
        // return ans;


        // //***Better approach O(n2)*O(logm)
        // set<vector<int>> s;
        // for(int i = 0;i < nums.size();i++){
        //     set<int> hash;
        //     for(int j = i + 1;j < nums.size();j++){
        //         int third = -(nums[i] + nums[j]); 
        //             if(hash.find(third) != hash.end()){
        //                 vector<int> v = {nums[i], nums[j], third};
        //                 sort(v.begin(),v.end());
        //                 s.insert(v);
        //             }
        //         hash.insert(nums[j]);    
        //    }
        // }     
        // vector<vector<int>> ans(s.begin(),s.end()); //copy directly
        // //for(auto& x : s) ans.push_back(x);
        // return ans;

        ///******Optimized approach
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i = 0;i < nums.size();i++){
           if(i > 0 and nums[i] == nums[i - 1]) continue;
           int j = i + 1;
           int k = nums.size() - 1;

           while(j < k){
               int sum = nums[i] + nums[j] +nums[k];
               if(sum < 0)
                j++;
               
               else if(sum > 0)
                k--; 
               
               else{
                ans.push_back({nums[i], nums[j], nums[k]});  
                j++;
                k--;
                while(j < k and nums[j] == nums[j - 1]) j++;//when cur and next are similar
                while(j < k and nums[k] == nums[k + 1]) k--;
               }   
           }
        }     
        return ans;
    }
};
