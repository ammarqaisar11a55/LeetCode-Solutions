class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
         int n = colors.size();
        vector<int> extendedColors = colors;
        extendedColors.insert(extendedColors.end(), colors.begin(), colors.end()); 

        int count = 0, alternatingLength = 1;

        for (int i = 1; i < 2 * n; i++) {
            if (extendedColors[i] != extendedColors[i - 1]) {
                alternatingLength++;
            } else {
                alternatingLength = 1;
            }

            if (alternatingLength >= k && i >= n) {
                count++;
            }
        }

        return count;
    }
};
