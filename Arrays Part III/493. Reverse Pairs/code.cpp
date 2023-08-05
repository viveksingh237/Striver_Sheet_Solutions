class Solution {
private:
void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid and right <= high){
        if(arr[left] <= arr[right]){
        temp.push_back(arr[left]);
        left++;
        }
    else{
        temp.push_back(arr[right]);
        right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int k = low;k <= high;k++) arr[k] = temp[k - low];
}
int countPairs(vector<int> &arr,int low,int mid,int high){
    int right = mid + 1;
    int cnt = 0;
    for(int  i = low ;i <= mid;i++){
        while(right <= high and arr[i] > (long long)2*arr[right])
        right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int> &arr,int low,int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = low + (high - low)/2;
    cnt += mergeSort(arr,low,mid);
    cnt += mergeSort(arr,mid + 1,high);
    cnt += countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};

// class Solution {
// public:
// void merge(vector<int>&arr,int low,int mid,int high,int &cnt){
//     int i=low,j=mid+1;
//     int r=j;
//     int c=0;
//     vector<int>v;
//      while(i<=mid){
//         while(r<=high and arr[i]>(long long)2*arr[r]){
//             c++;
//             r++;
//         }
//         cnt+=c;
        
//     while(j<=high and arr[j]<=arr[i])v.push_back(arr[j++]);
//           v.push_back(arr[i++]);
//      }
//      while(j<=high)v.push_back(arr[j++]);
     
//      for(int i=low;i<=high;i++)arr[i]=v[i-low];
// }

//    void mergesort(vector<int>&arr,int low,int high,int &cnt){
//        if(low<high){
//       int mid=low+(high-low)/2;
//       mergesort(arr,low,mid,cnt);
//       mergesort(arr,mid+1,high,cnt);
//       merge(arr,low,mid,high,cnt);
//        }
//    }
//     int reversePairs(vector<int>& arr) {
//     int cnt=0;
//     int n=arr.size();
//     mergesort(arr,0,n-1,cnt);
//     if(n<=1 or cnt==0)return 0;
//     return cnt;
        
//     }
// };
