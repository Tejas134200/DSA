class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        for(int i:candyType) s.insert(i);

        return min((int)candyType.size()/2 , (int)s.size());
    }
};