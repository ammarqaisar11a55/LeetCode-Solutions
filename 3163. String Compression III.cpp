class Solution
{
public:
    string compressedString(string word)
    {

        int i = 0;
        string res = "";

        while (i < word.length())
        {
            int count = 0;
            char Current_Character = word[i];

            while (i < word.length() && count < 9 && word[i] == Current_Character)
            {
                count++;
                i++;
            }

            res += to_string(count) + Current_Character;
        }

        return res;
    }
};