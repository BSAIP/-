//˫����
//��㶨��
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinkList;


//�������
//p��ָ�ڵ�����*s
s->next=p->next;
p->next->prior=s;
s->prior=p;
p->next=s;


//ɾ������
//ɾ��*p�ĺ��*q
p->next=q->next;
q->next->prior=p;
free(q); 


//��̬������
#define MaxSize 50
typedef struct{
	Elemtype data;
	int next;
}SLinkList[MaxSize]; 
