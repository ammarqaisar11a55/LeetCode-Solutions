class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {

        vector<int> mod;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                if (mod.size() == arr.size())
                {
                    break;
                }
                mod.push_back(0);
                if (mod.size() == arr.size())
                {
                    break;
                }
                mod.push_back(0);
                if (mod.size() == arr.size())
                {
                    break;
                }
            }
            else
                mod.push_back(arr[i]);
            if (mod.size() == arr.size())
            {
                break;
            }
        }
        arr.clear();
        arr = mod;
        mod.clear();
    }
};