class Solution {
public:
    long long key(int u, int v) {
        if (u > v) swap(u, v);
        return (long long)u * 50001 + v;
    }

    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        unordered_set<long long> st;
        st.reserve(edges.size() * 2);
        st.max_load_factor(0.7);

        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            deg[u]++;
            deg[v]++;
            st.insert(key(u, v));
        }

        vector<int> odd;
        for (int i = 0; i < n; i++) {
            if (deg[i] & 1) odd.push_back(i);
        }

        int oc = odd.size();
        if (oc == 0) return true;
        if (oc == 1 || oc == 3 || oc > 4) return false;

        // Case: exactly 2 odd nodes
        if (oc == 2) {
            int a = odd[0], b = odd[1];

            // If we can directly connect them
            if (!st.count(key(a, b))) return true;

            // Try a third node
            for (int i = 0; i < n; i++) {
                if (i == a || i == b) continue;
                if (!st.count(key(a, i)) && !st.count(key(b, i)))
                    return true;
            }
            return false;
        }

        // Case: exactly 4 odd nodes
        int a = odd[0], b = odd[1], c = odd[2], d = odd[3];

        if (!st.count(key(a, b)) && !st.count(key(c, d))) return true;
        if (!st.count(key(a, c)) && !st.count(key(b, d))) return true;
        if (!st.count(key(a, d)) && !st.count(key(b, c))) return true;

        return false;
    }
};
