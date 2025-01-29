
/*Approach 1: Recursive Approach:*/

class Solution
{
public:
    void Solve(int CurrentNumber, int limit, vector<int> &Res)
    {
        if (CurrentNumber > limit)
        {
            return;
        }

        Res.push_back(CurrentNumber);

        for (int i = 0; i <= 9; i++)
        {
            int Next_Number = CurrentNumber * 10 + i;

            if (Next_Number <= limit)
            {
                Solve(Next_Number, limit, Res);
            }
            else
            {
                break;
            }
        }
    }

    vector<int> lexicalOrder(int n)
    {
        vector<int> Res;

        for (int i = 1; i <= 9; i++)
        {
            Solve(i, n, Res);
        }

        return Res;
    }
};


/*Approach 2: Iterative Approach:*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> Res;

    int Current_Number = 1;

    for(int i = 0; i < n; i++)
    {
        Res.push_back(Current_Number);

        if(Current_Number*10 <= n)
        {
            Current_Number*=10;
        }
        else
        {
            while(Current_Number%10 == 9 || Current_Number >= n)
            {
                Current_Number /= 10;
            }

            Current_Number++;
        }
    }

    return Res;   
    }
};