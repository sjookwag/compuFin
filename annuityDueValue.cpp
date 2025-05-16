#include <iostream>
#include <vector>
#include <cmath> // For pow function

// Ordinary annuity with fixed rate
double annuityValue(const double payment, const double rate, const int periods) {
    if (rate == 0) return payment * periods;
    return payment * (1 - 1 / std::pow(1 + rate, periods)) / rate;
}

// Annuity due calculation
double annuityDueValue(const double payment, const double rate, const int periods) {
    return annuityValue(payment, rate, periods) * (1 + rate);
}

// Variable rate annuity calculation
double variableAnnuityValue(const double payment, const std::vector<double>& rates) {
    double PV = 0.0;
    for (size_t t = 1; t <= rates.size(); ++t) {
        PV += payment / std::pow(1 + rates[t - 1], t);
    }
    return PV;
}

int main() {
    constexpr double X = 100.0; // Fixed payment per period
    constexpr double r = 0.05;  // Fixed interest rate (5%)
    constexpr int T = 10;       // Number of periods

    const std::vector<double> rates = {0.05, 0.06, 0.07, 0.04, 0.05}; // Variable interest rates

    std::cout << "Present Value of Ordinary Annuity: " << annuityValue(X, r, T) << std::endl;
    std::cout << "Present Value of Annuity Due: " << annuityDueValue(X, r, T) << std::endl;
    std::cout << "Present Value of Variable Rate Annuity: " << variableAnnuityValue(X, rates) << std::endl;

    return 0;
}
