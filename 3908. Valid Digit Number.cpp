class Solution {
public:
    bool validDigit(int n, int x) {
        vector<int> ds;

        if (n == 0) {
            return false;
        }

        while (n > 0) {
            ds.push_back(n % 10);
            n /= 10;
        }

        reverse(ds.begin(), ds.end());

        if (ds[0] == x) {
            return false;
        }

        for (int i = 1; i < ds.size(); i++) {
            if (ds[i] == x) {
                return true;
            }
        }

        return false;
    }
};