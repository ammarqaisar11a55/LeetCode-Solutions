class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int longest_length = 0;
        int i = 0;
        int j = 0;
        unordered_set<char> St;

        while (j < s.length())
        {
            if (St.find(s[j]) != St.end())
            {
                St.erase(s[i]);
                i++;
            }
            else
            {
                St.insert(s[j]);
                longest_length = max(longest_length, j - i + 1);
                j++;
            }
        }

        return longest_length;
    }
};