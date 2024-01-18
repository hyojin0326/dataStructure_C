#include<stdio.h>
#include<stdlib.h>
//Head�� ���� �ٲ����� **�� �̿��Ͽ� �� ���� ����
typedef int ElementType;

//�����Ϳ� ���� ����� ������ �����ϴ� Node ����ü ����
typedef struct tagNode {
	ElementType Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
}Node;

//��� ����
Node* DLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

//��� �Ҹ�(�޸� ����)
void DLL_DestroyNode(Node* Node) {
	free(Node);
}

//��� �߰�(����Ʈ�� �������� �߰�)
void DLL_AppendNode(Node** Head, Node* NewNode) {
	//�� ����Ʈ�� ��� ��带 ����
	if ((*Head) == NULL) {
		*Head = NewNode;
	}
	//�̹� �����ϴ� ����Ʈ�� ��� ��� �߰�
	else {
		Node* Tail = (*Head);
		//����Ʈ�� ������ ã��
		while (Tail->NextNode != NULL)
			Tail = Tail->NextNode;
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

//��� ����(current��, ����Ʈ�� �߰��� ����)
void DLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}

//��� ����
void DLL_RemoveNode(Node** Head, Node* Remove) {
	//����Ʈ�� �Ǿճ�带 ���� ���
	if (*Head == Remove) {
		*Head = Remove->NextNode;
		if (*Head != NULL)
			(*Head)->PrevNode = NULL;
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else {
		Node* Temp = Remove;
		if (Remove->PrevNode != NULL)
			Remove->PrevNode->NextNode = Temp->NextNode;
		if (Remove->NextNode != NULL)
			Remove->NextNode->PrevNode = Temp->PrevNode;
		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;
	}
}

//��� Ž��, ��ġ�� 0������
Node* SLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}

	return Current;
}

//��� ���� ����
int SLL_GetNodeCount(Node* Head) {
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}

//��� ��� (....����?)
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