#include <stdio.h>
#include "stdafx.h"
#include"defines.h"

STATUS load_data()
{
	FILE *fp;
	STU stu;
	fp=fopen(_INFO_FILE_PATH_,"rb");
	if(fp==NULL)
	{
		perror("文件打开失败");
	    return ERROR;
	}
	while(1==fread(&stu,sizeof(STU),1,fp))
	{
		printf("读出信息：%d,%s,%s",stu.age,stu.name,stu.job);
	}
	printf("以上为全部信息");
	fclose(fp);
	return SUCCESS;
}

void wirte_info(const STU * stu,int len)
{
	FILE * fp;
	printf("写入准备");
	int i=0;
	fp=fopen(_INFO_FILE_PATH_,"rb+");
	if(!fp)
	{
		fp=fopen(_INFO_FILE_PATH_,"wb+");
	}
	fseek(fp,0,SEEK_END);
	while(i<len)
	{
		fwrite(stu+i,sizeof(STU),1,fp);
	    i++;
	}
	fclose(fp);

}