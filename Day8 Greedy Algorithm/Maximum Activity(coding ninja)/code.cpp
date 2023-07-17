#include<vector>
#include<algorithm>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> v;
    for(int i = 0;i < start.size();i++)
        v.push_back({finish[i],start[i]});//pushing finish time first ton sort acoording to it
    
    sort(v.begin(),v.end());     //sorting

    int cnt = 1;
    int finishtime = v[0].first;
    for(int i = 1;i < v.size();i++){
           if(v[i].second >= finishtime){ //start of cur >= finish of prev
               cnt++;                      //it can be counted
               finishtime = v[i].first;
           }
    }
    return cnt;
}
