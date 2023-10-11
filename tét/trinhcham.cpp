#include<bits/stdc++.h>
using namespace std;
signed main()
{
    srand(time(nullptr));
    for(int t = 1; t <= 100; t++)
    {
        ofstream inp("test.inp");
        int n = 20, m = 15;
        inp << n << endl;
        for(int i = 1; i <= n;i++)
        {
            int k = rand() % m + 1;
            inp << k <<  " ";
        }
        inp << endl;
        inp.close();
        system("test.exe");
        system("trau.exe");
        if(system("fc test.out test.ans") != 0)
        {
            cout << "Test " << t << " : WRONG\n";
            return 0;
        }
        cout << "Test " << t << " : CORRECT\n";
    }
}

