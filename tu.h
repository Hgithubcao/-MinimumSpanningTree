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
		void push(const node&, const node&, int, int);//������������
		int num();//������������
		line* gethead();//�������ͷ�ڵ�
		void dele();//ɾ������
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
		int ok();						//���ؽڵ���
		void chead(int);				//�޸�ͷ�ڵ�
		void zbz(CString&, int&, int&);//�ַ��������ζ�ά����
		void setxy(int, int, int);		//���ö���λ��
		bool paint(int, CString&);		//����ͼ
		void tutotree();				//��ͼ������С������
		void print(HDC&, CClientDC&, int);//��ӡ��С������
		void print2(HDC&, CClientDC&);	//��ӡͼ
		int dlnum();					//��������ڵ���
		void dele();					//ɾ��ͼ
		virtual ~tu();
};
#endif // !defined(AFX_TU_H__764BF5B4_A115_4B3A_BD31_B426BF540B35__INCLUDED_)
