// HashTable.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>  //scanf
#include <stdlib.h> //malloc

#define N 10

struct Node
{
	int num;
	Node* pNext;
};



//哈希表
class HashTable 
{
private:
	Node* arr[N];//存放头节点
public:
	//构造
	HashTable()
	{
		for (int i = 0; i < N; i++)
		{
			arr[i] = NULL;
		}
		printf("构造函数执行\n");
	}
	//存放
	void put(int num)
	{
		int n = (num * 3) % 7;
		if (arr[n] == NULL)
		{
			Node* p;
			p = (Node*)malloc(sizeof(Node));//p储存申请的内存空间的地址
			p->pNext = NULL;//为了后来的循环判断条件
			arr[n] = p;//将p储存的值赋给arr[n]，则arr[n]储存地址↑
			arr[n]->num = num;//第一个
		}
		else
		{
			Node* temp;
			temp = arr[n];
			while (temp->pNext != NULL)//移动到最后一个链表元素上
			{
				temp = temp->pNext;
			}
			//申请内存空间
			Node* p;
			p = (Node*)malloc(sizeof(Node));//p储存申请的内存空间的地址
			p->pNext = NULL;//为了后来的循环判断条件
			
			temp->pNext = p;//连接

			temp = temp->pNext;
			temp->num = num;
		}
	}
	//取出
	int get(int num)
	{
		int n = (num * 3) % 7;//数组下标
		Node* p;
		p = arr[n];
		while (p)//当前元素
		{
			if (p->num == num)//当key相等时
			{
				return p->num;//可以返回value
			}
			p = p->pNext;//后移
		}
		return -1;
	}
	//遍历
	void ergodic()
	{
		int i = 0;
		Node* p;
		printf("{ ");
		while (i < N)
		{
			p = arr[i];
			printf("[ ");
			while (p)//当前元素不为NULL
			{
				printf("%d ", p->num);//输出
				p = p->pNext;//后移
			}
			printf("]\n");
			i++;
		}
		printf("}\n");
	}
	//析构
	~HashTable()
	{
		int i = 0;
		Node* p;
		Node* temp;
		while (i<N)
		{
			p = arr[i];
			while (p)//不为NULL
			{
				temp = p;//储存申请的第 1 2 3 .. 个内存空间
				p = p->pNext;//指向下一个
				free(temp);//销毁
			}
		}
		for (int i = 0; i < N; i++)
		{
			arr[i] = NULL;
		}
		printf("析构函数执行");
	}
};


int main(void)
{
	int num;
	int sign = 5;
	//scanf("%d", &num);
	
	HashTable hashTable;
	while (sign) 
	{
		printf("请输入数据:");
		scanf_s("%d", &num);
		hashTable.put(num);
		sign--;
	}
	hashTable.ergodic();
	
	printf("请输入想要的得到数据:");
	int x;
	scanf_s("%d",&x);
	printf("%d", hashTable.get(x));
	
	//printf("结束");
	system("pause");
	exit(0);
    return 0;
}