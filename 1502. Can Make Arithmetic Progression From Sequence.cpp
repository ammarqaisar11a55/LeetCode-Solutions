class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {

        sort(arr.begin(), arr.end());
        int x = arr[0] - arr[1];

        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] - arr[i + 1] != x)
                return false;
        }

        return true;
    }
};