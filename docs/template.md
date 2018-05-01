# DataStructure-Templates

## 数据结构模板

## 前言

本篇博客的模板，全部是我纯手打的，如果有发现错误，请提issues指正:)。欢迎大家参考。

## C/C++ 常用字符串函数
```
#include <string.h>
```
strcpy

```
char * strcpy( char * dest, const char * src );
```
功能：把 src 所指由NULL结束的字符串复制到 dest 所指的数组中。
说明：src 和 dest 所指内存区域不可以重叠且 dest 必须有足够的空间来容纳 src 的字符串。返回指向 dest 结尾处字符(NULL)的指针。

strcmp

```
int strcmp ( const char * str1, const char * str2 );
```
功能：比较字符串 str1 和 str2。
说明：
当s1<s2时，返回值<0
当s1=s2时，返回值=0
当s1>s2时，返回值>0

strlen

```
size_t strlen ( const char * str );
```

功能：计算字符串 str 的长度
说明：返回 str 的长度，不包括结束符NULL。（注意与 sizeof 的区别）

C++：StringStream

```
#include <sstream>

int a;

stringstream ss;
ss << "32";
ss >> a;
ss.clear();
```


## 排序

### 相关定义
```
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*存储数组定义*/

int num[100005];

void swap1(int i, int j)
{
    int t = num[i];
    num[i] = num[j];
    num[j] = t;
}

/*Printnum 输出*/

void Printnum(int n)
{
    for (int i = 1; i <= n; i++) {
        cout << num[i] << " ";
    }
    
    cout << endl;
}
```
### 冒泡排序
```
/*Bubble_Sort 冒泡排序*/

void Bubble_Sort(int n)
{
    int i, j;
    
    for (i = 1; i <= n; i++)                //遍历n次
    {
        for (j = 1; j <= n-i; j++)          //每次都把最大数往后排，缩小范围
        {
            if (num[j] > num[j+1])
            {
                swap1(j, j+1);
            }
        }
    }
}

void Bubble_Sort_Better(int n)
{
    int i, j;
    
    for (i = 1; i <= n; i++)
    {
        bool flag = true;
        
        for (j = 1; j <= n-i; j++)
        {
            if (num[j] > num[j+1])
            {
                flag = false;
                
                swap1(j, j+1);
            }
        }
        
        if (flag) break;                    //某一次遍历没有发生交换时，结束
    }
}
```
### 选择排序
```
/*Selection_Sort 选择排序*/

void Selection_Sort(int n)
{
    int i, j;
    
    int rcd;
    
    for (i = 1; i <= n; i++)
    {
        rcd = i;
        
        for (j = i+1; j <= n; j++)
        {
            if (num[j] < num[rcd])          //找出i+1=>n范围内的最小元并前移
            {
                rcd = j;
            }
        }
        
        swap1(i, rcd);
    }
}
```
### 归并排序
```
/*Merge_Sort 归并排序*/

int temp[100005];

void Merge_Array(int l1, int r1, int l2, int r2)
{
    int p1 = l1;
    int p2 = l2;
    
    int i = 1;
    
    memset(temp, 0, sizeof(temp));
    
    for (i = l1; i <= r2; i++)
    {
        if (p1 > r1)
        {
            temp[i] = num[p2++];
            
            continue;
        }
        
        if (p2 > r2)
        {
            temp[i] = num[p1++];
            
            continue;
        }
        
        if (num[p1] < num[p2])
        {
            temp[i] = num[p1++];
            
            continue;
        }
        
        else
        {
            temp[i] = num[p2++];
            
            continue;
        }
    }
    
    for (i = l1; i <= r2; i++)
    {
        num[i] = temp[i];
    }
    
}

void Merge_Sort(int l, int r)
{
    if (l < r)
    {
        int mid = (l+r)/2;
        
        Merge_Sort(l, mid);             //l => mid
        Merge_Sort(mid+1, r);           //mid+1 => r
        
        Merge_Array(l, mid, mid+1, r);  //l => mid => mid+1 => r
    }
}
```
### 快速排序
```
/*Quick_Sort 快速排序*/

int Quick_Sort_Adjust(int l, int r)
{
    int key = l;               //选取第一个元素为基准值
    
    int a, b;
    
    a = l+1;
    
    b = r;
    
    while (a < b)
    {
        bool out_bound = false;
        
        while (1)
        {
            if (num[a] > num[key]) break;
            
            a++;
            
            if (a > r)
            {
                out_bound = true;
                
                break;
            }
        }
        
        while (1)
        {
            if (num[b] < num[key]) break;
            
            b--;
            
            if (b < l)
            {
                out_bound = true;
                
                break;
            }
        }
        
        if (out_bound || a >= b) break;         //如果出现越界或a>=b直接结束
        
        swap1(a, b);
        
        a++;
        b--;
    }
    
    swap1(key, a-1);
    
    return a-1;
}

void Quick_Sort(int l, int r)
{
    if (l < r)
    {
        int mid = Quick_Sort_Adjust(l, r);
        
        Quick_Sort(l, mid-1);               //l => mid-1
        Quick_Sort(mid+1, r);               //mid+1 => r
    }
}
```

