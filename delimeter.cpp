#include <iostream>
#include <stack>
#include <string>

bool isWellParenthesized(const std::string& expression) {
    std::stack<char> parenthesesStack;

    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            parenthesesStack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (parenthesesStack.empty()) {
                // Closing parenthesis with no matching opening parenthesis
                return false;
            }

            char openParen = parenthesesStack.top();
            parenthesesStack.pop();

            // Check if the closing parenthesis matches the top of the stack
            if ((ch == ')' && openParen != '(') ||
                (ch == ']' && openParen != '[') ||
                (ch == '}' && openParen != '{')) {
                return false;  // Mismatched parentheses
            }
        }
    }

    // Check if there are any unmatched opening parentheses left
    return parenthesesStack.empty();
}

int main() {
    std::string expression;

    // Read the expression from the user
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    // Check if the expression is well-parenthesized
    if (isWellParenthesized(expression)) {
        std::cout << "The expression is well-parenthesized.\n";
    } else {
        std::cout << "The expression is not well-parenthesized.\n";
    }

    return 0;
}

