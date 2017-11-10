#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <vector>

class Ball
{
private:
    std::vector<double> position;
    std::vector<double> previousPosition;
    std::vector<double> velocity;
    double mass;
    double radius;
    bool hasScored;
public:
    void setPosition(std::vector<double>);
    std::vector<double> getPosition();
    void setPreviousPosition(std::vector<double>);
    std::vector<double> getPreviousPosition();
    void setVelocity(std::vector<double>);
    std::vector<double> getVelocity();
    void setMass(double);
    double getMass();
    void setRadius(double);
    double getRadius();
    void setHasScored(bool);
    bool getHasScored();
};


#endif // BALL_H_INCLUDED
