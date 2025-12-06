class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> Res((int)s.length(), INT_MAX);
        int previous_target_location = INT_MAX;

        // Left to Right Iteration:
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                Res[i] = 0;
                previous_target_location = 0;
            } else {
                if (previous_target_location != INT_MAX) {
                    Res[i] = previous_target_location + 1;
                    previous_target_location = Res[i];
                }
            }
        }

        // Right to Left_Iteration:

        previous_target_location = INT_MAX;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == c) {
                previous_target_location = 0;
                Res[i] = 0;
            } else {
                if (previous_target_location != INT_MAX) {
                    Res[i] = min(Res[i], previous_target_location + 1);
                    previous_target_location = Res[i];
                }
            }
        }

        return Res;
    }
};
