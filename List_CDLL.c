#include<stdio.h>
#include<stdlib.h>
//Head의 값이 바뀔떄는 **을 이용하여 값 변경 가능
typedef int ElementType;

//데이터와 다음 노드의 정보를 저장하는 Node 구조체 선언
typedef struct tagNode {
	ElementType Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
}Node;

//노드 생성
Node* CDLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

//노드 소멸(메모리 해제)
void DLL_DestroyNode(Node* Node) {
	free(Node);
}

//노드 추가(리스트의 마지막에 추가)
void CDLL_AppendNode(Node** Head, Node* NewNode) {
	//빈 리스트의 경우 헤드를 생성
	if ((*Head) == NULL) {
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	//이미 존재하는 리스트의 경우 노드 추가
	else {
		//마지막노드는 헤드의 이전노드임
		Node* Tail = (*Head)->PrevNode;

		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;
		
		NewNode->NextNode = (*Head);
		NewNode->PrevNode = Tail;
	}
}

//노드 삽입(current뒤, 리스트의 중간에 삽입)
void CDLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}

//노드 제거
void CDLL_RemoveNode(Node** Head, Node* Remove) {
	//리스트의 맨앞노드를 지울 경우
	if (*Head == Remove) {
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		(*Head)->NextNode->PrevNode = Remove->PrevNode;

		*Head = Remove->NextNode;
	
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else {
		Remove->PrevNode->NextNode = Remove->NextNode;
		Remove->NextNode->PrevNode = Remove->PrevNode;
			
		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;
	}
}

//노드 탐색, 위치는 0부터임
Node* SLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}

	return Current;
}

//노드 개수 세기
int SLL_GetNodeCount(Node* Head) {
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}

//노드 출력 (....굳이?)
void PrintNode(Node* _Node) {
	if (_Node->PrevNode == NULL)
		printf("Prev: NULL");
	else
		printf("Prev: %d", _Node->PrevNode->Data);

	printf("Current: %d", _Node->Data);

	if (_Node->NextNode == NULL)
		printf("Next: NULL\n");
	else
		printf("Next; %d\n", _Node->NextNode->Data);
}