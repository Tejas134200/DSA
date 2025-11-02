class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long time=0;
        long long low = 0,high=1e18,ans=-1;
        while(low<=high){
            long long mid = (low+high)/2;
            
            if(can(mid,d,r)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    long long lcm(long long a , long long b){
        return (a/__gcd(a,b))*b;
    }
    bool can(long long time , vector<int>& d , vector<int>& r){
        long long a1=time-time/r[0];
        long long a2 = time-time/r[1];
        if(a1<d[0]||a2<d[1]) return false;
        long long lcmv = lcm((long long)r[0],(long long)r[1]);
        long long over = time/lcmv;
        long long total = time-over;
        if((long long)d[0]+d[1]>total) return false;
        return true;
    }
    
};