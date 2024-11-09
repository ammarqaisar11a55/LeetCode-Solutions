class Solution
{
public:
    string reformat(string s)
    {

        int cntletters = 0;
        int cntdigits = 0;
        string digits;
        string letters;

        for (char c : s)
        {
            if (isdigit(c))
            {
                cntdigits++;
                digits += c;
            }
            else
            {
                cntletters++;
                letters += c;
            }
        }

        int difference = abs(cntdigits - cntletters);

        if (difference != 0 && difference != 1)
            return "";

        string ans;

        if (cntdigits > cntletters)
        {
            while (digits.size() > 0)
            {
                if (digits.empty() == false)
                {
                    ans.push_back(digits.back());
                    digits.pop_back();
                }

                if (letters.empty() == false)
                {
                    ans.push_back(letters.back());
                    letters.pop_back();
                }
            }
        }
        else
        {

            while (letters.size() > 0)
            {

                if (letters.empty() == false)
                {
                    ans.push_back(letters.back());
                    letters.pop_back();
                }

                if (digits.empty() == false)
                {
                    ans.push_back(digits.back());
                    digits.pop_back();
                }
            }
        }

        return ans;
    }
};