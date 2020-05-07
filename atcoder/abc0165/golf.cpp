#include <iostream>
using namespace std;

int main()
{
    int k, a, b;
    cin >> k;
    cin >> a;
    cin >> b;

    if (a - b >= k)
    {
        cout << "OK";
        return 0;
    }

    for (int i = a; i <= b; i++)
        if (i % k == 0)
        {
            cout << "OK";
            return 0;
        }

    cout << "NG";
    return 0;
}