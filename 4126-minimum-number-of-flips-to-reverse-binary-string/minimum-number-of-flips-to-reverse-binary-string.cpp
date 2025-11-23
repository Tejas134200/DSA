class Solution {
public:
    int minimumFlips(int n) {
        vector<int> b;
        while(n>0){
            b.push_back(n%2);
            n = n/2;
        }
        int ans =0;
        int nu = b.size();
        for(int i =0;i<nu;i++){
            if(b[i]!=b[nu-1-i]) ans++;
        }
        return ans;
    }
};