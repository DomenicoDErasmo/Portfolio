class ParkingSystem 
{
public:
    ParkingSystem(int big, int medium, int small) 
    {
        big_ = big;
        medium_ = medium;
        small_ = small;
    }
    
    bool addCar(int carType) 
    {
        switch(carType)
        {
            case 1:
                if (big_current < big_)
                {
                    big_current++;
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            case 2:
                if (medium_current < medium_)
                {
                    medium_current++;
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            case 3:
                if (small_current < small_)
                {
                    small_current++;
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            default:
                return false;
                break;
        }
    }
private:
    int big_=0, medium_=0, small_=0;
    int big_current = 0, medium_current = 0, small_current = 0;
};
