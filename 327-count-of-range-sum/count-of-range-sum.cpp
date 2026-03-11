class Solution {
public:
    int n;
    vector<long long> pre;
    long long ll,hl;

    long long ans;


    void merge(vector<long long>& vec , int low , int mid , int high){

        int rl = mid+1;
        int rh = mid+1;

        for(int i =low;i<=mid;i++){

            while(rl<=high && vec[rl]-vec[i]<ll) rl++;
            while(rh<=high && vec[rh]-vec[i]<=hl) rh++;

            ans+=(rh-rl);
        }




        int l = low;
        int r = mid+1;
        vector<long long> temp;

        while(l<=mid&&r<=high){
            if(vec[l]<=vec[r]) temp.push_back(vec[l++]);
            else temp.push_back(vec[r++]);
        }
        while(l<=mid) temp.push_back(vec[l++]);
        while(r<=high) temp.push_back(vec[r++]);

        for(int i =0;i<temp.size();i++){
            vec[i+low] = temp[i];
        }
    }
    void mergeSort(vector<long long>& vec , int low , int high){
        if(low>=high) return;

        int mid = low+(high-low)/2;

        mergeSort(vec , low , mid);
        mergeSort(vec , mid+1 , high);

        merge(vec , low , mid , high);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        n = nums.size();
        ll = lower;
        hl = upper;
        ans =0;
        pre.resize(n+1, 0);
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pre[i+1]=sum;
        }
        mergeSort(pre , 0 , n);

        return ans;

    }
};