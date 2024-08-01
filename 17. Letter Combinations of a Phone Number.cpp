class Solution
{
public:
    void Solve(string digits, int index, string output, vector<string> &Ans, string keypad[])
    {
        if (index >= digits.size())
        {
            Ans.push_back(output);
            return;
        }

        string button = keypad[digits[index] - '0'];

        for (int i = 0; i < button.length(); i++)
        {
            output.push_back(button[i]);
            Solve(digits, index + 1, output, Ans, keypad);
            output.pop_back();
        }
    }

    //***************************************
    vector<string> letterCombinations(string digits)
    {

        vector<string> Ans;
        if (digits.length() == 0)
            return Ans;

        int index = 0;
        string output;
        string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        Solve(digits, index, output, Ans, keypad);
        return Ans;
    }
};