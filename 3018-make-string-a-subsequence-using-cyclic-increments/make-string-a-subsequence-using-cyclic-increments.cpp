class Solution {
public:
    bool match(int i , int j  ,string& s,string& t){
       if(s[i]==t[j]||s[i]+1==t[j]) return true;
       if(s[i]=='z'&&t[j]=='a') return true;
        return false;
    }


    bool canMakeSubsequence(string str1, string str2) {
        int i , j;
        for(i=0,j=0;i<str1.size()&&j<str2.size();){
            if(match(i , j , str1 , str2 )){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j==str2.size();

    }
};