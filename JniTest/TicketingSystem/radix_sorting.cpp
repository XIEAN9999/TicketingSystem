#include "stdafx.h"
#include "defines.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX_TRANSIT_NUM 3
#include <string>
using std::string;

//最大转机次数


//LINK_LIST
//链表结构体的初始化
void init_linklist(LinkList *list)
{
	list=(LinkList*)malloc(sizeof(LinkList));
	list->head=NULL;
	list->len=0;
}
//链表结构体的插入算法
void insert_linklist(LinkList *list,int *datas)
{
	Node *element=(Node *)malloc(sizeof(Node));
	element->datas=datas;
	element->next=list->head;
	list->head=element;
}
	
//SQ_LIST
//在顺序表中插入城市名字符串
STATUS insert_sqlist(string *list,string element)
{
	return SUCCESS;
}
//在顺序表中查找城市名称字符串的位置
STATUS locate_in_sqlist(string *list,string element,int &i)
{
	return SUCCESS;
}

//GRAPH
//为graph结构体分配内存空间
Graph * init_graph()
{
	return (Graph*)malloc(sizeof(Graph));
}
//为graph中的顶点和边赋值
STATUS create_graph(Graph *map,FlightInfo *infos)
{
	FlightInfo *info=infos;
	int i=0,j=0,k=0;
	while(info!=NULL)
	{
		if(insert_sqlist(map->cities,info->start)) map->vexnum++;
		if(insert_sqlist(map->cities,info->end)) map->vexnum++;
		i++;		
		info++;
	}
	for(i=0;i<map->vexnum;i++)
		for(j=0;j<map->vexnum;j++)
		{
			map->arcs[i][j].flight_number=INT_MAX;
		}
	info=infos;
	while(info!=NULL)
	{
		locate_in_sqlist(map->cities,info->start,i);
		locate_in_sqlist(map->cities,info->end,j);
		//k为当前info所指向的元素在数组中的序号，作为指针使用
		map->arcs[i][j].flight_number=k;
		k++;
		info++;
	}
	return SUCCESS;
}
//找到以start 和 end 为起点终点城市的所有转机次数少于等于最大值（MAX_TRANSIT_NUM）的路线，用
//链表储存，每个节点为一个数组
//寻路迭代函数
void if_pass(Graph *map,int start,int end,int *path,LinkList *results,int &transit_num)
{
	for(int i=0;i<map->vexnum;i++)
	{
		if(map->arcs[start][i].flight_number<INT_MAX)
		if(end==i)
		{
			path[transit_num]=map->arcs[start][i].flight_number;
			int result[MAX_TRANSIT_NUM];
			for(int j=0;j<MAX_TRANSIT_NUM;j++)
				result[j]=*(path++);
			insert_linklist(results,result);
		}
		else
		{
			if((transit_num+1)<MAX_TRANSIT_NUM)
			{				
					path[transit_num]=map->arcs[start][i].flight_number;
					transit_num++;
					if_pass(map,i,end,path,results,transit_num);
			}
		}
		

	}

}


LinkList * get_all_paths(Graph *map,string start ,string end)
{
	int i=0,j=0,transit_num=0;
	int path[MAX_TRANSIT_NUM];
	LinkList *results=NULL;
	init_linklist(results);
	if(!locate_in_sqlist(map->cities,start,i)||!locate_in_sqlist(map->cities,end,j))
		return NULL;
	if_pass(map,i,j,path,results,transit_num);
	return results;
}


