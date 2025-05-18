#include <iostream>
#include <vector>
#include <cmath>

struct CashFlow {
    double amount;
    int time;
};

double bond_price(const std::vector<CashFlow>& cash_flows, const double rate) {
    double price = 0.0;
    for (const auto& cf : cash_flows) {
        price += cf.amount / std::pow(1 + rate, cf.time);
    }
    return price;
}

double macaulay_duration(const std::vector<CashFlow>& cash_flows, const double rate) {
    double weighted_sum = 0.0;
    double price = bond_price(cash_flows, rate);

    for (const auto& cf : cash_flows) {
        weighted_sum += cf.time * (cf.amount / std::pow(1 + rate, cf.time));
    }

    return weighted_sum / price;
}

int main() {
    const std::vector<CashFlow> cash_flows = {{10, 1}, {10, 2}, {110, 3}};
    const double rate = 0.09; // Flat interest rate

    std::cout << "Bond Price: " << bond_price(cash_flows, rate) << std::endl;
    std::cout << "Macaulay Duration: " << macaulay_duration(cash_flows, rate) << std::endl;

    return 0;
}
