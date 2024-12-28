#include <iostream>
#include <string>
#include <math.h>
#include <stack>
bool pair(std::string mid);
bool zero(std::string mid);
bool sigpos(std::string mid);
bool check(std::string mid);
double cal(std::string mid);
double cal_2(double a, double b, char p);

bool zero(std::string mid)
{
   for (int i=0;i<mid.length()-1;i++)
   {
       if (mid[i]=='/' && mid[i+1]=='0')
       {
        if (i<=mid.length()-3 && !isdigit(mid[i+2]) && mid[i+2]!='.') return false;
        if (i==mid.length()-2) return false;
       }
   }
   return true;
}

bool sigpos(std::string mid)
{
   int last=mid.length()-1;
   if (mid[0]=='+' || mid[0]=='-' || mid[0]=='*' || mid[0]=='/') return false;
   if (mid[last]=='+' || mid[last]=='-' || mid[last]=='*' || mid[last]=='/') return false;
   for (int i=0;i<last;i++)
   {
      if (mid[i]=='+' || mid[i]=='-' || mid[i]=='*' || mid[i]=='/')
      {
         if (mid[i+1]=='+' || mid[i+1]=='-' || mid[i+1]=='*' || mid[i+1]=='/')
         {
            return false;
         }
      }
   }
   return true;
}

bool pair(std::string mid)
{
    int left,right=0;
    for (int i=0;i<mid.length();i++)
    {
        if (mid[i]=='(') left++;
        if (mid[i]==')') right++;
        if (right>left) return false;
    }
    return (left==right);
}

bool check(std::string mid)
{
   return pair(mid)&&zero(mid)&&sigpos(mid);
}

double cal_2(double a, double b, char p)
{
    switch (p)
    {
        case '+': return (a+b); break;
        case '-': return (a-b); break;
        case '*': return (a*b); break;
        case '/': return (a/b); break;
    }
    return 1;
}

double cal(std::string mid)
{
   char temp;
   int len=mid.length();
   int digit_initial=0;
   std::stack<double> num;
   std::stack<char> signal;
   int digit_exist=0;
   for (int i=0;i<len;i++)
   {
      while (isdigit(mid[i]) || mid[i]=='.') 
      {
        if (digit_exist==0) 
        {
          digit_initial=i;
          digit_exist=1;
        }
        i++;
      }//若是数值部分则跳过
      if (digit_exist==1) num.push(std::stof(mid.substr(digit_initial,i-digit_initial)));
      //现在处理符号位


      switch (mid[i])
      {
         case '+': 
         while (!signal.empty() && signal.top()!='(')
   {
     double temp2=num.top();
     num.pop();
     double temp1=num.top();
     num.pop();
     num.push(cal_2(temp1,temp2,signal.top()));
     signal.pop();
   }
   signal.push('+');
   break;


  case '-': 
  while (!signal.empty() && signal.top()!='(')
   {
     double temp2=num.top();
     num.pop();
     double temp1=num.top();
     num.pop();
     num.push(cal_2(temp1,temp2,signal.top()));
     signal.pop();
   }
   signal.push('-');
   break;



         case '*':
         while (!signal.empty() && (signal.top()=='*' || signal.top()=='/'))
         {
             double temp2=num.top();
             num.pop();
             double temp1=num.top();
             num.pop();
             num.push(cal_2(temp1,temp2,signal.top()));
             signal.pop();
         }
          signal.push('*');
          break;


         case '/':
          while (!signal.empty() && (signal.top()=='*' || signal.top()=='/'))
         {
             double temp2=num.top();
             num.pop();
             double temp1=num.top();
             num.pop();
             num.push(cal_2(temp1,temp2,signal.top()));
             signal.pop();
         }
          signal.push('/');
          break;

         case '(': 
         signal.push('('); break;

         
         case ')': 
         while (signal.top()!='(')
         {
             double temp2=num.top();
             num.pop();
             double temp1=num.top();
             num.pop();
             num.push(cal_2(temp1,temp2,signal.top()));
             signal.pop();
         }
          signal.pop();  //弹出(
          break;
      }
      digit_exist=0;
   }

   while (!signal.empty())
   {
     double temp2=num.top();
     num.pop();
     double temp1=num.top();
     num.pop();
     num.push(cal_2(temp1,temp2,signal.top()));
     signal.pop();
   }

   return num.top();
}