class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {

        long long area = 0;

        int minX = INT_MAX;
        int minY = INT_MAX;
        int maxX = INT_MIN;
        int maxY = INT_MIN;

        set<pair<int,int>> corners;

        auto toggle = [&](pair<int,int> p){

            if(corners.count(p))
                corners.erase(p);
            else
                corners.insert(p);
        };

        for(auto &r : rectangles){

            int x1 = r[0];
            int y1 = r[1];
            int x2 = r[2];
            int y2 = r[3];

            area += 1LL * (x2 - x1) * (y2 - y1);

            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            toggle({x1,y1});
            toggle({x1,y2});
            toggle({x2,y1});
            toggle({x2,y2});
        }

        long long bigArea = 1LL * (maxX - minX) * (maxY - minY);

        if(area != bigArea)
            return false;

        if(corners.size() != 4)
            return false;

        return corners.count({minX,minY}) &&
               corners.count({minX,maxY}) &&
               corners.count({maxX,minY}) &&
               corners.count({maxX,maxY});
    }
};