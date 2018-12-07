// TicketingSystem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"defines.h"
#include <stdlib.h>
int _tmain(int argc, _TCHAR* argv[])
{
	STU * student=new STU;
	STU * sec=new STU;
	if(student)
	{
		student->age=19;
		student->name="XIEAN";
		student->job="ENGINEER";
		sec->age=18;
		sec->name="hh";
		sec->job="ll";
		wirte_info(student,1);
		wirte_info(sec,1);
	}
	load_data();
	return 0;
}

