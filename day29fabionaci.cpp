#include <iostream>
#include <vector>
#include <iomanip>  // for scientific notation

double fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    std::vector<double> dp(n + 1);  // using double to handle large numbers
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;

    // Test cases
    std::vector<int> testCases = {5, 10, 0, 1000};

    for (int n : testCases) {
        double result = fibonacci(n);
        std::cout << "Input: " << n << "\n";
        std::cout << "Output: " << std::setprecision(15) << std::scientific << result << "\n\n";
    }

    return 0;
}