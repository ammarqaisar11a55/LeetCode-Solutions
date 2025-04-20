class Solution {
public:
    void Solve(int current_number, int index, int low, int high,
               vector<int>& Res) {
        if (current_number >= low && current_number <= high) {
            Res.push_back(current_number);
        }

        if (current_number > high)
            return;

        for (int i = index; i <= 9; i++) {
            if (current_number == 0 || i - current_number % 10 == 1)
                Solve(current_number * 10 + i, i + 1, low, high, Res);
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> Res;
        Solve(0, 1, low, high, Res);

        sort(Res.begin(), Res.end());
        return Res;
    }
};
