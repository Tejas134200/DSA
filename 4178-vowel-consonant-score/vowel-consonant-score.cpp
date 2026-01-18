class Solution {
public:
    int vowelConsonantScore(string s) {
        int v =0;
        int cc =0;
        for(char c:s){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') v++;
            else if (isalpha(c))cc++;
        }
        if(cc>0) return v/cc;
        return 0;
    }
};