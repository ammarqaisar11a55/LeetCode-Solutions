class Solution {
public:
    int minMaxDifference(int num) {
        string num_string = to_string(num);
        int digit_to_change = 0;
        int originial_digit;

        // max case:

        for (char c : num_string) {
            if (c != '9') {
                digit_to_change = c - '0';
                break;
            }
        }

        int maxi = 0, mini = 0;

        for (char& c : num_string) {
            if (c - '0' == digit_to_change) {

                maxi = maxi * 10 + (9);

                continue;
            }

            maxi = maxi * 10 + (c - '0');
        }

        // Min Case:

        for (char c : num_string) {
            if (c != '0') {
                digit_to_change = c - '0';
                break;
            }
        }

        for (char& c : num_string) {
            if (c - '0' == digit_to_change) {

                mini = mini * 10 + (0);

                continue;
            }

            mini = mini * 10 + (c - '0');
        }

        return maxi - mini;
    }
};
