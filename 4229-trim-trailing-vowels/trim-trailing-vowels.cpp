class Solution {
public:
    string trimTrailingVowels(string s) {
        int i = s.size()-1;
        while(i>=0&&(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u')) i--;
        string ans = "";
        for(int j =0;j<=i;j++) ans+=s[j];
        return ans;

    }
};