#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string s = "";
    while(n)
    {
        s += ('0'+n%2);
        n/=2;
    }
    int curr = 0, ans = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '1')
        {
            curr++;
            ans = max(ans,curr);
        }
        else curr = 0;
    }
    cout<<ans;
    return 0;
}
