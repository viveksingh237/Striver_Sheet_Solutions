class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //1.Brute force run two loops count for every elements
        //2. Using hashing or map

        //Optmal in linear time 
        //Extended boyer's moore's voting algo
        int ele1,ele2;
        int cnt1 = 0,cnt2 = 0;
        for(int i = 0;i < nums.size();i++){
            if(cnt1 == 0 and nums[i] != ele2){
                cnt1++;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 and nums[i] != ele1){
                cnt2++;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i])
            cnt1++;
            else if(ele2 == nums[i])
            cnt2++;
            else 
            cnt1--,cnt2--;
        }

      vector<int> ans;  //counting the occurence of elements
      int c1 = 0,c2 = 0;
      for(int i = 0;i < nums.size();i++)
      if(ele1 == nums[i])  c1++;
      for(int i = 0;i < nums.size();i++)
      if(ele2 == nums[i])  c2++;

      if(c1 > ceil(nums.size()/3))  
      ans.push_back(ele1);
      if(c2 > ceil(nums.size()/3) )
      ans.push_back(ele2);
    return ans;
    }
};
