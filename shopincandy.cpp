class Solution {
public:
    /**
     * @param prices: Vector of candy prices
     * @param k: Number of free candies allowed per purchase
     * @return: Vector containing [min_cost, max_cost]
     */
    vector<int> candyStore(vector<int>& prices, int k) {
        int n = prices.size();
        
        // Strategy: Sort prices to easily pick cheapest/most expensive
        sort(prices.begin(), prices.end());

        // Part 1: Minimum Cost Calculation
        int min_cost = 0;
        int buy_idx = 0;
        int free_idx = n - 1;
        
        while (buy_idx <= free_idx) {
            min_cost += prices[buy_idx]; // Buy cheapest
            buy_idx++;                   // Move to next cheapest
            free_idx -= k;               // Skip k most expensive
        }

        // Part 2: Maximum Cost Calculation
        int max_cost = 0;
        buy_idx = n - 1;
        free_idx = 0;
        
        while (free_idx <= buy_idx) {
            max_cost += prices[buy_idx]; // Buy most expensive
            buy_idx--;                   // Move to next most expensive
            free_idx += k;               // Skip k cheapest
        }

        return {min_cost, max_cost};
    }
};