class Solution
{
public:
    void Solve(int size, string &res, string word)
    {
        if (word.size() >= size)
        {
            if (res.empty() == true)
            {
                res = word;
            }
            return;
        }

        string temp = word;

        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] == 'z')
            {
                temp[i] = 'a';
            }
            else
            {
                temp[i] = temp[i] + 1;
            }
        }

        if (res.empty() == false)
            return;

        Solve(size, res, word + temp);
    }

    char kthCharacter(int k)
    {

        string generatedstring;
        Solve(k, generatedstring, "a");

        cout << generatedstring << endl;

        return generatedstring[k - 1];
    }
};