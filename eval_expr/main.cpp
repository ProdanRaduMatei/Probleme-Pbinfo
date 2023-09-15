#include <iostream>
#include <fstream>
#include <string>
#include <stack>
std::string s;

long long order(const char& c){
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*')
        return 2;
    return 0;
}

int main(){
    std::cin >> s;
    std::stack<long long>val;
    std::stack<char>ops;
    for(long long i = 0;i < s.length();i++){
        if(s[i] == ' ')
            continue;
        if(i == 0 && !isdigit(s[i])){
            char sign = s[0];
            long long value{};
            i++;
            while(isdigit(s[i])){
                value = value * 10 + s[i] - '0';
                i++;
            }
            i--;
            if(sign == '-')
                val.push(-1 * value);
            else val.push(value);
        }
        else if(isdigit(s[i])){
            long long value{};
            while(isdigit(s[i])){
                value = value * 10 + s[i] - '0';
                i++;
            }
            i--;
            val.push(value);
        }
        else{//is an operator
            while (!ops.empty() && order(ops.top()) >= order(s[i])&& val.size() >= 2) {
                long long a = val.top();
                val.pop();
                long long b = val.top();
                val.pop();
                char op = ops.top();
                ops.pop();
                std::swap(a,b);
                if(op == '+')
                    val.push(a + b);
                else if(op == '-')
                    val.push(a - b);
                else
                    val.push(a * b);
            }
            ops.push(s[i]);
        }
    }
    while (!ops.empty() && val.size() >= 2) {
        long long a = val.top();
        val.pop();
        long long b = val.top();
        val.pop();
        char op = ops.top();
        ops.pop();
        std::swap(a,b);
        if(op == '+')
            val.push(a + b);
        else if(op == '-')
            val.push(a - b);
        else val.push(a * b);
    }
    std::cout << val.top();
}
