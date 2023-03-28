//双链表
//结点定义
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinkList;


//插入操作
//p所指节点后插入*s
s->next=p->next;
p->next->prior=s;
s->prior=p;
p->next=s;


//删除操作
//删除*p的后继*q
p->next=q->next;
q->next->prior=p;
free(q); 


//静态链表定义
#define MaxSize 50
typedef struct{
	Elemtype data;
	int next;
}SLinkList[MaxSize]; 
