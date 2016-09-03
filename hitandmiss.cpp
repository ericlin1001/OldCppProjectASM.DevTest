#include<iostream>
#include<stack>
#include<string.h>
#include<vector>
#include<list>
using namespace std;
#include<fstream>
using namespace std;
ofstream out("/home/iladmin/sicily/web/temp.txt");
#define Mod 0
#if Mod==0
#define Trace(m) //out<<#m"="<<(m)<<endl;
#endif
#if Mod==1
#define Trace(m) out<<m<<" ";
#endif
#if Mod==2
#define Trace(m) out<<#m"="<<m<<endl;
#endif
#if Mod==3
#define Trace(m) cout<<#m"="<<m<<endl;
#endif
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
        }else{
             remove=false; 
        }
    }
};
int main(){
    int t;
    cin>>t;
    Trace(t);
    Trace(endl);
    Trace(endl);
    int numcase=0;
    while(t--){
        int n;
        cin>>n;
        vector<Player>players;
        players.resize(n+1);
        int i;
        bool winnable=false;
        for(i=0;i<52;i++){
            int k;
            cin>>k;
            Trace(k);
            players[0].addCard(k);
        }
        int numChange=0;
        while(1){//one cycle:
            for(i=0;i<n;i++){
                players[i].oneStep();           
            }
            bool change=false;
            for(i=0;i<n;i++){
                if(players[i].remove){
                    change=true;
                    players[i+1].addCard(players[i].tempCard);       
                }
            } 
            if(!change){
                numChange++;
            }else{
                numChange=0;
            }
            if(players[n].getNum()>=52){
                                       winnable=true;
                                       break;
            } 
            bool allUnchange=true;
            for(i=0;i<n;i++){
                if(100*players[i].getNum()>=numChange){
                    allUnchange=false;
                }
            }
            if(allUnchange){
                winnable=false;
                break;
            }
        }
        numcase++;
        cout<<"Case "<<numcase<<":";
            //
            if(winnable){
                         
                for(i=0;i<n;i++){
                if(players[i].getNum()!=0){
                                          cout<<"i="<<i<<"num="<<players[i].getNum()<<"Error!!!!"<<endl;
                                          }
                        cout<<" "<<players[i].tempCard;
                }
            }else{
                  
                  winnable=true;
            for(i=0;i<n;i++){
                if(players[i].getNum()>0){
                                          winnable=false;
                                          break;
                                          }
                }
                if(winnable){cout<<"Another error!"<<endl;}
                
                cout<<" unwinnable";
            } 
        cout<<endl;
        //
        Trace(endl);
    }    
}
