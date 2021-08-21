#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Node {
	char data;
	Node* pNext;
};
struct Stack {
	Node* pTop;
};
bool isEmpty(Stack stack);
Node* creatNode(char s);
void creatStack(Stack& stack);
void push(Stack& stack, Node* newNode);
Node* pop(Stack& stack);
void KT_Ngoac(string s);
void Dislay(Stack stack);
void KT_DoiXung(string s);
bool cmp(char a, char b);
