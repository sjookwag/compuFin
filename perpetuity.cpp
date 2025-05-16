#include <iostream>

double perpetuityValue(const double payment, const double rate) {
    if (rate == 0) {
        throw std::invalid_argument("Interest rate cannot be zero for perpetuity.");
    }
    return payment / rate;
}

int main() {
    try {
        constexpr double r = 0.05;
        constexpr double X = 100.0;
        const double PV = perpetuityValue(X, r);
        std::cout << "Present Value of Perpetuity: " << PV << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
