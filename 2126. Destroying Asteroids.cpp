class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {

        sort(asteroids.begin(), asteroids.end());

        unsigned long long int newmass = mass;

        for (int i = 0; i < asteroids.size(); i++)
        {
            if (newmass >= asteroids[i])
            {
                newmass += asteroids[i];
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};