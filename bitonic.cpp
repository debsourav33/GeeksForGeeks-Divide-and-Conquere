#include<bits/stdc++.h>
using namespace std;

int bin_search(int a[], int x, int low, int high){

    int mid= (high+low)/2;

    if(x==a[mid])
        return mid;

    if(low>high)
        return -1;


    if(x>a[mid])
        return bin_search(a,x,mid+1,high);

    else
        return bin_search(a,x,low,mid-1);


}

int bin_search_revert(int a[], int x, int low, int high){

    int mid= (high+low)/2;

    if(x==a[mid])
        return mid;

    if(low>high)
        return -1;


    if(x<a[mid]) //because the array is in decreasing order
        return bin_search_revert(a,x,mid+1,high);

    else
        return bin_search_revert(a,x,low,mid-1);


}


int getMax(int *a, int low, int high){
    int mid= (high+low)/2;

    if(mid==0){
        return (a[0]>a[1]) ? 0 : 1;
    }

    if(low==high)
        return low;


    if(a[mid]>=a[mid-1] && a[mid]>a[mid+1])
        return mid;

    else if(a[mid]>=a[mid-1] )
        return getMax(a,mid+1,high);

    else
        return getMax(a,low,mid-1);


}

main(){
    int opt;

    cin>> opt;

    for(int k=0;k<opt;k++){
        int *a, n, x;
        cin>>n;
        cin>>x;
        a= (int *) malloc(n*sizeof (int));

        for(int i=0; i<n; i++)
            cin>> a[i];

        int maxPos= getMax(a,0,n-1);

        int first= bin_search(a,x,0,maxPos-1); //this array is in increasing order
        int last= bin_search_revert(a,x,maxPos, n-1); //this array is in decreasing order

        if((first==last)&&(first==-1))
            cout<< "OOPS! NOT FOUND" <<endl;
        else if(first!=-1)
            cout<<first<<endl;
        else
            cout<<last<<endl;

        free(a);

    }


}
