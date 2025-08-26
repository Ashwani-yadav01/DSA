#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int vec[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int maxValue = 0;

     for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           cout << vec[i][j] << " ";
        }
       cout<<endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           if(i==j){
            maxValue+=vec[i][j];
           }else if(i+j==2){
            maxValue+=vec[i][j];
           }
        }
       cout<<maxValue<< " ";
    }

    cout << maxValue << endl;
    return 0;
}
