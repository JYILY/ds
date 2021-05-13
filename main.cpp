#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;


int main(){
    int *a = new int[10];
    int b[10] = {1};

    cout<<a<<endl;
    cout<<b<<endl;

    a=b;

    cout<<a[0]<<endl;

    return 0;
}