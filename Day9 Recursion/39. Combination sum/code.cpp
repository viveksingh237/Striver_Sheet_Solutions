class Solution {
private:
void solve(vector<int>& candidates,int sum,int ind,vector<int> &subSet,vector<vector<int>> &ans,int target){
    if(ind == candidates.size()){
     if(sum == target){   //desired combination
        ans.push_back(subSet);
     }
     return;
    }
    if(sum < target){
    subSet.push_back(candidates[ind]);
    solve(candidates,sum + candidates[ind],ind,subSet,ans,target); //since we can pick element more than once so we donot inc ind
    subSet.pop_back();
    }
    solve(candidates,sum,ind + 1,subSet,ans,target); //not picking the element
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subSet;
        solve(candidates, 0, 0, subSet, ans, target);
        return ans;
    }
};
