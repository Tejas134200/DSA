class Solution {
public:
    bool rec(int i , int j , string s , bool used){
        if(i>=j) return true;
        if(s[i]==s[j]){
            return rec(i+1 ,j-1 ,s , used);
        }else{
            if(used) return false;
            return rec(i+1 , j , s , !used)||rec(i  , j-1,s , !used);
        }
    }
    bool checkp(int i , int j , string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return checkp(i+1 , j ,s)||checkp(i,j-1 , s);
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};