class Solution {
public:
    #define ll long long
    long long maximumValueSum(vector<vector<int>>& board) {
        long long maxi =0;
        int m = board.size();
        int n = board[0].size();
        vector<vector<pair<ll,int>>> t3(m,vector<pair<ll,int>>());
        vector<pair<ll,pair<int,int>>> all;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                t3[i].push_back({board[i][j],j});
                all.push_back({board[i][j],{i,j}});
            }
            sort(t3[i].rbegin(),t3[i].rend());

        }
        sort(all.rbegin(),all.rend());
        ll ans = -1e10;
        for(int i =0;i<m-2;i++){
            for(int j =i+1;j<m-1;j++){
                for(int a=0;a<3;a++){
                    for(int b =0;b<3;b++){
                        if(t3[i][a].second==t3[j][b].second) continue;
                        for(int k=0;k<all.size();k++){
                            pair<int,int> temp = all[k].second;
                            if(temp.first!=i && temp.first!=j){
                                if(temp.second!=t3[i][a].second && temp.second!=t3[j][b].second){
                                    ans = max(ans,t3[i][a].first+t3[j][b].first+all[k].first);break;
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};