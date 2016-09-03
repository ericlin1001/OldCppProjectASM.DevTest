#include <cstdlib>
#include <iostream>
using namespace std;
class Furniture{
      protected:
                int weight;
      public:
      Furniture(int k=0):weight(k){cout<<"constructor of Furniture"<<endl;print();}
      void print(){cout<<"Furniture weight:"<<weight<<endl;}
      void setWeight(int i){weight=i;}
};

class Bed:virtual public Furniture{
      public:
             Bed(int k=7):Furniture(k){cout<<"contructor of Bed"<<endl;print();}
             void sleep(){cout<<"Sleep..."<<endl;}
             void print(){cout<<"Bed weight:"<<weight<<endl;}

};
class Sofa:virtual public Furniture{
      public:
             Sofa():bed(10),Furniture(3){cout<<"constructor of Sofa"<<endl;print();}
             void watchTV(){cout<<"Wathing TV..."<<endl;}
             void print(){cout<<"Sofa weight:"<<weight<<endl;}
      Bed bed;
};
class SleepSofa:public Bed,public Sofa{
      public:
             SleepSofa():Sofa(),Bed(50),Furniture(100000){cout<<"construtor of SleepSofa"<<endl;}
             void foldOut(){cout<<"Fold out the sofa"<<endl;}
};
class Obj1{
      public:Obj1(){cout<<"Obj1"<<endl;}
};
class Obj2{
      public:Obj2(){cout<<"Obj2"<<endl;}
};
class Base1{
      public:Base1(){cout<<"Base1"<<endl;}
};
class Base2{
      public:Base2(){cout<<"Base2"<<endl;}
};
class Base3{
      public:Base3(){cout<<"Base3"<<endl;}
};
class Base4{
      public:Base4(){cout<<"Base4"<<endl;}
};
class Derived:public Base1,virtual public Base2,
              public Base3,virtual public Base4
{
              public:Derived():Base4(),o2(),Base3(),Base2(),Base1(){cout<<"Derived"<<endl;}
              Obj2 o2;
              Obj1 o1[2];
              
};
/*int myMax(int a,int b){
    cout<<"myMax(int a,int b) myMax("<<a<<","<<b<<"):";
    return a>b?a:b;
}*/

template<class T>
T myMax(T a,T b){
        
        cout<<"template function myMax("<<typeid(a).name()<<","<<typeid(b).name()<<") max("<<a<<","<<b<<"):";
        return a>b?a:b;
}


using namespace std;
typedef int UNIT4;

class Hack{

};

Hack& operator<(Hack &a,Hack &b)
{
    std::cerr<<"小于操作符"<<endl;
    return a;
}

Hack &operator>(Hack &a,Hack &b)
{
    std::cerr<<"大于操作符"<<endl;
    return a;
}
#include <stdio.h>
//#include <typeinfo.h>
//
// TypeList
//
template <class T, class U>
struct TypeList
{
    typedef T Head;
    typedef U Tail;
};

struct NullType
{
};

#define TYPELIST_1(T1)            TypeList<T1, NullType>
#define TYPELIST_2(T1, T2)        TypeList<T1, TYPELIST_1(T2) >
#define TYPELIST_3(T1, T2, T3)    TypeList<T1, TYPELIST_2(T2,T3) >

//
// Length
//
template <class TList>  struct Length;

template <>  struct Length<NullType >
{
    enum {value = 0};
};

template <class T,class U>  
struct Length<TypeList<T,U> >
{
    enum {value = 1 + Length<U>::value};
};

//
// TypeAt
//
template <class TList, unsigned int index>  struct TypeAt;

template <class Head, class Tail>  
struct TypeAt< TypeList<Head,Tail>,0 >
{
    typedef Head Result;
};

template <class Head, class Tail, unsigned int index>  
struct TypeAt< TypeList<Head,Tail>,index >
{
    typedef typename TypeAt<Tail, index-1>::Result Result;
};

//
// IndexOf
//
template <class TList, class T>  struct IndexOf;

template <class T>  struct IndexOf< NullType, T >
{
    enum {value = -1};
};
template <class T,class Tail>  struct IndexOf< TypeList<T, Tail>, T >
{
    enum {value = 0};
};

template <class Head,class Tail, class T>  struct IndexOf< TypeList<Head, Tail>, T >
{
private:
    enum { temp = IndexOf<Tail,T>::value };
public:
    enum { value = temp==-1 ? -1 : 1 + temp};
};


//
// Append
//
template <class TList, class T>  struct Append{
        typedef TypeList<T,TList> result; 
};

//
// push_front
//
template <class TList, class T>  struct push_front
{
    typedef TypeList<T, TList> result;
};
//
template<typename T>
void f(T a){
      typename T::bar *p;
}
struct TWithBar{
      public:
             typedef int bar;
};

int main(int argc, char *argv[])
{
    TWithBar bar;
    f(bar);
    //
    printf("Hello, world\n");

    typedef TYPELIST_3(int, float,char) MyTypeList;
    printf("MyTypeList length %d\n", Length<MyTypeList>::value);

    printf("MyTypeList TypeAt 0 %s\n", typeid(TypeAt<MyTypeList,0>::Result).name());
    printf("MyTypeList TypeAt 0 %s\n", typeid(TypeAt<MyTypeList,1>::Result).name());
    printf("MyTypeList TypeAt 0 %s\n", typeid(TypeAt<MyTypeList,2>::Result).name());
    //
    printf("MyTypeList IndexOf<int> %d\n", IndexOf<MyTypeList, int>::value);
    printf("MyTypeList IndexOf<float> %d\n", IndexOf<MyTypeList, float>::value);
    printf("MyTypeList IndexOf<char> %d\n", IndexOf<MyTypeList, char>::value);

//
    Derived q1,q2;
    Hack vector;
    Hack UNIT4;
    Hack foo;
    vector<UNIT4> foo;
    //
    cout<<myMax(1,2)<<endl;
    cout<<myMax(1.2,2.0)<<endl;
    cout<<myMax(1.3,2.0)<<endl;
    cout<<myMax(1.2,2.0)<<endl;
//    myMax(q1,q2);
    //
    Derived k;
    SleepSofa s;
    /*
    furnit 0
    bed 1
    furn 3
    
    sofa 2
    
    */
    s.sleep();
    s.watchTV();
    s.foldOut();
    //
    s.setWeight(1000);
    s.Sofa::print();
    s.Bed::print();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
