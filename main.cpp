#include <iostream>
#include "LinearRegression.h"

using namespace std;

int main() {
    LinearRegression lr;
    lr.addDataPoint(60, 3.1);
    lr.addDataPoint(61, 3.6);
    lr.addDataPoint(62, 3.8);
    lr.addDataPoint(63, 4.0);
    lr.addDataPoint(65, 4.1);
    lr.getReport();

    return 0;
}
