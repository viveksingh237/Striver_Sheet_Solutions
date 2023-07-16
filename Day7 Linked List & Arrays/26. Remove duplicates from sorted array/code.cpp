class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // //****Using Jugaad :) O(nlogn)
        // if(nums.size() == 1) return 1;
        // int x = 202;
        // for(int i = 1;i < nums.size();i++){
        //     if(nums[i] == nums[i-1])
        //        nums[i - 1] += x;   //if prev is same then make it greater than 100
        // }
        // sort(nums.begin(),nums.end()); //sorted so all repeated(greater) will come at last unique will will be be in starting 
        // int cnt = 0;
        // for(int i = 0;i < nums.size();i++) // counting the unique elements
        //   if(nums[i] < 101) cnt++;

        //  return cnt;

         //****Using two pointers
         int i = 0;
         int j = 1;
         while(j < nums.size()){
           if(nums[i] != nums[j]){
            i++;
            nums[i] = nums[j];
           }
           j++;
         }
         return i + 1;
    }
};
