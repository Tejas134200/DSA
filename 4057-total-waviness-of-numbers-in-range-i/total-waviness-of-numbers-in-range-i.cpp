class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans =0;
        for(int i =num1;i<=num2;i++){
            vector<int> t;
            int ii= i;
            while(ii>0){
                t.push_back(ii%10);
                ii=ii/10;
            }
            reverse(t.begin(),t.end());
            for(int tt=1;tt<t.size()-1;tt++){
                if((t[tt]>t[tt-1]&&t[tt]>t[tt+1])||(t[tt]<t[tt-1]&&t[tt]<t[tt+1])) ans++;
            }
        }
        return ans;
    }
};