class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {

        unordered_map<char, int> MP;

        for (int i = 0; i < chars.length(); i++)
        {
            MP[chars[i]]++;
        }

        int ans = 0;
        unordered_map<char, int> Temp = MP;

        for (int i = 0; i < words.size(); i++)
        {
            bool good = true;
            for (int j = 0; j < words[i].length(); j++)
            {
                if (Temp.find(words[i][j]) != Temp.end() && Temp[words[i][j]] > 0)
                {
                    Temp[words[i][j]]--;
                }
                else
                {
                    good = false;
                    break;
                }
            }

            if (good == true)
                ans += words[i].length();

            Temp = MP;
        }

        return ans;
    }
};