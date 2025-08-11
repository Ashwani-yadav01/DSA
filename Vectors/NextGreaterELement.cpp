#include <iostream>
#include <vector>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums1[i] == nums2[j])
            {
                if (j + 1 != m)
                {
                    int NoGreater=0;
                    cout << j << endl;
                    for (int k = j+1 ; k < m; k++)
                    {
                        cout << " k " << k << endl;
                        if (nums2[k]>nums1[i])
                        {
                            nums1[i] = nums2[k];
                            NoGreater=1;
                            break;
                        }
                         
                    }
                    if(!NoGreater) nums1[i] = nums2[j];
                  
                    break;
                }
                else
                {
                    nums1[i] = -1;
                   break;
                }
                break;
            }
        }
    }
    return nums1;
}
int main()
{
    vector<int> nums1 = {1,3,5,2,4};
    vector<int> nums2 = {6,5,4,3,2,1,7};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int an : ans)
    {
        cout << an << " ";
    }
    return 0;
}