class Solution {
public:

    bool isP( vector<int>& quantiles , int n , int no){
        int i = 0;
        while(i<quantiles.size()){
            if(n==0) return false;
            n-=(quantiles[i]+no-1)/no;
            i++;
        }
        if(n>=0) return true;
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        sort(quantities.begin(),quantities.end());
        int high = quantities[quantities.size()-1];

        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(isP(quantities , n , mid)){
                ans = mid;
                high = mid-1;
            }else low= mid+1;
        }
        return ans;
    }
};