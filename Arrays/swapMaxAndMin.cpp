#include <iostream>
using namespace std;
int main()
{

    int numbers[] ={2,3,5,1,6};
    int B = INT32_MIN;
    int S = INT32_MAX;
    int Bi=0;
    int Si=0;
    for (int i = 0; i < 5; i++)
    {
        if (B < numbers[i]) // biggest
        {
            B = numbers[i];
            Bi=i;
        }
        if (S > numbers[i]) // smallest
        {
            S = numbers[i];
            Si=i;
        }
    }
    cout << "Biggest number in the array : " << B << endl;
    cout << "Smallest number in the array : " << S << endl;
     cout << "Biggest number in the index : " << Bi << endl;
    cout << "Smallest number in the index : " << Si << endl;
    for (int i = 0; i < 5; i++)
    {
      cout<< numbers[i]<< " ";
    }
    cout <<endl;
    int Temp=numbers[Si];
    numbers[Si]=numbers[Bi];
    numbers[Bi]=Temp;
    for (int i = 0; i < 5; i++)
    {
      cout<< numbers[i]<< " ";
    }
    
    return 0;
}