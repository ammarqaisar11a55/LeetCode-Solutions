class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int white = 0;

        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
                white++;
        }

        int Res = white;

        // W B W B B B W
        // 0 1 2 3 4 5 6

        for (int i = k; i < blocks.length(); i++)
        {
            if (blocks[i - k] == 'W')
            {
                white--;
            }

            if (blocks[i] == 'W')
            {
                white++;
            }

            Res = min(Res, white);
        }

        return Res;
    }
};