#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <iostream> // Needed for cout and endl

class LinearRegression {
    int DataPoints;
    int slopeCacheValid;
    float slopeCacheValue;
    float sumX;
    float sumY;
    float sumXX;
    float sumXY;
public:
    LinearRegression();
    void addDataPoint(float, float);
    float getSlope();
    float getIntercept();
    void getReport();
};


#endif // LINEARREGRESSION_H
