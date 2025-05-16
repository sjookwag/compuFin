#include <iostream>
#include <vector>
#include <cmath> // For pow function

double variablePerpetuityValue(const double payment, const std::vector<double>& rates) {
    double PV = 0.0;
    for (size_t t = 1; t <= rates.size(); ++t) {
        PV += payment / std::pow(1 + rates[t - 1], t);
    }
    return PV;
}

int main() {
    const double X = 100.0; // Fixed payment
    const std::vector<double> rates = {0.05, 0.06, 0.07, 0.04, 0.05}; // Variable interest rates over periods

    const double PV = variablePerpetuityValue(X, rates);
    std::cout << "Present Value of Variable Perpetuity: " << PV << std::endl;

    return 0;
}
