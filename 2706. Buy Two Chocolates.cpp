class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {

        sort(prices.begin(), prices.end());

        int CostOfTwoChocolates = prices[0] + prices[1];

        if (CostOfTwoChocolates <= money)
        {
            return money - CostOfTwoChocolates;
        }

        return money;
    }
};