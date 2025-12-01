class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum =0;
        for(int i: batteries) sum+=i;
        long long l = 1;
        long long r = sum/n;
        while(l<r){
            long long m = r-(r-l)/2;
            long long ex =0;
            for(int i:batteries) ex+=min((long long)i,m);
            if(ex>=(long long)n*m) l=m;
            else r=m-1;
        }
        return l;
        
    }
};