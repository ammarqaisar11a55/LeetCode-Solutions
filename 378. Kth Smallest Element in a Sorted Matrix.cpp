class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {

        vector<int> Sorted;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                Sorted.push_back(matrix[i][j]);
            }
        }

        priority_queue<int, vector<int>, less<int>> pq;

        for (int i = 0; i < k; i++)
            pq.push(Sorted[i]);

        for (int i = k; i < Sorted.size(); i++)
        {
            if (pq.top() > Sorted[i])
            {
                pq.pop();
                pq.push(Sorted[i]);
            }
        }

        return pq.top();
    }
};