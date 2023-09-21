#include <iostream>

using namespace std;

template<class T>
T max_num(T a, T b)
{
    return a > b ? a: b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << max_num(a, b);
    return 0;
}