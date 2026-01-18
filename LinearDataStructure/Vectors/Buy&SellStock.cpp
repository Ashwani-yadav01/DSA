#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxProfit = 0;
    int bestBuy = prices[0];
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > bestBuy)
            maxProfit = max(maxProfit, prices[i] - bestBuy);
         
        bestBuy = min(prices[i], bestBuy);     
    }
    return maxProfit;
}
int main()
{
    vector<int> vec = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(vec) << endl;
    return 0;
}