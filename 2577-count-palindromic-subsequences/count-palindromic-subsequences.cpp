class Solution {
public:
    // int rev(int n){
    //     int ans = 0;
    //     while (n > 0) {
    //         ans = ans * 10 + n % 10;
    //         n /= 10;
    //     }
    //     return ans;
    // }
int rev(int n) {
    int a = n / 10;   // tens (first digit)
    int b = n % 10;   // ones (second digit)
    return b * 10 + a;
}
    int countPalindromes(string s) {
        const int mod = 1'000'000'007;
        int n = s.size();
        if (n < 5) return 0;

        vector<long long> dp(100,0);    
        vector<long long> dprev(100,0);   
        vector<int> freq(10,0);         
        vector<int> freqfront(10,0);     
        for (int i = n - 1; i >= 3; i--) {
            for (int j = 0; j <= 9; j++) {
                if (freq[j] > 0) {
              
                    int a = (s[i] - '0') * 10 + j;
                    dprev[a] = (dprev[a] + freq[j]) % mod;
                }
            }
            freq[s[i] - '0']++;
        }

        freqfront[s[0]-'0']++;
        freqfront[s[1]-'0']++;

        int a0 = 10 * (s[0]-'0') + (s[1]-'0');
        dp[a0]++;

        long long ans = 0;

        for (int i = 2; i < n - 2; i++) {

            for (int j = 0; j < 100; j++) {
                if (dp[j] > 0) {
                    int r = rev(j);
                    if (dprev[r] > 0) {
                        ans = (ans + (dp[j] * dprev[r]) % mod) % mod;
                    }
                }
            }

            for (int d = 0; d <= 9; d++) {
                if (freqfront[d] > 0) {
                    int a = d * 10 + (s[i] - '0');
                    dp[a] = (dp[a] + freqfront[d]) % mod;
                }
            }

            freqfront[s[i] - '0']++;

            int rem = s[i+1] - '0';
            freq[rem]--;
            for (int j = 0; j <= 9; j++) {
                if (freq[j] > 0) {
                    int a = rem * 10 + j;
                    dprev[a] = (dprev[a] - freq[j]) % mod;
                    if (dprev[a] < 0) dprev[a] += mod;
                }
            }
        }
        return ans;
    }
};
