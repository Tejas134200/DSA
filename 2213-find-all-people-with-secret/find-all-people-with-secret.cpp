class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int n) {
        if (n == parent[n])
            return n;
        return parent[n] = findParent(parent[n]);
    }

    void unite(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);

        if (parU == parV)
            return;

        if (size[parU] < size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
        } else {
            parent[parV] = parU;                     
            size[parU] += size[parV];
        }
    }
};

struct Comparator {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }
};

class Solution {
private:
    void solve(int l, int r, DSU* dsu, vector<vector<int>>& meetings) {
        for (int i = l; i <= r; i++) {
            dsu->unite(meetings[i][0], meetings[i][1]);
        }
    }

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {

        DSU* dsu = new DSU(n);
        sort(meetings.begin(), meetings.end(), Comparator());

        dsu->unite(0, firstPerson);

        int totalMeets = meetings.size();
        int l = 0;

        while (l < totalMeets) {

            int r = l;
            while (r + 1 < totalMeets &&
                   meetings[r + 1][2] == meetings[l][2]) {
                r++;
            }

            solve(l, r, dsu, meetings);

            int src = dsu->findParent(0);
            for (int i = l; i <= r; i++) {
                int u = meetings[i][0];
                int v = meetings[i][1];

                if (dsu->findParent(u) != src) {
                    dsu->parent[u] = u;
                    dsu->size[u] = 1;
                }
                if (dsu->findParent(v) != src) {
                    dsu->parent[v] = v;
                    dsu->size[v] = 1;
                }
            }

            l = r + 1;
        }

        vector<int> ans;
        int src = dsu->findParent(0);
        for (int i = 0; i < n; i++) {
            if (dsu->findParent(i) == src)
                ans.push_back(i);
        }

        return ans;
    }
};