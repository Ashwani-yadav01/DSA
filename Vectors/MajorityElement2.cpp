#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int ans=0;
    int count = 0;
   
    for (int i = 0; i < nums.size(); i++)
    {
       if (count==0)
       {
        ans=nums[i];
       }
       if(ans==nums[i]) count++;
       else count--;
    }
    // if no majority element is found;
    int freq=0;
    for(int val : nums){
        if (ans==val)
        {
           freq++;
        }
        
    }
    if (freq>nums.size()/2)
    {
        return ans;
    }
    else{
        return -1;
    }
    
}
int main()
{
    vector<int> num = {1,2,3,4};
    int ans = majorityElement(num);
    
    cout << ans;
    return 0;
}

// int majorityElement(vector<int> &nums)
// {
//     int candidate;
//     int count = 0;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (count == 0)
//         {

//             candidate = nums[i];
//             cout << "candidate = " << candidate << endl;
//             count++;
//         }

//         else if (nums[i] == candidate)
//         {
//             count++;
//         }

//         else
//         {
//             count--;
//         }
//     }

//     return candidate;
// }