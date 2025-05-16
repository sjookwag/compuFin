#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<double> computeIRRs(const std::vector<double>& cashFlows, const double initialGuess = 0.1, const double tolerance = 1e-6) {
    std::vector<double> irrSolutions;
    double rate = initialGuess;
    double delta = 1.0;

    while (std::fabs(delta) > tolerance) {
        double npv = 0.0, derivative = 0.0;
        for (size_t t = 0; t < cashFlows.size(); ++t) {
            npv += cashFlows[t] / std::pow(1 + rate, t);
            if (t > 0) derivative -= static_cast<double>(t) * cashFlows[t] / std::pow(1 + rate, t + 1);
        }

        if (std::fabs(derivative) < tolerance) break; // Avoid division by zero
        delta = npv / derivative;
        rate -= delta;

        if (std::fabs(npv) < tolerance) irrSolutions.push_back(rate);
    }

    return irrSolutions;
}

int main() {
    const std::vector<double> cashFlows = {-1000, 500, -200, 800}; // Example with multiple IRRs
    const std::vector<double> irrValues = computeIRRs(cashFlows);

    std::cout << "Possible IRRs: ";
    for (const double irr : irrValues) {
        std::cout << irr * 100 << "% ";
    }
    std::cout << std::endl;

    return 0;
}
