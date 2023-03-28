//图的 邻接矩阵 存储结构定义
#define MaxVertexNum 100			//顶点数目最大值 
typedef char VertexType;			//顶点数据类型 
typedef int EdgeType;				//带权图边上权值的数据类型（仅表示边是否存在时可用01枚举类） 
typedef struct{
	VertexType Vex[MaxVertexNum];				//一维数组表示 顶点表 
	EdgeType Edge[MaxVertexNum][MaxVertexNum];	//二位数组表示 边表 
	int vexnum arcnum;							//当前顶点数和弧数 
}MGraph; 


//图的 邻接表 存储结构定义
#define MaxVertexNum 100
typedef struct ArcNode{				//边表节点定义 
	int adjvex;						//弧指向的顶点 
	struct ArcNode *next;			//指向下一条弧的指针 
	//InfoType info;				//网的边权值 
}ArcNode; 

typedef struct VNode{				//顶点表结点 
	VertexType data;				//顶点数据域 
	ArcNode *first;					//指向第一条依附该顶点弧的指针 
}VNode,AdjList[MaxVertexNum];		//（顶点表预定义）		 

typedef struct{						 
	AdjList vertices;				//邻接表
	int vexnum,arcnum;				
}ALGraph;


//图的遍历
//广度优先搜索
bool visited[MAX_VERTEX_NUM];      //定义访问标记数组 
void BFSTraverse(Graph G){		  	
	for(int i=0;i<G.vexnum;i++)    //访问标记数组初始化 
		visited[i]=FALSE;
	InitQueue(Q);				   //初始化辅助队列Q 
	for(int i=0;i<G.vexnum;i++)    //从0号顶点开始遍历 
		if(!visited[i])			   //对每个连通分量调用一次BFS 
			BFS(G,i);            
}

void BFS(Graph G,int v){          //从顶点v出发，广度优先遍历图G 
	visit(v);					  //访问v 
	visited[v]=TRUE;			  //标记v 
	Enqueue(Q,v);				  //v入队Q 
	while(!isEmpty(Q)){	
		DeQueue(Q,v);			  //队列非空，队首元素出队 
		for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))  //检测v所有邻接点 
			if(!visited[w]){	  //w为v的未访问邻接点 
				visit(w);		  //访问w 
				visited[w]=TRUE;  //标为w 
				EnQueue(w);		  //w入队 
			}
	}
}


//BFS算法求解单源最短路径问题 
//顶点u到顶点v
void BFS_MIN_Distance(Graph G,int u){ //用d[i]表示u到i的最短路径
	for(i=0;i<G.vexnum;i++)
		d[i]=∞;                      //初始化路径长度 
	 visited[u]=TRUE;d[u]=0;		  //该结点到自己的路径长度为0 
	 EnQueue(Q,u);
	 while(!isEmpty(Q)){
	 	DeQueue(Q,u);
	 	for(w=FirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w))
	 		if(!visited[w]){
	 			visited[w]=TRUE;	   
	 			d[w]=d[u]+1;		  //当前访问结点的路径长度为 上一个结点的路径长度加1 
	 			EnQueue(Q,w);
			 }
	 }	
} 


//深度优先搜索
bool visited[MAX_VERTEX_NUM];		//访问标记数组 
void DFSTraverse(Graph G){			//对图G进行深度优先遍历	
	for(v=0;v<G.vexnum;v++)			//初始化访问标记数组
		visited[v]=FALSE;
	for(v=0;v<G.vexnum;v++)			//本例从v=0开始遍历 
		if(!visited[v])				//对每个连通分量调用一次DFS 
			DFS(G,v);
} 

void DFS(Graph G,int v){			//顶点v出发深度优先遍历图G 
	visit(v);
	visited[v]=TRUE;				//访问v并标记 
	for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
		if(!visited[w])				//对每个尚未访问的邻接顶点调用DFS 
			DFS(G,w);
}


//拓扑排序算法
bool TopologicalSort(Graph G){
	InitStack(S);					//初始化栈 存储入度为0的点 
	for(int i=0;i<G.vexnum;i++)	
		if(indegree[i]==0)
			Push(S,i);	            //所有入度为0的点进栈 
	int count=0;					//记录已输出的顶点数 
	while(!IsEmpty(S)){				//栈不空 则存在入度为0的点 
		Pop(S,i);					//栈顶元素出栈 
		print[count++]=i;			//用数组记录该顶点 
		for(p=G.vertices[i].firstarc;p;p->nextarc){
			v=p->adjvex;			//所有i指向的顶点入度减1 
			if(!(--indegree[v]))	//入度减为0的点压入栈中 
				Push(S,v);
		}
	}
	if(count<G.vexnum)				 
		return false;				//计数小于顶点数，排序失败，图中有回路
	else				
		return true; 				//拓扑排序成功 
} 
























