class NumArray {
public:
    int n;
    vector<int> a , seg;
    NumArray(vector<int>& nums) {
        n = nums.size();
        a=nums;
        seg.resize(4*n);
        build(0,0,n-1);
    }

    void build(int i , int low , int high){
        if(low==high){
            seg[i] = a[low];
            return;
        }
        int mid = (high+low)/2;
        build(2*i+1 , low , mid);
        build(2*i+2 , mid+1 , high);

        seg[i] = seg[2*i+1] + seg[2*i+2];
        return;
    }

    int sum(int i , int low , int high , int l , int r){
        if(l>high||r<low) return 0;
        if(l<=low&&high<=r) return seg[i];
        int mid = (high+low)/2;
        int le = sum(i*2+1 , low , mid , l , r );
        int ri = sum(i*2+2 , mid+1 , high , l , r);

        return le+ri;
    }

    void upd(int i , int low , int high , int ind , int val){
        if(low==high){
            seg[i]+=val;
            return;
        }
        int mid = (low+high)/2;
        if(low<=ind&&ind<=mid){
            upd(2*i+1 , low , mid , ind , val);
        }else{
            upd(2*i+2 , mid+1 , high , ind , val);
        }

        seg[i] = seg[2*i+1]+seg[2*i+2];
        return;
    }
    void update(int index, int val) {
        int vv = val;
        val = val-a[index];
        a[index] = vv;
        upd(0 , 0 , n-1 , index , val);
    }
    
    int sumRange(int left, int right) {
        return sum(0 , 0 , n-1 , left , right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */