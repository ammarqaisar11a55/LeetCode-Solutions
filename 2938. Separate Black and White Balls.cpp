class Solution {
public:
    long long minimumSteps(string s) {
        int left = 0;
        int right = s.length();

        long long operations = 0;

        while (left < right) {
            if (s[left] != '1') {
                left++;
                continue;
            }

            if (s[right] != '0') {
                right--;
                continue;
            }

            operations += right - left;

            right--, left++;
        }

        return operations;
    }
};
