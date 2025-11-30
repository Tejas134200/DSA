class Solution {
public:
    void clear(vector<int>& v){
        for(int& i:v) i=0;

    }
    int maxDistinct(string s) {
        vector<int> v(26,0);
        int maxi = -1;
        int c =0;
        int i =0;
        while(i<s.size()){
            if(v[s[i]-'a']==0){
                v[s[i]-'a']++;
                char cj =s[i];
                c++;
                while(s[i]==cj) i++;
            }else{
                char cj =s[i];
                while(s[i]==cj) i++;
            }
        }
        return c;

        
    }
};