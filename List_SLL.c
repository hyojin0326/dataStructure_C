#include<stdio.h>
#include<stdlib.h>
//Head의 값이 바뀔떄는 **을 이용하여 값 변경 가능
typedef int ElementType;

//데이터와 다음 노드의 정보를 저장하는 Node 구조체 선언
typedef struct tagNode {
	ElementType Data;
	struct tagNode* NextNode;
}Node;

//노드 생성
Node* SLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

//노드 소멸(메모리 해제)
void SLL_DestroyNode(Node* Node) {
	free(Node);
}

//노드 추가(리스트의 마지막에 추가)
void SLL_AppendNode(Node** Head, Node* NewNode) {
	//빈 리스트의 경우 헤드를 생성
	if ((*Head) == NULL) {
		*Head = NewNode;
	}
	//이미 존재하는 리스트의 경우 노드 추가
	else {
		Node* Tail = (*Head);
		//리스트의 마지막 찾기
		while (Tail->NextNode != NULL)
			Tail = Tail->NextNode;
		Tail->NextNode = NewNode;
	}
}

//노드 삽입(current뒤, 리스트의 중간에 삽입)
void SLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

//노드 삽입(맨 앞에 삽입)
void SLL_InsertNewHead(Node** Head, Node* NewHead) {
	if (Head == NULL)
		(*Head) = NewHead;
	else {
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

//노드 제거
void SLL_RemoveNode(Node** Head, Node* Remove) {
	//리스트의 맨앞노드를 지울 경우
	if (*Head == Remove) {
		*Head = Remove->NextNode;
	}
	else {
		Node* Current = *Head;
		//지울 노드의 앞노드 찾기 -> NextNode 연결을 위해
		while (Current != NULL && Current->NextNode != Remove)
			Current = Current->NextNode;
		
		//찾은 경우
		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
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
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}