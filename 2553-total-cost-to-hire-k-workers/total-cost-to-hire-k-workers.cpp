class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        int n = costs.size();

        int i = candidates;
        int j = n - candidates;

        int ip = 0;
        int jp = n - 1;

        while (k--) {

            while (ip < i && ip <= jp) {
                pq.push({costs[ip], ip});
                ip++;
            }

            while (jp >= j && jp >= ip) {
                pq.push({costs[jp], jp});
                jp--;
            }

            auto [num, idx] = pq.top();
            pq.pop();

            sum += num;

            if (idx < i)
                i++;
            else
                j--;
        }

        return sum;
    }
};