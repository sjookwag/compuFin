#include <iostream>
#include <stdexcept> // For handling errors

double growingPerpetuityValue(const double payment, const double rate, const double growth) {
    if (rate <= growth) {
        throw std::invalid_argument("Interest rate must be greater than growth rate.");
    }
    return payment / (rate - growth);
}

int main() {
    try {
        constexpr double g = 0.03;
        constexpr double r = 0.07;
        constexpr double X = 100.0;
        const double PV = growingPerpetuityValue(X, r, g);
        std::cout << "Present Value of Growing Perpetuity: " << PV << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
