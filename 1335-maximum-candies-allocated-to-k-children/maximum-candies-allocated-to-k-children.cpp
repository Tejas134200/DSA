class Solution {
public:
    bool isP( vector<int>& quantiles , long long n , int no){
        int i = 0;
        long long aa = 0;
        while(i<quantiles.size()){
            aa += (quantiles[i++]/no);
        }
        if(aa>=n) return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        sort(candies.begin(),candies.end());
        int high = candies[candies.size()-1];

        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(isP(candies , k , mid)){
                ans = mid;
                low = mid+1;
            }else high = mid-1;
        }
        return ans;
    }
};