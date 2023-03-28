//ͼ�� �ڽӾ��� �洢�ṹ����
#define MaxVertexNum 100			//������Ŀ���ֵ 
typedef char VertexType;			//������������ 
typedef int EdgeType;				//��Ȩͼ����Ȩֵ���������ͣ�����ʾ���Ƿ����ʱ����01ö���ࣩ 
typedef struct{
	VertexType Vex[MaxVertexNum];				//һά�����ʾ ����� 
	EdgeType Edge[MaxVertexNum][MaxVertexNum];	//��λ�����ʾ �߱� 
	int vexnum arcnum;							//��ǰ�������ͻ��� 
}MGraph; 


//ͼ�� �ڽӱ� �洢�ṹ����
#define MaxVertexNum 100
typedef struct ArcNode{				//�߱�ڵ㶨�� 
	int adjvex;						//��ָ��Ķ��� 
	struct ArcNode *next;			//ָ����һ������ָ�� 
	//InfoType info;				//���ı�Ȩֵ 
}ArcNode; 

typedef struct VNode{				//������� 
	VertexType data;				//���������� 
	ArcNode *first;					//ָ���һ�������ö��㻡��ָ�� 
}VNode,AdjList[MaxVertexNum];		//�������Ԥ���壩		 

typedef struct{						 
	AdjList vertices;				//�ڽӱ�
	int vexnum,arcnum;				
}ALGraph;


//ͼ�ı���
//�����������
bool visited[MAX_VERTEX_NUM];      //������ʱ������ 
void BFSTraverse(Graph G){		  	
	for(int i=0;i<G.vexnum;i++)    //���ʱ�������ʼ�� 
		visited[i]=FALSE;
	InitQueue(Q);				   //��ʼ����������Q 
	for(int i=0;i<G.vexnum;i++)    //��0�Ŷ��㿪ʼ���� 
		if(!visited[i])			   //��ÿ����ͨ��������һ��BFS 
			BFS(G,i);            
}

void BFS(Graph G,int v){          //�Ӷ���v������������ȱ���ͼG 
	visit(v);					  //����v 
	visited[v]=TRUE;			  //���v 
	Enqueue(Q,v);				  //v���Q 
	while(!isEmpty(Q)){	
		DeQueue(Q,v);			  //���зǿգ�����Ԫ�س��� 
		for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))  //���v�����ڽӵ� 
			if(!visited[w]){	  //wΪv��δ�����ڽӵ� 
				visit(w);		  //����w 
				visited[w]=TRUE;  //��Ϊw 
				EnQueue(w);		  //w��� 
			}
	}
}


//BFS�㷨��ⵥԴ���·������ 
//����u������v
void BFS_MIN_Distance(Graph G,int u){ //��d[i]��ʾu��i�����·��
	for(i=0;i<G.vexnum;i++)
		d[i]=��;                      //��ʼ��·������ 
	 visited[u]=TRUE;d[u]=0;		  //�ý�㵽�Լ���·������Ϊ0 
	 EnQueue(Q,u);
	 while(!isEmpty(Q)){
	 	DeQueue(Q,u);
	 	for(w=FirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w))
	 		if(!visited[w]){
	 			visited[w]=TRUE;	   
	 			d[w]=d[u]+1;		  //��ǰ���ʽ���·������Ϊ ��һ������·�����ȼ�1 
	 			EnQueue(Q,w);
			 }
	 }	
} 


//�����������
bool visited[MAX_VERTEX_NUM];		//���ʱ������ 
void DFSTraverse(Graph G){			//��ͼG����������ȱ���	
	for(v=0;v<G.vexnum;v++)			//��ʼ�����ʱ������
		visited[v]=FALSE;
	for(v=0;v<G.vexnum;v++)			//������v=0��ʼ���� 
		if(!visited[v])				//��ÿ����ͨ��������һ��DFS 
			DFS(G,v);
} 

void DFS(Graph G,int v){			//����v����������ȱ���ͼG 
	visit(v);
	visited[v]=TRUE;				//����v����� 
	for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
		if(!visited[w])				//��ÿ����δ���ʵ��ڽӶ������DFS 
			DFS(G,w);
}


//���������㷨
bool TopologicalSort(Graph G){
	InitStack(S);					//��ʼ��ջ �洢���Ϊ0�ĵ� 
	for(int i=0;i<G.vexnum;i++)	
		if(indegree[i]==0)
			Push(S,i);	            //�������Ϊ0�ĵ��ջ 
	int count=0;					//��¼������Ķ����� 
	while(!IsEmpty(S)){				//ջ���� ��������Ϊ0�ĵ� 
		Pop(S,i);					//ջ��Ԫ�س�ջ 
		print[count++]=i;			//�������¼�ö��� 
		for(p=G.vertices[i].firstarc;p;p->nextarc){
			v=p->adjvex;			//����iָ��Ķ�����ȼ�1 
			if(!(--indegree[v]))	//��ȼ�Ϊ0�ĵ�ѹ��ջ�� 
				Push(S,v);
		}
	}
	if(count<G.vexnum)				 
		return false;				//����С�ڶ�����������ʧ�ܣ�ͼ���л�·
	else				
		return true; 				//��������ɹ� 
} 
























