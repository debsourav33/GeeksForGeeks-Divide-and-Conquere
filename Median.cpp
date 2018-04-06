#include<bits/stdc++.h>
using namespace std;

int median(int *a, int n){

    if(n%2==0)
        return (a[n/2]+a[n/2-1])/2;

    return a[n/2];


}

int getMedian(int *a, int *b, int n){

    if(n==1)
        return (a[0]+b[0])/2;

    if(n==2)
        return (max(a[0],b[0])+min(a[1],b[1]))/2;


    int medA= median(a,n);
    int medB= median(b,n);

    if(medA==medB)
        return medA;

    else if(medA<medB){

        if(n%2==0)
            return getMedian(a+n/2-1, b, n-n/2+1); //for even number elements, we take median using middle 2 elements so we have to consider first of these middle 2 elements

        return getMedian(a+n/2, b, n-n/2);
    }
    else{
        if(n%2==0)
            return getMedian(a, b+n/2-1, n-n/2+1);

        return getMedian(a, b+n/2, n-n/2);;
    }
}

main(){
    int opt;
    cin >> opt;

    for(int k=0; k<opt; k++){
        int n, *a,*b;

        cin>> n;

        a= (int *) malloc(n*sizeof (int));
        b= (int *) malloc(n*sizeof (int));

        for(int i=0; i<n; i++)
            cin>> a[i];

        for(int i=0; i<n; i++)
            cin>> b[i];

        cout << getMedian(a,b,n) << endl;

        free(a);
        free(b);
    }
}
