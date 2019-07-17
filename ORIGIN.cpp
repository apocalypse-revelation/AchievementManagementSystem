#include <stdio.h>
#include <cstdlib> //exit()
#include <string.h>
#include<stdlib.h> //atoi() 

#define MAXNUM 50 //���ѧ����

static int now = 0;//�Ѿ������ѧ������ 
struct student
{
	char number[20];//ѧ��
	char name[10];  //����    
	int language;  //���ĳɼ�
	int math;		//��ѧ�ɼ�
	int english;	//Ӣ�ĳɼ�
	int	sum;    //�ܷ�
	double average; //ƽ����        
}s[MAXNUM]={"blank","blank",0,0,0,0,0};//blank�ж��ǲ��ǿ����� 

//�Զ��庯�� 
char menu();//�˵����� 
void append();//����ѧ����Ϣ���� 
void list();//�б��� 
void del();//ɾ��ѧ����Ϣ���� 
void modify();//�޸�ѧ����Ϣ���� 
void search();//����ѧ����Ϣ���� 
void descending_sum();//�����ֽܷ��� 
void ascending_sum();//�����ܷ����� 
void descending_number();//����ѧ�Ž��� 
void ascending_number();//����ѧ������ 
void write();//д���ļ� 
void read();//�����ļ� 
void average();//���䣺��ѯȫ��ѧ����ƽ���� 
void sum();//���䣺��ѯȫ��ѧ�����ܷ�
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
				printf("\n��������ȷ�����ֻ���ţ�������\n\n");
		}
	}
}
void sum()
{
	if(now == 0)
	{
		printf("һ��ѧ����Ϣ��û�У�");
		return; 
	}
	double sum = 0;
	for(int i = 0; i < now; i++)
		sum += s[i].english+s[i].language+s[i].math;
	printf("%d��ѧ�����ܷ�Ϊ: %.2lf\n",now,sum);
}
void average()
{
	if(now == 0)
	{
		printf("һ��ѧ����Ϣ��û�У�");
		return;
	}
	double sum = 0;
	for(int i = 0; i < now; i++)
		sum += s[i].english+s[i].language+s[i].math;
	printf("%d��ѧ����ƽ����Ϊ: %.2lf\n",now,sum/now);
	
}
char menu()
{
	char c;
	printf("\n                      ��ǰѧ������Ϊ��%d\n",now);
	printf("                    ********************\n                    *       �˵�       *\n                    ********************\n");
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
	getchar();//��������
	return c;
}

//���ѧ����Ϣ
void append()
{
	char a[20];
	int flag = 1;
	printf("                ******�����ѧ����Ϣ������������******\n");
	printf("***������ѧ��: ");	
	gets(a);
	//�����ظ�ѧ�� 
	for(int i = 0;i < now; i++)
		if(strcmp(s[i].number,a) == 0)
		{
			flag = 0;
			printf("���Ѿ����˸�ѧ�ţ��벻Ҫ�ظ����룡\n\n"); 
		}
	if(flag == 1)
	{
		strcpy(s[now].number,a);
		printf("***����������: ");
		scanf("%s",s[now].name);
		printf("***���������ĳɼ�: ");
		scanf("%d",&s[now].language);
		printf("***��������ѧ�ɼ�: ");
		scanf("%d",&s[now].math);
		printf("***������Ӣ��ɼ�: ");
		scanf("%d",&s[now].english);
		getchar();//��������
		//�ܷ�
		s[now].sum = s[now].language+s[now].math+s[now].english;
		printf("\n     ���ܷ�:%d  ",s[now].sum);
		//ƽ����
		s[now].average=1.0*s[now].sum/3;
		printf("ƽ����:%.2f \n\n",s[now].average);
		now++;
	}
		
	
}

