class Solution
{
public:
    int isWinner(vector<int> &player1, vector<int> &player2)
    {

        vector<int> p1_scores;
        vector<int> p2_scores;

        p1_scores.push_back(player1[0]);
        p2_scores.push_back(player2[0]);

        for (int i = 1; i < player1.size(); i++)
        {
            if ((player1[i - 1] >= 10 && i >= 1) || ((i - 2) >= 0 && player1[i - 2] >= 10))
            {
                p1_scores.push_back(player1[i] * 2);
            }
            else
                p1_scores.push_back(player1[i]);
        }

        for (int i = 1; i < player2.size(); i++)
        {
            if ((player2[i - 1] >= 10 && i >= 1) || ((i - 2) >= 0 && player2[i - 2] >= 10))
            {
                p2_scores.push_back(player2[i] * 2);
            }
            else
                p2_scores.push_back(player2[i]);
        }

        if (sum(p1_scores) > sum(p2_scores))
        {
            return 1;
        }

        if (sum(p2_scores) > sum(p1_scores))
        {
            return 2;
        }

        return 0;
    }

    int sum(vector<int> a)
    {
        int sum = 0;

        for (int i = 0; i < a.size(); i++)
        {
            sum = sum + a.at(i);
        }
        return sum;
    }
};