## 并查集

### 并查集
```
int fa[100005];

void IniFUS(int n)
{
    int i;
    
    for (i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
}

int Find(int x)
{
    int f = x;
    
    while (f != fa[f])
    {
        f = fa[f];
    }
    
    int i = x, j;
    
    while (i != f)
    {
        j = fa[i];
        
        fa[i] = f;
        
        i = j;
    }
    
    return f;
}

void Union(int x, int y)
{
    int xfa = Find(x);
    int yfa = Find(y);
    
    if (xfa != yfa) {
        fa[yfa] = xfa;
    }
}
```

## 图

### 邻接表
```
struct edge
{
    edge *next;
    int num;
    int len;
};

edge eg[100000];

struct head
{
    edge *next;
    int num;
};

head h[100000];

void IniList(int n)
{
    int i;
    
    for (i = 1; i <= n; i++)
    {
        h[i].next = NULL;
        h[i].num = i;
    }
}

void CreatList(int x, int y, int leng)
{
    edge *p1, *p2;
    
    p1 = new edge;
    p1 -> next = NULL;
    p1 -> num = y;
    p1 -> len = leng;
    
    p2 = h[x].next;
    
    if (p2 == NULL) {
        h[x].next = p1;
    }
    
    else
    {
        while (p2 -> next != NULL) {
            p2 = p2 -> next;
        }
        
        p2 -> next = p1;
    }
}
```

**Dijkstra 单点到多点距离(邻接表实现)：**

```
/*
    Dijkstra：
        1.DijInitial
        2.x_HasPath_y
        3.Dijkstra
 */

int pre[100005];                         //最短路节点的前继节点(查询最短路)

int dist[100005];                        //源点到每个节点的最短路距离

bool ins[100005];                        //节点i是否位于已查询节点集合S

void DijInitail(int start, int n)
{
    int i;
    
    for (i = 1; i <= n; i++)
    {
        dist[i] = maxn;
        
        pre[i] = i;
        
        ins[i] = false;
    }
    
    dist[start] = 0;
    
    edge *p;
    
    p = h[start].next;
    
    while (p != NULL)
    {
        dist[p->num] = p->len;
        
        p = p -> next;
    }
}

int x_HasPath_y(int x, int y)
{
    edge *p;
    
    p = h[x].next;
    
    while (p != NULL)
    {
        if (p -> num == y)
        {
            return p -> len;
        }
        
        p = p -> next;
    }
    
    return -1;
}

int Dijkstra(int start, int find, int n)
{
    int i, j;
    
    DijInitail(start, n);
    
    ins[start] = true;
    
    for (i = 1; i < n; i++)                     //n-1次
    {
        int addnum = start;                     //记录此时V中最靠近源点的节点
        
        int minlen = 1000000;                   //以及源点到该节点的长度
        
        for (j = 1; j <= n; j++)                //源点从V中挑一个最近节点
        {
            if (ins[j]) continue;               //这个节点在S中，跳过
            
            if (dist[j] < minlen)               //当前到源点距离最小的节点
            {
                addnum = j;
                
                minlen = dist[j];               //更新离源点最近节点的信息
            }
        }
        
        ins[addnum] = true;
        
        for (j = 1; j <= n; j++)                //新来的节点向外得到路径信息
        {                                       //并维护dist
            if (ins[j]) continue;
            
            /* 从源点到当前节点next的距离 + 当前节点next到某个相邻节点j的距离。*/
            /* 如果小于目前源点到节点j的最短距离dist[j]，更新dist[j]。       */
            
            int pathlen = x_HasPath_y(addnum, j);
            
            if (pathlen == -1) continue;
            
            int t = dist[addnum] + pathlen;
            
            if (t < dist[j])
            {
                dist[j] = t;
                
                pre[j] = addnum;
            }
        }
        
    }
    
    return dist[find];
}
```

**Dijkstra 多点到多点(邻接矩阵实现)：**

