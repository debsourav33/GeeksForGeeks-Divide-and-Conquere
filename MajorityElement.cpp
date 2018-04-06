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
        return first(a,x,mid+1,low);

}

main(){
    int opt;
    cin>> opt;

    for(int k=0; k<opt; k++){
        int *a, n,x;

        cin>> n;
        a= (int*) malloc(n*sizeof (int));

        for(int i=0; i<n;i++)
            cin >> a[i];

        cin>> x;

        sort(a,a+n);
        int firstPos= first(a,x,0,n-1) ;

        if(a[firstPos+n/2]==x)
            cout << "True" << endl;
        else
            cout << "False" << endl;

        free(a);
    }

}
