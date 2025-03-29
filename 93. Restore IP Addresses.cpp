class Solution {
public:
void Solve(string s, string current_ip, int index, int used_dots, vector<string> &res)
{
    if (index >= s.length())
    {
        if (used_dots == 4)
            res.push_back(current_ip);

        return;
    }

    unsigned long long int current_number = 0;

    for (int i = index; i < s.length(); i++)
    {
        int current_digit = s[i] - '0';

        if(s[index]  == '0' && i > index)
            return;



        current_number = current_number * 10 + current_digit;

        if (current_number >= 0 && current_number <= 255 && used_dots < 4)
        {
            if (current_ip.empty() == false)
                Solve(s, current_ip + "." + to_string(current_number), i + 1, used_dots + 1, res);
            else
                Solve(s, to_string(current_number), i + 1, used_dots + 1, res);
        }
    }
}

    vector<string> restoreIpAddresses(string s) {
            vector<string> res;
    Solve(s, "", 0, 0, res);
    return res;
    }
};
