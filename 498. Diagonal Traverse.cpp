class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        int sum = 0;
        vector<int> Ans;

        while (mp.find(sum) != mp.end())
        {
            if (sum % 2 == 0)
            {
                while (mp[sum].empty() == false)
                {
                    Ans.push_back(mp[sum].back());
                    mp[sum].pop_back();
                }
            }
            else
            {
                for (int i : mp[sum])
                {
                    Ans.push_back(i);
                }
            }
            sum++;
        }

        return Ans;
    }
};