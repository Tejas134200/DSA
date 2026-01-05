class Solution {
public:
    int n;
    vector<int> pse(vector<int> a){
        stack<int> s;
        vector<int> ans;
        for(int i =0;i<a.size();i++){
            while(!s.empty()&&a[s.top()]>=a[i]) s.pop();
            if(s.empty()){
                ans.push_back(-1);
                s.push(i);
            }else{
                ans.push_back(s.top());
                s.push(i);
            }
        }
        return ans;
    }
     vector<int> nse(vector<int> a){
        stack<int> s;
        vector<int> ans;
        for(int i =n-1;i>=0;i--){
            while(!s.empty()&&a[s.top()]>=a[i]) s.pop();
            if(s.empty()){
                ans.push_back(n);
                s.push(i);
            }else{
                ans.push_back(s.top());
                s.push(i);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        n=heights.size();
        vector<int> pp = pse(heights);
        vector<int> nn = nse(heights);
        int maxi = -1;
        for(int i =0;i<n;i++){
            maxi = max(maxi,heights[i]*(nn[i]-pp[i]-1));
        }
        return maxi;
        
    }
};