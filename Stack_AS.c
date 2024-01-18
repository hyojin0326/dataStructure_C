#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
}Node;

typedef struct tagArrayStack {
	//각각 용량, 최상위 노드의 위치, 노드배열
	int Capacity;
	int Top;
	Node* Nodes;
}ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity) {
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	//입력된 갯수만큼 메모리 할당
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
	//초기화
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack) {
	free(Stack->Nodes);
	free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data) {
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop(ArrayStack* Stack) {
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack){
	return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack* Stack) {
	//0부터 시작이라 사이즈의 경우 +1
	return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack* Stack) {
	return (Stack->Top == -1);
}