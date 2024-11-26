class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {

        unordered_set<int> st;

        for (int i = 0; i < n; i++)
        {
            st.insert(i);
        }

        for (vector<int> Edge : edges)
        {
            if (st.find(Edge[1]) != st.end())
            {
                st.erase(Edge[1]);
            }
        }

        return st.size() == 1 ? *(st.begin()) : -1;
    }
};