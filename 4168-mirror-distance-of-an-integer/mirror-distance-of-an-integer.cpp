class Solution {
public:
    int rev(int n){
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int t = stoi(s);
        return t;
    }
    int mirrorDistance(int n) {
        return abs(n-rev(n));
        
    }
};