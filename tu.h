// tu.h: interface for the tu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TU_H__764BF5B4_A115_4B3A_BD31_B426BF540B35__INCLUDED_)
#define AFX_TU_H__764BF5B4_A115_4B3A_BD31_B426BF540B35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define MAX 50

struct node
{
	int x;
	int y;
	bool visit;
	int next[MAX];
};
 
struct line
{
	int dj;
	int len;
	node beg;
	node stp;
	line* next;
};

class duilie
{
	line* head;
	line* tail;
	int n;
	public:
		duilie();
		void push(const node&, const node&, int, int);//输入链表数据
		int num();//返回链表数量
		line* gethead();//获得链表头节点
		void dele();//删除链表
		~duilie();
};

class tree
{
	int root;
	node jd[MAX];
	int dj;
	int n;
	public:
		friend class tu;
		tree();
		~tree();
};

class tu  
{
	int num;
	int tou;
	node jd[MAX];
	tree tr;
	duilie xian;
	line* p;
	public:
		tu();
		int ok();						//返回节点数
		void chead(int);				//修改头节点
		void zbz(CString&, int&, int&);//字符串变整形二维数组
		void setxy(int, int, int);		//设置顶点位置
		bool paint(int, CString&);		//建立图
		void tutotree();				//由图生成最小生成树
		void print(HDC&, CClientDC&, int);//打印最小生成树
		void print2(HDC&, CClientDC&);	//打印图
		int dlnum();					//返回链表节点数
		void dele();					//删除图
		virtual ~tu();
};
#endif // !defined(AFX_TU_H__764BF5B4_A115_4B3A_BD31_B426BF540B35__INCLUDED_)
