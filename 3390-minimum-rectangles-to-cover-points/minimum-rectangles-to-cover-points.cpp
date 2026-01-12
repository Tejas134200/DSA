class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end(),[&](const auto& a,const auto& b){return a[0]<b[0];});
        vector<int> x;
        int px =-1;
        for(auto p:points){
            if(p[0]!=px){
                x.push_back(p[0]);
                px = p[0];
            }
        }
        int cur ;
        if(w==0) return x.size();
        int ans =0;
        int i =0;
        while(i<x.size()){
            cur=x[i];
            ans++;
            int f = cur+w;
            while(i<x.size()&&x[i]<=f) i++;

        }
        return ans;
    }
};