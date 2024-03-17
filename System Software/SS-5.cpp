#include<bits/stdc++.h>
using namespace std;
bool isoperator(char c)
{
string operators = "+-*/%=$";
return operators.find(c) != string::npos;
}
void pri(char stk[])
{
for(int i=0;i<20;i++)
if(isoperator(stk[i]) || isalpha(stk[i])) cout<<stk[i];
else break;
}
void SRP()
{
// char stk[20], input[20], act[20];
string input, act;
char stk[20];
int i = 0, k = 0, c;
// strcpy(stk, "$");
// stk+='$';
stk[0]='$';
23
SYSTEM SOFTWARE UI21CS43
// memset(stk,'$',sizeof(stk));
printf("The Grammer is \n\t\tE->E+T|T\n\t\tT->T*F|F\n\t\tF->E|id\n");
printf("Input The String : ");
cin>>input;
c = input.length();
printf("Stack\t Input\t\tAction\n");
printf("------- -------- -------------\n");
while (i <= c)
{
if (stk[k] == '$')
{
if (input[i] == '(')
{
stk[k] = '(';
input[i] = ' ';
i = i + 1;
}
else if (input[i] == 'i' && input[i + 1] == 'd')
{
stk[k] = 'i';
stk[k + 1] = 'd';
k = k + 1;
input[i] = ' ';
input[i + 1] = ' ';
i = i + 2;
}
else
{
printf("error\n");
return;
24
SYSTEM SOFTWARE UI21CS43
}
// strcpy(act, "Shift");
act="Shift";
cout <<"$";pri(stk);cout<< "\t" << input << "$\t" << act << endl;
}
else if (stk[k] == '(')
{
if (input[i] == 'i' && input[i + 1] == 'd')
{
stk[k + 1] = input[i];
stk[k + 2] = input[i + 1];
k = k + 1;
input[i] = ' ';
input[i + 1] = ' ';
i = i + 2;
}
else
{
cout<<"Error";
return;
}
// strcpy(act, "Shift");
act="Shift";
cout <<"$";pri(stk);cout<< "\t" << input << "$\t" << act << endl;
}
else if (stk[k - 1] == 'i' && stk[k] == 'd')
{
if (input[i] == '+' ||
input[i] == '*' || input[i] == '\0')
{
25
SYSTEM SOFTWARE UI21CS43
stk[k - 1] = 'F';
stk[k] = ' ';
k = k - 1;
// strcpy(act, "Redue F->id");
act="Reduce F->id";
}
else
{
printf("error\n");
return;
}
cout <<"$";pri(stk);cout<< "\t" << input << "$\t" << act << endl;
}
else if (stk[k] == '*' || stk[k] == '+')
{
if (input[i] == 'i' && input[i + 1] == 'd')
{
stk[k + 1] = 'i';
stk[k + 2] = 'd';
k = k + 2;
input[i] = ' ';
input[i + 1] = ' ';
i = i + 2;
// strcpy(act, "Shift");
act="Shift";
}
else
{
cout<<"Error";
return;
26
SYSTEM SOFTWARE UI21CS43
}
cout <<"$";pri(stk);cout<< "\t" << input << "$\t" << act << endl;
}
else if (stk[k] == 'F')
{
if (input[i] == '+' || input[i] == '*' || (input[i] == '\0' && stk[k - 1] == '+'))
{
stk[k] = 'T';
// strcpy(act, "RedceT->F");
act="ReduceT->F";
}
else if (input[i] == '\0' && stk[k - 1] == '*')
{
stk[k - 2] = 'T';
stk[k] = ' ';
stk[k - 1] = ' ';
k = k - 2;
// strcpy(act, "ReduceT->T*F");
act="ReduceT->T*F";
}
else
{
cout<<"Error";
return;
}
cout <<"$";pri(stk);cout<< "\t" << input << "$\t" << act << endl;
}
else if (stk[k] == 'T')
{
27
SYSTEM SOFTWARE UI21CS43
if (input[i] == '+')
{
stk[k] = 'E';
// strcpy(act, "Reduce E->T");
act="Reduce E->T";
}
else if (input[i] == '*')
{
stk[k + 1] = '*';
k = k + 1;
input[i] = ' ';
i = i + 1;
// strcpy(act, "Shift");
act="Shift";
}
else if (input[i] == '\0')
{
stk[k - 2] = 'E';
stk[k] = ' ';
stk[k - 1] = ' ';
k = k - 2;
// strcpy(act, "Reduce E->E+T");
act="Reduce E->E+T";
}
else
{
cout<<"Error";
return;
}
cout <<"$";pri(stk);cout<< "\t" << input << "$\t" << act << endl;
28
SYSTEM SOFTWARE UI21CS43
}
else if (stk[k] == 'E')
{
if (input[i] == '+' || input[i] == ')')
{
stk[k + 1] = input[i];
k = k + 1;
input[i] = ' ';
i = i + 1;
// strcpy(act, "Shift"); act="Shift";
}
else if (input[i] == '\0')
{
// strcpy(act, "Accepted");
act="Accepted";
cout <<"$";pri(stk);cout<< "\t" << input << "$\t" << act << endl;
return;
}
cout <<"$";pri(stk);cout<< "\t" << input << "$\t" << act << endl;
}
else if (stk[k] == ')')
{
stk[k - 2] = 'F';
stk[k] = ' ';
stk[k - 1] = ' ';
k = k - 2;
// strcpy(act, "Redue F->(E)");
act="Redue F->(E)";
cout <<"$";pri(stk);cout<< "\t" << input << "$\t" << act << endl;
}
29
SYSTEM SOFTWARE UI21CS43
else
{
cout<<"Error";
return;
}
}
}
void OPP()
{
string s,t="$";
cout<<"The Grammar is \n\t\tE->EAE|a\n\t\tA->*|+\n";
cout<<"Enter a String : ";
cin>>s;
for(int i=0;i<s.size();i++)
{
if(isalpha(s[i]))
{
t+='<';
t+=s[i];
t+='>';
}
else t+=s[i];
}
t+='$';
cout<<t<<endl;
for(int i=0;i<t.size();i++)
{
if(t[i]=='<' && t[i+1]=='a' && t[i+2]=='>')
{
t.replace(i,3,"E");
30
SYSTEM SOFTWARE UI21CS43
}
else if(isoperator(t[i])) continue;
cout<<t<<endl;
}
for(int i=t.size()-2;i!=0;i--)
{
if(t[i]=='E' && t[i-1]=='*' && t[i-2]=='E') t.replace(i-2,3,"E");
else if(t[i]=='E' && t[i-1]=='+' && t[i-2]=='E') t.replace(i-2,3,"E");
else if(isoperator(t[i])) continue;
cout<<t<<endl;
}
cout<<endl;
if(t=="$E$") cout<<"String Accepted";
else cout<<"String Rejected";
}
int main()
{
int decision;
cout<<"\t\t\t-----Bottom-Up Parsers-----\n";
while(1)
{
cout<<"1. Shift Reduce Parser"<<endl;
cout<<"2. Operator Precedence"<<endl;
cout<<"3. Exit"<<endl;
cout<<"Enter your choice :";
cin>>decision;
switch (decision)
{
case 1:
31
SYSTEM SOFTWARE UI21CS43
SRP();
cout<<endl<<endl;
break;
case 2:
OPP();
cout<<endl<<endl;
break;
case 3:
exit(0);
default:
cout<<"Enter Valid Number(1-3)\n\n";
break;
}
}
}