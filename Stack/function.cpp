#include "Stack.h"
bool isEmpty(Stack stack)
{
	if (stack.pTop == NULL)
		return true;
	return false;
}
Node* creatNode(char s)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = s;
	p->pNext = NULL;
	return p;
}
void creatStack(Stack& stack)
{
	stack.pTop = NULL;
}
void push(Stack& stack, Node* newNode)
{
	if (newNode == NULL)
		return;
	if (stack.pTop == NULL)
		stack.pTop = newNode;
	else
	{
		newNode->pNext = stack.pTop;
		stack.pTop = newNode;
	}
}
Node* pop(Stack& stack)
{
	if (stack.pTop == NULL)
		return NULL;
	Node* p = stack.pTop;
	stack.pTop = stack.pTop->pNext;
	p->pNext = NULL;
	return p;
}
void KT_Ngoac(string s)
{
	if (s.length() < 3)
	{
		cout << "Chuoi khong hop le" << endl;
		return;
	}
	Stack stack, temp;
	creatStack(stack);
	creatStack(temp);
	bool flag = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ')')
		{
			if (s[i] == '(')
			{
				creatStack(temp);
				flag = true;
			}
			if (flag == true)
				push(stack, creatNode(s[i]));
		}
		else
		{
			if (stack.pTop == NULL)
			{
				cout << "Chuoi kh hop le" << endl;
				return;
			}
			if (stack.pTop->data == '(')
			{
				cout << "tim thay ngoac du trong bieu thuc: ";
				Dislay(temp);
				return;
			}
			do {
				push(temp, pop(stack));
			} while (stack.pTop != NULL && stack.pTop->data != '(');
			pop(stack);
		}
	}
	if (stack.pTop != NULL)
		cout << "Chuoi khong hop le" << endl;
	else
		cout << "Chuoi binh thuong" << endl;
}
void Dislay(Stack stack)
{
	if (isEmpty(stack))
	{
		return;
	}
	Node* p = stack.pTop;
	while (p != NULL)
	{
		cout << p->data;
		p = p->pNext;
	}
	cout << endl;
}
bool cmp(char a, char b)
{
	if (a == '{' && b != '}'|| a == '(' && b != ')'|| a == '[' && b != ']')
		return false;
	return true;
}
void KT_DoiXung(string s)
{
	int n = s.length();
	if (n % 2 != 0)
	{
		cout << "Chuoi khong doi xung!" << endl;
		return;
	}
	Stack stack;
	char temp;
	creatStack(stack);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			push(stack, creatNode(s[i]));
		else
		{
			if (isEmpty(stack))
			{
				cout << "Chuoi khong hop le" << endl;
				return;
			}
			temp = stack.pTop->data;
			pop(stack);
			if (cmp( temp, s[i]) == false)
			{
				cout << "Chuoi khong doi xung!" << endl;
				return;
			}
		}
	}
	cout << "Chuoi doi xung" << endl;
}
