class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int cnteve=0; int cntodd=0;
        for(auto x:nums1){
            if(x%2==0) cnteve++;
            else cntodd++;
        }

        if(cnteve == n || cntodd == n) return true; 


        int mn=1e9+1;
        for(auto x:nums1){
            if(x%2==1) mn = min(mn,x);
        }

        for(auto x:nums1){
            if(x%2==0 && x-mn<1) return false;
        }
        return true;
    }
};