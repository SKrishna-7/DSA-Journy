#include <iostream>

using namespace std;

double solve(double x, long long nn)
{

    if (nn == 0)
    {
        return 1.0;
    }

    if (nn % 2 == 0)
    {
        return solve(x * x, nn / 2);
    }
    else
    {
        return x * solve(x, nn - 1);
    }
}

double myPow(double x, int n)
{

    long long nn = n;
    double ans = 1.0;

    if (nn < 0)
    {
        x = 1 / x;
        nn = nn * -1;
    }

    ans = solve(x, nn);

    return ans;
}

int main()
{
    double x = 2.00000;
    int n = 10;

    cout<< myPow(x,n);
    
    return 0;
}