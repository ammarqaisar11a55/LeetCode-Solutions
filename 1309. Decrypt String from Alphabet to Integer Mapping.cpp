class Solution
{
public:
    string freqAlphabets(string s)
    {

        unordered_map<string, char> Mp;

        Mp["10"] = 'j';
        Mp["11"] = 'k';
        Mp["12"] = 'l';
        Mp["13"] = 'm';
        Mp["14"] = 'n';
        Mp["15"] = 'o';
        Mp["16"] = 'p';
        Mp["17"] = 'q';
        Mp["18"] = 'r';
        Mp["19"] = 's';
        Mp["20"] = 't';
        Mp["21"] = 'u';
        Mp["22"] = 'v';
        Mp["23"] = 'w';
        Mp["24"] = 'x';
        Mp["25"] = 'y';
        Mp["26"] = 'z';

        string ans;
        int skipalternations = 0;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (skipalternations != 0)
            {
                skipalternations--;
                continue;
            }

            if (i >= 2 && s[i] == '#')
            {
                string temp = s.substr(i - 2, 2);
                ans.push_back(Mp[temp]);
                skipalternations = 2;
                continue;
            }

            ans.push_back((s[i] - '1') + 'a');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};