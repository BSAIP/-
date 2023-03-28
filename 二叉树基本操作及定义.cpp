//��������ʽ�洢�ṹ
typedef struct BiTNode{
	ElemType data;						//������ 
	struct BiTNode *lchild,*rchild;		//���Һ���ָ�� 
}BiTNode,*BiTree;


//����������							//�������������visit������λ�� 
//�������
void PreOrder(BiTree T){
	if(T!=NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
} 

//�������
void  InOrder(BiTree T){
	if(T!=NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
} 

//�������
void PostOrder(BiTree T){
	if(T!=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}


//���������ķǵݹ���� 
//����ջ
 
//��������ǵݹ��㷨
void InOrder2(BiTree T){
	InitStack(S);BiTree p=T;		//��ʼ��ջS��p�Ǳ���ָ�� 
	while(p||!IsEmpty(S)){			//ջ���ջ�p����ʱѭ�� 
		if(p){						//һ·���� 
			Push(S,p);				//��ǰ�����ջ 
			p=p->lchild				//���Ӳ��� һֱ������ 
		}
		else{
			Pop(S,p);				//ջ��Ԫ�س�ջ 
			visit(p);				//���ʸý�� 
			p=p->rchild; 			//ת���Һ��� 
		}
	}
} 


//��������ǵݹ��㷨
void PreOrder2(Bitree T){
	InitStack(S);BiTree p=T;
	while(p||!IsEmpty(S)){
		if(p){
			visit(p);				//������ǵݹ�����������visit������λ�� 
			Push(S,p);
			p->lchild;
		}
		else{
			Pop(S,p);
			p->rchild;
		}
	}
}


//��α���
//��������
void LevelOrder(Bitree T){
	InitQueue(Q);					//��ʼ������ 
	BiTree p;						
	EnQueue(Q,T);					//���ڵ���� 
	while(!IsEmpty(Q)){				//���в�����ѭ�� 
		DeQueue(Q,p);				//��ͷ������ 
		visit(p);					//���ʳ��ӽ�� 
		if(p->lchild!=NULL)			
			EnQueue(Q,p->lchild);	//���������գ��������������� 
		if(p->rchild!=NULL)
			EnQueue(Q,p->rchild);	//���������գ��������������� 
	}
} 


//�����������洢�ṹ
typedef struct ThreadNode{
	ElemType data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;						//����������־�������ڶ������ṹ����ĵط���  
}; 										// 0 ����    1 ǰ�� 


//�����������������죨�ݹ飩 
void InThread(ThreadTree &p,ThreadTree &pre){
	if(p!=NULL){
		InThread(p->lchild,pre);		//�ݹ飬������������ 
		if(p->lchild==NULL){			//������Ϊ�գ�����ǰ������ 
			p->lchild=pre;
			p->ltag=1;
		}
		if(pre!=NULL&&pre->rchild==NULL){
			pre->rchild=p;				//ǰ�����������Ϊ�գ������������ 
			pre->rtag=1;
		}
		pre=p;							//��ǰ�ڵ�Ϊ�ոշ��ʹ��Ľ�� 
		InThread(p->rchild,pre);		//�ݹ飬������������ 
	}
} 

void CreateInThread(ThreadThree T){
	ThreadTree pre=NULL;				//ǰ��ָ���ʼ�� 
	if(T!=NULL){						//�ǿն�������������	
		InThread(T,pre);	
		pre->rchild=NULL;				//������������һ����� 
		pre->rtag=1;
	} 
}


//���������������ı���
//�������������������������µ�һ�����
ThreadNode *FirstNode(ThreadNode *p){	//ʵ��Ϊ�������µĽ�㣨�������������ʼ��㣩 
	while(p->ltag==0)
		p=p->lchild;
		return p;
} 

//���p�����������µĺ��
ThreadNode *NextNode(ThreadNode *p){
	if(p->rtag==0)
		return FirstNode(p->rchild);	//�������������Ϊ�������������һ����� 
	else					
		return p->rchild;				//�����Һ���ָ��ֱ��ָ���� 
} 

//����ͷ�������������������ı���
void Inorder(ThreadTree *T){
	for(ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
		visit(p);
} 


//���Ĵ洢�ṹ
//˫�ױ�ʾ�����ṹ�����ʾ�� 
#define MAX_TREE_SIZE 100			//����������� 
typedef struct{						//���Ľ�㶨�� 
	ElemType data;
	int parent;
}PTNode;
typedef struct{						//�������Ͷ��� 
	PTNode nodes[MAX_TREE_SIZE];
	int n;							//��ǰ����� 
}PTree; 


//�����ֵܱ�ʾ��
typedef	struct CSNode{				//��㶨�� 
	ElemType data;
	struct CSNode *firstchild,*nextsibling;	
}CSNode,*CSTree;























