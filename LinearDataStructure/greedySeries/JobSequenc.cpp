#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit; // sort descending
}

vector<int> JobScheduling(Job arr[], int n) {
    sort(arr, arr+n, cmp);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, arr[i].deadline);

    vector<int> slot(maxDeadline + 1, -1); // -1 means empty
    vector<int> result;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline; j > 0; j--) { // find a free slot
            if (slot[j] == -1) {
                slot[j] = i; // assign job i to slot j
                result.push_back(arr[i].id);
                break;
            }
        }
    }
    return result;
}

int main() {
    Job arr[] = {{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,3,15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans = JobScheduling(arr, n);
    cout << "Jobs scheduled: ";
    for (int id : ans) cout << id << " ";
    cout << endl;
    return 0;
}
