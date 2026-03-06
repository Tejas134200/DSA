class Solution {
public:
    bool checkOnesSegment(string s) {
        bool a =false,b=false;
        for(char c:s){
            if(c=='1'&&!a) a=true;
            else if(c=='1'&&b) return false;
            else if(c=='0'&&a) b = true;
        }
        return true;

    }
};