class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {

        if (cost.size() == 1 || cost.size() == 2)
            return accumulate(cost.begin(), cost.end(), 0, plus<int>());

        sort(cost.rbegin(), cost.rend());

        int MinCost = 0;
        bool First_Purchased = false, Second_Purchased = false;

        for (int i = 0; i < cost.size(); i++)
        {
            if (!First_Purchased)
            {
                MinCost += cost[i];
                First_Purchased = true;
                continue;
            }

            if (!Second_Purchased)
            {
                MinCost += cost[i];
                Second_Purchased = true;
                continue;
            }

            First_Purchased = Second_Purchased = false;
        }

        return MinCost;
    }
};