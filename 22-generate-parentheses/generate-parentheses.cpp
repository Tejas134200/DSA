class Solution {
public:
    
    void find(string s , int op , int cl,vector<string>& ans){
        if(op==0&&cl==0){
            ans.push_back(s);
            return;
        }
        if(op>0) find(s+'(',op-1,cl,ans);
        if(op<cl) find(s+')',op,cl-1,ans);
        return;

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s ="";
        find(s,n,n,ans);
        return ans;
    }
};