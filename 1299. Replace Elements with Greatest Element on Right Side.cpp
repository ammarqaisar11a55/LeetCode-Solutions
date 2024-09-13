class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {

        reverse(arr.begin(), arr.end());

        int maxi = arr[0];
        arr[0] = -1;

        for (int i = 1; i < arr.size(); i++)
        {
            int copy = arr[i];
            arr[i] = maxi;
            maxi = max(copy, maxi);
        }

        reverse(arr.begin(), arr.end());
        return arr;
    }
};