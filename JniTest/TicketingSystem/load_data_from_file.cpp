#include <stdio.h>
#include "stdafx.h"
#include"defines.h"

STATUS load_data()
{
	FILE *fp;
	STU stu;
	printf("加载信息准备");
	fp=fopen(_INFO_FILE_PATH_,"rb");
	if(fp==NULL)
	{
		printf("文件打开失败");
	    return ERROR;
	}
	while(1)
	{
		
		if(1==fread(&stu,sizeof(STU),1,fp))
		{
			printf("%d %s %s\n",stu.age,stu.name.c_str(),stu.job.c_str());
		}
		else
		{
			printf("结束");
			break;
		}
	}
	fclose(fp);
	return SUCCESS;
}

void wirte_info(const STU * stu,int len)
{
	FILE * fp;
	int i=0;
	fp=fopen(_INFO_FILE_PATH_,"rb+");
	if(!fp)
	{
		fp=fopen(_INFO_FILE_PATH_,"wb+");
	}
	fseek(fp,0,SEEK_END);
	while(i<len)
	{
		printf("写入%d\n",stu->age);
		fwrite(stu+i,sizeof(STU),1,fp);
	    i++;
	}
	fclose(fp);

}