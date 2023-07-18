class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // ///Using three loops O(n3)*log(m), O(n) space
        // set<vector<int>> ans;
        // for(int i = 0;i < nums.size();i++){
        //     for(int j = i + 1;j < nums.size();j++){
        //         set<long long> hash;
        //         for(int k = j + 1;k < nums.size();k++){
        //             long long fourth;
        //             long long sum = nums[i] + nums[j];
        //             sum += nums[k];
        //             fourth = (long long)target - sum;
        //             if(hash.find(fourth) != hash.end()){
        //                 vector<int> quad = {nums[i], nums[j], nums[k],(int)fourth};
        //                 sort(quad.begin(),quad.end());
        //                 ans.insert(quad);
        //             }
        //             hash.insert(nums[k]);
        //         }
        //     }
        // }
        // vector<vector<int>> res(ans.begin(),ans.end());
        // return res;

        //Optimized approach O(n3) and O(1) space
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++){
            if(i > 0 and nums[i] == nums[i -1]) continue;
            for(int j = i + 1;j < n;j++){
                if(j != i + 1 and nums[j] == nums[j - 1]) continue;
            
            int k = j + 1;
            int l = n - 1;
            while(k < l){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){     
                  vector<int> v = {nums[i], nums[j], nums[k], nums[l]};
                  ans.push_back(v);
                  k++;
                  l--;
                  while(k < l and nums[k] == nums[k - 1]) k++;
                  while(k < l and nums[l] == nums[l + 1]) l--;
                }
                else if(sum > target) l--;
                else  k++;
            }
            }
        }
        return ans;
    }
};
