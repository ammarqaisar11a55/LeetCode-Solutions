class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1;
        int min_dis = INT_MAX;
        int index = 0;

        for (vector<int> Point : points) {
            int y2 = Point[1], x2 = Point[0];

            int dis = abs(x - x2) + abs(y - y2);

            if (y2 == y || x2 == x) {
                if (dis < min_dis) {
                    min_dis = dis;
                    res = index;
                }
            }
            index++;
        }

        return res;
    }
};
