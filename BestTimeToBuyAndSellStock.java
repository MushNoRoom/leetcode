
//Best Time to Buy and Sell Stock 
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.


public class Solution {
    public int maxProfit(int[] prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
                // the same Solution instance will be reused for each test case.
        
        int size = prices.length;
        if (size == 0 || size == 1)
        int lowest_buy_price = prices[0];
            return 0;
        int max_profit = 0;
        for (int i = 1; i < size; ++i)
        {
            int tprice = prices[i]; // today's price
            int profit_today = tprice - lowest_buy_price; // biggest profit that made at today. since the lowest_buy_price is updated along and it is always on the left of today's price, this is indeed the max profit for today
            if (profit_today > max_profit)
            {
                max_profit = profit_today;  // update max profit if needed
            }
            else
            {
                if (tprice < lowest_buy_price) // today is better for buying a stock. 
                    lowest_buy_price = tprice;
            }
        }
        
        return max_profit;
    }
}