```
int DijGraph[105][105];               //节点i和j之间的距离：DijGraph[i][j]

int pre[105];                         //最短路节点的前继节点(查询最短路)

int dist[105];                        //源点到每个节点的最短路距离

bool ins[105];                        //节点i是否位于已查询节点集合S

/*
 初始化函数
 */

void Initial(int n)
{
    for (int i = 1; i <= n; i++)
    {
        ins[i] = false;
        
        pre[i] = -1;
        
        for (int j = 1; j <= n; j++)
        {
            if (i == j) DijGraph[i][j] = 0;
            
            else DijGraph[i][j] = 1000000;
        }
    }
}

void Dijkstra(int n, int b, int e)
{
    int i, j;
    
    for (i = 1; i <= n; i++) {                  
        dist[i] = DijGraph[b][i];
    }
    
    dist[b] = 0;
    ins[b] = true;                              
    
    for (i = 2; i <= n; i++)                    
    {
        int next = b;                           
        int minlen = 1000000;                   
        
        for (j = 1; j <= n; j++)                
        {
            if (ins[j]) continue;              
            
            if (dist[j] < minlen) {             
                
                next = j;
                
                minlen = dist[j];               
            }
        }
        
        ins[next] = true;                       
        
        for (j = 1; j <= n; j++)                
        {                
            if (ins[j]) continue;
            
            int t = dist[next] + DijGraph[next][j];
            
            if (t < dist[j])
            {
                dist[j] = t;
                
                pre[j] = next;
            }
        }
    }
}

```

**Prim**

```
int Primgh[10000][10000];                        //存储图

bool refer[10005];                               //判断是否在Enew中

/*
    用于初始化的函数
 */

void Initial(int n, int m)
{
    int i, j;
    
    for (i = 1; i <= n; i++)
    {
        refer[i] = false;
        
        for (j = 1; j <= n; j++)
        {
            if (i == j) {
                Primgh[i][j] = 0;
            }
            
            else Primgh[i][j] = maxn;
        }
    }
    
    int u, v, w;
    
    for (i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        
        Primgh[u][v] = w;
        Primgh[v][u] = w;
    }
}

/*
    Prim算法，主体部分
 */

int Prim_Alg(int n, int m)
{
    Initial(n, m);
    
    int i, j, k;
    
    int ans = 0;                
    //最小生成树的路径长度                 
    
    refer[1] = true;            
    //选择点1出发        
    
    //最小生成树一共有n-1条边，因此需要寻找最短边n-1次，基于贪心
    for (i = 1; i <= n-1; i++)  
    {
        int minlen = maxn;      
        //minlen: 在Vnew中的节点所连接的边中，寻找cost最小的边
        
        int rcd = 1;            
        //cost最小的边有两个节点，rcd记录其中的不属于Vnew的节点
        
        for (j = 1; j <= n; j++)        
        {
            if (!refer[j]) continue;    
            //遍历Vnew中的所有节点
            
            int len1 = maxn;            
            //对于Vnew中的某个节点来说，所连接的最短的路径cost大小
            
            int rcd1 = 1;               
            //对于Vnew中的某个节点来说，rcd记录的节点
            
            //贪心，寻找这个节点连接的cost最小的路径
            for (k = 1; k <= n; k++)    
            {
                if (!refer[k])
                {
                    if (Primgh[j][k] < len1) {
                        
                        len1 = Primgh[j][k];
                        
                        rcd1 = k;
                    }
                }
            }
            
            if (len1 < minlen) {        
                //判断贪心得到的路径是否是全局cost最短
                
                minlen = len1;
                
                rcd = rcd1;
            }
        }
        
        /*Debug：*/
        //char check = 'A'+rcd-1;
        //cout << "rcd: " << check << endl;
        //cout << "minlen: " << minlen << endl;
        
        refer[rcd] = true;              
        //贪心求出cost最小的路径，rcd记录的节点入Vnew
        rcd = 1;                        
        //重置rcd
        
        ans += minlen;                  
    }
    
    return ans;
}

```

**Kruskal**

