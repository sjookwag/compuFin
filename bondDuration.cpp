#include <iostream>
#include <cmath> // For pow function

double bondPrice(const double faceValue, const double coupon, const double rate, const int years) {
    double price = 0.0;
    for (int t = 1; t <= years; ++t) {
        price += coupon / std::pow(1 + rate, t);
    }
    price += faceValue / std::pow(1 + rate, years);
    return price;
}

double bondDuration(const double faceValue, const double coupon, const double rate, const int years) {
    const double price = bondPrice(faceValue, coupon, rate, years);
    double duration = 0.0;

    for (int t = 1; t <= years; ++t) {
        duration += t * (coupon / std::pow(1 + rate, t));
    }
    duration += years * (faceValue / std::pow(1 + rate, years));

    return duration / price;
}

int main() {
    const double F = 1000.0;  // Face value
    const double C = 50.0;    // Annual coupon payment
    const double r = 0.05;    // Yield to maturity (5%)
    const int T = 10;         // Maturity period

    const double D = bondDuration(F, C, r, T);
    std::cout << "Bond Duration: " << D << " years" << std::endl;

    return 0;
}
