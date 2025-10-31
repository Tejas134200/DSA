class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ans =0;
        int mini =INT_MAX;
        for(int i =0;i<n;i++){
            int k =abs(nums1[i]-nums2[i]);
            ans+=k;
            if(nums2[i]>=nums1[i]){
                if(nums2[n]>=nums1[i]&&nums2[n]<=nums2[i]) mini=0;
            }
            if(nums2[i]<=nums1[i]){
                if(nums2[n]<=nums1[i]&&nums2[n]>=nums2[i]) mini=0;
            }
            mini = min(mini,min(abs(nums1[i]-nums2[n]),abs(nums2[i]-nums2[n])));
        }
        return ans+mini+1;

    }
};