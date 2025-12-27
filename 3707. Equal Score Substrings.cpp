class Solution
{
public:
    bool scoreBalance(string s)
    {
        int left_score = 0, right_score = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int current_character = s[i] - 'a' + 1;
            right_score += current_character;
        }

        for (int i = 0; i < s.length(); i++)
        {
            int current_character = s[i] - 'a' + 1;
            left_score += current_character;
            right_score -= current_character;

            // cout<<"index: "<<i<<endl<<"left: "<<left_score<< " , right:
            // "<<right_score<<endl;

            if (left_score > right_score)
                return false;

            if (left_score == right_score)
                return true;
        }

        return false;
    }
};