void list()
{
	int total = now;
	if(total == 0)
		{
			printf("����ǰ������ļ���û�з����κ�һ��ѧ����Ϣ��\n\n");
		}
	else 
	{
		for(int i = 0; i < total; i++)
		{
		printf("\n��ѧ��-%s����ϸ��Ϣ����:\n",s[i].name);
		printf("��ѧ��:%s, ",s[i].number);
		printf("���ķ���:%d, ",s[i].language);
		printf("��ѧ����:%d,",s[i].math);
		printf("Ӣ�����:%d\n",s[i].english);
		printf("���ܷ�:%d, ƽ����:%.2f\n",s[i].sum,s[i].average);
		}
	}
}


void del()
{
	char a[20];
	int flag = 0, index;
	printf("����������ɾ����ѧ����ѧ��: ");
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
		printf("��ɾ���ɹ�\n");
	else if(flag == 0)
		printf("            ���Ҳ�����ѧ��:%s \n\n\n",a);
	
}

void modify()
{
	int flag = 0;
	char a[20];
	printf("������ѧ���޸�ѧ����Ϣ��\n");
	scanf("%s",a);
	getchar();
	for(int i = 0; i < now; i++)
		if(strcmp(s[i].number, a) == 0)
		{
			flag = 1;
			printf("***������ѧ��:");		
			scanf("%s",s[i].number);
			printf("***����������:");
			scanf("%s",s[i].name);
			printf("***���������ĳɼ�:");
			scanf("%d",&s[i].language);
			printf("***��������ѧ�ɼ�:");
			scanf("%d",&s[i].math);
			printf("***������Ӣ��ɼ�:");
			scanf("%d",&s[i].english);
				getchar();//��������
			//�ܷ�
			s[i].sum = s[i].language+s[i].math+s[i].english;
			//ƽ����
			s[i].average=s[i].sum/3;
		}
	if(flag == 0)
		printf("���Ҳ�����ѧ�ţ�\n");
	else if(flag == 1)
		printf("���޸ĳɹ���\n");
	
}


void search()
{
	int i, flag = 0;
	char a[20];
	printf("������ѧ�Ų�ѯѧ����Ϣ��\n");
	gets(a);
	for(i=0;i < now; i++)
		if(strcmp(s[i].number,a)==0)
		{
			flag = 1;
			printf("��ѧ��-%s����ϸ��Ϣ����:\n",s[i].name);
			printf("ѧ��:%s, ",s[i].number);
			printf("���ķ���:%d, ",s[i].language);
			printf("��ѧ����:%d,",s[i].math);
			printf("Ӣ�����:%d\n",s[i].english);
			printf("���ܷ�:%d, ƽ����:%.2f\n",s[i].sum,s[i].average);	
		}
	if(flag == 0)
		printf("��û���ҵ���ѧ�ţ�\n\n");
}


void descending_sum()
{
	int i,j;
	struct student temp;
	// ð������  
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
	// ð������  
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
	// ð������  
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
	// ð������  
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
//	�½�һ���������ļ����Ѵ��ڵ��ļ�����ɾ����ֻ����д
	if(now == 0)
	{
		printf("��һ��ѧ����Ϣ��û�У�û��write\n");
		return;
	}
	stream = fopen("info.FIL","wb");
	fwrite(&total, sizeof(int), 1, stream);
	
	for(int i = 0; i < now; i++)
	{
		fwrite(&s[i], sizeof(struct student), 1, stream);
		printf("�����%d:�ɹ�д���ļ���\n",i+1);
	}
	fclose(stream);
}
void read()
{
//	��һ���������ļ����ļ�������ڣ�ֻ�����
	FILE *stream;
	int n,total,i = 0;
	printf("����ʼ���Զ�ȡ.......\n \n");
	if((stream = fopen("info.FIL","rb")) == NULL)
	{
		printf("���ļ��գ�\n");
		exit(0);
	}
	fread(&total, sizeof(int), 1, stream);
	while(fread(&s[i++], sizeof(struct student), 1, stream) == 1)
		printf("���ɹ����ļ�������\n");
	now = total;
	fclose(stream);
}


