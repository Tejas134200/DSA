class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans;
        if(k==0){
            for(int i =0;i<n;i++) ans.push_back(0);
            return ans;
        }
        

        if(k>0){
            int i = 1;
            int j = k;
            int sum =0;
            for(int o = i;o<j;o++) sum+=code[o];
            
            
            for(int ii =0;ii<n;ii++){
                sum+=code[j];
                ans.push_back(sum);
                sum-=code[i];
                i = (i+1)%n;
                j = (j+1)%n;
            }
            return ans;
        }

        if(k<0){
            k = abs(k);
            int i = n-k;
            int j = n-1;
            int sum =0;
            for(int o = i;o<j;o++) sum+=code[o];
            
            
            for(int ii =0;ii<n;ii++){
                sum+=code[j];
                ans.push_back(sum);
                sum-=code[i];
                i = (i+1)%n;
                j = (j+1)%n;
            }
            return ans;
        }
        return {};
    }
};