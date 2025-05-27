class Solution {
public:
    void Solve(vector<string> nums, int index, vector<vector<string>>& Ans) {
        if (index >= nums.size()) {
            Ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            Solve(nums, index + 1, Ans);
            swap(nums[index], nums[i]);
        }
    }

    string Binary_Conversion(int n) {
        if (n == 0)
            return "0";

        string res;

        while (n > 0) {
            res = char((n % 2) + '0') + res;
            n /= 2;
        }

        return res;
    }

    int Binary_To_Decimal(string binary) {
        int decimal = 0;
        int power = 1; // Represents 2^0 initially

        // Start from the last digit of the binary string
        for (int i = binary.length() - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                decimal += power; // Add current power of 2 if bit is 1
            }
            power *= 2; // Move to the next power of 2
        }

        return decimal;
    }
    int maxGoodNumber(vector<int>& nums) {
        int res = 0;
        vector<string> Binary_Conversions;

        for (int i = 0; i <= 2; i++) {
            Binary_Conversions.push_back(Binary_Conversion(nums[i]));
        }

        vector<vector<string>> Perms;

        Solve(Binary_Conversions, 0, Perms);

        for (vector<string> B : Perms) {
            string current = B[0] + B[1] + B[2];
            res = max(res, Binary_To_Decimal(current));
        }

        return res;
    }
};
