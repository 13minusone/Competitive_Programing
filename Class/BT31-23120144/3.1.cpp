#include<iostream>
#include<math.h>
#include<string>

using namespace std;
string s;
int namsinh;
int main()
{
    cout << "Ten = " ;
    getline(cin, s);
    cout << endl;
    cout << "Nam sinh = " ;
    cin >> namsinh;
    cout << endl;
    cout << "Chao ban " << s <<", nam nay ban " <<  2023-namsinh << " tuoi.";
    return 0;
}
