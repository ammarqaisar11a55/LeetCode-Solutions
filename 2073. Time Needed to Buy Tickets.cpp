class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {

        int Time_Needed = 0;

        queue<int> Customers;

        for (int i = 0; i < tickets.size(); i++)
        {
            Customers.push(i);
        }

        while (tickets[k] > 0)
        {
            Time_Needed++;

            tickets[Customers.front()]--;

            if (tickets[Customers.front()] > 0)
            {
                Customers.push(Customers.front());
                Customers.pop();
            }
            else
            {
                Customers.pop();
            }
        }

        return Time_Needed;
    }
};