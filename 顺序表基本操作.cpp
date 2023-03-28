//顺序表定义
#define Maxsize  50	 
typedef struct{
	ElemType data[Maxsize];		//顺序表元素 
	int length;					//顺序表当前长度 
}SqList;


//插入操作
//在第i个位置插入新元素e 
bool ListInsert(SqList &L,int i,ElemType e){
	if(i<1||i>L.length+1)		//判断i范围是否有效 
		return false;
	if(L.length>=Maxsize)		//存储空间已满，不能插入 
		return false;
	for(int j=L.length;j>=i;j--) //第i个元素之后的元素后移 
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;				//位置i处放入e 
	L.length++;					//线性表长度加1 
	return true;
} 


//删除操作
//删除第i个位置的元素，并用变量e返回
bool ListDelete(SqList &L,int i,ElemType &e){
	if(i<1||i>L.length)			//判断i范围是否有效
		return false;
	e=L.data[i-1];				//被删除元素赋值给e 
	for(int j=i;j<L.length;j++) //第i个位置后的元素前移 
		L.data[j-1]=L.data[j];
	L.length--;					//线性表长度减1 
	return true;
} 


//按值查找
//查找第一个值等于e的元素，并返回其位序
int LocateElem(SqList L,ElemType e){
	int i;
	for(i=0;i<L.length;i++)		//遍历顺序表 
		if(L.data[i]==e)		//下标为i的元素等于e，返回其位序i+1 
			return i+1;
	return 0; 					//退出循环，说明查找失败 
} 

























