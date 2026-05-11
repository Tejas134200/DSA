class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.size()-1;

        while(true){
            cout<<1;
            if(i>=j||s[i]!=s[j]) break;
            cout<<2;
            char c = s[i];
            while(i<s.size()&&s[i]==c) i++;
            while(j>=0&&s[j]==c) j--;

        }
        return j-i<0?0:j-i+1;
    }
};