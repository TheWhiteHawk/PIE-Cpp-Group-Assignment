#include"ball.h"
#include <iostream>
#include <vector>


// Set the ball position of the ball and check its size.
void Ball::setPosition(std::vector<double> newPos){
    if (newPos.size() == 2){
        position = newPos;
    }
    else{
        std::cout << "newPos.size() is not 2, it is: "<< newPos.size() << std::endl;
        std::exit(-1);
    }
}

// Get the ball position of the ball.
std::vector<double> Ball::getPosition(){
    return position;
}

// Set the previous ball position of the ball and check its size.
void Ball::setPreviousPosition(std::vector<double> newPos){
    if (newPos.size() == 2){
        previousPosition = newPos;
    }
    else{
        std::cout << "newPos.size() is not 2, it is: "<< newPos.size() << std::endl;
        std::exit(-1);
    }
}

//Get the previous ball position of the ball and check its size.
std::vector<double> Ball::getPreviousPosition(){
    return previousPosition;
}

// Set the ball velocity of the ball and check its size.
void Ball::setVelocity(std::vector<double>newVel){
    if (ballNumber > -1) {
        if (newVel.size() == 2){
            velocity = newVel;
        }
        else{
            std::cout << "newVel.size() is not 2, it is: "<< newVel.size() << std::endl;
            std::exit(-1);
        }
    }
}

// Get the ball velocity of the ball.
std::vector<double> Ball::getVelocity(){
    return velocity;
}

// Set the mass of the ball and check its sign
void Ball::setMass(double newMass){
    if (newMass > 0){
        mass = newMass;
    }
    else{
        std::cout << "Invalid mass" << std::endl;
        std::exit(-1);
    }
}

// Get the mass of the ball
double Ball::getMass(){
    return mass;
}

//Set the radius of the ball and check its sign
void Ball::setRadius(double newRadius){
    if (newRadius > 0){
        radius = newRadius;
    }
    else{
        std::cout << "Invalid radius" << std::endl;
        std::exit(-1);
    }
}

//get the radius of the ball
double Ball::getRadius(){
    return radius;
}

//set the hasScored bool of the ball
void Ball::setHasScored(bool newHasScored){
    hasScored = newHasScored;
}

//get the hasScored bool of the ball
bool Ball::getHasScored(){
    return hasScored;
}

//set the ball number if number is larger tan -2
void Ball::setBallNumber(int newBallNumber){
    if (newBallNumber > -2){
        ballNumber = newBallNumber;
    }
    else{
        std::cout << "ballNumber cannot be smaller than -1" << std::endl;
        std::exit(-1);
    }
}

//get the ball number
int Ball::getBallNumber(){
    return ballNumber;
}



