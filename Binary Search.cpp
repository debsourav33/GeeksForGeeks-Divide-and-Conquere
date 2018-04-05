#include<bits/stdc++.h>
using namespace std;

int bin_search(int a[], int x, int low, int high){

    int mid= (high+low)/2;

    if(x==a[mid]){
        cout<< "Mid found: "<< mid <<endl;
        return mid;
    }

    if(x>a[mid])
        return bin_search(a,x,mid+1,high);

    else
        return bin_search(a,x,low,mid-1);


}

main(){
    int a[100], n, x;

    cin >> n;

    for(int i=0; i<n; i++)
        cin>> a[i];

    cin >> x;

    cout<< bin_search(a,x,0,n-1) <<endl;





}
