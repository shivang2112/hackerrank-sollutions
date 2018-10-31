#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l, int m, int u)
{
    int n1=m-l+1;
    int n2=u-m,i,j,k;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }
    for(int i=0;i<n2;i++)
        R[i]=a[m+i+1];
    i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i],i++,k++;
    }
    while(j<n2)
    {
        a[k]=R[j],j++,k++;
    }
}

void mergesort(int a[],int n, int l ,int u)
{
    if(l<u)
    {
        int m=l+(u-l)/2;
        mergesort(a,n,l,m);
        mergesort(a,n,m+1,u);
        merge(a,l,m,u);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,n,0,n-1);
    printf("Sorted array: \n");
    printArray(a, n);

}
