class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {

        vector<char> mag;

        for (int i = 0; i < magazine.length(); i++)
        {
            mag.push_back(magazine[i]);
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {
            if (!is_there(mag, ransomNote[i]))
            {
                return false;
            }
        }

        return true;
    }

    bool is_there(vector<char> &magazine, char tobecheck)
    {

        for (int i = 0; i < magazine.size(); i++)
        {
            if (magazine[i] == tobecheck)
            {
                magazine.erase(magazine.begin() + i);
                return true;
            }
        }

        return false;
    }
};