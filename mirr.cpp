// The Modified Internal Rate of Return (MIRR) is a more reliable metric than IRR, 
// as it eliminates multiple IRRs and provides a realistic reinvestment assumption. 
// It is widely used in capital budgeting, investment analysis, and financial decision-making.
#include <iostream>
#include <vector>
#include <cmath>

double futureValue(const std::vector<double>& cashFlows, const double reinvestmentRate) {
    double FV = 0.0;
    for (size_t t = 0; t < cashFlows.size(); ++t) {
        if (cashFlows[t] > 0) {
            FV += cashFlows[t] * std::pow(1 + reinvestmentRate, cashFlows.size() - t);
        }
    }
    return FV;
}

double presentValue(const std::vector<double>& cashFlows, const double financingRate) {
    double PV = 0.0;
    for (size_t t = 0; t < cashFlows.size(); ++t) {
        if (cashFlows[t] < 0) {
            PV += cashFlows[t] / std::pow(1 + financingRate, t);
        }
    }
    return std::fabs(PV);
}

double computeMIRR(const std::vector<double>& cashFlows, const double reinvestmentRate, const double financingRate) {
    const double FV = futureValue(cashFlows, reinvestmentRate);
    const double PV = presentValue(cashFlows, financingRate);
    const int T = cashFlows.size() - 1;
    return std::pow(FV / PV, 1.0 / T) - 1;
}

int main() {
    const std::vector<double> cashFlows = {-1000, 200, 300, 500, 600}; // Example cash flows
    constexpr double reinvestmentRate = 0.05; // 5% reinvestment rate
    constexpr double financingRate = 0.07; // 7% financing rate

    double mirr = computeMIRR(cashFlows, reinvestmentRate, financingRate);
    std::cout << "Modified Internal Rate of Return (MIRR): " << mirr * 100 << "%" << std::endl;

    return 0;
}
