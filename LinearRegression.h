#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <iostream> // Needed for cout and endl


class LinearRegression {
    int DataPoints;
    float sumX;
    float sumY;
    float sumXX;
    float sumXY;

public:

    LinearRegression() {
        DataPoints = 0;
        sumX = 0;
        sumY = 0;
        sumXX = 0;
        sumXY = 0;
    }

    void addDataPoint(float newX, float newY) {
        sumX += newX;
        sumY += newY;
        sumXX += (newX * newX);
        sumXY += (newX * newY);
        DataPoints += 1;
    }

    // Todo move getSlope and getIntercept to getLinearLine 
    //   getLinearLine should be a struct with slope and intercept
    float getSlope() {        
        const auto partA = (DataPoints * sumXY) - (sumX * sumY);
        const auto partB = (DataPoints * sumXX) - (sumX * sumX);
        return (partB == 0.0f) ? 0 : (partA / partB);
    };

    float getIntercept() {
        return (sumY - (this->getSlope()*sumX)) / DataPoints;
    }

    // Todo Move getReport to external
    void getReport() {
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
};


#endif // LINEARREGRESSION_H
