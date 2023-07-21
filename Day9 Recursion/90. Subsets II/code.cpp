class Solution {
    //optimal usng recursion
private:
void solve(vector<int>& nums,int ind,vector<int> subSet,vector<vector<int>> &ans){
    ans.push_back(subSet);
    for(int i = ind;i < nums.size();i++){
        if(i != ind and nums[i] == nums[i - 1]) continue;
        subSet.push_back(nums[i]);
        solve(nums,i + 1,subSet,ans);
        subSet.pop_back();
    }
}
// //Brute force
// private:
// void solve(vector<int>& nums,int ind,vector<int> subSet,set<vector<int>> &s){
//     if(ind == nums.size()){
//         sort(subSet.begin(),subSet.end());
//         s.insert(subSet);
//         return;
//     }
//     subSet.push_back(nums[ind]);
//     solve(nums,ind + 1,subSet,s);
//     subSet.pop_back();
//     solve(nums,ind + 1,subSet,s);
// }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subSet;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(nums,0,subSet,ans);
        return ans;
    }
};
