#include<cstdlib>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
#define Trace(m) cout<<#m"="<<(m)<<endl;
class Foo{
	private:
		static double a;
		float max,min;
		double k;
};double Foo::a=0;
template<class T>
struct CC;

template<class T,class T1>struct Pari{};

template<class T,class T1>
struct CC<Pari<T,T1> >{
	typedef  T1 k;
};
class Depart{
	public:
		Depart(int i=0){
			d=i;
			cout
				<<"Constructing depart:"<<d<<endl;
		}
		Depart(const Depart&p){
			d=p.d;
			cout<<"Copy construcitng depart:"<<d<<endl;
		}
		~Depart(){
			cout<<"Destructing of depart..."<<d<<endl;
		}
		Depart& operator=(const Depart &p){
			cout<<"calling operator= of depart set"<<d<<" equal to "<<p.d<<endl;
			d=p.d;
		}
	private:
		int d;
};
class    Employ{
	public:
		Employ(int emp=5,int dep=1):depart(dep){
			cout<<"constructing empoy "<<emp<<endl;
		}                    
		~Employ(){
			cout<<"destructing of employ"<<emp<<endl;
		}
		Depart getDepart(){return depart;}
	private :Depart depart;
		 int emp;
};

class Dic{
	public:
		Dic(){
              Dic::dict["a"]="adfa";
              }
		void addPair(char *e,char *c);
		void translate(char *e,char *c);
	private:
		map<string,string> dict;
};
void Dic::addPair(char *e,char *c){
	dict[string(e)]=string(c);
}
void Dic::translate(char *e,char *c){
	char buffer[100];
	int len=0;
	while(*e!=0){
		len=0;
		while(*e==' ' )e++;
		while(*e!=' ' && *e!=0){
			buffer[len++]=*e;
			e++;
		}
		if(len>0){
    		buffer[len]=0;
    		string tran;
    		if(dict.find(buffer)!=dict.end()){
    			tran=dict[buffer];
    			strcpy(c,tran.c_str());
    			c+=strlen(c);
    		}else{
    			strcpy(c,"(Unknown)");
    			c+=strlen(c);
    		}
        }
	}
}
void f(int a){
     cout<<"f(int)"<<endl;
     }
     void f(int a,double){
          cout<<"f(int,float)"<<endl;
          }
union UnionTest{
      public:
             int a;
             private:
                   int  b;
                     };
int main(){
    cout<<"123\x0b \x30456789\b0123"<<"\b"<<"adding";
    cout<<"\b\b\bother";
    
    f(2);
    f(2,4);
    Trace(9/2);
        Trace(9.0/2);
            Trace(9/2.0);
                Trace(9.0/2.0);
    //
    UnionTest u;
    Trace('\251');
    //u.b;
    //
    Dic dic,*pdic;
    pdic=&dic;
    pdic->addPair("a","b");
    (*pdic).addPair("a","badf");
    dic.addPair("I","我");
    dic.addPair("am","是");
    dic.addPair("a","一个");
    dic.addPair("student","学生");
    char buffer[100]=" I  am a  student ";
    char chinese[100];
    do{
    dic.translate(buffer,chinese);
    cout<<chinese<<endl;;
    cin.getline(buffer,100,'\n');
}while(1);
    //
	Depart dep;
	Employ emp;
	const Depart &temp=emp.getDepart();
	dep=temp;

	//
	/*	CC<Pari<char,int> > a;
		Trace(012);
		Trace(12);
		Trace(0x12);
		Trace('\060');
	//
	Trace(sizeof(Foo));*/
	system("pause");
	return 0;
}
