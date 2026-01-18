#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {-8, 2, 3, -6, 10};
    //

    int k = 2;
    vector<int> ans;
    queue<int> q;

    int i = 0, j = 0;
    int n = arr.size();

    while (j < n)//-8, 2, 3, -6, 10
    {          
        if (arr[j] < 0)
        {
            q.push(j); 
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            // window size == k
            if (!q.empty())
                ans.push_back(arr[q.front()]);
            else
                ans.push_back(0);

            i++;
            j++;

            
            while (!q.empty() && q.front() < i)
                q.pop();
                

            // remove outgoing element explicitly
            // if (!q.empty() && q.front() == i)
            //     q.pop();  
            // i++; j++;
        }
    }

    for (int val : ans)
        cout << val << " ";

    return 0;
}
