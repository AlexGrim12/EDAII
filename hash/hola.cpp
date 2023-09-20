#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // Add your solution here
    int n;
    int n2;
    cin >> n;
    while (true)
    {
        cin >> n2;
        cout << (n2*3) % n << endl;
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
