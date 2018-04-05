#include<bits/stdc++.h>
using namespace std;

#define Modulo 100000007

long long power(int x, int n){
    if(n==1)
        return x;

    return ((power(x,n/2) % Modulo)* (power(x,n-(n/2)) % Modulo)) % Modulo;
}

int reversDigits(int num){

    int rev_num = 0;
    while(num > 0)
    {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
    return rev_num;
}


main(){
    int opt;
    cin>> opt;

    for(int i=0;i<opt;i++){
        int x,n;
        cin>> x;

        n= reversDigits(x);

        cout << power(x,n) << endl;
    }

}
