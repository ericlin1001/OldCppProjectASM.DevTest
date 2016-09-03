#include<iostream>
#include<stack>
#include<string.h>
#include<vector>
#include<list>
using namespace std;
struct Player{
       Player(){
                count=13;
                remove=false;
                }
       list<int>cards;
       int tempCard;
       int getNum(){return cards.size();}
       int count;
       void countOne(){count++;if(count>13)count-=13;}
       bool remove;
       void addCard(int card){
            cards.push_back(card);
       }
       void oneStep(){
            if(getNum()!=0){
                  countOne();
                  tempCard=cards.front();
                  cards.pop_front();
                  if(tempCard==count){
                        remove=true;
                      
                  }else{
                        remove=false;
                        cards.push_back(tempCard);
                      
                  }
            }
       }
       //
      
};
int main(){
   int t;
   cin>>t;
   int case=0;
   while(t--){
              int n;
              cin>>n;
              vector<Player>players;
              players.resize(n);
              int i;
              bool winnable=false;
              for(i=0;i<52;i++){
                                int k;
                                cin>>k;
                                players[0].addCard(k);
                                }
                                
                                int numChange=0;
                                
              while(1){//one cycle:
                     bool change=false;
                    for(i=0;i<n;i++){
                          players[i].oneStep();           
                    } 
                    for(i=1;i<n;i++){
                          if(players[i-1].remove){
                                   change=true;
                                   players[i].addCard(players[i-1].tempCard);       
                          }
                    } 
                    if(change){
                   numChange++;
                   }else{
                         numChange=0;
                         }
                   winnable=true;
                   for(i=0;i<n;i++){
                          if(players[i].getNum()>=numChange){
                          winnable=false;
                                                            }
                   }
                   if(winnable){
                                break;
                                }
              }
              
              case++;
              cout<<"Case "<<case<<":": 
                          //
              if(winnable){
              for(i=0;i<n;i++){
                    for(i=0;i<n;i++){
                          cout<<" "<<players[i].tempCard;
                          
                   }       
               }
                           }else{
                                cout<<"unwinnable"<<endl;
                                } 
              cout<<endl;
              }    
}
