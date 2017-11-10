#include"ball.h"
#include <iostream>
#include <vector>



void Ball::setPosition(std::vector<double> newPos){
    if (newPos.size() == 2){
        position = newPos;
    }
    else{
        std::cout << "newPos.size() is not 2, it is: "<< newPos.size() << std::endl;
        std::exit(-1);
    }
}

std::vector<double> Ball::getPosition(){
    return position;
}

void Ball::setPreviousPosition(std::vector<double> newPos){
    if (newPos.size() == 2){
        previousPosition = newPos;
    }
    else{
        std::cout << "newPos.size() is not 2, it is: "<< newPos.size() << std::endl;
        std::exit(-1);
    }
}

std::vector<double> Ball::getPreviousPosition(){
    return previousPosition;
}

void Ball::setVelocity(std::vector<double>newVel){
    if (newVel.size() == 2){
        velocity = newVel;
    }
    else{
        std::cout << "newVel.size() is not 2, it is: "<< newVel.size() << std::endl;
        std::exit(-1);
    }
}

std::vector<double> Ball::getVelocity(){
    return velocity;
}


void Ball::setMass(double newMass){
    if (newMass > 0){
        mass = newMass;
    }
    else{
        std::cout << "Invalid mass" << std::endl;
        std::exit(-1);
    }
}

double Ball::getMass(){
    return mass;
}


void Ball::setRadius(double newRadius){
    if (newRadius > 0){
        radius = newRadius;
    }
    else{
        std::cout << "Invalid radius" << std::endl;
        std::exit(-1);
    }
}

double Ball::getRadius(){
    return radius;
}

void Ball::setHasScored(bool newHasScored){
    hasScored = newHasScored;
}

bool Ball::getHasScored(){
    return hasScored;
}

