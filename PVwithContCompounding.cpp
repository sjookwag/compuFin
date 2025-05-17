#include <iostream>
#include <cmath> // For exp() function

double presentValue(const double futureValue, const double rate, const int periods) {
    return futureValue * std::exp(-rate * periods);
}

int main() {
    constexpr double FV = 1000.0; // Future Value
    constexpr double rate = 0.05; // Interest rate (5%)
    constexpr int T = 5; // Number of periods (years)

    const double PV = presentValue(FV, rate, T);
    std::cout << "Present Value with Continuous Compounding: " << PV << std::endl;

    return 0;
}
