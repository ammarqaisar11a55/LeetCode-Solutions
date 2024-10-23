class Solution
{
public:
    string reformatNumber(string number)
    {

        string filtered_string;

        for (char c : number)
        {
            if (isdigit(c))
            {
                filtered_string.push_back(c);
            }
        }

        string ans;

        reverse(filtered_string.begin(), filtered_string.end());

        while (true)
        {
            string temp;

            if (filtered_string.size() > 4)
            {
                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
            }
            else if (filtered_string.length() == 3)
            {
                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
            }
            else if (filtered_string.length() == 4)
            {
                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
                ans.push_back('-');

                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
            }
            else if (filtered_string.length() == 2)
            {
                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
                ans.push_back(filtered_string.back());
                filtered_string.pop_back();
            }
            else
            {
                if (ans.back() == '-')
                    ans.pop_back();

                break;
            }
            ans.push_back('-');
        }

        return ans;
    }
};