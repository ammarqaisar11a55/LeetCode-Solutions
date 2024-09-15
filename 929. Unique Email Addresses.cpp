class Solution
{
public:
    void Filteration(string &s)
    {
        int SymbolP = s.find('@');
        int PlusP = s.find('+');
        bool FoundAtSymbol = false;
        string modify;

        if (SymbolP == string::npos)
            return;

        for (int i = 0; i < s.length(); i++)
        {
            if ((PlusP != string::npos) && i >= PlusP && i < SymbolP)
            {
                continue;
            }
            else if (FoundAtSymbol)
            {
                modify.push_back(s[i]);
            }
            else if (s[i] == '@')
            {
                FoundAtSymbol = true;
                modify.push_back('@');
            }
            else
            {
                if (isalpha(s[i]))
                    modify.push_back(s[i]);
            }
        }

        s = modify;
    }

    //***************************
    int numUniqueEmails(vector<string> &emails)
    {

        unordered_set<string> Ans;

        for (int i = 0; i < emails.size(); i++)
        {
            Filteration(emails[i]);
            Ans.insert(emails[i]);
        }

        return Ans.size();
    }
};