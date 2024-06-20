class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {

        // Left Sum:

        vector<int> ls = nums;

        ls.insert(ls.begin(), 0);
        ls.pop_back();

        for (int i = 1; i < ls.size(); i++)
        {
            ls[i] = ls[i] + ls[i - 1];
        }

        // Right Sum:

        vector<int> rs = nums;

        reverse(rs.begin(), rs.end());

        rs.insert(rs.begin(), 0);
        rs.pop_back();

        for (int i = 1; i < rs.size(); i++)
        {
            rs[i] = rs[i] + rs[i - 1];
        }

        reverse(rs.begin(), rs.end());

        // Answer:

        vector<int> answer;

        for (int i = 0; i < nums.size(); i++)
        {
            answer.push_back(abs(ls[i] - rs[i]));
        }

        return answer;
    }
};