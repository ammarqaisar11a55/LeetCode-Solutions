class Solution
{
public:
    string reverseWords(string s)
    {

        reverse(s.begin(), s.end());

        if (s.back() != ' ')
        {
            s.push_back(' ');
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                int j = i;
                while (i + 1 < s.length() && s[i + 1] != ' ')
                {
                    i++;
                }

                int k = i;

                while (j < k)
                {
                    swap(s[j], s[k]);
                    j++;
                    k--;
                }
                i++;
                s[i] = '*';
            }
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                s.erase(s.begin() + i);
                i--;
            }
        }

        s.pop_back();

        for (char &c : s)
        {
            if (c == '*')
            {
                c = ' ';
            }
        }

        return s;
    }
};