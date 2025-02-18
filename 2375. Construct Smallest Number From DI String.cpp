class Solution
{
public:
    void Solve(int index, string &pattern, string current, string &Res, vector<bool> &Used)
    {
        if (current.length() == pattern.length() + 1)
        {
            if (Res.empty() || current < Res)
            {
                Res = current;
            }
            return;
        }

        for (int i = 1; i <= 9; i++)
        {
            if (Used[i])
            {
                continue;
            }

            if (index == 0)
            {
                current.push_back((i + '0'));
                Used[i] = true;

                Solve(index + 1, pattern, current, Res, Used);

                current.pop_back();
                Used[i] = false;
            }
            else
            {
                if (pattern[index - 1] == 'I')
                {
                    if (current.back() - '0' < i)
                    {
                        Used[i] = true;
                        current.push_back(i + '0');

                        Solve(index + 1, pattern, current, Res, Used);

                        Used[i] = false;
                        current.pop_back();
                    }
                }
                else if (pattern[index - 1] == 'D')
                {
                    if (current.back() - '0' > i)
                    {
                        Used[i] = true;
                        current.push_back(i + '0');

                        Solve(index + 1, pattern, current, Res, Used);

                        Used[i] = false;
                        current.pop_back();
                    }
                }
            }
        }
    }

    string smallestNumber(string pattern)
    {
        string Res;
        vector<bool> Used(10, false);
        Solve(0, pattern, "", Res, Used);
        return Res;
    }
};

/*Optimized:*/

class Solution
{
public:
    bool Solve(int index, string &pattern, string current, string &Res, vector<bool> &Used)
    {
        if (current.length() == pattern.length() + 1)
        {
            Res = current;
            return true;
        }

        for (int i = 1; i <= 9; i++)
        {
            if (Used[i])
            {
                continue;
            }

            if (index == 0)
            {
                current.push_back((i + '0'));
                Used[i] = true;

                if (Solve(index + 1, pattern, current, Res, Used))
                    return true;

                current.pop_back();
                Used[i] = false;
            }
            else
            {
                if (pattern[index - 1] == 'I')
                {
                    if (current.back() - '0' < i)
                    {
                        Used[i] = true;
                        current.push_back(i + '0');

                        if (Solve(index + 1, pattern, current, Res, Used))
                            return true;

                        Used[i] = false;
                        current.pop_back();
                    }
                }
                else if (pattern[index - 1] == 'D')
                {
                    if (current.back() - '0' > i)
                    {
                        Used[i] = true;
                        current.push_back(i + '0');

                        if (Solve(index + 1, pattern, current, Res, Used))
                            return true;

                        Used[i] = false;
                        current.pop_back();
                    }
                }
            }
        }

        return false;
    }

    string smallestNumber(string pattern)
    {
        string Res;
        vector<bool> Used(10, false);
        Solve(0, pattern, "", Res, Used);
        return Res;
    }
};