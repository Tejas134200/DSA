class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int maxw =0;
        long long ans =0;
        int maxh = 0;
        int n = bottomLeft.size();
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                maxw = min(topRight[i][0],topRight[j][0])-max(bottomLeft[i][0],bottomLeft[j][0]);
                maxh = min(topRight[i][1],topRight[j][1])-max(bottomLeft[i][1],bottomLeft[j][1]);
                if(maxw>0&&maxh>0){
                    ans = max(ans , (long long)min(maxh,maxw));
                }
            }
        }
        return ans*ans;
    }
};