class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       // next_permutation(nums.begin(),nums.end());
    
    //******code for Built in function next_permutation;

        int n=nums.size(),ind=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
            ind = i;            //finding the break point (smaller than next)
            break;
            }
        }
        if(ind == -1){ // if last permutation
        reverse(nums.begin(),nums.end()); // next permutatuon will be very  
         return;                                  //first one
        }
        for(int i=n-1;i>ind;i--){   
        if(nums[ind] < nums[i]){        //finding the smaller element just 
        swap(nums[ind],nums[i]);       //after common prefix and swapping
        break;                  
        }     
        }
        // now adding remaining elements in increasing order

        reverse(nums.begin()+ind+1,nums.end());
        //for we can use this also or built in
        // for(int i=ind+1,j=n-1; i<=j;i++,j--){
        //     swap(nums[i], nums[j]);
        // } 
 

    }
};
