class Solution
{
public:
    string decodeMessage(string key, string message)
    {

        unordered_map<char, char> Mp;
        char alpha = 'a';

        for (int i = 0; i < key.length(); i++)
        {
            if (key[i] != ' ' && Mp.find(key[i]) == Mp.end())
            {
                Mp[key[i]] = alpha++;
            }
        }

        string ans;

        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] == ' ')
            {
                ans += ' ';
            }
            else
            {
                ans += Mp[message[i]];
            }
        }

        return ans;
    }
};