#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
unsigned int graph[1024][1024];
int nr,nc;
#define INFINITE 10000000
struct Node {

       Node(int tx=0,int ty=0,int tg=0, Node*tpre=NULL):x(tx),y(ty),pre(tpre),g(tg){
                
       }
       bool operator==(const Node &p){
           // cout<<"operator=="<<endl;
            return x==p.x&& y==p.y;
            }
       int x,y;
       int f,g,h;
        Node*pre;
       void print()const{
            //cout<<"Node: ("<<x<<","<<y<<") g:"<<g<<"\th:"<<h<<"\tf:"<<f<<endl;
            }
       };
       struct mycomp2{
              bool operator()(const Node&a,const Node&b)const{
                  // cout<<"mycomp2 ";a.print();b.print();cout<<"end"<<endl;
                       return a.x*1000+a.y > b.x*1000+b.y;
                       }
              };
       
       struct mycomp{
              bool operator()(const Node*a,const Node*b)const{
                       return a->f > b->f;
                       }
              };
              #define Trace(m) //cout<<#m"="<<(m)<<endl;
vector<Node*> getSuccessor( Node& n){
          vector<Node*> succs;
          succs.push_back(new Node(n.x-1,n.y,n.g,&n));
          succs.push_back(new Node(n.x,n.y-1,n.g,&n));
          succs.push_back(new Node(n.x+1,n.y,n.g,&n));
          succs.push_back(new Node(n.x,n.y+1,n.g,&n));
          int i;
          for( i=0;i<succs.size();i++){
                  int tx=(succs[i]->x);
                  int ty=(succs[i]->y);
                  if(tx<0 || ty<0 || tx>=nr || ty>=nc ){
                       succs.erase(succs.begin()+i);
                       i--;
                       }
                  }
            for(i=0;i<succs.size();i++){
                       succs[i]->g+=graph[succs[i]->x][succs[i]->y];
                  }
          return succs;
}
Node *start,*goal;
int hamitonHfun(const Node *n){
 return abs(n->x-goal->x)+abs(n->y-goal->y);   
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
           
           scanf("%d %d",&nr,&nc);
           int r,c;
           int len=0;
           memset(graph,1024*1024,0);
           for(r=0;r<nr;r++){
                             for(c=0;c<nc;c++){
int temp;scanf("%d",&temp);
                                  graph[r][c]=temp;             
                                               }
                                               }
           
           priority_queue<int,vector<Node*>,mycomp> openL;
           set<Node,mycomp2> closeL;
          ;
         /* Node t1,t2;
          t1.x=1;t1.y=2;closeL.insert(t1);
          t2.x=5;t2.y=2;closeL.insert(t1);
          
          Trace((closeL.find(t2)!=closeL.end())?"found":"Not found");

          t2.x=1;t2.y=2;closeL.insert(t2);
          Trace((closeL.find(t2)!=closeL.end())?"found":"Not found");
          Trace(closeL.find(t2)!=closeL.end());
          */
          ;
           start=new Node();
           goal=new Node();
           scanf("%d %d",&start->x,&start->y);
           scanf("%d %d",&goal->x,&goal->y);
           start->x--;start->y--;
           goal->x--;goal->y--;
           
           start->g=graph[start->x][start->y];
           openL.push(start);
           //************
           while(!openL.empty()){
                       Node *cur=openL.top();openL.pop();
                      // cout<<"searching in ";cur->print();
                       closeL.insert(*cur);
                       if((*cur)==(*goal)){
                                           len=cur->g;break;
                                           stack<Node *>path;
                                           while(!((*cur)==(*start))){
                                           path.push(cur);
                                           cur=cur->pre;
                                                                }
                                                                path.push(start);
                                                                while(!path.empty()){
                                                                path.top()->print();path.pop();
                                                               // cout<<"to";
                                                                }
                                 // cout<<"find!"<<endl;  
                                 break; 
                                     }
                                 //
                                vector<Node*> successor=getSuccessor(*cur);
                                Trace(successor.size());
                                for(int i=0;i<successor.size();i++){
                                        //successor[i]->print();
                                        Trace(closeL.find(*successor[i])==closeL.end());
                                       if(closeL.find(*successor[i])==closeL.end()){
                                                 successor[i]->h=hamitonHfun(successor[i])                                  ;
                                                 successor[i]->f=successor[i]->g+successor[i]->h;
                                                 //cout<<"add to open list ";successor[i]->print();
                                                 openL.push(successor[i]);                                  
                                              }else{
                                                delete successor[i];
                                              }
                                }
                                 //
                                // cin.get();
                                 }      
                                        
           //***************
           printf("%d\n",len);
               }
    return 0;
}
