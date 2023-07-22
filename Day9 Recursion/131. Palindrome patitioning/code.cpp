class Solution {
private:
bool isPalindrome(string s,int i,int j){
    while(i <= j)
    if(s[i++] != s[j--]) return false;
    return true;
}
void solve(int ind,string s,vector<vector<string>> &ans,vector<string> &subSet){
  if(ind == s.size()){
      ans.push_back(subSet);
      return;
  }
  for(int i = ind;i < s.size();i++){
      if(isPalindrome(s,ind,i)){
       subSet.push_back(s.substr(ind,i - ind + 1));
       solve(i + 1,s,ans,subSet);
       subSet.pop_back();
  }
  }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subSet;
        solve(0,s,ans,subSet);
        return ans;
    }
};
