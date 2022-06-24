/**Using stack to
 * check whether brackets are balanced
 * evaluate postfix and prefix expressions
 * convert infix to postfix and prefix
*/

#include<iostream>
#include<stack>     //push(), pop(), empty(), top()
#include<algorithm> //reverse()
using namespace std;

bool isOpeningBracket(char b)
{
  return (b == '(' || b == '{' || b == '[');
}

bool isClosingBracket(char b)
{
  return (b == ')' || b == '}' || b == ']');
}

bool isMatchingBracketPair(char b1, char b2)
{
  return (
          (b1 == '(' && b2 == ')') ||
          (b1 == '{' && b2 == '}') ||
          (b1 == '[' && b2 == ']')
         );
}

//function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
  stack<char> s;
  for(auto ch: expr)
  {
    if(isOpeningBracket(ch))
    {
      s.push(ch);
    }
    else if(isClosingBracket(ch))
    {
      if(!s.empty() && isMatchingBracketPair(s.top(), ch))
        s.pop();
      else
        return false;
    }
  }
  return s.empty();  //if stack is empty, return true
}

bool isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

//evaluate postfix expressions
float postfixEvaluate(string expr)
{
  stack<float> s;
  for(int i=0; i<expr.length(); i++)
  {
    if(isdigit(expr[i]))
    {
      float x = 0;
      while(isdigit(expr[i]))
      {
        x = 10*x + (expr[i]-'0');
        i++;
      }
      i--;
      s.push(x);
    }
    else if(isOperator(expr[i]))
    {
      float operand2 = s.top();
      s.pop();
      float operand1 = s.top();
      switch(expr[i])
      {
        case '+':s.top()=operand1 + operand2; break;
        case '-':s.top()=operand1 - operand2; break;
        case '*':s.top()=operand1 * operand2; break;
        case '/':s.top()=operand1 / operand2; break;
      }
    }
  }
  return s.top();
}

//evaluate prefix expressions
float prefixEvaluate(string expr)
{
  stack<float> s;
  for(int i = expr.length()-1; i>=0;i--)
  {
    if(isdigit(expr[i]))
    {
      float x = 0, mul=1;
      while(isdigit(expr[i]))
      {
        x+=mul*(expr[i]-'0');
        mul*=10;
        i--;
      }
      i++;
      s.push(x);
    }
    else if(isOperator(expr[i]))
    {
      float operand1 = s.top();
      s.pop();
      float operand2 = s.top();
      switch(expr[i])
      {
        case '+':s.top()=operand1 + operand2; break;
        case '-':s.top()=operand1 - operand2; break;
        case '*':s.top()=operand1 * operand2; break;
        case '/':s.top()=operand1 / operand2; break;
      }     
    }
  }
  return s.top();
}

bool hasHigherPrecedence(char ch1, char ch2)
{
  if((ch1 == '*' || ch1 == '/') && (ch2 == '*' || ch2 == '/' || ch2 == '+' || ch2 == '-'))
    return true;
  else if((ch1 == '+' || ch1 == '-') && (ch2 == '+' || ch2 == '-'))
    return true;
  else
    return false;
}

//infix to postfix
//Example: 2+3*(4-7+3/(8+9)) --> 2 3 4 7 - 3 8 9 + / + * +
string infixToPostfix(string expr)
{
  string res = "";
  stack<char> s;
  for(int i=0;i<expr.length();i++)
  {
    if(isOpeningBracket(expr[i]))
      s.push(expr[i]);
    else if(isalnum(expr[i]))
    {
      while(isalnum(expr[i]))
      {
        res+=expr[i];
        i++;
      }
      res+=" ";
      i--;
    }
    else if(isOperator(expr[i]))
    {
      while(!s.empty() && hasHigherPrecedence(s.top(), expr[i]) && !isOpeningBracket(s.top()))
      {
        res+=s.top(); res+=" ";
        s.pop();
      }
      s.push(expr[i]); 
    }
    else if(isClosingBracket(expr[i]))
    {
      while(!s.empty() && !isOpeningBracket(s.top()))
      {
        res+=s.top(); res+=" ";
        s.pop();
      }
      s.pop();
    }
  }
  while(!s.empty())
  {
    res+=s.top(); res+=" ";
    s.pop();
  }
  return res;
}

//infix to prefix
//we will reverse the infix string, and then convert into postfix and then reverse
//the postfix expression to get prefix
string infixToPrefix(string expr)
{
  reverse(expr.begin(),expr.end());
  for(int i=0;i<expr.length();i++)
  {
    if(isOpeningBracket(expr[i]))
    {
      expr[i] = ')';
    }
    else if(isClosingBracket(expr[i]))
    {
      expr[i] = '(';
    }
  }
  string prefix = infixToPostfix(expr);
  reverse(prefix.begin(), prefix.end());
  return prefix;
}

int main()
{
  string expr = "2+3*(4-7+3/(8+9))";
  if(areBracketsBalanced(expr))
    cout<<"Brackets are balanced\n";
  string expr_postfix = infixToPostfix(expr);
  string expr_prefix = infixToPrefix(expr);
  cout<<"Infix Expression: "<<expr<<endl;
  cout<<"Postfix Expression: "<<expr_postfix<<endl;
  cout<<"Prefix Expression: "<<expr_prefix<<endl;

  cout<<"Postfix Evaluation: "<<postfixEvaluate(expr_postfix)<<endl;
  cout<<"Prefix Evaluation: "<<prefixEvaluate(expr_prefix)<<endl;
}