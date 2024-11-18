class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {

        vector<int> Result(code.size(), 0);

        if (k == 0)
            return Result;

        int i, j;

        if (k > 0)
        {
            i = 1;
            j = k;
        }
        else
        {
            i = code.size() + k;
            j = code.size() - 1;
        }

        int WindowSum = 0;

        for (int FirstWindow = i; FirstWindow <= j; FirstWindow++)
        {
            WindowSum += code[FirstWindow % code.size()];
        }

        for (int L = 0; L < code.size(); L++)
        {
            Result[L] = WindowSum;

            WindowSum -= code[i % code.size()];
            i++;
            j++;
            WindowSum += code[j % code.size()];
        }

        return Result;
    }
};