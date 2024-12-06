class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {

        unordered_set<int> Banned_Ints;

        for (int a : banned)
        {
            if (a <= n)
                Banned_Ints.insert(a);
        }

        int Current_Sum = 0;
        int No_of_Intergers = 0;

        for (int i = 1; i <= n; i++)
        {
            if (Banned_Ints.find(i) == Banned_Ints.end() && (Current_Sum + i) <= maxSum)
            {
                Current_Sum += i;
                No_of_Intergers++;
            }
        }

        return No_of_Intergers;
    }
};