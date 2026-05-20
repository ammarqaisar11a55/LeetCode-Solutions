class Solution
{
public:
    int minimumIndex(vector<int> &capacity, int itemSize)
    {
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;

        for (int i = 0; i < capacity.size(); i++)
        {
            if (capacity[i] >= itemSize)
            {
                mp[capacity[i]].push(i);
            }
        }

        if (mp.empty() == false)
        {
            for (auto [i, p] : mp)
            {
                return mp[i].top();
            }
        }

        return -1;
    }
};