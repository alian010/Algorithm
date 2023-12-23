#include<bits/stdc++.h>
#define fastread()  (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
void merge(int arr[],int b,int mid,int l)
{
    int len1=mid-b+1;
    int len2=l-mid;
    int m[len1],n[len2];
    for(int i=0;i<len1;i++)
    {
        m[i]=arr[b+i];
    }
    for(int i=0;i<len1;i++)
    {
        n[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=b;
    while(i<len1 && j<len2)
    {
        if(m[i]<n[j])
        {
            arr[k]=m[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=n[j];
            k++;
            j++;
        }
    }
    while(i<len1)
    {
        arr[k]=m[i];
        i++;
        k++;
    }
    while(j<len2)
    {
        arr[k]=n[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int b,int l)
{
    if (b<l)
    {
        int mid=(b+l)/2;
        mergesort(arr,b,mid);
        mergesort(arr,mid+1,l);
        merge(arr,b,mid,l);
    }
}

int main()
{
    fastread();
    int arr[]={4,1,5,7,3,4,6};
    int b=0;
    int l=6;
    mergesort(arr,b,l);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
}

