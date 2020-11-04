#include<iostream>
#include<string>
using namespace std;
//#define max 100;

struct edge{
string chutai;
string change;
string zhongtai;
};

int N;
string part[100];

string move(string jihe,char ch,edge *b){
int i,j;
string s="";
for(i=0;i<jihe.length();i++){
for(j=0;j<N;j++){
if(b[j].chutai[0]==jihe[i] && b[j].change[0]==ch) s=s+b[j].zhongtai;
}
}
if(s=="") return "&";
else return s;
}

bool isexist(string s,string d){
if(d!="" && 0<=d.find(s) && d.find(s)<=d.length()-1) return 1;
else return 0;
}

int divide(edge *b,string change){
int x,m,flag=2,flag0,i,j;
string ss,part0[100];
flag0=flag;
for(x=0;x<change.length();x++){
for(m=0;m<flag0;m++){
for(i=0;i<part[m].length();i++){
ss=move(part[m].substr(i,1),change[x],b);
for(j=0;j<flag;j++){
if(isexist(ss,part[j])) part0[j]=part0[j]+part[m].substr(i,1);
if(ss=="&"){
part0[flag]=part0[flag]+part[m].substr(i,1);
break;
}
}
}
for(j=0;j<flag;j++){
if(part0[j]!="" && part0[j]!=part[m]){
part[flag++]=part0[j];
part0[j]="";
part[m]="";
}
else part0[j]="";
}
}
flag0=flag;
}
return flag;
}

int main(int argc, char const *argv[]) {
int i,j,flag,x;
string Change;
string ss;
edge *b=new edge[100];
cout<<"请输入你要输入的DFA各边信息：起点条件（空用&表示）终点以输入#结束。"<<endl;
for(i=0;i<100;i++){
cin>>b[i].chutai;
if(b[i].first=="#") break;
else
cin>>b[i].change>>b[i].zhongtai;
}
N=i;

cout<<"请输入这个DFA的最终态集合："<<endl;
cin>>part[1];
cout<<"请输入这个DFA的非终结态集合："<<endl;
cin>>part[0];
cout<<"请输入这个DFA状态中的输入符号即边上的条件："<<endl;
cin>>Change;
flag=divide(b,Change);
cout<<"此DFA最小化划分的子集如下："<<endl;
for(i=0;i<flag;i++){
if(part[i]!="") cout<<part[i]<<endl;
}
cout<<"用A、B、C...等代替子集：";
for(i=0;i<flag;i++){
if(part[i]!="") cout<<"{"<<part[i]<<"},";
}
cout<<endl<<"则DFA最小化后的各边信息如下："<<endl;
char letters[100];
char letter='A';
for(i=0;i<flag;i++){
if(part[i]!=""){
letters[i]=letter;
++letter;
}
}
for(i=0;i<flag;i++){
for(j=0;j<Change.length();j++){
ss=move(part[i],Change[j],b);
if(part[i]!="" && ss!="&") cout<<letters[i]<<" "<<Change[j]<<" ";
for(x=0;x<flag;x++){
if(isexist(ss.substr(0,1),part[x])) cout<<letters[x]<<endl;
}
}
}
system("pause");
return 0;
}
