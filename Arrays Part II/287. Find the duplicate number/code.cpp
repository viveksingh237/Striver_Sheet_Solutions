class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //***usingh sorting O(nlogn)
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++)
        // if(nums[i] == nums[i+1])
        // return nums[i];
        // return nums[0];
         
         //****** Using cycle slow and fast pointer
         int slow = nums[0];
         int fast = nums[0];

         do{
             slow = nums[slow];
             fast = nums[nums[fast]];
         } while( slow != fast);

         fast = nums[0];
         while( slow != fast){
             slow = nums[slow];
             fast = nums[fast];
         }
         return slow;

    }
};

