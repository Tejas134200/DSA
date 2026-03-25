class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        for(int i:candyType){ s.insert(i);if(s.size()>candyType.size()/2) return candyType.size()/2;}

        return min((int)candyType.size()/2 , (int)s.size());
    }
};