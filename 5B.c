#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
char data[20];

}sheet[3][4];
typedef struct  data df;
void csv_bin(df a);
int main()
{
        FILE *fp = NULL;
    	char *line,*record;
    	char buffer[1024];
  	if ((fp = fopen("sheet.csv", "r")) != NULL)//判断文件能否正常打开
	{
		int i=0;
		while ((line=fgets(buffer,sizeof(buffer),fp))!=NULL)//当没有读取到文件末尾时循环继续
		{

			record = strtok(line, ",");
			strcpy(sheet[i][0].data, record);//将数据存入结构体数组中
			int j=1;
			while (record != NULL)//读取每一行的数据
			{
				if (j==4)
				{
					break;
				}
				record = strtok(NULL, ",");
				strcpy(sheet[i][j].data,record);
				j++;
				
			}
        printf("\n");
		i++;
		}
		fclose(fp);//如果文件为空，则关闭文件
		fp = NULL;
	}
	// for (int i = 0; i < 3; i++)
	// {
	// 	for (int j = 0; j < 4; j++)
	// 	{
	// 		printf("%s	",sheet[i][j].data);
	// 	}
	
	// }打印该数据组
	FILE *fpb;
	fpb=fopen("sheet","wb");
	fwrite(sheet[0][0].data,20,12,fpb);//将csv文件转化为二进制文件
	fclose(fpb);
	fpb=fopen("sheet","rb");
	df sheet_binary[3][4];
	
	fread(sheet_binary[0][0].data,20,12,fpb);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%s ",sheet_binary[i][j].data);//将二进制文件打印出来
		}
	}
	

	
}

        