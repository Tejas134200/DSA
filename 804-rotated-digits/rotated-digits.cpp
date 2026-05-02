class Solution {
public:
    unordered_map<int,int> mp;

    bool isGood(int x){
        int copy = x;
        //build from right 788

        int cx = 0;
        int mul = 1;

        while(x>0){
            int dig = x%10;
            x/=10;

            int rot = mp[dig];
            if(rot==-1) return false;

            cx = mul*rot+cx;
            mul*=10;
        }
        return copy!=cx;

    }
    int rotatedDigits(int n) {
        int ans = 0;
        mp[6]=9;
        mp[9]=6;
        mp[2]=5;
        mp[5]=2;
        mp[0]=0;
        mp[1]=1;
        mp[8]=8;
        mp[3]=-1;
        mp[4]=-1;
        mp[7]=-1;

        for(int i = 1;i<=n;i++){
            if(isGood(i)) {
                cout<<i<<endl;
                ans++;
            }
        }
        return ans;
    }
};