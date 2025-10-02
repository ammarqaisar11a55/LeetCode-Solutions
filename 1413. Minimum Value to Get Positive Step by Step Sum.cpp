class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 1;

        int index = 0;
        int start_value = 1;

        while (index < nums.size()) {
            res += nums[index++];

            if (res < 1) {
                cout << "Start Value: " << start_value << " == " << res << endl;
                index = 0;
                start_value++;
                res = start_value;
            }
        }

        return start_value;
    }
};
