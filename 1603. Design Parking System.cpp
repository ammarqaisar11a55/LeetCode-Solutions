
class ParkingSystem
{
public:
    int big_cars;
    int medium_cars;
    int small_cars;

    ParkingSystem(int big, int medium, int small)
    {
        big_cars = big;
        medium_cars = medium;
        small_cars = small;
    }

    bool addCar(int carType)
    {
        if (carType == 1)
        {
            if (big_cars > 0)
            {
                big_cars--;
                return true;
            }

            return false;
        }

        if (carType == 2)
        {
            if (medium_cars > 0)
            {
                medium_cars--;
                return true;
            }

            return false;
        }

        if (carType == 3)
        {
            if (small_cars > 0)
            {
                small_cars--;
                return true;
            }

            return false;
        }

        return NULL;
    }
};
