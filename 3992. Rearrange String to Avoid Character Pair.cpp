class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        string res;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == y)
            {
                res += s[i];
                s[i] = '-';
            }
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != '-')
            {
                res.push_back(s[i]);
            }
        }
        
        
        return res;
        
    }
};