#include<bits/stdc++.h>
using namespace std;

int interpolation(float a[],int n, float k)
{
    int l=0,h=n-1;
    while(l<=h && k>=a[l]&& k<=a[h])
    {
        //pos = lo + (((double)(hi-lo) /(arr[hi]-arr[lo]))*(x - arr[lo]));
        int pos= l+((float)((h-l)/(a[h]-a[l]))*((float)(k-a[l])));
        if(a[pos]==k)
            return pos;
        else if(a[pos]>k)
            h=pos-1;
        else
            l=pos+1;
    }
    return -1;
}

int main()
{
    fflush(stdin);
    int n;
    cin>>n;
    string w;
    cin>>w;
    float a[n];
    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    float ans=0;
    for(int i=0;i<n;i++)
    {
        ans=0;
        for(int j=0;j<s[i].length();j++)
        {
            int k=j-s[i].length()+1;
            ans+=(float)(s[i][j]-'a'+1)*(float)pow(5,k);
        }
        a[i]=ans;
    }
    ans=0;
    for(int j=0;j<w.length();j++)
    {
        int k=j-w.length()+1;
        ans+=(float)(w[j]-'a'+1)*(float)pow(5,k);
    }
    int k=interpolation(a,n,ans);
    cout<<k<<endl;
}
