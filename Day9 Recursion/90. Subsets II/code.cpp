class Solution {
private:
void solve(vector<int>& nums,int ind,vector<int> subSet,set<vector<int>> &s){
    if(ind == nums.size()){
        sort(subSet.begin(),subSet.end());
        s.insert(subSet);
        return;
    }
    subSet.push_back(nums[ind]);
    solve(nums,ind + 1,subSet,s);
    subSet.pop_back();
    solve(nums,ind + 1,subSet,s);
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> subSet;
        solve(nums,0,subSet,s);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};
