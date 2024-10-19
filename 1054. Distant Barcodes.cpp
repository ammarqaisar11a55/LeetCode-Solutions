class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {

        unordered_map<int, int> Mp;

        for (auto x : barcodes)
        {
            Mp[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

        for (auto x : Mp)
        {
            pq.push({x.second, x.first});
        }

        vector<int> Ans;
        pair<int, int> prev = {-1, -1};

        while (pq.empty() == false)
        {
            pair<int, int> temp = pq.top();
            pq.pop();

            Ans.push_back(temp.second);
            temp.first--;

            if (prev.first > 0)
            {
                pq.push(prev);
            }

            prev = temp;
        }

        return Ans;
    }
};