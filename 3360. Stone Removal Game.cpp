class Solution
{
public:
    bool canAliceWin(int n)
    {
        int stones_to_remove_on_this_turn = 10;

        bool alice_turn = true;

        while (true)
        {
            if (alice_turn)
            {
                alice_turn = false;

                if (stones_to_remove_on_this_turn > n)
                {
                    return false;
                }
                else
                {
                    n -= stones_to_remove_on_this_turn;
                    stones_to_remove_on_this_turn--;
                }
            }
            else
            {
                alice_turn = true;

                if (stones_to_remove_on_this_turn > n)
                {
                    return true;
                }
                else
                {
                    n -= stones_to_remove_on_this_turn;
                    stones_to_remove_on_this_turn--;
                }
            }
        }

        return true;
    }
};