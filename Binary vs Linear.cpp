#include<bits/stdc++.h>
using namespace std;


int bin_iter(int a[], int x, int low, int high){

    int mid= (high+low)/2;

    if(x==a[mid])
        return 1;

    if(low>high)
        return -1;

    if(x>a[mid])
        return 1+bin_iter(a,x,mid+1,high);

    else
        return 1+bin_iter(a,x,low,mid-1);


}

main(){
    int opt;
    cin>>opt;

    for(int k=0;k<opt;k++){
        int a[1005], n, x, lin_weight, bin_weight;

        cin >> n >> x >> lin_weight >> bin_weight;

        for(int i=1; i<=n; i++)
            a[i]=i;

        int lin= x;
        int bin= bin_iter(a,x,1,n);

        int lin_time= lin*lin_weight;
        int bin_time= bin* bin_weight;

        if(lin_time==bin_time)
            cout<< 0 << endl;

        else if(lin_time<bin_time)
            cout<< 1 << endl;

        else
            cout<< 2 <<endl;

    }


}

