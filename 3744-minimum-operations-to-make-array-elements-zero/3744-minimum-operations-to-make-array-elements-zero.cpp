#include <vector>
#include <algorithm>

class Solution {
private:
    // Helper function to calculate the sum of costs from 1 to n
    // without using any extra storage.
    long long calculate_total_cost(int n) {
        if (n <= 0) {
            return 0;
        }
        
        long long total_cost = 0;
        long long power_of_4 = 1;
        int cost_level = 0;

        // Loop through full blocks of numbers with the same cost.
        // e.g., numbers from 4-15 (cost 2), 16-63 (cost 3), etc.
        while (power_of_4 * 4 <= n && power_of_4 * 4 > 0) { // check for overflow
            long long next_power_of_4 = power_of_4 * 4;
            cost_level++;
            total_cost += cost_level * (next_power_of_4 - power_of_4);
            power_of_4 = next_power_of_4;
        }

        // Add the cost for the remaining partial block up to n.
        cost_level++;
        total_cost += cost_level * (n - power_of_4 + 1);

        return total_cost;
    }

public:
    long long minOperations(std::vector<std::vector<int>>& queries) {
        if (queries.empty()) {
            return 0;
        }

        long long total_operations = 0;
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum_of_costs_r = calculate_total_cost(r);
            long long sum_of_costs_l_minus_1 = calculate_total_cost(l - 1);
            
            long long sum_of_costs = sum_of_costs_r - sum_of_costs_l_minus_1;
            
            total_operations += (sum_of_costs + 1) / 2;
        }

        return total_operations;
    }
};