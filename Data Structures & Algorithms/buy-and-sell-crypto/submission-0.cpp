class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int current_stock = prices[0];
        for(size_t i = 1; i<prices.size(); i++){
            int selling_value = prices[i];
            if(prices[i] < current_stock) current_stock = prices[i];
            else if(prices[i] - current_stock > profit) profit = prices[i]-current_stock;
        }
        return profit;
    }
};
