#include<iostream>
using namespace std;    
int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // Declare and initialize an array of integers
    cout << "Elements of the array are: ";
    
    // Loop through the array and print each element
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl; // Print a newline at the end
    return 0; // Return success
}