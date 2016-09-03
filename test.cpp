#include<iostream>
using namespace std;
class A{
      public:
             A(int k=0):i(k){}
            virtual void print(){
                     cout<<"A("<<i<<")";
                     }
      private:
              int i;
};
class B:public A{
      public:
             B(int k=0):A(k-1),i(k){}
            virtual void print(){
                  A::print();
                  cout<<"B("<<i<<")";
                  }
                  private:
                          int i;
                          };
void print(const A as[],int size){
     for(int i=0;i<size;i++){
             const_cast<A*>(&as[i])->print();cout<<",";
     }
     cout<<endl;
}
int main(){
    B b[10];
    A a[10];
    print(a,10);
    cout<<"print A OK"<<endl;
    print(b,10);
    system("pause");
    
}
