class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res = 0;

        for (int x : nums) {
            if (!(x & 1)) {

                res = res | x;
            }
        }

        return res;
    }
};
