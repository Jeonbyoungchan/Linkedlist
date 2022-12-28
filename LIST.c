#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct NODE {
	int num;
	struct NODE* link;
}NODE;

NODE* first = NULL;
NODE* p1 = NULL, * p, * next, * pNew = NULL;
int num;
char buffer[10];

int makeLIST();
int INSERT();
int DELETE();
int freeLIST();
int PRINT();

int main(void)
{
	makeLIST(first);
	PRINT(first);

	INSERT(first);
	PRINT(first);

	DELETE(first);
	PRINT(first);

	freeLIST(first);

	return 0;
}

int makeLIST(void)
{
	while (1)
	{
		char buffer[10];
		printf("번호는? 종료:enter");
		fgets(buffer, 10, stdin);
		if (buffer[0] == '\n')
			break;
		p = (NODE*)malloc(sizeof(NODE));
		num = atoi(buffer);
		p->num = num;
		if (first == NULL)
			first = p;
		else
			p1->link = p;
		p->link = NULL;
		p1 = p;
	}
	printf("\n");

	return 0;
}

int INSERT(void)
{
	printf("넣을 번호는?");
	fgets(buffer, 10, stdin);
	pNew = (NODE*)malloc(sizeof(NODE));
	num = atoi(buffer);
	pNew->num = num;
	pNew->link = NULL;

	p = first;
	while (p != NULL)
	{
		if (p->link == NULL)
		{
			p->link = pNew;
			break;
		}
		if ((pNew->num) < (first->num))
		{
			pNew->link = first;
			first = pNew;
			break;
		}
		if ((pNew->num) < (p->link->num))
		{
			pNew->link = p->link;
			p->link = pNew;
			break;
		}
		p = p->link;
	}
	return 0;
}

int DELETE(void)
{
	printf("지울 번호는?");
	int delete_num;
	scanf("%d", &delete_num);
	p = first;
	NODE* temp = NULL;
	while (p != NULL)
	{
		if (delete_num == first->num)
		{
			first = p->link;
			free(p);
			break;
		}
		if (delete_num > p->num)
		{
			temp = p;
		}
		if (p->num == delete_num)
		{
			temp->link = p->link;
			free(p);
			break;
		}

		p = p->link;
	}
	return 0;
}

int PRINT(void)
{
	p = first;
	while (p != NULL)
	{
		printf("[%d]", p->num);
		p = p->link;
	}
	return 0;
}

int freeLIST(void)
{
	p = first;
	while (p != NULL)
	{
		next = p->link;
		free(p);
		p = next;
	}
	return 0;
}