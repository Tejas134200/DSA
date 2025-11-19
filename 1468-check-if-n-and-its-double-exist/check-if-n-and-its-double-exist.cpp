class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> m;
        for(int i:arr) m[i]++;
        int c =0;
        for(int i:arr){
            if(i==0) c++;
            else if(m.count(i*2)) return true;
        }
        return c>=2;
    }
};