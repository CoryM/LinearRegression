#include "LinearRegression.h"

LinearRegression::LinearRegression() {
    DataPoints = 0;
    sumX = 0;
    sumY = 0;
    sumXX = 0;
    sumXY = 0;
    slopeCacheValid = false;
    slopeCacheValue = 0;
}

void LinearRegression::addDataPoint(float newX, float newY) {
    sumX += newX;
    sumY += newY;
    sumXX += (newX * newX);
    sumXY += (newX * newY);
    DataPoints += 1;
    slopeCacheValid = false;
}

float LinearRegression::getSlope() {
    if (slopeCacheValid == false) {
        float partA, partB;

        partA = (DataPoints * sumXY) - (sumX * sumY);
        partB = (DataPoints * sumXX) - (sumX * sumX);
        if (partB == 0.0f) {
            slopeCacheValue = 0;
        } else {
            slopeCacheValue = (partA / partB);
        }
        slopeCacheValid = true;
    }
    return slopeCacheValue;
};

float LinearRegression::getIntercept() {
    return (sumY - (this->getSlope()*sumX)) / DataPoints;
}

void LinearRegression::getReport() {
    using std::cout;
    using std::endl;
    cout << "Number of DataPoints " << DataPoints << endl;
    cout << "Sum of all X's " << sumX << endl;
    cout << "Sum of all Y's " << sumY << endl;
    cout << "Sum of all X*X's " << sumXX << endl;
    cout << "Sum of all X*Y's " << sumXY << endl;
    cout << "Slope of line " << this->getSlope() << endl;
    cout << "Intercept of line " << this->getIntercept() << endl;
}
