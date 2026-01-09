class NumArray {
public:
    vector<int> pre;
    vector<int> nn;
    int n;
    NumArray(vector<int>& nums) {
        nn=nums;
         n = nums.size();
        pre.resize(n,0);
        pre[0]=nums[0];
        for(int i =1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }

    }
    
    void update(int index, int val) {
        int k = val-nn[index];
        nn[index]= val;
        for(int i =index;i<n;i++) pre[i]+=k;
    }
    
    int sumRange(int left, int right) {
        if(left==0) return pre[right];
        return pre[right]-pre[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */