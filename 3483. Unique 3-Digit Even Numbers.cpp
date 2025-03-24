class Solution {
public:
    unordered_set<int> Temp_Res;

    void Solve(int number, vector<int>& digits, int& res,
               unordered_set<int>& used_digits) {
        if (used_digits.size() == 3) {
            if (number % 2 == 0) {
                Temp_Res.insert(number);
                // cout<<number<<endl;
                res++;
            }

            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (used_digits.find(i) != used_digits.end()) {
                continue;
            }

            if (used_digits.size() == 0 && digits[i] == 0)
                continue;

            used_digits.insert(i);
            Solve((number * 10 + digits[i]), digits, res, used_digits);
            used_digits.erase(i);
        }
    }

    int totalNumbers(vector<int>& digits) {
        int res = 0;
        unordered_set<int> used;
        Solve(0, digits, res, used);
        res = Temp_Res.size();
        Temp_Res.clear();
        return res;
    }
};
