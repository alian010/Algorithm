#include<bits/stdc++.h>
#define fastread()  (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int  partitio(int arr[],int b,int l)
{
    int pivot= arr[b];
    int i=b;
    int j=l;
    while(i<=j)
    {
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[b],arr[j]);
    return j;
}
void quicksort(int arr[],int b,int l)
{
    if (b<l)
    {
        int pi=partitio(arr,b,l);
        quicksort(arr,b,pi-1);
        quicksort(arr,pi+1,l);
    }
}
int main()
{
    fastread();
    int arr[]= {6,3,8,1,2,9,4};
    int b=0;
    int l=6;
    quicksort(arr,b,l);
    for(int i=0; i<6; i++)
    {
        cout<<arr[i]<<" ";
    }
}

