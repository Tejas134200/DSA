class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int , int> ls;
        int n = nums.size();

        vector<int> arr(n ,INT_MAX);
        for(int i =0 ;i<nums.size();i++){
            if(ls.count(nums[i])){
                int prev = ls[nums[i]];
                arr[i] = i-prev;
                arr[prev] = min(arr[prev],i-prev);
                ls[nums[i]] = i;
            }else{
                ls[nums[i]]=i;
            }
        }
        for(int i =0;i<n/2+1;i++){
            if(ls.count(nums[i])){
                int prev = ls[nums[i]];
                if(prev>i){
                    int d = i+n-prev;
                    arr[i] = min(arr[i] ,d );
                    arr[prev] = min(arr[prev] , d);
                    ls[nums[i]] = i;
                }
            }
        }


        vector<int> ans;
        for(int i:queries){
            if(arr[i]==INT_MAX) ans.push_back(-1);
            else ans.push_back(arr[i]);
        }
        return ans;
    }
};