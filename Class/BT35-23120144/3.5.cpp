#include<iostream>
#include<math.h>
#include<string>

using namespace std;
float ans, p, q, canhai;
int main()
{
    cout << "Nhap p, q = ";
    cin >> p >> q;
    cout << endl;
    canhai = sqrt(pow(p, 6) / float(27) + pow(q, 2) / float(4));
    ans = cbrt(canhai - (q / float(2))) - cbrt(canhai + q / float(2));
    cout << "Nghiem x = " << ans << endl;
    return 0;
}
