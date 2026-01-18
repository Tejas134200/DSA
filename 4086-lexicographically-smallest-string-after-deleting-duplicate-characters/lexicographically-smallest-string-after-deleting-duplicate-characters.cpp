class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector<int> f(26,0);
        for(char c:s) f[c-'a']++;
        stack<char> st;
        string ans="";
        for(int i=0;i<s.size();i++){
            while(!st.empty()&&st.top()>s[i]&&f[st.top()-'a']>1){
                f[st.top()-'a']--;
                st.pop();
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        int i =1;
        cout<<ans<<endl;
        string ans2 ="";
        // ans2+=ans[0];
        // while(ans[i]==ans[0]) i++;
        // while(i<ans.size()) ans2+=ans[i++];
        i=0;
        // ans=ans2;
        ans2="";
        cout<<"THIS";
        while(i<ans.size()&&f[ans[i]-'a']>1) {f[ans[i]-'a']--;i++;}
        cout<<i<<ans.size();
        while(i<ans.size()) {ans2+=ans[i];i++;}

        
        reverse(ans2.begin(),ans2.end());

        return ans2;


    }
};