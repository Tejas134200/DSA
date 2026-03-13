class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pair<long long,pair<int,int>>,
        vector<pair<long long,pair<int,int>>>,
        greater<pair<long long,pair<int,int>>>> pq;

        int n = workerTimes.size();
        vector<long long> ans(n,0);

        for(int i=0;i<n;i++){
            pq.push({workerTimes[i],{1,i}});
        }

        while(mountainHeight--){
            long long top = pq.top().first;
            int iter = pq.top().second.first;
            int ind = pq.top().second.second;
            pq.pop();

            ans[ind] = top;  // worker finishes this block at time = top
            iter++;

            pq.push({ans[ind] + 1LL*iter*workerTimes[ind], {iter,ind}});
        }

        long long maxi = 0;
        for(long long x:ans) maxi=max(maxi,x);

        return maxi;
    }
};