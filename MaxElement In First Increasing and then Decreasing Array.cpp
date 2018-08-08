#include<bits/stdc++.h>
using namespace std;

int bin_search(int *a, int low, int high){
    int mid= (high+low)/2;

    if(mid==0){
        return (a[0]>a[1]) ? a[0] : a[1];
    }

    if(low==high)
        return a[low];


    if(a[mid]>=a[mid-1] && a[mid]>a[mid+1])
        return a[mid];

    else if(a[mid]>=a[mid-1] )
        return bin_search(a,mid+1,high);

    else
        return bin_search(a,low,mid-1);


}

main(){
    int opt;

    cin>> opt;

    for(int k=0;k<opt;k++){
        int *a, n, x;

        cin >> n;

        a= (int*) malloc(n*sizeof (int));

        for(int i=0; i<n; i++)
            cin>> a[i];

        cout<< bin_search(a,0,n-1) <<endl;


        free(a);

    }


}
