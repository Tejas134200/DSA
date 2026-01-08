class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> pre;
        int maxi = values[0];
        pre.push_back(maxi);
        for(int i =1;i<n;i++){
            pre.push_back(maxi);
            maxi = max(maxi , values[i]+i);
        }

        maxi = 0;
        for(int i =1;i<n;i++){
            maxi = max(maxi , values[i]-i+pre[i]);
        }
        return maxi;
        
    }
};