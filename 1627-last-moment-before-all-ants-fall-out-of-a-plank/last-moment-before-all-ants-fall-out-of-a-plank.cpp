class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi = 0;
        for(int i:left) maxi = max(maxi , i);
        for(int j:right) maxi = max(maxi ,n-j);
        return maxi;
    }
};