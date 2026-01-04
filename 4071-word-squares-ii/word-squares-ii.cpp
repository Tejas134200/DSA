class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>>ans;
        for(int i=0; i<n; i++) {
            string top = words[i];
            for(int j=0; j<n; j++) {
                string left = words[j];
                if(i != j && top[0] == left[0]) {
                    for(int k=0; k<n; k++) {
                        string right = words[k];
                        if(i != k && j != k && top[3] == right[0]) {
                            for(int l=0; l<n; l++) {
                                string bottom = words[l];
                                if(i!=l && j != l && k != l && left[3] == bottom[0] && right[3] == bottom[3]) {
                                    ans.push_back({top,left,right,bottom});
                                }
                            }
                        }
                    }
                }
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};