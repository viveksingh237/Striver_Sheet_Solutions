class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //**** brute force O(n3) TLE
        // int maxi=INT_MIN,n=nums.size();
        // for(int i=-0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int sum=0;
        //         for(int k=i;k<=j;k++)
        //         sum += nums[k];

        //         maxi = max(sum,maxi);
        //     }
        // }
        // return maxi;
         

        // ***** O(n2) TLE
        //  int maxi=INT_MIN,n=nums.size();
        // for(int i=-0;i<n;i++){
        //      int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum += nums[j];
        //     maxi = max(sum,maxi);
        //     }
        // }
        // return maxi;


        //*** kadane's algo
        int start,end;
        long long int maxi=INT_MIN,sum=0,n=nums.size();
        int temp;
        for(int i=0;i<n;i++){
            if(sum == 0) temp=i;
            sum +=nums[i];
            if(sum > maxi){
                 maxi = sum;
                 start=temp, end=i;
            }
            else if(sum < 0) sum=0;
        }
        // when every subarray sum <= 0
        if(maxi == INT_MIN){
            for(int i=0;i<n;i++)
            if(nums[i] >maxi) maxi = nums[i];
        }
        cout<< start<<" "<<end;
        return maxi;
    }
};
