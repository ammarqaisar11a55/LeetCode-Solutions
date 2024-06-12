class Solution
{
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {

        unordered_map<char, int> values;

        values['a'] = 0;
        values['b'] = 1;
        values['c'] = 2;
        values['d'] = 3;
        values['e'] = 4;
        values['f'] = 5;
        values['g'] = 6;
        values['h'] = 7;
        values['i'] = 8;
        values['j'] = 9;
        values['k'] = 10;
        values['l'] = 11;
        values['m'] = 12;
        values['n'] = 13;
        values['o'] = 14;
        values['p'] = 15;
        values['q'] = 16;
        values['r'] = 17;
        values['s'] = 18;
        values['t'] = 19;
        values['u'] = 20;
        values['v'] = 21;
        values['w'] = 22;
        values['x'] = 23;
        values['y'] = 24;
        values['z'] = 25;

        int first = 0;
        int second = 0;
        int target = 0;

        for (int i = 0; i < firstWord.length(); i++)
        {
            first = first * 10 + values[firstWord[i]];
        }

        for (int i = 0; i < secondWord.length(); i++)
        {
            second = second * 10 + values[secondWord[i]];
        }

        for (int i = 0; i < targetWord.length(); i++)
        {
            target = target * 10 + values[targetWord[i]];
        }

        return first + second == target;
    }
};