class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //1.naive approach is to rur two loops and check for enery pair

        ///2.*********Using Binary search for (target -each element)******
        //can only be applied by saving element along with index
        //else we will loose indices
        
        //3 Using hasing or Map
         unordered_map<int, int> mp;
         for(int i = 0;i < nums.size();i++){
             int tempTarget = target - nums[i];

             if(mp.find(tempTarget) != mp.end()){
                 return {i, mp[tempTarget]};
             }
             mp[nums[i]] = i;
         }

        //4. Using two pointer 
        //sort(nums.begin(),nums.end()); 
        //Can only be applied if we have to return pair of elements
        // int i = 0,j = nums.size()-1;
        
        // while(i < j){
        //     int sum = nums[i] + nums[j];

        //     if(sum == target)
        //      return {i, j};

        //     else if(sum < target) i++;

        //     else if(sum > target) j--;
        // }

        // return {i,j};
        return {-1,-1};
    }
};
