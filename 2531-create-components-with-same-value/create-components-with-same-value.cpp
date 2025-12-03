class Solution {
public:
    set<int> sums;
    vector<vector<int>> adj;
    vector<int> nums;
    int total;

     int dfs(int cur, int par) {
        int sum = nums[cur];
        for (int next : adj[cur]) {
            if (next != par)
                sum += dfs(next, cur);
        }
        if (total % sum == 0) 
            sums.insert(sum);
        return sum;
    }

    int dfsSum(int cur , int par  ,int& comp , int tar ){
        int sum =0;
        for(auto& it:adj[cur]){
            if(it!=par){
                sum+=dfsSum(it,cur,comp,tar);
            }
        }
        sum += nums[cur];
        if(sum==tar){
            comp++;
            return 0;
        }
        return sum;
    }

    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums = nums;
        total =0;
        for(int i:nums) total+=i;
        int n = nums.size();
        adj.assign(n, {});

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // dfs(0,-1);

        

        int best = 0;
        for (int target =1;target<=total;target++) {
            if(total%target==0){
            int comp = 0;
            dfsSum(0, -1, comp, target);
            if (comp == total / target)
                best = max(best, comp);
            }
            
            
        }

        return best - 1;




        
    }
};