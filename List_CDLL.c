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
Node* CDLL_CreateNode(ElementType NewData) {
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
void CDLL_AppendNode(Node** Head, Node* NewNode) {
	//�� ����Ʈ�� ��� ��带 ����
	if ((*Head) == NULL) {
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	//�̹� �����ϴ� ����Ʈ�� ��� ��� �߰�
	else {
		//���������� ����� ���������
		Node* Tail = (*Head)->PrevNode;

		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;
		
		NewNode->NextNode = (*Head);
		NewNode->PrevNode = Tail;
	}
}

//��� ����(current��, ����Ʈ�� �߰��� ����)
void CDLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}

//��� ����
void CDLL_RemoveNode(Node** Head, Node* Remove) {
	//����Ʈ�� �Ǿճ�带 ���� ���
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