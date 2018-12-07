
//����״̬
#ifndef _STATUS_
#define _STATUS_
#define STATUS int
#define ERROR 0
#define SUCCESS 1
#endif

//���Խṹ��
#ifndef _TESTING_STRUCT_
#define _TESTING_STRUCT_
#include<string>
using std::string;
typedef struct student
{
    string name,job;
	int age;
} STU;
#define _INFO_FILE_PATH_  "./test.data"
#endif

//�ļ����غ���
#ifndef _FILE_LOADER_
#define _FILE_LOADER_
int load_data();
void wirte_info(const STU *,int);
//ʱ��ṹ��
typedef struct Time
{
	int hour,minute;
}Time;
//��Ҫ�ṹ��
#include<string>
using std::string;
typedef struct FlightInfo
{
	string flight_num,start,end,plane_type;
	Time launch_time,arrive_time;
	float price;
}FlightInfo;

#endif

//����ͼ�Ľṹ�������㷨
#ifndef _GRAPH_
#define _GRAPH_
#define _CITIES_TOTLAL_AMOUNT_ 20
#include<string>
using std::string;
typedef struct ArcCell
{
	int flight_number;
}ArcCell, AdjMatrix[_CITIES_TOTLAL_AMOUNT_][_CITIES_TOTLAL_AMOUNT_];

void InsertSqList();
typedef struct Graph
{
	string cities[_CITIES_TOTLAL_AMOUNT_+1];
	AdjMatrix  arcs;
	int vexnum,arcnum;

}Graph;
typedef struct Node
{
	int *datas;
	struct Node * next;
} Node;
typedef struct LinkList
{
	Node * head;
	int len;
} LinkList;
LinkList * get_all_paths(Graph *map,string start ,string end);
#endif






