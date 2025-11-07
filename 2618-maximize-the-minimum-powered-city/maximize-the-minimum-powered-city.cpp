class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long long low = 0,high=2e10,ans=0;

        auto check=[&](long long val){
            vector<long long> power(n);
            long long curp  =0;
            for(int i =0;i<r&&i<n;i++){
                curp+=stations[i];
            }

            for(int i =0;i<n;i++){
                if(i+r<n) curp+=stations[i+r];
                if(i-r-1>=0) curp-=stations[i-r-1];
                power[i]=curp;
            }
            vector<long long> dif(n+1,0);
            long long add = 0;
            long long k_rem = k;

            for(int i =0;i<n;i++){
                add+=dif[i];
                long long curr_total=power[i]+add;
                if(curr_total<val){
                    long long needed = val-curr_total;
                    if(k_rem<needed) return false;
                    k_rem-=needed;
                    add+=needed;
                    int end = i+2*r+1;
                    if(end<n) dif[end]-=needed; 
                }
            }
            return true;

        };

        while(low<=high){
            long long mid = low+(high-low)/2;
            if(check(mid)){
                ans=mid;
                low=mid+1;
            }else high=mid-1;

        }
        return ans;
        
    }
};