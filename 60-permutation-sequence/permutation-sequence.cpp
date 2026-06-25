class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        k--;
        for(int i=1;i<=n;i++) v.push_back(i);
        while(k--){
            next_permutation(v.begin(),v.end());
        }
        string s="";
        for(int i:v) s+=to_string(i);
        return s;
    }
};