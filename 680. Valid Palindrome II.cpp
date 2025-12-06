class Solution {
public:
    bool validPalindrome(string s) {
        bool check_simple_palindrome = true;

        int left = 0, right = s.length() - 1;

        while (left < right) {
            if (s[left++] != s[right--]) {
                check_simple_palindrome = false;
            }
        }

        if (check_simple_palindrome)
            return true;

        check_simple_palindrome = true;

        // skipping left

        left = 0, right = s.length() - 1;

        int mismatched = 0;

        while (left < right) {
            if (s[left] != s[right]) {
                if (mismatched == 0) {
                    left++;
                    mismatched++;
                } else {
                    check_simple_palindrome = false;
                    break;
                }
            } else {
                left++, right--;
            }
        }

        if (check_simple_palindrome)
            return true;

        // skipping right

        check_simple_palindrome = true;
        left = 0, right = s.length() - 1, mismatched = 0;

        while (left < right) {
            if (s[left] != s[right]) {
                if (mismatched == 0) {
                    right--;
                    mismatched++;
                } else {
                    check_simple_palindrome = false;
                    break;
                }
            } else {
                left++, right--;
            }
        }

        return check_simple_palindrome;
    }
};
