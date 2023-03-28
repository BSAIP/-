//查找

//顺序查找
typedef struct{			//查找表的数据结构 
	ElemType *elem;		//元素存储空间基址，建表时按实际长度分配，0号留空 
	int TableLen;		//表长 
}SSTable;

int Search_Seq(SSTable ST,ElemType key){
	ST.elem[0]=key;								//哨兵 
	for(i=ST.TableLen;ST.elem[i]!=key;i--);		//从后往前找 
	return i;									//返回0时查找失败 
} 


//折半查找
int Binary_Search(SeqList L,ElemType key){
	int low=0,high=L.TableLen-1,mid;
	while(low<=high){
		mid=(low+high)/2;			//取中间位置 
		if(L.elem[mid]==key)		//查找成功返回所在位置 
			return mid;
		else if(L.elem[mid]>key)	//从前半部继续查找 
			high=mid-1;
		else
			low=mid+1;				//从后半部继续查找 
		}
	return -1;						//查找失败返回-1 
} 


//树型查找
//二叉排序树非递归查找
BSTNode *BST_Search(BiTree T,ElemType key){
	while(T!=NULL&&key!=T->data){			//树空或结点等于根植，结束循环 
		if(key<T->data)						//key小，左子树上查找 
			T=T->lchild;		
		else								//key大，右子树上查找 
			T=T->rchild;
	}
	return T;
} 


//二叉排序树插入操作
int BST_Insert(BiTree &T,KeyType k){
	if(T==NULL){							//原树为空，新插入记录作为根结点 
		T=(BiTree)malloc(sizeof(BSTNode));
		T->data=k;
		T->lchild=T->rchild=NULL;
		return 1;
	}
	else if(k==T->data)						//有相同关键字结点，插入失败 
		return 0;
	else if(k<T->data)
		return BST_Insert(T->lchild,k);		//递归，插入左子树 
	else
		return BST_Insert(T->rchild,k);		//递归，插入右子树 
} 


//二叉排序树的构造
void Creat_BST(BiTree &T,KeyType str[],int n){
	T=NULL;
	int i=0;
	while(i<n){
		BST_Insert(T,str[i]);
		i++;
	}
} 
























