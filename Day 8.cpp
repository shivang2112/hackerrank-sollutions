#include <bits/stdc++.h>
using namespace std;

int main() {
    map <string,int> ma;
    int n,x;
    cin>>n;
    string s;

    for(int i = 0; i < n; i++){
        cin>>s>>x;
        ma[s] = x;
    }
    string S = "";
    while(cin>>s)
    {

        if(ma.find(s) == ma.end())
        {
            cout<<"Not found\n";
        }
        else
        {
            cout<<s<<"="<<ma[s]<<endl;
        }

    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
