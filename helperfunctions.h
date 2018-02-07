#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H


class helperfunctions
{
public:
    helperfunctions();
    enum color{red, green, blue};
    static double calculateColor(double value, color to_calculate);
    static double clip(double val, double min=0, double max=1);
};

#endif // HELPERFUNCTIONS_H
