class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        
        int steps = 0;
    int initial = capacity;

    for (int i = 0; i < plants.size(); i++)
    {
        if (plants[i] <= capacity)
        {
            steps++;
            capacity -= plants[i];
            continue;
        }
        else if (capacity < plants[i])
        {
            // Refilling the can:
            capacity = initial;
            // Back to River:
            steps += i;
            // Back to Plant:
            steps += i;

            //Watering the same plant again:
            --i;
        }
    }

    return steps;
        
    }
};