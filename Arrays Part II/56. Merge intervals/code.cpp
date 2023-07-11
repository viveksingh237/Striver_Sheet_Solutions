class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //****** O(nlogn) approach
        if(intervals.size() == 1) return intervals; //corner case
        sort(intervals.begin(),intervals.end()); // sorting
        vector<vector<int>> ans;
        // first interval is pushed in ans
        ans.push_back(intervals[0]); 
        int n = intervals.size();
        for(int i = 1;i < n;i++){
            if(ans.back()[1] >= intervals[i][0]) // if intervals overlap

            // pushing the max element of prev and cur interval
            ans.back()[1] = max(intervals[i][1],ans.back()[1]);
            
            // if no overlapping directly push th interval
            else
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};
