/*Approach 1 : Time Limit Exceed*/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        sort(p.begin(), p.end());
        vector<int> res;

        string current_substring;

        for (int i = 0; i < p.length(); i++)
        {
            current_substring += s[i];
        }

        string temp = current_substring;
        sort(temp.begin(), temp.end());

        if (p == temp)
        {
            res.push_back(0);
        }

        for (int i = p.length(); i < s.length(); i++)
        {
            reverse(current_substring.begin(), current_substring.end());
            current_substring.pop_back();
            reverse(current_substring.begin(), current_substring.end());
            current_substring.push_back(s[i]);

            string temp = current_substring;
            sort(temp.begin(), temp.end());

            if (temp == p)
                res.push_back(i - current_substring.length() + 1);
        }

        return res;
    }
};

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        unordered_map<char, int> Given_P_Map, Window_Map;

        for (char c : p)
            Given_P_Map[c]++;

        for (int i = 0; i < p.length(); i++)
        {
            Window_Map[s[i]]++;
        }

        if (Window_Map == Given_P_Map)
        {
            res.push_back(0);
        }

        for (int i = p.length(); i < s.length(); i++)
        {
            Window_Map[s[i]]++;

            Window_Map[s[i - p.length()]]--;

            if (Window_Map[s[i - p.length()]] == 0)
            {
                Window_Map.erase(s[i - p.length()]);
            }

            if (Window_Map == Given_P_Map)
                res.push_back(i - p.length() + 1);
        }

        return res;
    }
};