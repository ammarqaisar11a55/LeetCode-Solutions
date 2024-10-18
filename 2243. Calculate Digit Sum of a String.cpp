class Solution
{
public:
    string digitSum(string s, int k)
    {

        while (s.length() > k)
        {
            string temp;
            string tempgroup;

            for (int i = 0; i < s.length(); i++)
            {
                if (tempgroup.length() < k)
                {
                    tempgroup.push_back(s[i]);
                }

                if (tempgroup.length() == k || i == s.length() - 1)
                {
                    int tempsum = 0;
                    for (char c : tempgroup)
                    {
                        tempsum += c - '0';
                    }
                    temp += to_string(tempsum);
                    tempgroup.clear();
                }
            }

            s = temp;
        }

        return s;
    }
};