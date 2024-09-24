class Solution
{
public:
    int minLength(string s)
    {

        while (!s.empty() && (s.find("AB") != string::npos || s.find("CD") != string::npos))
        {
            if (s.find("AB") != string::npos)
            {
                s.erase(s.find("AB"), 2);
            }

            if (s.find("CD") != string::npos)
            {
                s.erase(s.find("CD"), 2);
            }
        }

        return s.length();
    }
};