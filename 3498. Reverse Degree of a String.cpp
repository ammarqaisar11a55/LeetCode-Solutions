class Solution {
public:
    int reverseDegree(string s) {
     int res = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int current_character_val = 26 - (s[i] - 'a');
        res += (current_character_val * (1+i));
    }

    return res;   
    }
};
