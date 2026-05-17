class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n , 0);
        vis[start]=1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int no = q.front();
            q.pop();

            if(arr[no]==0) return true;
            if(no-arr[no]>=0&&!vis[no-arr[no]]){
                vis[no-arr[no]]=1;
                q.push(no-arr[no]);
            }
            if(no+arr[no]<n&&!vis[no+arr[no]]){
                vis[no+arr[no]]=1;
                q.push(no+arr[no]);
            }

        }
        return false;
    }
};