//����
//�������㶨��
typedef struct LNode{
	ElemType data;			//������ 
	struct LNode *next;		//ָ���� 
}LNode,*LinkList; 


//ͷ�巨(���򣩽���������
LinkList List_HeadInsert(LinkList &L){
	LNode *s;int x;
	L=(LinkList)malloc(sizeof(LNode));	//����ͷ��� 
	L->next=NULL;						//��ʼΪ�� 
	scanf("%d",&x);						//�����һ������ֵ 
	while(x!=9999){						//����9999ʱ����������ʵ��������������� 
		s=(LNode*)malloc(sizeof(LNode));//�½ڵ� 
		s->data=x;
		s->next=L->next;
		L->next=s;						//�½ڵ��������LΪͷָ�� 
		scanf("%d",&x);
	}
	return L;
} 


//β�巨�����򣩽���������
LinkList List_TailInsert(LinkList &L){
	int x;
	L=(LinkList)malloc(sizeof(LNode));	//����ͷ��� 
	LNode *s,*r=L; 						//rΪβָ�루sÿ�ζ�ָ�������Ľ�㣬��ͷ�巨��ͬ�� 
	L->next=NULL;						//��ʼΪ�� 
	scanf("%d",&x);						//�����һ������ֵ 
	while(x!=9999){						//����9999ʱ����������ʵ��������������� 
		s=(LNode*)malloc(sizeof(LNode));//�½ڵ� 
		s->data=x;
		r->next=s;
		r=s;							//rָ���µı�β 
		scanf("%d",&x);
	}
	r->next=NULL;						//β���ָ���ÿ� 
	return L;
} 


//����Ų��ҽ��ֵ
//����ָ��ýڵ��ָ��
LNode *GetElem(LinkList L,int i){
	int j=1;				//������ 
	LNode *p=L->next;		//pָ���һ����� 
	if(i==0)				
		return L;			//i=0 ����ͷ�ڵ� 
	if(i<1)	
		return NULL;		//i��Ч ����NULL 
	while(p&&j<i){
		p-p->next;
		j++;
	}
	return p;				//���ظýڵ�ָ�룬i���ڱ�ʱ pΪNULL 
} 


//��ֵ���ҽ��
LNode *LocateElem(LinkList L,ElemType e){
	LNode *p=L->next;		//pָ���һ���ڵ� 
	while(p->data!=e&&p){   //��ʼ���� 
		p=p->next;
	}
	return p;				//���ظýڵ�ָ�룬δ�ҵ�ʱ pΪNULL 
} 


//ָ����i��λ�ò�����
//pΪ����ָ�룬sָ�������ڵ� 
p=GetElem(L,i-1);			//�ҵ�����λ�õ�ǰ����� 
s->next=p->next;
p->next=s; 


//��ĳһ������ǰ�����

//����һ��ת��Ϊ��ǰһ���ĺ�����
//���������Ըýڵ���к�壬ǰ��ڵ㽻��������
//*s�����뵽*p֮ǰ
s->next=p->next;
p->next=s;
temp=p->data;		//���������򣨷������� 
p->data=s->data;
s->data=temp;


//ɾ���ڵ�
//ɾ����i����㣬pΪ����ָ��
p=GetElem(L,i-1);
q=p->next;			//qָ��ɾ����� 
p->next=q->next;	//����ɾ���������жϿ� 
free(q);			//�ͷŽڵ�洢�ռ� 			


//ɾ���ڵ�*p
//����ɾ��*p�ĺ�̽ڵ㣬��������ֵ����*p
q=p->next;			//qָ��*p���
p->data=q->data;	//ȡ��̽ڵ�����ֵ 
p->next=q->next;	//����̽ڵ�Ͽ� 
free(q)
 
