```
struct stedge
{
    int u, v, len;
};

bool cmp(stedge s1, stedge s2)
{
    return s1.len < s2.len;
}

stedge seg[100000];

int fa[100005];

void Inifa(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
}

int findfa(int x)
{
    int f = x;
    
    while (f != fa[f])
    {
        f = fa[f];
    }
    
    int i = x, j;
    
    while (i != f)
    {
        j = fa[i];
        
        fa[i] = f;
        
        i = j;
    }
    
    return f;
}

int main()
{
    int i, n, m;
    
    cin >> n >> m;
    
    Inifa(n);
    
    int u, v, w;
    
    for (i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        
        seg[i].u = u;
        seg[i].v = v;
        seg[i].len = w;
    }
    
    sort(seg+1, seg+m+1, cmp);
    
    int cnt = 0, lencnt = 0;
    
    for (i = 1; i <= m; i++)
    {
        int fa1 = findfa(seg[i].u);
        int fa2 = findfa(seg[i].v);
        
        if (fa1 == fa2) continue;
        
        cnt++;
        
        lencnt += seg[i].len;
        
        fa[fa1] = fa2;         //一定是祖先找祖先合并
        
        if (cnt == n-1) break;
    }
    
    cout << lencnt;
    
    return 0;
}
```


## 树

### 树的序遍历
```
//
//  main.cpp
//  Tree2
//
//  Created by wasdns on 16/12/19.
//  Copyright © 2016年 wasdns. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Node
{
    int num;
    
    Node *l, *r;
};

int preorder[100005];

int midorder[100005];

int aftorder[100005];

Node *node[100005];

int n;

int tot = 1;    //记录aftorder


/*
    Ininode函数：用于初始化节点
 */
void Ininode()
{
    int i;
    
    for (i = 1; i <= n; i++)
    {
        Node *p = new Node;
        
        p -> num = i;
        p -> l = NULL;
        p -> r = NULL;
        
        node[i] = p;
    }
}

/*
    FindRoot函数：根据后序、中序建树
 */
Node* FindRoot(int aft_l, int aft_r, int mid_l, int mid_r)
{
    if (aft_r - aft_l < 0) return NULL;
    
    Node *root = new Node;
    
    root -> num = aftorder[aft_r];
    
    if (aft_l == aft_r)
    {
        root -> l = NULL;
        root -> r = NULL;
        
        return root;
    }
    
    int index;
    
    for (index = mid_l; index <= mid_r; index++)
    {
        if (midorder[index] == aftorder[aft_r]) break;
    }
    
    root -> r = FindRoot(aft_r-(mid_r-index), aft_r-1, index+1, mid_r);
    root -> l = FindRoot(aft_l, aft_r-(mid_r-index)-1, mid_l, index-1);
    
    return root;
}


/*
    FindRoot函数：根据先序和中序建树。
 */
Node* FindRoot1(int pre_l, int pre_r, int mid_l, int mid_r)
{
    if (pre_r - pre_l < 0) return NULL;
    
    Node* root = new Node;
    
    /*将先序列表中最左边的节点作为root*/
    root -> num = preorder[pre_l];
    
    if (pre_l == pre_r)
    {
        root -> l = NULL;
        root -> r = NULL;
        
        return root;
    }
    
    /*在中序中找到root所在的位置，用index表示*/
    int index;
    
    for (index = mid_l; index <= mid_r; index++)
    {
        if (midorder[index] == preorder[pre_l]) break;
    }
    
    /*说明：利用index进行递归，分成左子树和右子树。        */
    /*同时将先序序列和后序序列进行划分，将位置作为递归的参数。*/
    root -> l = FindRoot1(pre_l+1, pre_l+(index-mid_l), mid_l, index-1);
    root -> r = FindRoot1(pre_l+(index-mid_l)+1, pre_r, index+1, mid_r);
    
    return root;
}

/*
    CalAftorder函数：根据给定的树来计算后序序列
 */
void CalAftorder(Node *head)
{
    if (head == NULL) return ;
    
    CalAftorder(head -> l);
    CalAftorder(head -> r);
    
    aftorder[tot++] = head -> num;
}


/*
    CalPreorder函数：根据给定的树来计算先序序列
 */
void CalPreorder(Node *head)
{
    if (head == NULL) return ;
    
    preorder[tot++] = head -> num;
    
    CalPreorder(head -> l);
    CalPreorder(head -> r);
}


/*
    Print函数：输出先序、后序序列
 */
void Print()
{
    int i;
    
    for (i = 1; i <= n; i++) {
        cout << preorder[i] << " ";
    }
    
    cout << endl;
    
    for (i = 1; i <= n; i++) {
        cout << aftorder[i] << " ";
    }
    
    cout << endl;
}
```


## 优先队列 STL

值大 => 优先级高

```
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;
```

值小 => 优先级高

```
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

struct cmp
{
    bool operator() (int x,int y) {
        return x > y;
    }
};

priority_queue<int, vector<int>, cmp> q;
```
结构体：

