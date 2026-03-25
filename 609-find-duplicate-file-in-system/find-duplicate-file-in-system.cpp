class Solution {
public:

    string trimm(string s){
        int i =0;
        while(i<s.size()&&s[i]==' '){
            i++;
        }
        string ans ="";
        for(i;i<s.size();i++){
            ans+=s[i];
        }
        return ans;
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> m;
        for(auto &st : paths){
            string dir = "";
            int i =0;
            while(st[i]!=' ') dir+=st[i++];
            i++;
            while(i<st.size()){
                string fname = "";
                while(st[i]!='(') fname+=st[i++];
                i++;
                string con = "";
                while(st[i]!=')') con+=st[i++];
                i++;
                m[con].push_back(dir+'/'+trimm(fname));
            }
        }
        vector<vector<string>> ans;
        for(auto&it:m) if(it.second.size()>1) ans.push_back(it.second);
        return ans;
    }
};