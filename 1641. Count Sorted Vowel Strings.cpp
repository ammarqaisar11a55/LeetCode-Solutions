// Approach 1: TLE

class Solution
{
public:
    void Backtrack(string current, int target_length, int index, string &vowels, int &ans)
    {
        if (current.length() == target_length)
        {
            ans++;
            return;
        }

        for (int i = index; i < vowels.length(); i++)
        {

            Backtrack(current + vowels[i], target_length, i, vowels, ans);
        }
    }

    int countVowelStrings(int n)
    {
        string vowels = "aeiou";
        int ans = 0;
        Backtrack("", n, 0, vowels, ans);
        return ans;
    }
};

/*Approach 2: Upadting length instead of appending the characters*/

class Solution
{
public:
    void Backtrack(int current_length, int target_length, int index, string &vowels, int &ans)
    {
        if (current_length == target_length)
        {
            ans++;
            return;
        }

        for (int i = index; i < vowels.length(); i++)
        {
            Backtrack(current_length + 1, target_length, i, vowels, ans);
        }
    }

    int countVowelStrings(int n)
    {
        string vowels = "aeiou";
        int ans = 0;
        Backtrack(0, n, 0, vowels, ans);
        return ans;
    }
};