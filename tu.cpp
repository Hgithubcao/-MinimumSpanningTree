// tu.cpp: implementation of the tu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "最小生成树.h"
#include "tu.h"
#include "最小生成树Dlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////图/////////////////////////////////////////////////////////////////
tu::tu()
{
	p = NULL;
	num = 0; 
	tou = 0;
}

void tu::chead(int a)
{
	tou = a;
}

int tu::dlnum()
{
	return xian.num();
}

int tu::ok()
{
	return num;
}

void tu::zbz(CString& a, int& j, int& i)
{
	int beg = i;
    int fin = i;
    int sz = 0;
    int ai = 0;
    int ws = 1;
	while(i + 1 < a.GetLength())
	{
		if(a[i + 1] >= '0' && a[i + 1] <= '9')
		{
			fin = ++ i;
			j ++;
		}
		else
		{
			break;
		}
	}
    for(int k = fin; k >=  beg; k --)
    {
    	ai = a[k] - '0';
    	sz += ai * ws;
    	ws *= 10;
    }
	jd[(i - j) / num].next[(i - j) % num] = sz;
	jd[(i - j) / num].visit = 1;
}

void tu::setxy(int x, int y, int i)
{
	jd[i].x = x;
	jd[i].y = y;
}

bool tu::paint(int m_num, CString& m_jz)
{
	num = m_num;
	int i = 0;
	int j = 0;
	int k = 0;
	int m = m_jz.GetLength();
	for(; i < m; i ++)
	{
		if(m_jz[i] <= '9' && m_jz[i] >= '0')
		{
			zbz(m_jz, j, i);
		}
		else
		{
			j ++;
		}
	} 
	if((i - j) / num != num)
	{
		dele();
		return true;
	}
	else
	{
		return false;
	}
}

void tu::tutotree()
{
	int min;
	int m = tou;
	int n = tou;
	int nn[MAX];
	int sz = 0;
	tr.n = num;
	xian.dele();
	for(int k = 0; k < num; k ++)
	{
		tr.jd[k].x = jd[k].x + 325;
		tr.jd[k].y = jd[k].y;
	}
	while(sz < num)
	{
		min = 100;
		jd[n].visit = 0;
		for(int i = 0; i < sz; i ++)
		{
			for(int j = 0; j < num; j ++)
			{
				if(jd[j].visit && jd[nn[i]].next[j])
				{
					if(jd[nn[i]].next[j] < min )
					{
						min = jd[nn[i]].next[j];
						m = nn[i];
						n = j;
					}
				}
			}
		}
		nn[sz] = n;
		tr.jd[m].next[n] = jd[m].next[n];
		tr.dj += jd[m].next[n];
		if(m != n)
		{
			if(sz < num)
			{
				xian.push(tr.jd[m], tr.jd[n], tr.dj, jd[m].next[n]);
			}
		}
		sz ++;
	}
	tr.dj = 0;
	for(int t = 0; t < num; t ++)
	{
		jd[t].visit = 1;
	}
} 
	
void tu::print(HDC& hdc, CClientDC& dc, int sc)//0:一键；1：自动；2:手动
{
	char a = '0';
	CString csStr;
	if(sc != 2 || p == NULL)
	{
		p = xian.gethead();
	}
	for(int k = 0; k < num; k ++, a += 1)
	{
		dc.Ellipse(tr.jd[k].x + 20, tr.jd[k].y + 25, tr.jd[k].x - 5, tr.jd[k].y - 5);
		dc.TextOut(tr.jd[k].x , tr.jd[k].y, a);
	}
	if(sc != 2)
	{
		while(p)
		{
			MoveToEx(hdc, p -> beg.x, p -> beg.y, NULL);
			LineTo(hdc, p -> stp.x, p -> stp.y);
			csStr.Format("%d", p -> len);
			dc.TextOut((p -> beg.x + p -> stp.x) / 2, (p -> beg.y + p -> stp.y) / 2, csStr);
			csStr.Format("最小生成树的总代价：%d", p -> dj);
			dc.TextOut(600, 330, csStr);
			p = p -> next;
			if(sc)
			{
				Sleep(500);
			}
		}
	}
	else
	{
		MoveToEx(hdc, p -> beg.x, p -> beg.y, NULL);
		LineTo(hdc, p -> stp.x, p -> stp.y);
		csStr.Format("%d", p -> len);
		dc.TextOut((p -> beg.x + p -> stp.x) / 2, (p -> beg.y + p -> stp.y) / 2, csStr);
		csStr.Format("最小生成树的总代价：%d", p ->dj);
		dc.TextOut(600, 330, csStr);
		p = p -> next;			
	}
}

void tu::print2(HDC& hdc, CClientDC& dc)
{
	char a = '0';
	CString csStr;
	for(int k = 0; k < num; k ++, a += 1)
	{
		dc.Ellipse(jd[k].x + 20, jd[k].y + 25, jd[k].x - 5, jd[k].y - 5);
		dc.TextOut(jd[k].x , jd[k].y, a);
	}
	for(int i = 0; i < num; i ++)
	{
		for(int j = 0; j < num; j ++)
		{
			if(jd[i].next[j])
			{
				MoveToEx(hdc, jd[i].x, jd[i].y, NULL);
				LineTo(hdc, jd[j].x, jd[j].y);
				csStr.Format("%d", jd[i].next[j]);
				dc.TextOut((jd[i].x + jd[j].x) / 2, (jd[i].y + jd[j].y) / 2, csStr);
			}
		}
	}
}

void tu::dele()
{
	int i = 0;
	for(; i < num; i ++)
	{
		jd[i].visit = 1;
		jd[i].x = 0;
		jd[i].y = 0;
		for(int j = 0; j <num; j ++)
		{
			jd[i].next[j] = 0;
		}
	}
	for(i = 0; i < num; i ++)
	{
		tr.jd[i].visit = 1;
		tr.jd[i].x = 0;
		tr.jd[i].y = 0;
		for(int j = 0; j <num; j ++)
		{
			tr.jd[i].next[j] = 0;
		}
	}
	tr.n = 0;
	num = 0;
}

tu::~tu()
{
}

///////////////////////////////////////////////////树/////////////////////////////////////////////////////////////////
tree::tree()
{
	root = 0;
	dj = 0;
	n = 0;
}

tree::~tree()
{
}

///////////////////////////////////////////////////队列/////////////////////////////////////////////////////////////////
duilie::duilie()
{
	head = tail = NULL;
	n = 0;
}

void duilie::push(const node& beg, const node& stp, int dj, int length)
{
	line* xian;
	xian = new line;
	xian -> dj = dj;
	xian -> len = length;
	xian -> beg = beg;
	xian -> stp = stp;
	xian -> next = NULL;
	n ++;
	if(head == NULL || tail == NULL)
	{
		head = xian;
		tail = xian;
	}
	else
	{
		tail -> next = xian;
		tail = xian;
	}
}

line* duilie::gethead()
{
	return head;
}

int duilie::num()
{		
	return n;
}

void duilie::dele()
{
	line* p1;
	p1 = head;
	while(p1)
	{
		line* p2 = p1;
		p1 = p1 -> next;
		delete p2;
	}
	tail = NULL;
	n = 0;
}

duilie::~duilie()
{
}
