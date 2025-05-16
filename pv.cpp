#include <iostream>
#include <cmath> // For pow function

double presentValue(const double futureValue, const double rate, const int periods) {
    return futureValue / std::pow(1 + rate, periods);
}

int main() {
    constexpr double FV = 1000.0; // Future Value
    constexpr double rate = 0.05; // Annual interest rate (5%)
    constexpr int periods = 5; // Number of periods (years)

    const double PV = presentValue(FV, rate, periods);
    std::cout << "Present Value: " << PV << std::endl;

    return 0;
}
