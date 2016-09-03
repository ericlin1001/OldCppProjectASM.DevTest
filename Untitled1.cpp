#include<iostream>
using namespace std;
template<typename T>
struct Node{
      public:
              Node(const T t, Node* const ppre=NULL, Node* const pnext=NULL):data(t),pre(ppre),next(pnext){}
       T data;
       Node<T> *next;
       Node<T> *pre;
};
template<typename T>
void swap(Node<T> *p){
     //Attention!
     //this swaps the p->next and p->next->next;
     Node<T>*pivot=p->next;
     p->next=p->next->next;
     pivot->next=p->next->next;
     p->next->next=pivot;
}
template<typename T>
void swap2(Node<T> *A1){
 //   input:A1
//post-condition:swap A1 and A1->next
A1->pre->next=A1->next;
A1->next=A1->next->next;
A1->pre->next->next=A1;
//
A1->next->pre->pre=A1->next->pre->pre->pre;
A1->pre=A1->next->pre;
A1->next->pre=A1;
}


template<typename T>
void printList(const Node<T> *p){
     cout<<"List(";
     if(p!=NULL &&(p=p->next)!=NULL)cout<<p->data;
     while(p->next!=NULL){
          if(p->next->pre==p){
              cout<<"<->"<<p->next->data;
          }else{
                //means p->next->pre not point to a proper element.
                cout<<"->("<<(p->next->pre!=NULL?p->next->pre->data:-1)<<"<-)"<<p->next->data;
          }
          p=p->next;
     }
          cout<<")"<<endl;
}
typedef Node< int > IntNode;

IntNode* findKth(IntNode* head,int n){//get the nth element.
         IntNode*p=head;
         for(int i=0;i<n;i++)p=p->next;
         return p;
}

template<typename T>
Node<T>* push_back(const T data, Node<T>* const tail){
     return tail->next=new Node<T>(data,tail);
}

IntNode* intersection(IntNode*L1,IntNode*L2){
     IntNode* L;
    IntNode *tail;
    tail=L=new IntNode(-1);//Initialize list L.
    //
   // input:L1,L2 are two sorted lists.(In increasing order)
//output:L as the intersection of L1,and L2.
IntNode*i1,*i2;
i1=L1->next;
i2=L2->next;
while(i1!=NULL && i2!=NULL){
if(i1->data == i2->data){
tail=push_back(i1->data,tail);
i1=i1->next;
i2=i2->next;
}else if(i1->data > i2->data){
i2=i2->next;
}else {
i1=i1->next;
}
}
return L;
}
IntNode*initList(){
                   return new IntNode(-1);
}
int main(){
    //creating a list(containning a header node).
    IntNode* L1;
    IntNode *tail;
    tail=L1=initList();//initial,as a header node.
    //
    tail=push_back(1,tail);//the first elements.
    tail=push_back(3,tail);//the second one.
    tail=push_back(7,tail);
    tail=push_back(9,tail);
    tail=push_back(10,tail);
    tail=push_back(12,tail);
    tail=push_back(15,tail);
    tail->next=NULL;
    //
    IntNode* L2;
    tail=L2=initList();//initial,as a header node.
    //
    tail=push_back(1,tail);//the first elements.
    tail=push_back(2,tail);//the second one.
    tail=push_back(3,tail);
    tail=push_back(8,tail);
    tail=push_back(9,tail);
    tail=push_back(13,tail);
    tail=push_back(15,tail);
    tail->next=NULL;
    //
    cout<<"L1:";printList(L1);
    cout<<"L2:";printList(L2);
    //
    cout<<"intersection(L1,L2):";printList(intersection(L1,L2));
    
    system("pause");
    return 0;
}
