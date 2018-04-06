#include<bits/stdc++.h>
using namespace std;

int first(int *a, int x, int low, int high){
    if(high<low)
        return -1;

    if(low==0 && a[low]==x)
        return low;

    int mid= (low+high)/2;

    if(a[mid]==x && a[mid-1]!=x)
        return mid;

    else if(x<= a[mid])
        return first(a, x, low, mid-1);

    else
        return first(a,x,mid+1,high);

}

int last(int *a, int x, int low, int high){
    if(high<low)
        return -3;

    if((low==high)&&(a[high]==x))
        return high;

    int mid= (low+high)/2;

    if(a[mid]==x && a[mid+1]!=x)
        return mid;

    else if(x>= a[mid])
        return last(a, x, mid+1, high);

    else
        return last(a,x, low, mid-1);

}

main(){
    int opt;
    cin>> opt;

    for(int k=0; k<opt; k++){
        int *a, n,x;

        cin>> n;
        cin>> x;

        a= (int*) malloc(n*sizeof (int));

        for(int i=0; i<n;i++)
            cin >> a[i];


        sort(a,a+n);

        int firstPos= first(a,x,0,n-1) ;
        int lastPos= last(a,x,0,n-1);

        int occur= lastPos-firstPos + 1;

        cout<< occur << endl;

        free(a);
    }

}
