class Solution {
public:
    vector<int> ans;
    vector<int> indices; 

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left;      
        int j = mid + 1;   
        int k = 0;         
        int right_count = 0; 

        while (i <= mid && j <= right) {
            if (nums[indices[j]] < nums[indices[i]]) {
                right_count++; 
                temp[k++] = indices[j++];
            } else {
                ans[indices[i]] += right_count;
                temp[k++] = indices[i++];
            }
        }

        while (i <= mid) {
            ans[indices[i]] += right_count;
            temp[k++] = indices[i++];
        }
        
        while (j <= right) {
            temp[k++] = indices[j++];
        }

        for (int p = 0; p < temp.size(); p++) {
            indices[left + p] = temp[p];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2; 
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);
        indices.resize(n);
        for (int i = 0; i < n; i++) indices[i] = i;
        mergeSort(nums, 0, n - 1);
        return ans;
    }
};