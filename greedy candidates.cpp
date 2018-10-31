#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli n,m,i,j,count=0,sum=0,count1=0;
        cin>>n>>m;
        int a[n],b[m][3];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<m;i++)
            for(j=0;j<2;j++)
            {
                cin>>b[i][j];
                b[i][2]=b[i][1];
            }
        for(i=0;i<n;i++)
        {
            string s;
            cin>>s;
            int max=0,x=10000;
            for(j=0;j<m;j++)
            {
                if(s[j]=='1' && b[j][1]!=0 && b[j][0]>=a[i])
                {
                    if(max<b[j][0])
                    {
                        x=j;
                        max=b[j][0];
                    }

                }
            }
            if(x!=10000)
            {
                sum+=(long long)b[x][0];
                count++;
                if(b[x][2]==b[x][1])
                    count1++;
                b[x][1]--;
            }
        }
        cout<<count<<" "<<sum<< " "<<m-count1<<endl;
    }
}
