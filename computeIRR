#include <iostream>
#include <vector>
#include <cmath>

double computeNPV(const std::vector<double>& cashFlows, const double rate) {
    double NPV = 0.0;
    for (size_t t = 0; t < cashFlows.size(); ++t) {
        NPV += cashFlows[t] / std::pow(1 + rate, t);
    }
    return NPV;
}

double computeIRR(const std::vector<double>& cashFlows, const double initialGuess = 0.1, const double tolerance = 1e-6) {
    double rate = initialGuess;
    double delta = 1.0;

    while (std::fabs(delta) > tolerance) {
        const double npv = computeNPV(cashFlows, rate);
        double derivative = 0.0;

        for (size_t t = 1; t < cashFlows.size(); ++t) {
            derivative -= t * cashFlows[t] / std::pow(1 + rate, t + 1);
        }

        delta = npv / derivative;
        rate -= delta;
    }

    return rate;
}

int main() {
    const std::vector<double> cashFlows = {-1000, 200, 300, 500, 600};  // Example cash flows
    const double irr = computeIRR(cashFlows);
    
    std::cout << "Internal Rate of Return: " << irr * 100 << "%" << std::endl;
    return 0;
}
