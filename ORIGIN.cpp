#include <stdio.h>
#include <cstdlib> //exit()
#include <string.h>
#include<stdlib.h> //atoi() 

#define MAXNUM 50 //最大学生数

static int now = 0;//已经加入的学生人数 
struct student
{
	char number[20];//学号
	char name[10];  //姓名    
	int language;  //语文成绩
	int math;		//数学成绩
	int english;	//英文成绩
	int	sum;    //总分
	double average; //平均分        
}s[MAXNUM]={"blank","blank",0,0,0,0,0};//blank判断是不是空数组 

//自定义函数 
char menu();//菜单方法 
void append();//增加学生信息方法 
void list();//列表方法 
void del();//删除学生信息方法 
void modify();//修改学生信息方法 
void search();//搜索学生信息方法 
void descending_sum();//根据总分降序 
void ascending_sum();//根据总分升序 
void descending_number();//根据学号降序 
void ascending_number();//根据学号升序 
void write();//写入文件 
void read();//读入文件 
void average();//扩充：查询全部学生的平均分 
void sum();//扩充：查询全部学生的总分
main()
{
	char c;
	while(1)
	{
		
		c = menu();
		switch(c)
		{
			case'1':
				append();
				break;
			case'2':
				list();
				break;
			case'3':
				del();
				break;
			case'4':
				modify();
				break;
			case'5':
				search();
				break;
			case'6':
				descending_sum();
				break;
			case'7':
				ascending_sum();
				break;
			case'8':
				descending_number();
				break;
			case'9':
				ascending_number();
				break;
			case'A':
				average();
				break;
			case'S':
				sum();
				break;
			case'W':
				write();
				break;
			case'R':
				read();
				break;
			case'0':
				return 0;
			default:
				printf("\n请输入正确的数字或符号！！！！\n\n");
		}
	}
}
void sum()
{
	if(now == 0)
	{
		printf("一个学生信息都没有！");
		return; 
	}
	double sum = 0;
	for(int i = 0; i < now; i++)
		sum += s[i].english+s[i].language+s[i].math;
	printf("%d个学生的总分为: %.2lf\n",now,sum);
}
void average()
{
	if(now == 0)
	{
		printf("一个学生信息都没有！");
		return;
	}
	double sum = 0;
	for(int i = 0; i < now; i++)
		sum += s[i].english+s[i].language+s[i].math;
	printf("%d个学生的平均分为: %.2lf\n",now,sum/now);
	
}
char menu()
{
	char c;
	printf("\n                      当前学生数量为：%d\n",now);
	printf("                    ********************\n                    *       菜单       *\n                    ********************\n");
	printf("             Management for Students' scores\n");
	printf("                    1.Append record\n");
	printf("                    2.List record\n");
	printf("                    3.Delete record\n");
	printf("                    4.Modify record\n");
	printf("                    5.Search record\n");
	printf("                    6.Sort in descending order by sum\n");
	printf("                    7.Sort in ascending order by sum\n");
	printf("                    8.Sort in descending order by num\n");
	printf("                    9.Sort in ascending order by num\n");
	printf("                    S.Sum of Point of all student\n");
	printf("                    A.Average of Point of all student\n");
	printf("                    W.Write to a File\n");
	printf("                    R.Read from a File\n");
	printf("                    0.Exit\n");
	printf("    Please input your choice:\n");
	c = getchar();
	getchar();//吸缓冲区
	return c;
}

//添加学生信息
void append()
{
	char a[20];
	int flag = 1;
	printf("                ******【添加学生信息】请输入数据******\n");
	printf("***请输入学号: ");	
	gets(a);
	//检验重复学号 
	for(int i = 0;i < now; i++)
		if(strcmp(s[i].number,a) == 0)
		{
			flag = 0;
			printf("→已经有了该学号，请不要重复输入！\n\n"); 
		}
	if(flag == 1)
	{
		strcpy(s[now].number,a);
		printf("***请输入姓名: ");
		scanf("%s",s[now].name);
		printf("***请输入语文成绩: ");
		scanf("%d",&s[now].language);
		printf("***请输入数学成绩: ");
		scanf("%d",&s[now].math);
		printf("***请输入英语成绩: ");
		scanf("%d",&s[now].english);
		getchar();//吸缓冲区
		//总分
		s[now].sum = s[now].language+s[now].math+s[now].english;
		printf("\n     →总分:%d  ",s[now].sum);
		//平均分
		s[now].average=1.0*s[now].sum/3;
		printf("平均分:%.2f \n\n",s[now].average);
		now++;
	}
		
	
}

