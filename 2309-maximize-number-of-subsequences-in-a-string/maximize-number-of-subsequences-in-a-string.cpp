class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        vector<long long> a;
        vector<long long> b;
        int c = 0;
        for(char ch: text){
            if(ch==pattern[0]) c++;
            a.push_back(c);
        }
        c =0;
        for(int i = text.size();i>=0;i--){
            char ch = text[i];
            if(ch==pattern[1]) c++;
            b.push_back(c);

        }
        reverse(b.begin(),b.end());

        long long maxi = 0;
        for(int i =0;i<text.size()-1;i++){
            if(text[i]==pattern[0]) maxi+=b[i+1];
        }
        maxi+=max(b[0] , a[text.size()-1]);
        return maxi;

    }
};