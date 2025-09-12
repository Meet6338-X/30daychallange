#include <iostream>
#include <vector>
#include <iomanip>  // For std::scientific and std::setprecision

double fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    std::vector<double> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    // You can modify this list to include any test cases
    std::vector<int> testCases = {5, 10, 0, 1000};

    for (int n : testCases) {
        double result = fibonacci(n);
        std::cout << "Input: " << n << " Output: ";

        // Use scientific notation for large numbers like F(1000)
        if (n >= 100) {
            std::cout << std::setprecision(15) << std::scientific << result << std::endl;
        } else {
            std::cout << static_cast<long long>(result) << std::endl;
        }
    }

    return 0;
}