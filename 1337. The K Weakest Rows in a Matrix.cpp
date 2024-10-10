class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> Ans;

        for (int i = 0; i < mat.size(); i++)
        {
            int CountOnes = 0;

            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                    CountOnes++;
            }

            pq.push({CountOnes, i});
        }

        while (k--)
        {
            Ans.push_back(pq.top().second);
            pq.pop();
        }

        return Ans;
    }
};