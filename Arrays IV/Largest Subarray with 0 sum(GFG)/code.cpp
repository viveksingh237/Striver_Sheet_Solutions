class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //naive approach sort and then count

        //better approach in O(n)
        int maxi =  0,cnt = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 1){
              cnt++;
              maxi = max(cnt, maxi);
            }
        
            else
             cnt = 0;
        }
            
        return maxi;
    }
};