```
struct node
{
      int x, y;
       friend bool operator < (node a, node b)
      {
             return a.x > b.x; //结构体中，x小的优先级高
      }
};
priority_queue<node>q;//定义方法
//在该结构中，y为值, x为优先级。
//通过自定义operator<操作符来比较元素中的优先级。
//在重载”<”时，最好不要重载”>”，可能会发生编译错误
```

手写Heap堆：

```
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int size = 0;

int Heap[100005];

/*
     维护函数keep
 */
void keep(int son)
{
    int fa = son/2;
    
    while (fa >= 1 && Heap[fa] > Heap[son])
    {
        int t = Heap[fa];
        Heap[fa] = Heap[son];
        Heap[son] = t;
        
        son = fa;
        fa = fa/2;
    }
}

/*
    初始化函数IniHeap
 */
void IniHeap()
{
    int i;
    
    for (i = size; i >= 1; i--)
    {
        keep(i);
    }
}

/*
    InsProtect函数：插入新节点并维护
 */
void InsProtect(int a)
{
    Heap[++size] = a;
    
    keep(size);
}

/*
    DelMin函数：删除最小元并维护
 */
int DelMin()
{
    int minum = Heap[1];
    
    int t = Heap[size];
    
    Heap[1] = t;
    
    size--;
    
    IniHeap();
    
    return minum;
}
```

## Hash函数

Index哈希函数例1：

```
#include<iostream> 
#include<cstdio> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
const int maxn =1000005; 
int num[maxn]; 
char a[maxn],str[10]; 
   
int IndexHash(char *key) 
{ 
    int hashval = 0; 
    while (*key != '\0')    hashval = (hashval<<5) + *key++; 
    return hashval; 
} 
   
   
int main() 
{ 
    //freopen("data.txt","r",stdin); 
    //freopen("2.txt","w",stdout);  
    int n,m,k,i,p = 0; 
    memset(str,0,sizeof(str)); 
    scanf("%d%d%d",&n,&m,&k); 
    scanf("%s",a); 
    for (i = 0;i <= n - k;i++) 
    { 
        strncpy(str,a + i,k); 
        int hashval = IndexHash(str); 
        num[p++] = hashval; 
    } 
    sort(num,num+p); 
    int res = 1; 
    for (i = 1;i < p;i++) 
    { 
        if (num[i] != num[i-1]) res++; 
    } 
    printf("%d\n",res); 
    return 0; 
}
```

例2：

```
//
//  main.cpp
//  searchme
//
//  Created by wasdns on 16/12/12.
//  Copyright © 2016年 wasdns. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 999983                          //int范围内取最大的素数
#define maxn 1000005
using namespace std;

/*
    Hash函数：IndexHash
 */

int IndexHash(char *s)
{
    int hashval = 0;
    
    while (*s != '\0') {
        hashval = (hashval << 5) + *s++;
    }
    
    return hashval % mod;
}

char searchname[maxn][10];                  //你的名字

int head[maxn];                             //邻接表的头数组

int lnext[maxn];                            //邻接表的节点数组

int tot = 1;                                //第tot个字符串

/*
    AddNode创建邻接表函数：
        在head[hashval]中存指向单链表的指针
        插入时，现有head的值存入lnext[tot]
        之后使head[hashval]成为新的节点
        相当于不断在链表的首部进行插入
 */

void AddNode(int hashval)
{
    lnext[tot] = head[hashval];
    
    head[hashval] = tot;
    
    tot++;
}

/*
    询问函数：
        通过IndexHash得到hash值
        利用head[hashval]找到指向对应hash值的单链表
        遍历单链表，找到 -> 计数器++。
 */

void query(int q)
{
    int cnt = 0;
    
    for (int i = 1; i <= q; i++)
    {
        int hashval = 0;
        
        char findname[10];
        
        scanf("%s", findname);
        
        hashval = IndexHash(findname);
        
        for (int j = head[hashval]; j != -1; j = lnext[j])
        {
            if (strcmp(searchname[j], findname) == 0) {
                cnt++;
            }
        }
    }
    
    printf("%d\n", cnt);
}

int main()
{
    memset(head, -1, sizeof(head));
    memset(lnext, -1, sizeof(lnext));
    
    int n, m;
    
    cin >> n >> m;
    
    int i;
    
    for (i = 1; i <= n; i++)
    {
        scanf("%s", searchname[i]);
        
        int hashval = IndexHash(searchname[i]);
        
        AddNode(hashval);
    }
    
    cout << endl;
    
    query(m);
    
    return 0;
}
```

2017.3.20
