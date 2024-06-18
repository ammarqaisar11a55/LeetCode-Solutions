class Solution
{
public:
    int xorOperation(int n, int start)
    {

        vector<int> arr;

        for (int i = 0; i < n; i++)
        {
            arr.push_back(start + 2 * i);
        }

        int XOR = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            XOR ^= arr[i];
        }

        return XOR;
    }
};