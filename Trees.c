#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
};

struct Node *root = NULL;

struct Queue
{
	int size;
	int front;
	int rear;
	struct Node **Array;
};


void createQueue(struct Queue *q,int x)
{
	q->size = x;
	q->front = -1;
	q->rear = -1;
	q->Array = (struct Node **)malloc(x*sizeof(struct Node*));
}

void enqueue(struct Queue *q,struct Node *x) 
{
	if(q->rear == q->size-1)
	printf("Queue is Full");
	else
	{
		q->rear++;
		q->Array[q->rear] = x;
	}
}

struct Node* dequeue(struct Queue *q)
{
	struct Node *x = NULL;
	if(q->front == q->rear)
	printf("Queue is Empty ");
	else
	{
		q->front++;
		x = q->Array[q->front];
	}
	return x;
}

int isnotEmpty(struct Queue q)
{
	if(q.front!=q.rear)
	return 1;
	else
	return 0;
}

void createTree()
{
	struct Node *p,*r;
	int data,x;
	struct Queue q;
	createQueue(&q,100);
	
	
	printf("Enter root data : ");
	scanf("%d",&x);
	
	
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = NULL;
	root->rchild = NULL;
	
	enqueue(&q,root);
	
	while(isnotEmpty(q))
	{
		r = dequeue(&q);
		
		printf("Enter left child of %d : ",r->data);
		scanf("%d",&data);
		
		if(data!=-1)
		{
		p = (struct Node *)malloc(sizeof(struct Node));
		r->lchild = p;
		p->data = data;
		p->lchild = NULL;
		p->rchild = NULL;
		enqueue(&q,p);
		}
		
		printf("Enter right child of %d : ",r->data);
		scanf("%d",&data);
		if(data!=-1)
		{
		p = (struct Node *)malloc(sizeof(struct Node));
		r->rchild = p;
		p->data = data;
		p->lchild = NULL;
		p->rchild = NULL;
		enqueue(&q,p);
		}
	}
}

void preOrder(struct Node *p)
{
	if(p!=NULL)
	{
		printf("%d ",p->data);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

void inOrder(struct Node *p)
{
	if(p!=NULL)
	{
		inOrder(p->lchild);
		printf("%d ",p->data);
		inOrder(p->rchild);
	}
}

void postOrder(struct Node *p)
{
	if(p!=NULL)
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		printf("%d ",p->data);
	}
}
int main()
{
	struct Queue q;
	int n,i;
	
	createQueue(&q,10);
	createTree();
	printf("\n\nPreorder Traversal is : ");
	preOrder(root);
	printf("\n\nInorder Traversal is : ");
	inOrder(root);
	printf("\n\nPostorder Traversal is : ");
	postOrder(root);
	
	
}
