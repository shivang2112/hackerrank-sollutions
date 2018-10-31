#include <bits/stdc++.h>
using namespace std;
#define lli long long int
struct node
{
    struct node *left;
    struct node *right;
};
struct node* newNode()
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->left = NULL;
  node->right = NULL;
  return(node);
}
string addBinary(string a, string b)
{
    string r = "";
    int s = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);
        r = char(s % 2 + '0') + r;
        s /= 2;
        i--; j--;
    }
    return r;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli q,m=0,ans=1;
        int n,i;
        char x;
        cin>>n>>q;
        struct node *root = newNode();
        fflush(stdin);
        string s1;
        for(int i=0;i<n;i++)
            s1='0'+s1;
        for(int k=0;k<q;k++)
        {
            cin>>x;
            if(x=='!')
            {
                string s2;
                int c;
                cin>>c;
                if(c>n)
                    continue;
                for(i=0;i<n;i++)
                    s2='0'+s2;
                s2[n-1-c]='1';
                struct node *curr=root;
                s1=addBinary(s1,s2);
                int p =s1.length();
                if(p>n)
                    s1=s1.substr(p-n,n);
                //cout<<s1<<endl;
                for(i=0;i<n;i++)
                {
                    if(s1[i]=='0')
                    {
                        if(curr->left==NULL)
                        {
                            ans=(long long)ans+1;
                            curr->left=newNode();
                        }
                        curr=curr->left;
                    }
                    else
                    {
                        if(curr->right==NULL)
                        {
                            ans=(long long)ans+1;
                            curr->right=newNode();
                        }
                        curr=curr->right;
                    }
                }
            }
            else
                {cout<<(long long)ans<<endl;}


        }

    }
}
