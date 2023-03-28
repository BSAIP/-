//二叉树链式存储结构
typedef struct BiTNode{
	ElemType data;						//数据域 
	struct BiTNode *lchild,*rchild;		//左右孩子指针 
}BiTNode,*BiTree;


//二叉树遍历							//三者区别仅在于visit（）的位置 
//先序遍历
void PreOrder(BiTree T){
	if(T!=NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
} 

//中序遍历
void  InOrder(BiTree T){
	if(T!=NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
} 

//后序遍历
void PostOrder(BiTree T){
	if(T!=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}


//中序和先序的非递归遍历 
//借助栈
 
//中序遍历非递归算法
void InOrder2(BiTree T){
	InitStack(S);BiTree p=T;		//初始化栈S，p是遍历指针 
	while(p||!IsEmpty(S)){			//栈不空或p不空时循环 
		if(p){						//一路向左 
			Push(S,p);				//当前结点入栈 
			p=p->lchild				//左孩子不空 一直向左走 
		}
		else{
			Pop(S,p);				//栈顶元素出栈 
			visit(p);				//访问该结点 
			p=p->rchild; 			//转向右孩子 
		}
	}
} 


//先序遍历非递归算法
void PreOrder2(Bitree T){
	InitStack(S);BiTree p=T;
	while(p||!IsEmpty(S)){
		if(p){
			visit(p);				//与中序非递归的区别仅在于visit（）的位置 
			Push(S,p);
			p->lchild;
		}
		else{
			Pop(S,p);
			p->rchild;
		}
	}
}


//层次遍历
//借助队列
void LevelOrder(Bitree T){
	InitQueue(Q);					//初始化队列 
	BiTree p;						
	EnQueue(Q,T);					//根节点入队 
	while(!IsEmpty(Q)){				//队列不空则循环 
		DeQueue(Q,p);				//队头结点出队 
		visit(p);					//访问出队结点 
		if(p->lchild!=NULL)			
			EnQueue(Q,p->lchild);	//左子树不空，左子树根结点入队 
		if(p->rchild!=NULL)
			EnQueue(Q,p->rchild);	//右子树不空，右子树根结点入队 
	}
} 


//线索二叉树存储结构
typedef struct ThreadNode{
	ElemType data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;						//左右线索标志（区别于二叉树结构定义的地方）  
}; 										// 0 孩子    1 前驱 


//中序线索二叉树构造（递归） 
void InThread(ThreadTree &p,ThreadTree &pre){
	if(p!=NULL){
		InThread(p->lchild,pre);		//递归，线索化左子树 
		if(p->lchild==NULL){			//左子树为空，建立前驱线索 
			p->lchild=pre;
			p->ltag=1;
		}
		if(pre!=NULL&&pre->rchild==NULL){
			pre->rchild=p;				//前驱结点右子树为空，建立后继线索 
			pre->rtag=1;
		}
		pre=p;							//当前节点为刚刚访问过的结点 
		InThread(p->rchild,pre);		//递归，线索化右子树 
	}
} 

void CreateInThread(ThreadThree T){
	ThreadTree pre=NULL;				//前驱指针初始化 
	if(T!=NULL){						//非空二叉树，线索化	
		InThread(T,pre);	
		pre->rchild=NULL;				//处理遍历的最后一个结点 
		pre->rtag=1;
	} 
}


//中序线索二叉树的遍历
//求中序线索二叉树中序序列下第一个结点
ThreadNode *FirstNode(ThreadNode *p){	//实质为找最左下的结点（即中序遍历的起始结点） 
	while(p->ltag==0)
		p=p->lchild;
		return p;
} 

//结点p在中序序列下的后继
ThreadNode *NextNode(ThreadNode *p){
	if(p->rtag==0)
		return FirstNode(p->rchild);	//有右子树，后继为右子树的中序第一个结点 
	else					
		return p->rchild;				//否则右孩子指针直接指向后继 
} 

//不含头结点的中序线索二叉树的遍历
void Inorder(ThreadTree *T){
	for(ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
		visit(p);
} 


//树的存储结构
//双亲表示法（结构数组表示） 
#define MAX_TREE_SIZE 100			//树中最多结点数 
typedef struct{						//树的结点定义 
	ElemType data;
	int parent;
}PTNode;
typedef struct{						//树的类型定义 
	PTNode nodes[MAX_TREE_SIZE];
	int n;							//当前结点数 
}PTree; 


//孩子兄弟表示法
typedef	struct CSNode{				//结点定义 
	ElemType data;
	struct CSNode *firstchild,*nextsibling;	
}CSNode,*CSTree;























