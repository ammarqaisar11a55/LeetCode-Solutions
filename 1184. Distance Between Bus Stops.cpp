class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {

        int clockwise = 0;
        int anticlockwise = 0;

        for (int i = start; i != destination; i = (i + 1) % distance.size())
            clockwise += distance[i];

        for (int i = destination; i != start; i = (i + 1) % distance.size())
            anticlockwise += distance[i];

        return clockwise < anticlockwise ? clockwise : anticlockwise;
    }
};