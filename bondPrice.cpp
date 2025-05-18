#include <iostream>
#include <cmath>

double bondPrice(const double faceValue, const double coupon, const double rate, const int years) {
    double price = 0.0;
    for (int t = 1; t <= years; ++t) {
        price += coupon / std::pow(1 + rate, t);
    }
    price += faceValue / std::pow(1 + rate, years);
    return price;
}

int main() {
    const double F = 100;  // Face value
    const double C = 10;    // Annual coupon payment
    const double r = 0.09;  // Interest rate
    const int T = 3;       // Maturity period

    const double P = bondPrice(F, C, r, T);
    std::cout << "Bond Price: " << P << std::endl;

    return 0;
}
