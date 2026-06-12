class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string ans = "";
        for(char c:s){
            if(c=='(') {
                st.push(c);
                ans+=c;
            }else if(c==')'){
                if(!st.empty()){
                    st.pop();
                    ans+=c;
                }
            }else ans+=c;
        }

        reverse(ans.begin(),ans.end());
        s=ans;
        ans="";
        stack<char> st2;
        for(char c:s){
            if(c==')') {
                st2.push(c);
                ans+=c;
            }else if(c=='('){
                if(!st2.empty()){
                    st2.pop();
                    ans+=c;
                }
            }else ans+=c;
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};