class Solution
{
public:
    int differences(string q, string dicword)
    {
        int diff = 0;

        for (int i = 0; i < q.length(); i++)
        {
            if (q[i] != dicword[i])
                diff++;
        }

        return diff;
    }

    bool SearchInDic(string q, vector<string> Dict)
    {

        for (int i = 0; i < Dict.size(); i++)
        {
            if (differences(q, Dict[i]) <= 2)
                return true;
        }

        return false;
    }

    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {

        vector<string> Ans;

        for (int i = 0; i < queries.size(); i++)
        {
            if (SearchInDic(queries[i], dictionary))
                Ans.push_back(queries[i]);
        }

        return Ans;
    }
};