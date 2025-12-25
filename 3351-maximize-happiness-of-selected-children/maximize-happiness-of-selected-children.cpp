class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long sum =happiness[0];
        int dec=1;

        
        k--;
        for(int i=1;i<=k;i++){
            sum+=max(0,happiness[i]-dec);
            dec++;
        }
       return sum;


    }
};