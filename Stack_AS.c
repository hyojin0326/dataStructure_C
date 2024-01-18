#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
}Node;

typedef struct tagArrayStack {
	//���� �뷮, �ֻ��� ����� ��ġ, ���迭
	int Capacity;
	int Top;
	Node* Nodes;
}ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity) {
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	//�Էµ� ������ŭ �޸� �Ҵ�
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
	//�ʱ�ȭ
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
	//0���� �����̶� �������� ��� +1
	return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack* Stack) {
	return (Stack->Top == -1);
}