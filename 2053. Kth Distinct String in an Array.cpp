class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {

        string ans = arr[0];
        int dis = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int count = 1;
            for (int j = 0; j < arr.size(); j++)
            {
                if (arr[i] == arr[j] && i != j)
                {
                    count++;
                    if (count > 1)
                    {
                        break;
                    }
                }
            }

            if (count == 1)
            {

                dis++;

                if (dis == k)
                {
                    ans = arr[i];
                }
            }
        }

        if (dis >= k)
        {
            return ans;
        }
        else
            return "";
    }
};

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {

        unordered_map<string, int> strings;
        int count = 0;

        for (auto x : arr)
            strings[x]++;

        for (string x : arr)
        {
            if (strings[x] == 1)
            {
                count++;
            }

            if (count == k)
                return x;
        }

        return "";
    }
};