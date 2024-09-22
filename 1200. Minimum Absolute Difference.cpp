class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {

        vector<vector<int>> Ans;

        sort(begin(arr), end(arr));
        int MiniAbs = INT_MAX;

        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                MiniAbs = min(MiniAbs, arr[i + 1] - arr[i]);
            }
        }

        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i + 1] - arr[i] == MiniAbs)
            {
                Ans.push_back({arr[i], arr[i + 1]});
            }
        }

        return Ans;
    }
};