class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {

        int b = 0;
        int a = 0;
        int l = 0;
        int o = 0;
        int n = 0;

        int count = 0;

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == 'b')
            {
                b++;
                continue;
            }

            if (text[i] == 'a')
            {
                a++;
                continue;
            }

            if (text[i] == 'l')
            {
                l++;
                continue;
            }

            if (text[i] == 'o')
            {
                o++;
                continue;
            }

            if (text[i] == 'n')
            {
                n++;
                continue;
            }
        }

        while (b >= 1 && a >= 1 && l >= 2 && o >= 2 && n >= 1)
        {
            count++;
            b--;
            a--;
            l -= 2;
            o -= 2;
            n--;
        }

        return count;
    }
};