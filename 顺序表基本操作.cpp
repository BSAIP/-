//˳�����
#define Maxsize  50	 
typedef struct{
	ElemType data[Maxsize];		//˳���Ԫ�� 
	int length;					//˳���ǰ���� 
}SqList;


//�������
//�ڵ�i��λ�ò�����Ԫ��e 
bool ListInsert(SqList &L,int i,ElemType e){
	if(i<1||i>L.length+1)		//�ж�i��Χ�Ƿ���Ч 
		return false;
	if(L.length>=Maxsize)		//�洢�ռ����������ܲ��� 
		return false;
	for(int j=L.length;j>=i;j--) //��i��Ԫ��֮���Ԫ�غ��� 
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;				//λ��i������e 
	L.length++;					//���Ա��ȼ�1 
	return true;
} 


//ɾ������
//ɾ����i��λ�õ�Ԫ�أ����ñ���e����
bool ListDelete(SqList &L,int i,ElemType &e){
	if(i<1||i>L.length)			//�ж�i��Χ�Ƿ���Ч
		return false;
	e=L.data[i-1];				//��ɾ��Ԫ�ظ�ֵ��e 
	for(int j=i;j<L.length;j++) //��i��λ�ú��Ԫ��ǰ�� 
		L.data[j-1]=L.data[j];
	L.length--;					//���Ա��ȼ�1 
	return true;
} 


//��ֵ����
//���ҵ�һ��ֵ����e��Ԫ�أ���������λ��
int LocateElem(SqList L,ElemType e){
	int i;
	for(i=0;i<L.length;i++)		//����˳��� 
		if(L.data[i]==e)		//�±�Ϊi��Ԫ�ص���e��������λ��i+1 
			return i+1;
	return 0; 					//�˳�ѭ����˵������ʧ�� 
} 

























