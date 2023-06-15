    void sortColors(vector<int>& nums) {
        //declearing three pointers
        int i=0,j=nums.size()-1,k=0;
        while(k<=j){
            if(nums[k] == 0){
                //whenever 0 is found 
                //swapped with the leftmost non-zero
                swap(nums[i],nums[k]);
                i++;
                k++;
            }
            else if(nums[k] == 2){
                // whenever 2 is found
                //swapped with the rightmost non-two
                swap(nums[k],nums[j]);
                j--;
            }
            else
            //if 1 is found 
            //simply pointer is incremented
            k++;
        }
    }
