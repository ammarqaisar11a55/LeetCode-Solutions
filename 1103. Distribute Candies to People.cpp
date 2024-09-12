class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {

        vector<int> People(num_people, 0);
        vector<int> CandiesDistribution;

        int now = 1;
        while (candies > 0)
        {
            if (now <= candies)
            {
                candies -= now;
                CandiesDistribution.push_back(now);
            }
            else // jab canides kam hongi
            {
                now = candies;
                CandiesDistribution.push_back(now);
                break;
            }
            now++;
        }

        int i = 0;
        int j = 0;

        while (j < CandiesDistribution.size())
        {

            People[i % People.size()] += CandiesDistribution[j];
            i++;
            j++;
        }

        return People;
    }
};

class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {

        vector<int> People(num_people, 0);
        vector<int> CandiesDistribution;

        int now = 1;
        int i = 0;
        while (candies > 0)
        {
            if (now <= candies)
            {
                candies -= now;
                People[i % People.size()] += now;
            }
            else // jab canides kam hongi
            {
                now = candies;
                People[i % People.size()] += now;
                break;
            }
            now++;
            i++;
        }

        return People;
    }
};