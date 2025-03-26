class Solution {
public:
    bool Solve(int index, string digits, vector<int>& Res) {

        if (index >= digits.size()) {
            return Res.size() >= 3 ? true : false;
        }

        long long int current_number = 0;

        for (int i = index; i < digits.length(); i++) {
            int current_digit = digits[i] - '0';

            if (digits[index] == '0' && i > index)
                return false;

            current_number = current_number * 10 + current_digit;

            if (current_number > INT_MAX)
                return false;

            if (Res.size() < 2 || (long long int)Res[Res.size() - 1] +
                                          (long long int)Res[Res.size() - 2] ==
                                      current_number) {
                Res.push_back(current_number);

                if (Solve(i + 1, digits, Res)) {
                    return true;
                }

                Res.pop_back();
            }
        }

        return false;
    }

    vector<int> splitIntoFibonacci(string num) {
        vector<int> Res;
        Solve(0, num, Res);
        return Res;
    }
};
