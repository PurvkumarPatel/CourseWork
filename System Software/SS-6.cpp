#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class ThreeAddressCode {
public:
    ThreeAddressCode() {
        temp_count = 0;
    }

    void emit(string op, string arg1, string arg2, string result) {
        code.push_back( "    "+ op + "          " + arg1 + "            " + arg2 + "           " + result);
        code4.push_back("  "+arg1 + " " + op + " " + arg2 + " = " + result);
        if(arg1.size()>1 && arg2.size()>1)
        {
            code1.push_back("   " + op + "          " + arg1[1] + "            " + arg2[1]);
        }
        else if(arg1.size()>1)
        {
            code1.push_back("   " + op + "          " + arg1[1] + "            " + arg2);
        }
        else if(arg2.size()>1)
        {
            code1.push_back("   " + op + "          " + arg1 + "            " + arg2[1]);
        }
        else
        {
            code1.push_back("   " + op + "          " + arg1 + "            " + arg2);
        }

        if(arg1.size()>1 && arg2.size()>1)
        {
            code2.push_back("   " + op + "          " + char(((int(arg1[1])-48+20)/10)+48)+ char(((int(arg1[1])-48+20)%10)+48) + "            " + char(((int(arg2[1])-48+20)/10)+48)+ char(((int(arg2[1])-48+20)%10)+48));
        }
        else if(arg1.size()>1)
        {
            code2.push_back("   " + op + "          " +char(((int(arg1[1])-48+20)/10)+48)+ char(((int(arg1[1])-48+20)%10)+48) + "            " + arg2);
        }
        else if(arg2.size()>1)
        {
            code2.push_back("   " + op + "          " + arg1 + "            " + char(((int(arg2[1])-48+20)/10)+48)+ char(((int(arg2[1])-48+20)%10)+48));
        }
        else
        {
            code2.push_back("   " + op + "          " + arg1 + "            " + arg2);
        }
    }

    string new_temp() {
        string temp = "t" + to_string(temp_count++);
        v.push_back({temp_count-1,20+temp_count-1});
        return temp;
    }

    void print_code() {
            cout<<"Sr No. Operation   Source1    Source2     Destination "<<endl;
        for (int i = 0; i < code.size(); i++) {
            cout <<i<<"     "<< code[i] << endl;
        }
    }
    void print_code1() {
            cout<<"Sr No. Operation   Source1    Source2"<<endl;
        for (int i = 0; i < code.size(); i++) {
            cout <<i<<"     "<< code1[i] << endl;
        }
    }
    void print_code2() {
            cout<<"Sr No. Operation   Source1    Source2"<<endl;
        for (int i = 0; i < code.size(); i++) {
            cout <<i<<"     "<< code2[i] << endl;
        }
    }
    void print_code4() {
            cout<<"Sr No. Equation"<<endl;
        for (int i = 0; i < code.size(); i++) {
            cout <<i<<"     "<< code4[i] << endl;
        }
    }
    void print_code3() {
        cout<<"list of pointer table"<<endl;
        cout<< "Pointed        Pointer"<<endl;
        for(auto it :v)
        {
            cout<<it.first << "                 "<<it.second<<endl;
        }
    }

private:
    vector<string> code,code1,code2,code4;
    vector<pair<int,int>> v;
    int temp_count;
};

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}

void process_operator(stack<char>& op_stack, stack<string>& val_stack, ThreeAddressCode& tac) {
    char op = op_stack.top();
    op_stack.pop();
    string right_operand = val_stack.top();
    val_stack.pop();
    string left_operand = val_stack.top();
    val_stack.pop();
    string result = tac.new_temp();
    tac.emit(string(1, op), left_operand, right_operand, result);
    val_stack.push(result);
}

void process_expression(const string& input, ThreeAddressCode& tac) {
    stack<char> op_stack;
    stack<string> val_stack;
    int i = 0;
    while (i < input.length()) {
        char c = input[i];
        if (c == ' ') {
            i++;
        } else if (c == '(') {
            op_stack.push(c);
            i++;
        } else if (c == ')') {
            while (op_stack.top() != '(') {
                process_operator(op_stack, val_stack, tac);
            }
            op_stack.pop();
            i++;
        } else if (is_operator(c)) {
            while (!op_stack.empty() && op_stack.top() != '(' && precedence(c) <= precedence(op_stack.top())) {
                process_operator(op_stack, val_stack, tac);
            }
            op_stack.push(c);
            i++;
        } else {
            // It's a value, so extract the whole value
            string value = "";
            while (i < input.length() && !is_operator(input[i]) && input[i] != '(' && input[i] != ')') {
                value += input[i];
                i++;
            }
            val_stack.push(value);
        }
    }

    while (!op_stack.empty()) {
        process_operator(op_stack, val_stack, tac);
    }
    string result = tac.new_temp();
    tac.emit("=", val_stack.top(), "", result);
}

int main() {
    string input;
    cout << "Enter an expression: ";
    getline(cin, input);

   
 ThreeAddressCode tac;
 process_expression(input, tac);
 cout<<"--------------------------"<<endl;
 tac.print_code4();
 cout<<"\n----------------Triples-----------------"<<endl;
 tac.print_code1();
 cout<<"--------------------------"<<endl;
 
 return 0;
}