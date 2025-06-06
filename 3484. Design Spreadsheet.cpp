class Spreadsheet {
    unordered_map<string, int> mp;

public:
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) { mp[cell] = value; }

    void resetCell(string cell) { mp[cell] = 0; }

    int getValue(string formula) {
        int left = 0;
        int right = 0;

        int plus_position = formula.find('+');

        if (isalpha(formula[1])) {
            string left_val;

            int temp_index = 1;

            while (temp_index != plus_position) {
                left_val += formula[temp_index++];
            }

            left = mp[left_val];
        } else {
            int temp_index = 1;

            while (temp_index != plus_position) {
                left = left * 10 + (formula[temp_index] - '0');
                temp_index++;
            }
        }

        if (isalpha(formula[plus_position + 1])) {
            string right_val;

            int temp_index = plus_position + 1;

            while (temp_index < formula.length()) {
                right_val += formula[temp_index++];
            }

            right = mp[right_val];
        } else {
            int temp_index = plus_position + 1;

            while (temp_index < formula.length()) {
                right = right * 10 + (formula[temp_index] - '0');
                temp_index++;
            }
        }

        return left + right;
    }
};
