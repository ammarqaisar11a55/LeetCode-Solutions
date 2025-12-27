class Solution {
public:
    int binaryGap(int n) {
        string binary;

        while (n > 0) {
            binary.push_back(('0' + n % 2));
            n /= 2;
        }

        reverse(binary.begin(), binary.end());

        vector<int> ones_position;

        for (int i = 0; i < binary.length(); i++) {
            if (binary[i] == '1') {
                ones_position.push_back(i);
            }
        }

        int res = 0;

        for (int i = 1; i < ones_position.size(); i++) {
            res = max(res, ones_position[i] - ones_position[i - 1]);
        }

        return res;
    }
};