class Solution
{
public:
    int minOperations(vector<string> &logs)
    {

        int depth = 0;

        for (int i = 0; i < logs.size(); i++)
        {
            if (logs[i] == "../")
            {
                depth = max(0, depth - 1);
            }
            else if (logs[i] != "./")
            {
                depth++;
            }
        }
        return depth;
    }
};