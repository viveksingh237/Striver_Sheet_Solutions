class Solution {
void solve(int ind,vector<int>& nums,int target,vector<int> &subSet,vector<vector<int>> &ans){
     if(target == 0){
        ans.push_back(subSet);
     return;
    }
   for(int  i = ind;i < nums.size();i++){
       if(i > ind and nums[i] == nums[i - 1]) continue;//skip similar elelments
       if(nums[i] > target) break;
       subSet.push_back(nums[i]);
       solve(i + 1,nums,target - nums[i],subSet,ans);
       subSet.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> subSet;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        solve(0,nums, target, subSet, ans);
        return ans;
    }
};
