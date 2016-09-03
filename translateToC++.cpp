#include<iostream>
#include<fstream>
using namespace std;
const char prefix[]="cout<<\"";
const char suffix[]="\"<<endl;\n";
char *change(const char *str,char *buf,const char *prefix,const char *suffix){
     const char *p=str;
     char *p2=buf;
     strcpy(p2,prefix);
     p2+=strlen(prefix);
     while(*p){
          switch(*p){
                     case '\"':
                          strcpy(p2,"\\\"");
                          p2+=2;
                          break;
                     case '\\':
                          strcpy(p2,"\\\\");
                          p2+=2;
                          break;
                     default:
                           *p2=*p;
                           p2++;
                           }
                           p++;  
               }
                strcpy(p2,suffix);
     p2+=strlen(suffix);
               *p2=0;
               return buf;
}
void tran(istream &in,ostream &out,const char *prefix,const char *suffix){
     char buffer[1024];
 char buffer2[1024];
 while( 1){
        in.getline(buffer,1024,'\n');
         if(in.eof())break;
        out<<change(buffer,buffer2,prefix,suffix);
       
        }
}
#if 0
int main(){
    #define IN_FILE "in.txt"
    fstream infile(IN_FILE);
    if(infile.fail()){
                      cout<<"can't open "IN_FILE<<endl;
                      return 0;
                      }
    ofstream outfile("out.txt");
 tran(infile,outfile,prefix,suffix);
 outfile.close();
system("pause");
return 0;   
}
#endif

#if 1
int main(){
    ofstream outfile("out.html");


    #define cout outfile
 cout<<"<HTML><HEAD>"<<endl;
cout<<"<TITLE>cgic test</TITLE></HEAD>"<<endl;
cout<<"<BODY><H1>cgic test</H1>"<<endl;
cout<<"<!-- 2.0: multipart/form-data is required for file uploads. --><form method=\"POST\" enctype=\"multipart/form-data\" 	action=\"/cgi-bin/cgitest.exe\">"<<endl;
cout<<"<p>"<<endl;
cout<<"Text Field containing Plaintext"<<endl;
cout<<"<p>"<<endl;
cout<<"<input type=\"text\" name=\"name\">Your Name"<<endl;
cout<<"<p>"<<endl;
cout<<"Multiple-Line Text Field"<<endl;
cout<<"<p>"<<endl;
cout<<"<textarea NAME=\"address\" ROWS=4 COLS=40>"<<endl;
cout<<"Default contents go here. "<<endl;
cout<<"</textarea>"<<endl;
cout<<"<p>"<<endl;
cout<<"Checkbox"<<endl;
cout<<"<p>"<<endl;
cout<<"<input type=\"checkbox\" name=\"hungry\" checked>Hungry"<<endl;
cout<<"<p>"<<endl;
cout<<"Text Field containing a Numeric Value"<<endl;
cout<<"<p>"<<endl;
cout<<"<input type=\"text\" name=\"temperature\" value=\"98.6\">"<<endl;
cout<<"Blood Temperature (80.0-120.0)"<<endl;
cout<<"<p>"<<endl;
cout<<"Text Field containing an Integer Value"<<endl;
cout<<"<p>"<<endl;
cout<<"<input type=\"text\" name=\"frogs\" value=\"1\">"<<endl;
cout<<"Frogs Eaten"<<endl;
cout<<"<p>"<<endl;
cout<<"Single-SELECT"<<endl;
cout<<"<br>"<<endl;
cout<<"<select name=\"colors\">"<<endl;
cout<<"<option value=\"Red\">Red"<<endl;
cout<<"<option value=\"Green\">Green"<<endl;
cout<<"<option value=\"Blue\">Blue"<<endl;
cout<<"</select>"<<endl;
cout<<"<br>"<<endl;
cout<<"Multiple-SELECT"<<endl;
cout<<"<br>"<<endl;
cout<<"<select name=\"flavors\" multiple>"<<endl;
cout<<"<option value=\"pistachio\">Pistachio"<<endl;
cout<<"<option value=\"walnut\">Walnut"<<endl;
cout<<"<option value=\"creme\">Creme"<<endl;
cout<<"</select>"<<endl;
cout<<"<p>Exclusive Radio Button Group: Age of Truck in Years"<<endl;
cout<<"<input type=\"radio\" name=\"age\" value=\"1\">1"<<endl;
cout<<"<input type=\"radio\" name=\"age\" value=\"2\">2"<<endl;
cout<<"<input type=\"radio\" name=\"age\" value=\"3\" checked>3"<<endl;
cout<<"<input type=\"radio\" name=\"age\" value=\"4\">4"<<endl;
cout<<"<p>Nonexclusive Checkbox Group: Voting for Zero through Four Candidates"<<endl;
cout<<"<input type=\"checkbox\" name=\"vote\" value=\"A\">A"<<endl;
cout<<"<input type=\"checkbox\" name=\"vote\" value=\"B\">B"<<endl;
cout<<"<input type=\"checkbox\" name=\"vote\" value=\"C\">C"<<endl;
cout<<"<input type=\"checkbox\" name=\"vote\" value=\"D\">D"<<endl;
cout<<"<p>File Upload:"<<endl;
cout<<"<input type=\"file\" name=\"file\" value=\"\"> (Select A Local File)"<<endl;
cout<<"<p>"<<endl;
cout<<"<p>Set a Cookie<p>"<<endl;
cout<<"<input name=\"cname\" value=\"\"> Cookie Name"<<endl;
cout<<"<input name=\"cvalue\" value=\"\"> Cookie Value<p>"<<endl;
cout<<"<input type=\"submit\" name=\"testcgic\" value=\"Submit Request\">"<<endl;
cout<<"<input type=\"reset\" value=\"Reset Request\">"<<endl;
cout<<"<p>Save the CGI Environment<p>"<<endl;
cout<<"Pressing this button will submit the form, then save the CGI environment so that it can be replayed later by calling cgiReadEnvironment (in a debugger, for instance).<p>"<<endl;
cout<<"<input type=\"submit\" name=\"saveenvironment\" value=\"Save Environment\">"<<endl;
cout<<"</form>"<<endl;
cout<<"</BODY></HTML>"<<endl;

 outfile.close();

system("pause");
return 0;   
}
#endif
