class Solution {
public:
    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id,
        int level
    ) {
        int n = friends.size();
        queue<int> q;
        vector<int> vis(n, 0);

        q.push(id);
        vis[id] = 1;

        int curr = 0;

        // BFS till required level
        while (!q.empty() && curr < level) {
            int sz = q.size();
            while (sz--) {
                int node = q.front(); 
                q.pop();
                for (int f : friends[node]) {
                    if (!vis[f]) {
                        vis[f] = 1;
                        q.push(f);
                    }
                }
            }
            curr++;
        }

        // Count frequencies
        unordered_map<string, int> freq;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto &v : watchedVideos[node]) {
                freq[v]++;
            }
        }

        // Convert to vector and sort
        vector<pair<string, int>> temp;
        for (auto &p : freq) temp.push_back(p);

        sort(temp.begin(), temp.end(), [](auto &a, auto &b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });

        // Build answer
        vector<string> ans;
        for (auto &p : temp) ans.push_back(p.first);

        return ans;
    }
};
