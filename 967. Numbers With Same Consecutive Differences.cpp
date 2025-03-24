class Solution {
public:
    void Solve(int current_number, int target_length, int current_length,
               int required_difference, vector<int>& Res) {
        if (current_length == target_length) {
            Res.push_back(current_number);
            return;
        }

        for (int i = 0; i <= 9; i++) {
            if (current_number == 0 && i == 0)
                continue;

            if (current_number != 0) {
                int max_digit = max(current_number % 10, i);
                int min_digit = min(current_number % 10, i);

                if (max_digit - min_digit == required_difference) {
                    Solve(current_number * 10 + i, target_length,
                          current_length + 1, required_difference, Res);
                }

            } else {
                Solve(i, target_length, current_length + 1, required_difference,
                      Res);
            }
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        Solve(0, n, 0, k, res);
        return res;
    }
};
