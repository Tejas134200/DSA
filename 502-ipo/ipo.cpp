class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        int n = capital.size();
    for(int i = 0; i < n; i++){
         v.push_back({capital[i], profits[i]});
    }

    sort(v.begin(), v.end());
        if(w<v[0].first) return w;
        priority_queue<int> pq;
        int ii = 0;
        for(auto i:v){
            if(i.first<=w){ pq.push(i.second);ii++;}
            else break;
        }
        while(k--&&!pq.empty()){
            w+=pq.top();
            pq.pop();
            while(ii<n&&v[ii].first<=w){
                pq.push(v[ii].second);
                ii++;
            }

        }
        return w;
    }
};