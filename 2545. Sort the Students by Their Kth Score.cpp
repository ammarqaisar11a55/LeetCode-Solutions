class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {

        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, less<pair<int, vector<int>>>> pq;

        for (vector<int> X : score)
        {
            pq.push({X[k], X});
        }

        vector<vector<int>> Ans;

        while (pq.empty() == false)
        {
            Ans.push_back(pq.top().second);
            pq.pop();
        }
        return Ans;
    }
};