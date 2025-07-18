#include "arithmeticAverage.hpp"
#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& v1, const std::vector<int>& v2) {
    double ave = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0, std::plus<int>(), std::plus<int>());

    return ave / (v1.size() + v2.size());
}

double Distance(const std::vector<int>& v1, const std::vector<int>& v2) {
    int result = std::inner_product(v1.begin(),
                                    v1.end(),
                                    v2.begin(),
                                    0,
                                    std::plus<int>(),
                                    [](const auto& e1, const auto& e2) {
                                        return std::pow(e1 - e2, 2);
                                    });
    return std::sqrt(result);
}