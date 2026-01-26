class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        int mind = INT_MAX;
        sort(arr.begin() , arr.end());
        for(int i = 1;i<n;i++){
            mind = std::min(mind , arr[i]-arr[i-1]);
        }
        for(int i = 1;i<n;i++){
            
                if(abs(arr[i]-arr[i-1])==mind) {
                    vector<int> ans1;
                    ans1.push_back(arr[i-1]);
                    ans1.push_back(arr[i]);
                    ans.push_back(ans1);
                }
            
        }
        return ans;

    }
};