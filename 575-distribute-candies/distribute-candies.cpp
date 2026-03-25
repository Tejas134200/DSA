class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        for(int i:candyType){
            s.insert(i);
        }
        int n = candyType.size();
        return min((int)n/2 , (int)s.size());
    }
};