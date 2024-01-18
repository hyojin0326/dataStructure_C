#include<stdio.h>
#include<stdlib.h>
//Head�� ���� �ٲ����� **�� �̿��Ͽ� �� ���� ����
typedef int ElementType;

//�����Ϳ� ���� ����� ������ �����ϴ� Node ����ü ����
typedef struct tagNode {
	ElementType Data;
	struct tagNode* NextNode;
}Node;

//��� ����
Node* SLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

//��� �Ҹ�(�޸� ����)
void SLL_DestroyNode(Node* Node) {
	free(Node);
}

//��� �߰�(����Ʈ�� �������� �߰�)
void SLL_AppendNode(Node** Head, Node* NewNode) {
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
	}
}

//��� ����(current��, ����Ʈ�� �߰��� ����)
void SLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

//��� ����(�� �տ� ����)
void SLL_InsertNewHead(Node** Head, Node* NewHead) {
	if (Head == NULL)
		(*Head) = NewHead;
	else {
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

//��� ����
void SLL_RemoveNode(Node** Head, Node* Remove) {
	//����Ʈ�� �Ǿճ�带 ���� ���
	if (*Head == Remove) {
		*Head = Remove->NextNode;
	}
	else {
		Node* Current = *Head;
		//���� ����� �ճ�� ã�� -> NextNode ������ ����
		while (Current != NULL && Current->NextNode != Remove)
			Current = Current->NextNode;
		
		//ã�� ���
		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
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
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}