class Solution {
public:
    long long coloredCells(int n) {
    long long res = 1;
    int prev = 0;

    for(int i = 1; i <= n; i++)
    {
        res += prev;
        prev = prev + 4;
    }


    return res;
    }
};
