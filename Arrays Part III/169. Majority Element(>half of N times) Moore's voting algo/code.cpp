class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //1.naive approach or Brute force O(nlogn)
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()/2];

        //2.it can be also done in linear timme with hashing 

        //3.linear time with O(1) space without hashing
        //******Moore's voting algorithm

        int cnt = 0;
        int element;
        for(int i = 0;i < nums.size();i++){
            if(cnt == 0){
            element = nums[i];    //store the current element
            cnt++;                  //so cnt inc by 1
            } 
            else if(nums[i] == element) 
            cnt++;              // cnt is incremented
            else 
            cnt--;              //if not same element cnt is decreased
        }
        return element;
    }
};
