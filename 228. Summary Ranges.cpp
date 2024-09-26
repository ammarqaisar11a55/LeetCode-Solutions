class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        if (nums.size() == 0)
            return {};

        vector<string> Ans;
        stack<int> sk;

        sk.push(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - 1 == sk.top())
            {
                sk.push(nums[i]);
            }
            else
            {

                if (sk.size() == 1)
                {
                    string s = to_string(sk.top());
                    Ans.push_back(s);
                    sk.pop();
                    sk.push(nums[i]);
                    continue;
                }

                string end = to_string(sk.top());

                string start;

                while (!sk.empty())
                {
                    start = to_string(sk.top());
                    sk.pop();
                }

                sk.push(nums[i]);

                string range = start + "->" + end;

                Ans.push_back(range);
            }
        }

        if (!sk.empty())
        {
            if (sk.size() == 1)
            {
                string s = to_string(sk.top());
                Ans.push_back(s);
                sk.pop();
            }
            else
            {
                string end = to_string(sk.top());

                string start;

                while (!sk.empty())
                {
                    start = to_string(sk.top());
                    sk.pop();
                }
                string range = start + "->" + end;

                Ans.push_back(range);
            }
        }

        return Ans;
    }
};