#include<iostream>
#include <vector>
using namespace std;

int knapsack(int C, vector<int>& weight, vector<int>& value) {

    int n = weight.size();

    // dp[i][w] = maximum value using first i items
    // with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= n; i++) {

        for (int w = 0; w <= C; w++) {

            // Don't take the current item
            dp[i][w] = dp[i - 1][w];//Current item ko hata do, aur sirf previous i-1 items se best answer lo.
            // First i items use karke capacity w mein maximum value.

            // Take the current item if it fits
            if (weight[i - 1] <= w) {
                //Kya current item ki weight current capacity mein fit ho rahi hai?
                dp[i][w] = max(
                    dp[i][w],
                    value[i - 1] +
                    dp[i - 1][w - weight[i - 1]]
                );
//                 Don't Take = dp[i-1][w]

//                 Take = value[i-1] + dp[i-1][w-weight[i-1]]
            }
        }
    }

    return dp[n][C];
}

int main() {

    vector<int> weight = {1, 3, 4, 5};
    vector<int> value = {1, 4, 5, 7};

    int C = 7;

    cout << knapsack(C, weight, value) << endl;

    return 0;
}


//                     ┌── Don't Take
//                     │
// dp[i][w] = max(     │
//                     │
//                     └── Take

//0-1 Knapsack code