class Solution {
public:

    int solve(int n)
    {
        string s=to_string(n);
        reverse(s.begin(),s.end());
        int ele=stoi(s);
        return ele;
    }
    int minMirrorPairDistance(vector<int>& arr) {
        map<int,int>mp;

        int n=arr.size();
        mp[solve(arr[0])]=0;
        int len=arr.size();
        for(int i=1;i<n;i++)
            {
                if(mp.find(arr[i])!=mp.end())
                {
                    len=min(len,i-mp[arr[i]]);
                }
                mp[solve(arr[i])]=i;
            }
        if(len==n) return -1;
        return len;
    }
};