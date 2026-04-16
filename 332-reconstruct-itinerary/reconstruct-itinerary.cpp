class Solution {
public:
    unordered_map<string , int> out;
    stack<string> s;
    unordered_map<string  , vector<string>> adj;
    void dfs(string cur){
        while(out[cur]!=0){
            string nxt = adj[cur][--out[cur]];
            dfs(nxt);
        }
        s.push(cur);

    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto& t:tickets){
            adj[t[0]].push_back(t[1]);
        }
        for(auto &it : adj){
    sort(it.second.rbegin(), it.second.rend());
}
        int n = adj.size();

        
        for(auto it:adj){
            out[it.first] = it.second.size();
        }
        dfs("JFK");

        vector<string> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();

        }
        return ans;



    }
};

// class Solution {
// public:
//     void dbg(vector<vector<string>> &v){
//     for(auto &r : v){
//         for(auto &s : r){
//             cout << s << " ";
//         }
//         cout << "\n";
//     }
// }  
//     int c;
//     vector<vector<string>> anss;

//     void findc(string cur , vector<string> p , unordered_map<string  , vector<string>> adj ){
//         p.push_back(cur);
//         if(p.size()==c){
//             anss.push_back(p);
//             return;
//         }
//         vector<string> vv = adj[cur];
//         for(auto s:vv){
//             adj[cur].erase(remove(adj[cur].begin(),adj[cur].end() , s),adj[cur].end());
//             findc(s , p , adj);
//             adj[cur].push_back(s);
//         }
//     }

    
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         c =tickets.size();
//         c++;
//         unordered_map<string  , vector<string>> adj;

//         unordered_map<string , int > vis;
//         for(auto& t:tickets){
//             adj[t[0]].push_back(t[1]);
//         }
//         vector<string> p;
//         findc("JFK"  , p , adj);

//         sort(anss.begin(),anss.end(),[&](const vector<string>& a  , const vector<string>& b){
//             string aa= "";
//             string bb = "";
//             for(auto s:a) aa+=s;
//             for(auto s:b) bb+=s;
//             return aa<bb;
//         });
//         return anss[0];




//         return {};



        
        
        

//     }
// };