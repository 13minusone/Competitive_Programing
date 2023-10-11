#include<iostream>
#include<math.h>
#include<string>

using namespace std;
long long num;
int main()
{
    cout << "So tien can doi = ";
    cin >> num;
    cout << endl;
    cout << "So to 20000: " << num/20000 << endl;
    num -= (num/20000) * 20000;
    cout << "So to 10000: " << num/10000 << endl;
    num -= (num/10000) * 10000;
    cout << "So to 5000: " << num/5000 << endl;
    num -= (num/5000) * 5000;
    cout << "So to 1000: " << num/1000 << endl;
    num -= (num/1000) * 1000;
    if(num != 0)cout << "So tien du = " << num << endl;
    return 0;
}
