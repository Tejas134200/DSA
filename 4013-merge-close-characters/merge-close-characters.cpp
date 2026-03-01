class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n = s.size();
        string ans =s;
        
        while(true){
            n = ans.size();
            bool finded = false;
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if(ans[i]==ans[j]&& j-i<=k){
                    ans.erase(j,1);
                    finded= true;
                    break;
                }
            }
            if(finded) break;
        }
            if(!finded) break;
        }
        return ans;
    }
};