class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(),0);
        for(int i =0;i<words.size();i++){
            for(char c:words[i]) mask[i]|=1<<(c-'a');
        }
        int maxi =0;
        for(int i =0;i<words.size();i++){
            for(int j =i+1;j<words.size();j++){
                if((mask[i]&mask[j])==0) maxi=max(maxi , (int)words[i].size()*(int)words[j].size());
            }
        }
        return maxi;
    }
};