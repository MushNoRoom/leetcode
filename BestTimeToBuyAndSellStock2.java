//Best Time to Buy and Sell Stock II 
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
//However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

public class Solution {
    public int maxProfit(int[] prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int size = prices.length;
        if (size == 0 || size == 1)
            return 0;
            
        if (size == 2)
        {
            if (prices[1] >= prices[0])
                return prices[1] - prices[0];
            else
                return 0;
        }
        int c_profit = 0; // cummulative profit
        int c_max_profit = 0; // current max profit
        
        int lowest_buy_price = prices[0];  // the lowest possible buy in price
        
        
        for (int i = 1; i < size; i++)
        {
            int tprice = prices[i]; // today's price
            int yprice = prices[i - 1]; // yesterday's price
            int tprofit = tprice - lowest_buy_price;
            
            if (tprofit >= c_max_profit)
            {
                c_max_profit = tprofit;
            }
            else
            {
                if (tprice < lowest_buy_price || tprice < yprice) // the price went down from yesterday
                {
                    c_profit += c_max_profit;
                    c_max_profit = 0; // clear the current max profit
                    lowest_buy_price = tprice;
                }
            }
        }
        c_profit += c_max_profit; // at the last profit to the cummulative profit
        return c_profit;
    }
}