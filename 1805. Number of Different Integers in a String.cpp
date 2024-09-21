class Solution
{
public:
    int numDifferentIntegers(string word)
    {

        unordered_set<string> st;
        string single;
        string forZeros;
        int countzeros = 0;

        for (int i = 0; i < word.size(); i++)
        {
            if (isdigit(word[i]))
            {
                if (word[i] == '0')
                    countzeros++;

                forZeros.push_back(word[i]);

                if (single.empty() && word[i] == '0')
                {
                    continue;
                }
                else
                {
                    single.push_back(word[i]);
                }
            }
            else
            {
                if (!single.empty())
                {
                    st.insert(single);
                    single.clear();
                }

                if (!forZeros.empty() && countzeros == forZeros.length())
                {
                    string temp = "0";
                    st.insert(temp);
                    forZeros.clear();
                    countzeros = 0;
                }

                countzeros = 0;
                forZeros.clear();
            }
        }

        if (!single.empty())
        {
            st.insert(single);
            single.clear();
        }

        if (!forZeros.empty() && countzeros == forZeros.length())
        {
            st.insert("0");
            forZeros.clear();
            countzeros = 0;
        }

        return st.size();
    }
};