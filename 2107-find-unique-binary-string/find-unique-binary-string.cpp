class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        
        int n=nums.size();
        string s="";
        for(int i=0;i<n;i++) s.push_back('0');

        for(int i=0;i<n;i++)
        {
            if(!st.count(s)) return s;
            s[i]='1'; 
             if(!st.count(s)) return s;
        }
        return "";
    }
};