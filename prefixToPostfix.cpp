#include <bits/stdc++.h>
using namespace std;

#define shofiul
#define ll long long

void solve();

int main(){
    #ifdef shofiul
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    //cin>>t;

    while(t--){
        solve();
    }
    return 0;
}

double postfixSum(string s){
    stack<double> stk;
    for(char x:s){
        if(x == '/'){
            double a = stk.top();stk.pop();
            double b = stk.top();stk.pop();
            stk.push(b/a);
        }else if(x == '-'){
            double a = stk.top();stk.pop();
            double b = stk.top();stk.pop();
            stk.push(b-a);
        }else if(x == '+'){
            double a = stk.top();stk.pop();
            double b = stk.top();stk.pop();
            stk.push(b+a);
        }else if(x == '*'){
            double a = stk.top();stk.pop();
            double b = stk.top();stk.pop();
            stk.push(b*a);
        }else{
            double d = (double)(x - 48); // convert to int ascii char - 48
            stk.push(d);
        }
    }
    return stk.top();
}

bool isOperator(char c){
    return c == '+' or c == '-' or c == '*' or c == '/' or c == '('; 
}

bool isClosingParenthesis(char c){
    return c == ')';
}

string convertInfixToPostfix(string str){
    vector<char> v;
    stack<char> stk;
    bool closing = false;
    v.reserve(str.size());
    for(char x:str){
        if(isOperator(x)){ // if operator push to the stack
            if(closing){ // if we encouter a closing parenthesis in the else block
                closing = false;
                // Pop until the operator has less power or encounter a open parenthesis
                if(x == '*' or x == '/'){ // +,- are posses lesser power than *,-
                    while(!stk.empty()){
                        if(stk.top() == '('){
                            stk.pop();
                            break;
                        }else if(stk.top() == '+' or stk.top() == '-'){
                            break;
                        }
                        v.push_back(stk.top());
                        stk.pop();
                    }
                }else{
                    // since + and - posses the lowest power loop will break it we encounter an open parenthesis
                    while(!stk.empty()){
                        if(stk.top() == '('){
                            stk.pop();
                            break;
                        }
                        v.push_back(stk.top());
                        stk.pop();
                    }
                }
            }
            // push current operator to the stack
            stk.push(x);
            
        }else{
            // if encouter closing parenthesis pop the stack until encounter an open parenthesis
            if(isClosingParenthesis(x)){
                closing = true; // make the closing parenthesis flag on
                while(!stk.empty()){
                    // pop until stack is empty or envounter an open parenthesis
                    if(stk.top() == '('){
                        stk.pop();
                        break;
                    }
                    v.push_back(stk.top());
                    stk.pop();
                }
            }else{
                closing = false; // keep it false for safty (what if we don't encounter an operator after enconter a closing parenthesis)
                v.push_back(x);
            }
        }

    }
    //convert the char array to string
    string result(v.begin(),v.end());

    // return the postfix string
    return result;
}

bool isOperatorForInfix(char c){
    return c == '+' or c == '-' or c == '*' or c == '/'; 
}

string convertPrefixToPostfix(string s){
    deque<char> dq;
    stack<char> stk;
    bool first = true;
    bool previousEncounterOperator = false;
    int len = s.size();
    for(int i = len-1;i>=0;i--){
        if(isOperatorForInfix(s[i])){
            if(first){ // first time pop two
                first = false;
                char a = stk.top(); stk.pop();
                char b = stk.top(); stk.pop();
                dq.push_back(s[i]);
                dq.push_front(b);
                dq.push_front(a);
            }else{ // then pop one
                char a = stk.top(); stk.pop();
                if(previousEncounterOperator){
                    // if the pervious char was an operator than
                    // the operand will be added in the back of the deque
                    // before the current operator  
                    dq.push_back(a);
                }else{
                    dq.push_front(a);
                }
                dq.push_back(s[i]);
                
            }
            previousEncounterOperator = true;
            
        }else{
            previousEncounterOperator = false;
            stk.push(s[i]);
        }
    }
    string str(dq.begin(),dq.end());
    return str;
}


// prefix to postfix: *4-+1*2/935 =>  41293/*+5-*

void solve(){
   string s;
   cin>>s;
   string prefixToPostfix = convertPrefixToPostfix(s);
   cout<<prefixToPostfix<<endl;
   double sum = postfixSum(prefixToPostfix);
   cout<<"Sum: "<<sum<<endl;
   return;
}