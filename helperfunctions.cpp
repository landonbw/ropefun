#include "helperfunctions.h"
#include <cmath>
#include <iostream>

helperfunctions::helperfunctions()
{

}

double helperfunctions::calculateColor(double value, helperfunctions::color to_calculate)
{
    double color{-1};
    if (to_calculate == helperfunctions::green)
    {
//        color = -2.5 * std::abs(value - 0.01) + 1.2;
        color = -3.5 * std::abs(value - 0.54) + 1.75;
    }
    else if (to_calculate == helperfunctions::blue)
    {
//        color = -2.5 * std::abs(value - 0.5) + 1.2;
        color = -3 * std::abs(value - 0.14) + 1.5;
    }
    else if (to_calculate == helperfunctions::red)
    {
//        color = -2.5 * std::abs(value - 0.99) + 1.2;
        color = -2. * std::abs(value - 1.15) + 1.68;
    }
    color = clip(color);
    return color;
}

double helperfunctions::clip(double val, double min, double max)
{
    if(min >= max)
    {
        return val;
    }

    if(val > max)
    {
        val = max;
    }
    else if (val < min)
    {
        val = min;
    }
    return val;
}
