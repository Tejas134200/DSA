class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int> m, mm;
        
        int maxi1=0, maxi1_2=0, num=0;
        for(int i=0;i<n;i+=2){
            m[nums[i]]++;
        }
        for(auto &x:m){
            if(x.second>maxi1){
                maxi1_2=maxi1;
                maxi1=x.second;
                num=x.first;
            }
            else if(x.second>maxi1_2){
                maxi1_2=x.second;
            }
        }
        
        int maxi2=0, maxi2_2=0, num2=0;
        for(int i=1;i<n;i+=2){
            mm[nums[i]]++;
        }
        for(auto &x:mm){
            if(x.second>maxi2){
                maxi2_2=maxi2;
                maxi2=x.second;
                num2=x.first;
            }
            else if(x.second>maxi2_2){
                maxi2_2=x.second;
            }
        }
        
        int c1 = (n+1)/2;
        int c2 = n/2;
        
        if(num!=num2){
            return (c1-maxi1) + (c2-maxi2);
        }
        else{
            return min((c1-maxi1)+(c2-maxi2_2),(c1-maxi1_2)+(c2-maxi2));
        }
    }
};