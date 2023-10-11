#include<iostream>
#include<math.h>
#include<string>

using namespace std;
int h1,m1,s1, h2, m2, s2, c;
int main()
{
    cout << "Thoi diem T1 (h m s) = ";
    cin >> h1 >> m1 >> s1;
    cout << "Thoi diem T2 (h m s) = ";
    cin >> h2 >> m2 >> s2;
    if(h1 > h2)c = h1, h1 = h2, h2 = c, c = m1, m1 = m2, m2 = c, c = s1, s1 = s2, s2 = c;
    else if(h1 == h2 && m1 > m2)c = m1, m1 = m2, m2 = c, c = s1, s1 = s2, s2 = c;
    else if(h1 == h2 && m1 == m2 && s1 > s2) c = s1, s1 = s2, s2 = c;
    cout << "Khoang cach = " << abs(h2-h1) * 3600 + abs(m2-m1) * 60  -s1 + s2;
    cout << endl;
    return 0;
}
