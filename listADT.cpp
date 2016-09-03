#include<iostream>
using namespace std;
//
template<typename T>
struct Node{
       Node(const T t, Node* const ppre=NULL, Node* const pnext=NULL):data(t),pre(ppre),next(pnext){}
       T data;
       Node<T> *next;
       Node<T> *pre;
};
//
template<typename T>
void swap(Node<T> *const p){
     //Attention!
     //this swaps the p->next and p->next->next;
     Node<T>*pivot=p->next;
     p->next=p->next->next;
     pivot->next=p->next->next;
     p->next->next=pivot;
}
//
template<typename T>
void swap2(Node<T> *const A1){
//input:A1
//post-condition:swap A1 and A1->next
A1->pre->next=A1->next;
A1->next=A1->next->next;
A1->pre->next->next=A1;
//
A1->next->pre->pre=A1->next->pre->pre->pre;
A1->pre=A1->next->pre;
A1->next->pre=A1;
}
//
template<typename T>
void printList(const Node<T> * const L){
     const Node<T> *p=L;
     cout<<"List[";
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
          cout<<"]"<<endl;
}


template<typename T>
Node<T>* findKth(const Node<T>* const head,const int n){//get the nth element.
         Node<T>*p=head->next;
         for(int i=0;i<n-1&&p!=NULL;i++)p=p->next;
         return p;
}

template<typename T>
Node<T>* push_back(const T data, Node<T>* const tail){
     return tail->next=new Node<T>(data,tail);
}
//

typedef Node< int > IntNode;
//
IntNode* intersection(const IntNode*const L1,const IntNode*const L2){
// input:L1,L2 are two sorted lists.(In increasing order)
//output:L as the intersection of L1,and L2.
     IntNode* L;
    IntNode *tail;
    tail=L=new IntNode(-1);//Initialize list L.
//
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
IntNode*initList(){return new IntNode(-1);}//creating a list(containning a header node).
int main(){
    const IntNode* L1;
    const IntNode* L2;
    IntNode *tail;
    //
    //create list L1
    L1=tail=initList();//initial,as a header node.
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
    //create list L2
    L2=tail=initList();//initial,as a header node.
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
    //demonstrates some operations on list L1,L2.
    cout<<"L1:";printList(L1);
    cout<<"L2:";printList(L2);
    cout<<endl;
    //
    cout<<"intersection(L1,L2):";printList(intersection(L1,L2));
    cout<<endl;
    //
    swap(findKth(L1,2));//findKth(L1,2) get the second one in L1,but swap the third and 4th one.
    cout<<"After swap(findKth(L1,2));//findKth(L1,2) get the second one in L1,but swap the third and 4th one.\n";cout<<"L1:";printList(L1);
    cout<<"ps:1<->3->(7<-)9 means 1->next=3,3->pre=1,3->next=9,but 9->pre=7"<<endl;
    cout<<endl;
    //
    swap2(findKth(L2,2));//findKth(L1,2) get the second one in L2,but swap the second and third one.
    cout<<"After swap2(findKth(L2,2));//findKth(L1,2) get the second one in L2,but swap the second and third one.\n";cout<<"L2:";printList(L2);
    cout<<endl;
    //
    system("pause");
    return 0;
}
