#include <iostream>
using namespace std;

int main()
{
    unsigned long long x;
    cin >> x;

    unsigned long long val = 100;
    int count = 0;
    while (val < x)
    {
        val += (val / 100);
        count++;
    }
    cout << count;
    return 0;
}