class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string ans = s;
        for(int i =0;i<n;i++){
            string k =s;
            reverse(k.begin(),k.begin()+i);
            if(k<ans) ans=k;
            k= s;
            reverse(k.begin()+i,k.end());
            if(k<ans) ans=k;

            

        }
        return ans;
    }
};