class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans =0;
        int n = intervals.size();
        int lastend = -1;
        sort(intervals.begin(),intervals.end(),[&](const vector<int>&a , const vector<int>& b){return a[0]<b[0];});
        lastend = intervals[0][1];
        for(int i =1;i<n;i++){
            if(intervals[i][0]<lastend){
                ans++;
                lastend = min(lastend , intervals[i][1]);
            }
            else lastend = intervals[i][1];
        }
        return ans;

    }
};