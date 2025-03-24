class Solution {
public:
    void Solve(int current_number, unordered_set<int>& Used_digits, int& res,
               int target_digits) {
        res++;
        if (target_digits == 0) {
            return;
        }

        for (int i = 0; i <= 9; i++) {
            if (current_number == 0 && i == 0)
                continue;

            if (Used_digits.find(i) != Used_digits.end())
                continue;

            Used_digits.insert(i);
            Solve(current_number * 10 + i, Used_digits, res, target_digits - 1);
            Used_digits.erase(i);
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        int res = 0;
        unordered_set<int> st;
        Solve(0, st, res, n);
        return res;
    }
};