void list()
{
	int total = now;
	if(total == 0)
		{
			printf("→当前程序或文件中没有发现任何一项学生信息！\n\n");
		}
	else 
	{
		for(int i = 0; i < total; i++)
		{
		printf("\n→学生-%s的详细信息如下:\n",s[i].name);
		printf("→学号:%s, ",s[i].number);
		printf("语文分数:%d, ",s[i].language);
		printf("数学分数:%d,",s[i].math);
		printf("英语分数:%d\n",s[i].english);
		printf("→总分:%d, 平均分:%.2f\n",s[i].sum,s[i].average);
		}
	}
}


void del()
{
	char a[20];
	int flag = 0, index;
	printf("请输入你想删除的学生的学号: ");
	gets(a);	
	for(int i = 0;i < now; i++)
		if(strcmp(s[i].number,a) == 0)
		{
			index = i;
			flag = 1;
			now--;
			break;
		}
	if(flag == 1)
		for(int j = index; flag == 1, j < now; j++)
			s[j] = s[j+1];
	if(flag == 1)
		printf("→删除成功\n");
	else if(flag == 0)
		printf("            →找不到该学号:%s \n\n\n",a);
	
}

void modify()
{
	int flag = 0;
	char a[20];
	printf("请输入学号修改学生信息：\n");
	scanf("%s",a);
	getchar();
	for(int i = 0; i < now; i++)
		if(strcmp(s[i].number, a) == 0)
		{
			flag = 1;
			printf("***请输入学号:");		
			scanf("%s",s[i].number);
			printf("***请输入姓名:");
			scanf("%s",s[i].name);
			printf("***请输入语文成绩:");
			scanf("%d",&s[i].language);
			printf("***请输入数学成绩:");
			scanf("%d",&s[i].math);
			printf("***请输入英语成绩:");
			scanf("%d",&s[i].english);
				getchar();//吸缓冲区
			//总分
			s[i].sum = s[i].language+s[i].math+s[i].english;
			//平均分
			s[i].average=s[i].sum/3;
		}
	if(flag == 0)
		printf("→找不到该学号！\n");
	else if(flag == 1)
		printf("→修改成功！\n");
	
}


void search()
{
	int i, flag = 0;
	char a[20];
	printf("请输入学号查询学生信息：\n");
	gets(a);
	for(i=0;i < now; i++)
		if(strcmp(s[i].number,a)==0)
		{
			flag = 1;
			printf("→学生-%s的详细信息如下:\n",s[i].name);
			printf("学号:%s, ",s[i].number);
			printf("语文分数:%d, ",s[i].language);
			printf("数学分数:%d,",s[i].math);
			printf("英语分数:%d\n",s[i].english);
			printf("→总分:%d, 平均分:%.2f\n",s[i].sum,s[i].average);	
		}
	if(flag == 0)
		printf("→没有找到该学号！\n\n");
}


void descending_sum()
{
	int i,j;
	struct student temp;
	// 冒泡排序  
	for(i = 1; i < now; i++)
		for(j = 0;j< now-i;j++)
			if(s[j].sum < s[j+1].sum)
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			} 
	list();
}

void ascending_sum()
{
	int i,j;
	struct student temp;
	// 冒泡排序  
	for(i = 1; i < now; i++)
		for(j = 0;j< now-i;j++)
			if(s[j].sum > s[j+1].sum)
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			} 
	list();
}

void descending_number()
{
	int i,j;
	struct student temp;
	// 冒泡排序  
	for(i = 1; i < now; i++)
		for(j = 0; j< now-i; j++)
			if(atoi(s[j].number) < atoi(s[j+1].number))
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			} 
	list();
}
void ascending_number()
{
	int i,j;
	struct student temp;
	// 冒泡排序  
	for(i = 1; i < now; i++)
		for(j = 0;j< now-i;j++)
			if(atoi(s[j].number) > atoi(s[j+1].number))
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			} 
	list();
}

void write()
{
	FILE *stream;
	int total = now;
//	新建一个二进制文件，已存在的文件将被删除，只允许写
	if(now == 0)
	{
		printf("→一个学生信息都没有，没法write\n");
		return;
	}
	stream = fopen("info.FIL","wb");
	fwrite(&total, sizeof(int), 1, stream);
	
	for(int i = 0; i < now; i++)
	{
		fwrite(&s[i], sizeof(struct student), 1, stream);
		printf("→序号%d:成功写入文件！\n",i+1);
	}
	fclose(stream);
}
void read()
{
//	打开一个二进制文件，文件必须存在，只允许读
	FILE *stream;
	int n,total,i = 0;
	printf("→开始尝试读取.......\n \n");
	if((stream = fopen("info.FIL","rb")) == NULL)
	{
		printf("→文件空！\n");
		exit(0);
	}
	fread(&total, sizeof(int), 1, stream);
	while(fread(&s[i++], sizeof(struct student), 1, stream) == 1)
		printf("→成功从文件读出！\n");
	now = total;
	fclose(stream);
}


