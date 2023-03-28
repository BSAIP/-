//链表
//单链表结点定义
typedef struct LNode{
	ElemType data;			//数据域 
	struct LNode *next;		//指针域 
}LNode,*LinkList; 


//头插法(逆向）建立单链表
LinkList List_HeadInsert(LinkList &L){
	LNode *s;int x;
	L=(LinkList)malloc(sizeof(LNode));	//创建头结点 
	L->next=NULL;						//初始为空 
	scanf("%d",&x);						//输入第一个结点的值 
	while(x!=9999){						//输入9999时结束（根据实际情况更改条件） 
		s=(LNode*)malloc(sizeof(LNode));//新节点 
		s->data=x;
		s->next=L->next;
		L->next=s;						//新节点插入链表，L为头指针 
		scanf("%d",&x);
	}
	return L;
} 


//尾插法（正向）建立单链表
LinkList List_TailInsert(LinkList &L){
	int x;
	L=(LinkList)malloc(sizeof(LNode));	//创建头结点 
	LNode *s,*r=L; 						//r为尾指针（s每次都指向待插入的结点，与头插法相同） 
	L->next=NULL;						//初始为空 
	scanf("%d",&x);						//输入第一个结点的值 
	while(x!=9999){						//输入9999时结束（根据实际情况更改条件） 
		s=(LNode*)malloc(sizeof(LNode));//新节点 
		s->data=x;
		r->next=s;
		r=s;							//r指向新的表尾 
		scanf("%d",&x);
	}
	r->next=NULL;						//尾结点指针置空 
	return L;
} 


//按序号查找结点值
//返回指向该节点的指针
LNode *GetElem(LinkList L,int i){
	int j=1;				//结点计数 
	LNode *p=L->next;		//p指向第一个结点 
	if(i==0)				
		return L;			//i=0 返回头节点 
	if(i<1)	
		return NULL;		//i无效 返回NULL 
	while(p&&j<i){
		p-p->next;
		j++;
	}
	return p;				//返回该节点指针，i大于表长时 p为NULL 
} 


//按值查找结点
LNode *LocateElem(LinkList L,ElemType e){
	LNode *p=L->next;		//p指向第一个节点 
	while(p->data!=e&&p){   //开始查找 
		p=p->next;
	}
	return p;				//返回该节点指针，未找到时 p为NULL 
} 


//指定第i个位置插入结点
//p为辅助指针，s指向待插入节点 
p=GetElem(L,i-1);			//找到插入位置的前驱结点 
s->next=p->next;
p->next=s; 


//对某一结点进行前插操作

//方法一：转变为对前一结点的后插操作
//方法二：对该节点进行后插，前后节点交换数据域
//*s结点插入到*p之前
s->next=p->next;
p->next=s;
temp=p->data;		//交换数据域（方法二） 
p->data=s->data;
s->data=temp;


//删除节点
//删除第i个结点，p为辅助指针
p=GetElem(L,i-1);
q=p->next;			//q指向被删除结点 
p->next=q->next;	//将被删除结点从链中断开 
free(q);			//释放节点存储空间 			


//删除节点*p
//可以删除*p的后继节点，将其数据值赋予*p
q=p->next;			//q指向*p后继
p->data=q->data;	//取后继节点数据值 
p->next=q->next;	//将后继节点断开 
free(q)
 
















