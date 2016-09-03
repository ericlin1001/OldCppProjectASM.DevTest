#include<iostream>
using namespace std;
enum DIR{UP,DOWN,LEFT,RIGHT,FONT,BACK};
enum COLOR{YELLOW,WHITE,ORANGE,RED,BLUE,GREEN};
struct Base{
};
struct Edge:public Base{
       COLOR colors[2];
       DIR dir;
};
struct  Corner:public Base{
        COLOR colors[3];
        DIR dir;
};
struct Block{
       COLOR colors[6];
       Block(){
               for(int i=0;i<6;i++)colors[i]=-1;
               }
};
struct Cube:public Base{
       Corner corners[8];
       Edge edges[12];
       
       void print(){
       }
};
int main(){
    system("pause");
    return 0;
}
