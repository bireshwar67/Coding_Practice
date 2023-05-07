#include <iostream>
using namespace std;

int main()
{
    int arr[]{1, 2, 3, 4, 5};
   // int arr[] = arr{1, 2, 3, 4, 5};

    cout << "At Index 0 : " << arr[0] << endl;
    cout << "At Index 1 : " << arr[1] << endl;
    cout << "At Index 2 : " << arr[2] << endl;
    cout << "At Index 3 : " << arr[3] << endl;
    cout << "At Index 4 : " << arr[4] << endl;
    cout << "The name of the array is actually an address :  " << arr << endl;

    cout << "Here we can take new inputs also from the console" << endl;

    cin >> arr[0];
    cin >> arr[1];
    cin >> arr[2];
    cin >> arr[3];
    cin >> arr[4];

    cout << "Arrat with new inputs are :" << endl;
    cout << "At Index 0 : " << arr[0] << endl;
    cout << "At Index 1 : " << arr[1] << endl;
    cout << "At Index 2 : " << arr[2] << endl;
    cout << "At Index 3 : " << arr[3] << endl;
    cout << "At Index 4 : " << arr[4] << endl;
    cout << "The name of the array is actually an address :  " << arr << endl;
    cout << "The name of the array is actually an address :  " << &arr[0] << endl; // even with the indexing the address of the arrar will only get printed;
    return 0;
}