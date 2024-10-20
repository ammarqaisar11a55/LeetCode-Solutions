class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {

        stack<int> sk;

        for (int i = 0; i < asteroids.size(); i++)
        {
            bool destroyed = false;

            while (sk.empty() == false && sk.top() > 0 && asteroids[i] < 0)
            {
                int stacktop = sk.top();

                if (abs(stacktop) == abs(asteroids[i]))
                {
                    destroyed = true;
                    sk.pop();
                    break;
                }
                else if (abs(stacktop) < abs(asteroids[i]))
                {
                    sk.pop();
                }
                else
                {
                    destroyed = true;
                    break;
                }
            }

            if (destroyed == false)
            {
                sk.push(asteroids[i]);
            }
        }

        asteroids.clear();
        asteroids.shrink_to_fit();

        while (sk.empty() == false)
        {
            asteroids.push_back(sk.top());
            sk.pop();
        }

        reverse(asteroids.begin(), asteroids.end());

        return asteroids;
    }
};