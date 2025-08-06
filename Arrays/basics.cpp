#include <iostream>
using namespace std;
int main()
{

    // Find the biggest, smallest and second biggest number in an array
    // Mine apporach was first find the biggest and smallest number in the array
    // then find the second biggest number by checking if the current number is less than the biggest   and greater than the next number
    // if it is then it is the second biggest number   then assign it to SB
    // if not then continue to the next number and repeat the process
    // this is not the most efficient way to do it but it works
    int numbers[] = {5,5,5,5,5};
    // int B = INT32_MIN;
    // int S = INT32_MAX;
    // int SB = numbers[0];
    // for (int i = 0; i < 5; i++)
    // {
    //     if (B < numbers[i]) // biggest
    //     {
    //         B = numbers[i];
    //     }
    //     if (S > numbers[i]) // smallest
    //     {
    //         S = numbers[i];
    //     }
    // }
    // cout << "Biggest number in the array : " << B << endl;
    // cout << "Smallest number in the array : " << S << endl;
    // // 1 2 3 4 5
    // for (int i = 0; i < 4; i++)
    // {
    //     if (!(SB < B && SB > numbers[i + 1]))
    //     {
    //         SB = numbers[i + 1];
    //     }

    // }

    // cout << "Second Biggest number in the array : " << SB << endl;

    // chatgpt
    int B = INT32_MIN, SB = INT32_MIN;
for (int i = 0; i < 5; i++) {
    if (numbers[i] > B) {
        SB = B;
        B = numbers[i];
    } else if (numbers[i] > SB && numbers[i] != B) {
        SB = numbers[i];
    }
}
    cout << "Biggest number in the array : " << B << endl;
    cout << "Second Biggest number in the array : " << SB << endl;
    return 0;
}