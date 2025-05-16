#include <iostream>
#include <cmath> // For pow function

double annuityValue(const double payment, const double rate, const int periods) {
    if (rate == 0) {
        return payment * periods; // If interest rate is zero, PV is simply sum of payments
    }
    return payment * (1 - 1 / std::pow(1 + rate, periods)) / rate;
}

int main() {
    constexpr double X = 100.0; // Fixed payment per period
    constexpr double r = 0.05;  // Interest rate (5%)
    constexpr int T = 10;       // Number of periods

    const double PV = annuityValue(X, r, T);
    std::cout << "Present Value of Annuity: " << PV << std::endl;

    return 0;
}
