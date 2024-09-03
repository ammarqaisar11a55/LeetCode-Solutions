class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {

        // Approach 1:

        // string modified;

        // for (int i = s.length() - 1 ; i >= 0 ; i--)
        // {
        //     if (s[i] >= 'a' && s[i] <= 'z')
        //     {
        //         modified.push_back(s[i]-'a' + 'A');
        //     }
        //     else if (s[i] != '-')
        //     {
        //         modified.push_back(s[i]);
        //     }
        // }

        // int i = 0;
        // int j = 0;
        // string ans;

        // while(i<modified.length())
        // {
        //     while(j<k)
        //     {
        //         ans+= modified[i++];
        //         j++;
        //     }

        //     ans += "-";
        //     j = 0;
        // }

        // ans.pop_back();
        // if(ans[ans.length()-1] == ' ')
        //     ans.pop_back();
        // reverse(begin(ans),end(ans));

        // return ans;

        //Approach 2: 

        string ans;
        int count = 0;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] != '-')
            {
                if (s[i] >= 'a' && s[i] <= 'z')
                {

                    ans.push_back(s[i] - 'a' + 'A');
                }
                else
                {
                    // Case for uppercase and numbers:
                    ans.push_back(s[i]);
                }

                count++;

                if (count == k)
                {
                    ans += "-";
                    count = 0;
                }
            }
        }

        if (ans.size() > 0 && ans.back() == '-')
            ans.pop_back();

        reverse(ans.begin(), ans.end());
        return ans;
    }
};