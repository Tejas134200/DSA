// class Solution {
// public:
//     int mod;
//     vector<vector<int>> v;
//     int nn;
//     void findc(int i,int j,int& ans){
//         if(i==nn+1){ans=(ans+1)%mod; return;}
        
//         for(int ii =0;ii<3;ii++){
//             if(v[i-1][j]!=ii&&v[i][j-1]!=ii){
//                 v[i][j]=ii;
//                 if(j<3) findc(i,j+1,ans);
//                 else findc(i+1,1,ans);
//                 v[i][j]=-1;
//             }
//         }
//         return;
//     }
//     int numOfWays(int n) {
//         mod = 1e9+7;
//         nn=n;
//         v.resize(n+1,vector<int>(4,-1));
//         int ans =0;
//         findc(1,1,ans);
//         return ans;
        
//     }
// };
class Solution {
public:
    int mod = 1e9 + 7;
    int nn;

    int numOfWays(int n) {
        nn = n;

        
        vector<vector<int>> rows;
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                for (int c = 0; c < 3; c++) {
                    if (a != b && b != c) {
                        rows.push_back({a, b, c});
                    }
                }
            }
        }

        int m = rows.size(); 

        vector<vector<int>> dp(nn + 1, vector<int>(m, 0));

        for (int k = 0; k < m; k++) {
            dp[1][k] = 1;
        }

        for (int i = 2; i <= nn; i++) {
            for (int cur = 0; cur < m; cur++) {
                for (int prev = 0; prev < m; prev++) {

                    bool ok = true;
                    for (int j = 0; j < 3; j++) {
                        if (rows[cur][j] == rows[prev][j]) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) {
                        dp[i][cur] = (dp[i][cur] + dp[i - 1][prev]) % mod;
                    }
                }
            }
        }

        int ans = 0;
        for (int k = 0; k < m; k++) {
            ans = (ans + dp[nn][k]) % mod;
        }

        return ans;
    }
};
