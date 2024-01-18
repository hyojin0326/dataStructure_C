#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tagNode {
	char* Data;
	struct tagNode* NextNode;
}Node;

typedef struct tagLinkedListStack {
	Node* List;
	Node* Top;
}LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack) {
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack) {
	while (!LLS_IsEmpty(Stack)) {
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyStack(Popped);
	}
	free(Stack);
}

Node* LLS_CreateNode(char* NewData) {
	//메모리 할당
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData)+1);

	strcpy(NewNode->Data, NewData);
	NewNode->NextNode = NULL;
	
	return NewNode;
}

void LLS_DestroyNode(Node* Node) {
	free(Node->Data);
	free(Node);
}
void LLS_Push(LinkedListStack* Stack,Node* NewNode) {
	//비어있는 경우
	if (Stack->List == NULL)
		Stack->List = NewNode;
	else
		Stack->Top->NextNode = NewNode;
	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack) {
	Node* TopNode = Stack->Top;

	//지우면 리스트 비워지는 경우
	if (Stack->List == Stack->Top) {
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else {
		Node* CurrentTop = Stack->List;
		//삭제할 이전 노드 찾기
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
			CurrentTop = CurrentTop->NextNode;
		Stack->Top = CurrentTop;
		Stack->Top->NextNode = NULL;
	}
}

Node* LLS_Top(LinkedListStack* Stack) {
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack) {
	int Count = 0;
	Node* Current = Stack->List;

	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}

int LLS_IsEmpty(LinkedListStack* Stack) {
	return (Stack->List == NULL);
}