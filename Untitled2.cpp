#include<iostream>
#include<string.h>
#include<direct.h>
#include<vector>
using namespace std;
//
void func(char *a,char *b){
     while(*a){
               *a^=*b^=*a^=*b;
               a++;
               b++;
    }
}

int main(int argc,char *argv[]){
    char buffer[10]="abc";
    char c[10];
    
    func(buffer,c);
    c[3]=0;
    cout<<c<<endl;
    system("pause");
    return 0;
}
