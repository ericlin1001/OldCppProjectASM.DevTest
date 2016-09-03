#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
ofstream out("/home/iladmin/sicily/web/temp.txt");
#define test 0
#if test==1
#define Trace(m) out<<m<<endl;
#endif
#if test==2
#define Trace(m) out<<#m"="<<m<<endl;
#endif
#if test==0
#define Trace(m) ;
#endif

struct Pair{
    string str;
    int value;
};
bool comp(const Pair &b,const Pair &a){
    return b.value<=a.value;
}
int main(){
    int t;
    cin>>t;
    Trace(t);
    while(t--){
        int num;
        cin>>num;
        Trace(num);
        vector<Pair>pairs;
        Pair pair;
        int i;
        for( i=0;i<num;i++){
            cin>>pair.str>>pair.value;
            Trace(pair.str);Trace(pair.value);
            pairs.push_back(pair);
        }
        sort(pairs.begin(),pairs.end(),comp);
        for( i=0;i<num;i++){
            cout<<pairs[i].str<<endl;
        }
        if(t!=1)cout<<endl;
    }
    out.close();
    return 0;
}
