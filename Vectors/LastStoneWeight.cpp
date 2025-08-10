#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lastStoneWeight(vector<int> &stones)
{
    sort(stones.begin(), stones.end()); // Ensure the vector is sorted
    int size = stones.size();
    if (size == 1 || size == 0)
    {
        return size == 1 ? stones[0] : 0;
    }
    {
        for (int i = size - 1; i >= 0;)
        {
            if (stones[i] == stones[i - 1])
            {
                stones.pop_back();
                stones.pop_back();
            }
            else
            {
                stones[i - 1] = stones[i] - stones[i - 1];
                stones.pop_back();
            }

            sort(stones.begin(), stones.end()); // Ensure the vector is sorted

            if (stones.size() == 1 || stones.size() == 0)
            {
                return stones.size() == 1 ? stones[0] : 0;
            }
            i = stones.size() - 1;
            // cout << i << endl;
            for (int val : stones)
            {
                cout << val << " ";
            }
            cout << endl;
        }
        return stones[0];
    }
}
int main()
{
    vector<int> vec = {1,1,2,4};
    int ans = lastStoneWeight(vec);
    cout << ans << endl;
    return 0;
}