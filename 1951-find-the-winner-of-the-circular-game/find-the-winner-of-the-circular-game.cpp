class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        int kk = k;
        for(int i =0;i<n;i++) q.push(i+1);
        while(q.size()>1){
            while(k!=1){
                int kii = q.front();
                q.pop();
                q.push(kii);
                k--;
            }
            q.pop();
            k=kk;

        }
        return q.front();
    }
};