#ifndef TREE_H_
#define TREE_H_

#ifdef __cplusplus
extern "C"{
#endif

/*定义一个5阶B树*/
#define ORDER 5 
#define MIN_CHILDREN ceil(ORDER / 2) 
#define MAX_ELEMENT (ORDER - 1) 
#define MIN_ELEMENT (MAX_ELEMENT - 1)
#define MAX_NUM	(ORDER - 1) 

struct tree;
struct __tree;
typedef struct tree* BTree;
typedef struct __tree* __BTree;
typedef BTree BNode;
typedef __BTree __BNode;
typedef int ElementType;

struct tree{
	BTree children[ORDER];
	ElementType data[ORDER - 1];	
	int amount;
};

struct __tree{
	__BTree children[ORDER + 1];
	ElementType data[ORDER];
	int amount;
};

//当元素数量超过阶数的时候进行分裂
static BTree
slpit_b_tree(const ElementType X,BNode T);

//错误处理
static void
error_print(const char* s);

//动态分配一个结点
static BNode
alloc_node(void);

//用给定的数据集初始化一棵B树
BTree
InitBTree(const ElementType* data);

//查找元素X，如果没有找到则返回NULL，
//如果找到则返回元素所在结点指针
BNode
FindX(const ElementType X,const	BTree tree);

//在结点中查找元素X，如果没有找到则返回-1
//如果找到，则返回元素所在数组的下标
static int
find(const ElementType X,const BNode node);

//向B树中插入元素X
BTree
Insert(const ElementType X,BTree T);

//删除X元素
ElementType
Delete(ElementType X,BTree T);

//销毁B树，释放动态申请的内存
void
FreeTree(BTree* T);

//打印B树
void
PrintBTree(BTree* T);

//向未满的结点中插入元素
static BNode
insert_non_full(ElementType X,BNode node);


#ifdef __cplusplus
}
#endif

#endif  
