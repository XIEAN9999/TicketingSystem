#include "stdafx.h"
#include "defines.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX_TRANSIT_NUM 3
#include <string>
using std::string;

//���ת������


//LINK_LIST
//����ṹ��ĳ�ʼ��
void init_linklist(LinkList *list)
{
	list=(LinkList*)malloc(sizeof(LinkList));
	list->head=NULL;
	list->len=0;
}
//����ṹ��Ĳ����㷨
void insert_linklist(LinkList *list,int *datas)
{
	Node *element=(Node *)malloc(sizeof(Node));
	element->datas=datas;
	element->next=list->head;
	list->head=element;
}
	
//SQ_LIST
//��˳����в���������ַ���
STATUS insert_sqlist(string *list,string element)
{
	return SUCCESS;
}
//��˳����в��ҳ��������ַ�����λ��
STATUS locate_in_sqlist(string *list,string element,int &i)
{
	return SUCCESS;
}

//GRAPH
//Ϊgraph�ṹ������ڴ�ռ�
Graph * init_graph()
{
	return (Graph*)malloc(sizeof(Graph));
}
//Ϊgraph�еĶ���ͱ߸�ֵ
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
		//kΪ��ǰinfo��ָ���Ԫ���������е���ţ���Ϊָ��ʹ��
		map->arcs[i][j].flight_number=k;
		k++;
		info++;
	}
	return SUCCESS;
}
//�ҵ���start �� end Ϊ����յ���е�����ת���������ڵ������ֵ��MAX_TRANSIT_NUM����·�ߣ���
//�����棬ÿ���ڵ�Ϊһ������
//Ѱ·��������
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


