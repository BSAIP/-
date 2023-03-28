//����

//˳�����
typedef struct{			//���ұ�����ݽṹ 
	ElemType *elem;		//Ԫ�ش洢�ռ��ַ������ʱ��ʵ�ʳ��ȷ��䣬0������ 
	int TableLen;		//�� 
}SSTable;

int Search_Seq(SSTable ST,ElemType key){
	ST.elem[0]=key;								//�ڱ� 
	for(i=ST.TableLen;ST.elem[i]!=key;i--);		//�Ӻ���ǰ�� 
	return i;									//����0ʱ����ʧ�� 
} 


//�۰����
int Binary_Search(SeqList L,ElemType key){
	int low=0,high=L.TableLen-1,mid;
	while(low<=high){
		mid=(low+high)/2;			//ȡ�м�λ�� 
		if(L.elem[mid]==key)		//���ҳɹ���������λ�� 
			return mid;
		else if(L.elem[mid]>key)	//��ǰ�벿�������� 
			high=mid-1;
		else
			low=mid+1;				//�Ӻ�벿�������� 
		}
	return -1;						//����ʧ�ܷ���-1 
} 


//���Ͳ���
//�����������ǵݹ����
BSTNode *BST_Search(BiTree T,ElemType key){
	while(T!=NULL&&key!=T->data){			//���ջ�����ڸ�ֲ������ѭ�� 
		if(key<T->data)						//keyС���������ϲ��� 
			T=T->lchild;		
		else								//key���������ϲ��� 
			T=T->rchild;
	}
	return T;
} 


//�����������������
int BST_Insert(BiTree &T,KeyType k){
	if(T==NULL){							//ԭ��Ϊ�գ��²����¼��Ϊ����� 
		T=(BiTree)malloc(sizeof(BSTNode));
		T->data=k;
		T->lchild=T->rchild=NULL;
		return 1;
	}
	else if(k==T->data)						//����ͬ�ؼ��ֽ�㣬����ʧ�� 
		return 0;
	else if(k<T->data)
		return BST_Insert(T->lchild,k);		//�ݹ飬���������� 
	else
		return BST_Insert(T->rchild,k);		//�ݹ飬���������� 
} 


//�����������Ĺ���
void Creat_BST(BiTree &T,KeyType str[],int n){
	T=NULL;
	int i=0;
	while(i<n){
		BST_Insert(T,str[i]);
		i++;
	}
} 
























