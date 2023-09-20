#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // Add your solution here
    int n = 12;
    int n1;
    int n2;
    while (true)
    {
        cin >> n1;
        cin >> n2;
        cout << (n2+3*n1+3*n1*n1) % n << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
