class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int i = 0, j = n-1;

        while(i<=j && s[i]=='L') i++;
        while(j>=i && s[j]=='R') j--;

        int c = 0;
        for(int k=i;k<=j;k++){
            if(s[k] != 'S') c++;
        }
        return c;
    }
};
