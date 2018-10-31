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
string toBinary(long long int n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=(long long)2;}
    return r;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli q,m=0,ans=1;
        int n;
        char x;
        cin>>n>>q;
        struct node *root = newNode();
        fflush(stdin);
        long long int z=(long long)pow(2,n);
        while(q--)
        {
            cin>>x;
            if(x=='!')
            {
                int c,i;
                cin>>c;
                lli g=(long long)pow(2,c);
                g%=(long long)z;
                m+=(long long)g;
                m%=(long long)z;
                struct node *curr=root;
                string s= toBinary(m);
                int p =s.length();
                //cout<<s;
                for(i=0;i<n-p;i++)
                {
                    if(curr->left)
                    {
                        curr=curr->left;
                    }
                    else
                    {
                        ans=(long long)ans+1;
                        curr->left=newNode();
                        curr=curr->left;
                    }
                }
                int j=0;
                for(i=n-p;i<n;i++)
                {
                    if(s[j]=='0')
                    {
                        if(curr->left)
                        {
                            curr=curr->left;
                        }
                        else
                        {
                            ans=(long long)ans+1;
                            curr->left=newNode();
                            curr=curr->left;
                        }
                    }
                    else
                    {
                        if(curr->right)
                        {
                            curr=curr->right;
                        }
                        else
                        {
                            ans=(long long)ans+1;
                            curr->right=newNode();
                            curr=curr->right;
                        }
                    }
                    j++;
                }
            }
            else
                cout<<(long long)ans<<endl;

        }

    }
}
