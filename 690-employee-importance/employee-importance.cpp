/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,int> mp;
        unordered_map<int,vector<int>> adj;
        for(auto &it:employees){
            mp[it->id]=it->importance;
            for(int i:it->subordinates){
                adj[it->id].push_back(i);
            }
        }

        queue<int> q;
        q.push(id);
        unordered_map<int,int> vis;
        vis[id]=1;
        int ans =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans+=mp[node];

            for(auto it:adj[node]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);

                }
            }
        }
        return ans;
    }
};