class Solution
{
public:
    string maskPII(string s)
    {

        if (s.find('@') != string::npos)
        {
            string ans = "";
            string beforesymbol;
            int start_from;

            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '@')
                {
                    start_from = i;
                    break;
                }
                else
                {
                    beforesymbol.push_back(s[i]);
                }
            }

            ans.push_back(islower(beforesymbol[0]) ? beforesymbol[0] : tolower(beforesymbol[0]));
            ans.push_back('*');
            ans.push_back('*');
            ans.push_back('*');
            ans.push_back('*');
            ans.push_back('*');
            ans.push_back(islower(beforesymbol[beforesymbol.length() - 1]) ? beforesymbol[beforesymbol.length() - 1] : tolower(beforesymbol[beforesymbol.length() - 1]));

            for (int i = start_from; i < s.length(); i++)
            {
                if (isalpha(s[i]))
                {
                    if (isupper(s[i]))
                    {
                        ans.push_back(tolower(s[i]));
                    }
                    else
                    {
                        ans.push_back(s[i]);
                    }
                }
                else
                    ans.push_back(s[i]);
            }

            return ans;
        }

        string number;
        string local;
        string countrycode;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (local.length() != 4)
            {
                if (isdigit(s[i]))
                    local.push_back(s[i]);
            }
            else if (local.length() + number.length() != 10)
            {
                if (isdigit(s[i]))
                    number.push_back(s[i]);
            }
            else
            {
                if (isdigit(s[i]))
                    countrycode.push_back(s[i]);
            }
        }

        reverse(begin(local), end(local));
        reverse(begin(number), end(number));
        reverse(begin(countrycode), end(countrycode));

        string ans;

        if (countrycode.length() == 0)
        {
            ans += "***-***-" + local;
        }
        else if (countrycode.length() == 1)
        {
            ans += "+*-***-***-" + local;
        }
        else if (countrycode.length() == 2)
        {
            ans += "+**-***-***-" + local;
        }
        else if (countrycode.length() == 3)
        {
            ans += "+***-***-***-" + local;
        }

        return ans;
    }
};