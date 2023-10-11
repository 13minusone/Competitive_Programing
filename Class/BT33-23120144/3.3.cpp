#include<iostream>
#include<math.h>
#include<string>

using namespace std;
float temp;
int main()
{
    cout << "Do C = ";
    cin >> temp;
    cout << "Do F = " << temp * 1.8 + 32 << endl;
    cout << "Do C = " << temp + 273;
    return 0;
}
