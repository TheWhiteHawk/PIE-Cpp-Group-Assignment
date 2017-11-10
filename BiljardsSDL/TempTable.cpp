#include "TempTable.h"
#include <iostream>
#include <vector>

void TempTable::setOffset(std::vector<double> newOffset){
    if (newOffset.size() == 2){
        offset = newOffset;
    }
    else{
        std::cout << "newOffset.size() is not 2, it is: "<< newOffset.size() << std::endl;
        std::exit(-1);
    }
}

std::vector<double> TempTable::getOffset(){
    return offset;
}

void TempTable::setWidth(double newWidth){
    if (newWidth > 0){
        width = newWidth;
    }
    else{
        std::cout << "newWidth is <= 0, not a positive number" << std::endl;
        std::exit(-1);
    }
}

double TempTable::getWidth(){
    return width;
}

void TempTable::setLength(double newLength){
    if (newLength > 0){
        length = newLength;
    }
    else{
        std::cout << "newLength is <= 0, not a positive number" << std::endl;
        std::exit(-1);
    }
}

double TempTable::getLength(){
    return length;
}

void TempTable::setCornerCoordinates(std::vector<std::vector<double>> newCornerCoordinates){
    int rowNumber = newCornerCoordinates.size();
    if (rowNumber == 12){
        bool correctDimension = true;
        for (int i = 0; i < rowNumber; i++){
            if (newCornerCoordinates[i].size() != 2){
                correctDimension = false;
            }
        }
        if (correctDimension){
            cornerCoordinates = newCornerCoordinates;
        }
        else{
            std::cout << "Not all elements of newCornerCoordinates have a dimension of 2" << std::endl;
            std::exit(-1);
        }
    }
    else{
        std::cout << "Number of coordinate vectors is not 12, it is: " << rowNumber << std::endl;
        std::exit(-1);
    }
}

std::vector<std::vector<double>> TempTable::getCornerCoordinates(){
    return cornerCoordinates;
}

void TempTable::setCornerRadius(double newCornerRadius){
    if (newCornerRadius> 0){
        cornerRadius = newCornerRadius;
    }
    else{
        std::cout << "newCornerRadius is <= 0, not a positive number" << std::endl;
        std::exit(-1);
    }
}

double TempTable::getCornerRadius(){
    return cornerRadius;
}







