class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         //********* Using extra space
        //  vector<int> v;
        //  int i,j;
        //  for(i=0,j=0;i<m and j<n;){
        //      if(nums1[i] <= nums2[j])
        //      v.push_back(nums1[i]);
        //      else
        //      v.push_back(nums2[j]);
        //  }
        //  while(i<m) v.push_back(nums1[i]);
        //  while(j<n) v.push_back(nums2[j]);
        //  nums1 = v;

        //****** without using extra space
        int i=m-1,j=n-1;
        while(i>=0 and j>=0){
            if(nums1[i] >= nums2[j]){
            swap(nums1[i],nums1[i+j+1]);
            i--;
        }
        else{
            swap(nums2[j],nums1[i+j+1]);
            j--;
        }
      }
       while(j >= 0) nums1[i+j+2] = nums2[j--];

       //******* Using sorting
    //    int i=m-1,j=0;
    //    while(nums1[i] >= nums2[j]){
    //        swap(nums1[i],nums2[j]);
    //        i--;
    //        j++;
    //    }
    //    sort(nums2.begin(),nums2.end());
    //    sort(nums1.begin(),nums1.begin()+m);
    //    for(int k=m,l=0;l<n and k< m+n-1;k++,l++) nums1[k] = nums2[l];
    }
};
