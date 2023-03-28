//排序
//直接插入
void InsertSort(ElemType A[],int n){
	int i,j;
	for(i=2;i<=n;i++)					//依次将A[2]~A[n]插入到已排序的序列 
		if(A[i]<A[i-1]){				//A[i]关键码小于前驱，A[i]插入有序表 
			A[0]=A[i];					//复制为哨兵，A[0]不存放元素 
			for(j=i-1;A[0]<A[j];j--)	//从后往前查找待插入位置	
				A[j+1]=A[j];			//向后挪位 
			A[j+1]=A[0];				//复制到待插入位置 
		}
} 


//折半插入
void InsertSort(Element A[],int n){
	int i,j,low,high,mid;
	for(i=2;i<=n;i++){					//依次将A[2]~A[n]插入到已排序的序列
		A[0]=A[i];						//A[i]暂存A[0] 
		low=1;high=i-1;					//依据i，设置查找范围 
		while(low<=high){				//折半查找（默认递增有序） 
			mid=(low+high)/2;
			if(A[mid]>A[0])
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=high+1;j--)		//后移并插入 
			A[j+1]=A[j];	
		A[high+1]=A[0];
	}
} 


//希尔排序
void ShellSort(ElemType A[],int n){
	for(dk=n/2;dk>=1;dk=dk/2)			//步长变化 
		for(i=dk+1;i<=n;i++)			//从dk+1处开始依次扫描 
			if(A[i]<A[i-dk]){			//需要将A[i]插入对应的有序增量子表 
				A[0]=A[i];				//A[0]暂存A[i] 
				for(j=i-dk;j>0&&A[0]<A[j];j=j-dk)	//比较并移位 
					A[j+dk]=A[j];
				A[j+dk]=A[0];						//插入 
			}
} 


//冒泡排序
void BubbleSort(ElemType A[],int n){
	for(i=0;i<n-1;i++){
		flag=false;
		for(j=n-1;j>i;j--)
			if(A[j-1]>A[j]){
				swap(A[j-1],A[j]);
				flag=true;
			}
		if(flag==false)
			return;
	}
} 


//快速排序***
void QuickSort(ElemType A[],int low,int high){
	if(low<high){
		int pivotpos=Partition(A,low,high);		//划分 
		QuickSort(A,low,pivotpos-1);			//依次对两个子表递归排序 
		QuickSort(A,pivotpos+1,high);
	}
} 

int Partition(ElemType A[],int low,int high){
	ElemType pivot=A[low];						//将表中一个元素设为枢轴，对表进行划分 
	while(low<high){								
		while(low<high&&A[high]>=pivot) high--;	//从右侧查找比枢轴小的元素 
		A[low]=A[high];							//将该元素移动到左端 
		while(low<high&&A[low]<=pivot) low++;	//从左侧查找比枢轴大的元素 
		A[high]=A[low];							//将其移动到右端 
	}
	A[low]=pivot;								//枢轴元素存放到最终位置 
	return low;									//返回枢轴元素位置 
}


//简单选择排序
void SelectSort(ElemType A[],int n){
	for(i=0;i<n-1;i++){
		min=i;
		foe(j=i+1;j<n;j++)
			if(A[j]<A[min])
				min=j;
		if(min!=i)
			Swap(A[i],A[min]);
	}
} 


//堆排序


//归并排序
void MergeSort(ElemType A[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);
	}
}
ElemType *B=(ElemType*)malloc((n+1)*sizeof(ElemType));
void Merge(ElemType A[],int low,int mid,int high){
	
	
	
	
	
}






















 















 
