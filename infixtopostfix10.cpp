#include <iostream>
#include <stack>
#include <string>

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // For non-operators
}

std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operatorStack;
    std::string postfix;

    for (size_t i = 0; i < infix.length(); ++i) {
    	char ch = infix[i];
        if (isalnum(ch)) {
            postfix += ch; // Operand, add to the postfix expression
        } else if (ch == '(') {
            operatorStack.push(ch);
        } else if (ch == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop(); // Pop the '('
            }
        } else if (isOperator(ch)) {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(ch)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    // Pop remaining operators from the stack to postfix expression
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string infixExpression;

    // Read the infix expression from the user
    std::cout << "Enter an infix expression: ";
    std::cin >> infixExpression;

    // Convert infix to postfix
    std::string postfixExpression = infixToPostfix(infixExpression);

    // Display the postfix expression
    std::cout << "Postfix expression: " << postfixExpression << std::endl;

    return 0;
}

