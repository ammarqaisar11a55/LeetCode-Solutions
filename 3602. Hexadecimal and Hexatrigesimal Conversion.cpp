class Solution {
public:
    string concatHex36(int n) {
        int n2 = n * n;

        string hexadecimal;

        while (n2 > 0) {
            int digit = n2 % 16;

            if (digit <= 9) {
                hexadecimal += ('0' + digit);
            } else {
                hexadecimal += (digit - 10 + 'A');
            }

            n2 /= 16;
        }

        int n3 = n * n * n;
        string hexatri;

        while (n3 > 0) {
            int digit = n3 % 36;

            if (digit <= 9) {
                hexatri += ('0' + digit);
            } else {
                hexatri += (digit - 10 + 'A');
            }

            n3 /= 36;
        }

        reverse(hexadecimal.begin(), hexadecimal.end());
        reverse(hexatri.begin(), hexatri.end());

        return hexadecimal + hexatri;
    }
};
