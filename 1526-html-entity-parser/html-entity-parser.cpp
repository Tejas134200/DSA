class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> entities = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };

        string result;
        int i = 0, n = text.size();

        while (i < n) {
            bool found = false;

            // Entity length ranges from 4 to 7
            for (int len = 7; len >= 4; len--) {
                if (i + len <= n) {
                    string sub = text.substr(i, len);
                    if (entities.count(sub)) {
                        result += entities[sub];
                        i += len;
                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                result += text[i++];
            }
        }

        return result;
    }
};