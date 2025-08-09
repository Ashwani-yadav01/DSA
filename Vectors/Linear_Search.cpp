#include <iostream>
#include <vector>
using namespace std;
void search(vector<int> &vec, int &num)
{
    int flag = 0;
    for (int val : vec)
    {
        if (val == num)
        {
            flag = 1;
        }
    }
    if (flag)
    {
        cout << " Number is found" << endl;
    }
    else
    {
        cout << "Number is not found" << endl;
    }
}
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    int num = 6;
    search(vec, num);
    return 0;
}
