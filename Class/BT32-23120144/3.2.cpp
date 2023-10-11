#include<iostream>
#include<math.h>
#include<string>

using namespace std;
int num, ans = 0;
int main()
{
    cout << "So xe = ";
    cin >> num;
    cout << endl;
    while(num > 0)
    {
        ans += (num % 10);
        ans %= 10;
        num /= 10;
    }
    cout << "So nut = " << ans << endl;
    return 0;
}
