#include <iostream>
using namespace std;
class stack {
public:
	stack();
	void push(char);
	char pop();
	bool isfull();
	bool isempty();
	void postfix();
	int sign(char);
private:
	int top = -1, i = 0, j = 0;
	int size = 30;
	char arr[30];
	char arr2[30];
};
stack::stack() {

}
int stack::sign(char sign)
{
	if (sign == '(')
		return 5;
	if (sign == '-')
		return 4;
	if (sign == '+')
		return 3;
	if (sign == '*')
		return 2;
	if (sign == '/')
		return 1;
	if (sign == '^')
		return 0;
}
char stack::pop() {
	if (!isempty())
		return arr[top--];
}
void stack::push(char data) {
	if (!isfull()) {
		top ++;
		arr[top] = data;
	}
	else 
		cout<<"Stack is full.\n";
}
bool stack::isfull() {
	if (top == size)
		return true;
	else
		return false;
}
bool stack::isempty() {
	if (top == -1)
		return true;
	else
		return false;
}
void stack::postfix() {
	char infix[30];
	cout << "inter in infix like: (a/(b-c+d))*(e-a)*c \n";
	cin >> infix;			//adad ha ba parantez gozary kamel bedon fasele mesl (a/(b-c+d))*(e-a)*c 
	cout << "your postfix is: ";
	for (int i = 0; infix[i] != '\0'; i++) {
		if (infix[i] == '(') 
			push(infix[i]);
		else if (infix[i] == ')') {
			while(arr[top] != '(')
				cout << pop();
			if (arr[top] == '(')
				top--;
		}
			else if (infix[i] == '*' || infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '^') {
				if (!isempty())
					if (sign(infix[i]) < sign(arr[top]))
						push(infix[i]);
					else {
						cout << pop();
						push(infix[i]);
					}
				else
					push(infix[i]);
			}			
			else 
				cout<< infix[i];
	}
	while (!isempty())
		cout << pop();
}
int main() {
	stack s;
	s.postfix();
}