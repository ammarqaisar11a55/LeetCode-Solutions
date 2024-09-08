class Solution
{
public:
    bool isSubstringPresent(string s)
    {

        string reverseSTR = s;
        reverse(reverseSTR.begin(), reverseSTR.end());

        for (int i = 0; i < s.length() - 1; i++)
        {
            string substring = s.substr(i, 2);
            if (reverseSTR.find(substring) != string::npos)
                return true;
        }

        return false;
    }
};

bool isSubstringPresent(string s)
{
    unordered_set<string> substringsofs;

    for (int i = 0; i < s.length() - 1; i++)
    {
        substringsofs.insert(s.substr(i, 2));
    }

    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (substringsofs.find(s.substr(i, 2)) != substringsofs.end())
            return true;
    }

    return false;
}