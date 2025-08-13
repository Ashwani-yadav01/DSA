#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> price = {7,6,4,3,1};
    int n = price.size();
    int buyStock = price[0];
    int day = 0;
    for (int i = 1; i < n; i++)
    {
        if (buyStock > price[i])
        {
            buyStock = price[i];
            day=i;
        }
    }
    cout << buyStock << endl;
     cout << day << endl;

     int sellStock=0;
     for (int i = day+1; i < n; i++)
    {
        if (sellStock < price[i])
        {
            sellStock = price[i];
            
        }
    }
     cout << sellStock << endl;
     cout<< "profit" << sellStock-buyStock;
    return 0;
}