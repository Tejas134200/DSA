class Solution {
public:

    pair<int,int> getdig(int i, string &formula) {
        if (i >= formula.size() || !isdigit(formula[i]))
            return {1, i};

        int no = 0;
        while (i < formula.size() && isdigit(formula[i])) {
            no = no * 10 + (formula[i] - '0');
            i++;
        }
        return {no, i};
    }

    pair<string,int> getstr(int i, string &formula) {
        string s;
        s += formula[i++];
        
        while (i < formula.size() && islower(formula[i])) {
            s += formula[i];
            i++;
        }

        return {s, i};
    }

    string countOfAtoms(string formula) {
        stack<pair<string,int>> st;
        int i = 0;
        int n = formula.size();

        while (i < n) {
            if (formula[i] == '(') {
                st.push({"(", -1});
                i++;
            }
            else if (formula[i] == ')') {
                auto [mul, ni] = getdig(i + 1, formula);
                i = ni;

                stack<pair<string,int>> temp;

                while (!st.empty() && st.top().first != "(") {
                    auto [atom, cnt] = st.top();
                    st.pop();
                    temp.push({atom, cnt * mul});
                }

                st.pop();

                while (!temp.empty()) {
                    st.push(temp.top());
                    temp.pop();
                }
            }
            else {
                auto [atom, ni] = getstr(i, formula);
                i = ni;

                auto [cnt, nj] = getdig(i, formula);
                i = nj;

                st.push({atom, cnt});
            }
        }

        map<string,int> mp;

        while (!st.empty()) {
            auto [atom, cnt] = st.top();
            st.pop();

            if (atom != "(")
                mp[atom] += cnt;
        }

        string ans;

        for (auto &[atom, cnt] : mp) {
            ans += atom;
            if (cnt > 1)
                ans += to_string(cnt);
        }

        return ans;
    }
};