#ifndef TEMPTABLE_H
#define TEMPTABLE_H

#include <vector>

class TempTable
{
private:
    std::vector<double> offset;
    double width;
    double length;
    std::vector<std::vector<double>> cornerCoordinates;
    double cornerRadius;

public:
    void setOffset(std::vector<double>);
    std::vector<double> getOffset();
    void setWidth(double);
    double getWidth();
    void setLength(double);
    double getLength();
    void setCornerCoordinates(std::vector<std::vector<double>>);
    std::vector<std::vector<double>> getCornerCoordinates();
    void setCornerRadius(double);
    double getCornerRadius();
};

#endif // TEMPTABLE_H
