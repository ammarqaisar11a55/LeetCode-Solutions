class Solution {
public:
    int findClosest(int x, int y, int z) {
        int one = abs(x - z);
        int two = abs(y - z);

        return one == two ? 0 : one < two ? 1 : 2;
    }
};
