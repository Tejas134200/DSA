class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int c =0;
        int s =0;
        for(int i:apple) s+=i;
        int i =0;
        while(i<capacity.size()&&s>0){
            s-=capacity[i++];
            c++;
        }
        return c;
    }
};