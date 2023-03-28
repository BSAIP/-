//����
//ֱ�Ӳ���
void InsertSort(ElemType A[],int n){
	int i,j;
	for(i=2;i<=n;i++)					//���ν�A[2]~A[n]���뵽����������� 
		if(A[i]<A[i-1]){				//A[i]�ؼ���С��ǰ����A[i]��������� 
			A[0]=A[i];					//����Ϊ�ڱ���A[0]�����Ԫ�� 
			for(j=i-1;A[0]<A[j];j--)	//�Ӻ���ǰ���Ҵ�����λ��	
				A[j+1]=A[j];			//���Ųλ 
			A[j+1]=A[0];				//���Ƶ�������λ�� 
		}
} 


//�۰����
void InsertSort(Element A[],int n){
	int i,j,low,high,mid;
	for(i=2;i<=n;i++){					//���ν�A[2]~A[n]���뵽�����������
		A[0]=A[i];						//A[i]�ݴ�A[0] 
		low=1;high=i-1;					//����i�����ò��ҷ�Χ 
		while(low<=high){				//�۰���ң�Ĭ�ϵ������� 
			mid=(low+high)/2;
			if(A[mid]>A[0])
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=high+1;j--)		//���Ʋ����� 
			A[j+1]=A[j];	
		A[high+1]=A[0];
	}
} 


//ϣ������
void ShellSort(ElemType A[],int n){
	for(dk=n/2;dk>=1;dk=dk/2)			//�����仯 
		for(i=dk+1;i<=n;i++)			//��dk+1����ʼ����ɨ�� 
			if(A[i]<A[i-dk]){			//��Ҫ��A[i]�����Ӧ�����������ӱ� 
				A[0]=A[i];				//A[0]�ݴ�A[i] 
				for(j=i-dk;j>0&&A[0]<A[j];j=j-dk)	//�Ƚϲ���λ 
					A[j+dk]=A[j];
				A[j+dk]=A[0];						//���� 
			}
} 


//ð������
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


//��������***
void QuickSort(ElemType A[],int low,int high){
	if(low<high){
		int pivotpos=Partition(A,low,high);		//���� 
		QuickSort(A,low,pivotpos-1);			//���ζ������ӱ�ݹ����� 
		QuickSort(A,pivotpos+1,high);
	}
} 

int Partition(ElemType A[],int low,int high){
	ElemType pivot=A[low];						//������һ��Ԫ����Ϊ���ᣬ�Ա���л��� 
	while(low<high){								
		while(low<high&&A[high]>=pivot) high--;	//���Ҳ���ұ�����С��Ԫ�� 
		A[low]=A[high];							//����Ԫ���ƶ������ 
		while(low<high&&A[low]<=pivot) low++;	//�������ұ�������Ԫ�� 
		A[high]=A[low];							//�����ƶ����Ҷ� 
	}
	A[low]=pivot;								//����Ԫ�ش�ŵ�����λ�� 
	return low;									//��������Ԫ��λ�� 
}


//��ѡ������
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


//������


//�鲢����
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






















 















 
