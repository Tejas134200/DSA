class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<>());
        sort(discounts.begin(), discounts.end(), greater<>());

        double price = 0.0;

        int n = prices.size();
        int m = discounts.size();

        for (int i = 0; i < min(m, n); i++) {
            price += (double)prices[i] * (100 - discounts[i]) / 100;
        }

        if (n > m) {
            for (int i = m; i < n; i++) {
                price += prices[i];
            }
        }

        return price;
    }
};
