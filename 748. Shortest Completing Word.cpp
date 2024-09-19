class Solution
{
public:
    bool isShortest(string s, unordered_map<char, int> &Plate_Mp, unordered_set<char> CharactersofPlate)
    {
        unordered_map<char, int> Temp;

        for (char c : s)
            Temp[c]++;

        for (auto x = CharactersofPlate.begin(); x != CharactersofPlate.end(); x++)
        {
            if (Plate_Mp[*x] > Temp[*x])
                return false;
        }

        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {

        unordered_map<char, int> Plate_Mp;
        unordered_set<char> CharactersofPlate;

        for (int i = 0; i < licensePlate.length(); i++)
        {
            if (isdigit(licensePlate[i]) || licensePlate[i] == ' ')
                continue;

            if (isupper(licensePlate[i]))
            {
                CharactersofPlate.insert(tolower(licensePlate[i]));
                Plate_Mp[tolower(licensePlate[i])]++;
            }
            else
            {
                CharactersofPlate.insert(licensePlate[i]);
                Plate_Mp[licensePlate[i]]++;
            }
        }

        int MinLength = INT_MAX;
        string Ans;

        for (int i = 0; i < words.size(); i++)
        {

            if (isShortest(words[i], Plate_Mp, CharactersofPlate))
            {

                if (words[i].length() < MinLength)
                {
                    Ans = words[i];
                    MinLength = words[i].length();
                }
            }
        }
        return Ans;
    }
};