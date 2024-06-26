
class Bank
{
public:
    vector<long long> accounts;

    Bank(vector<long long> &balance)
    {
        accounts = balance;
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 <= accounts.size() && account2 <= accounts.size() && account1 > 0 && account2 > 0)
        {
            if (accounts[account1 - 1] >= money)
            {
                accounts[account2 - 1] += money;
                accounts[account1 - 1] -= money;
                return true;
            }
            else
                return false;
        }

        return false;
    }

    bool deposit(int account, long long money)
    {
        if (account <= accounts.size() && account > 0)
        {
            accounts[account - 1] += money;
            return true;
        }
        else
            return false;
    }

    bool withdraw(int account, long long money)
    {
        if (account <= accounts.size() && account > 0 && accounts[account - 1] >= money)
        {
            accounts[account - 1] -= money;
            return true;
        }
        else
            return false;
    }
};