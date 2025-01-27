class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {

        unordered_map<int, vector<int>> mp;

        int Metal_Max_Travel = -1, Paper_Max_Travel = -1, Glass_Max_Travel = -1;

        for (int i = 0; i < garbage.size(); i++)
        {
            int M_Count = 0;
            int P_Count = 0;
            int G_Count = 0;

            for (int j = 0; j < garbage[i].length(); j++)
            {
                M_Count += garbage[i][j] == 'M' ? 1 : 0;
                P_Count += garbage[i][j] == 'P' ? 1 : 0;
                G_Count += garbage[i][j] == 'G' ? 1 : 0;
            }

            Metal_Max_Travel = M_Count == 0 ? Metal_Max_Travel : i;
            Paper_Max_Travel = P_Count == 0 ? Paper_Max_Travel : i;
            Glass_Max_Travel = G_Count == 0 ? Glass_Max_Travel : i;

            mp[i].push_back(M_Count);
            mp[i].push_back(P_Count);
            mp[i].push_back(G_Count);
        }

        int Minimum_Time = 0;

        for (int i = 0; i <= Metal_Max_Travel; i++)
        {
            if (i == 0)
            {
                Minimum_Time += mp[i][0];
            }
            else
            {
                Minimum_Time += travel[i - 1];
                Minimum_Time += mp[i][0];
            }
        }

        for (int i = 0; i <= Paper_Max_Travel; i++)
        {
            if (i == 0)
            {
                Minimum_Time += mp[i][1];
            }
            else
            {
                Minimum_Time += travel[i - 1];
                Minimum_Time += mp[i][1];
            }
        }

        for (int i = 0; i <= Glass_Max_Travel; i++)
        {
            if (i == 0)
            {
                Minimum_Time += mp[i][2];
            }
            else
            {
                Minimum_Time += travel[i - 1];
                Minimum_Time += mp[i][2];
            }
        }

        return Minimum_Time;
    }
};