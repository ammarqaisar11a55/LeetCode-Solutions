class Solution {
public:
    int mirrorDistance(int n) {
        string no = to_string(n);

        reverse(no.begin(), no.end());

        int new_n = 0;

        for (int i = 0; i < no.length(); i++) {
            int digit = no[i] - '0';
            new_n = new_n * 10 + digit;
        }

        return abs(n - new_n);
    }
};