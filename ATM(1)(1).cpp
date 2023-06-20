#include"stdio.h"
#include"stdlib.h"
#include"windows.h"
struct bank{
	char number[20];
	char key[10];
	int  balance;
};
    char ID[20];
	//�������� 
	int landing(void);
    char menu(void);
    int balance(void);
    int withdrawal(void);
    int add(void);
    int transfer_accountd(void);
    int change_password(void);
    int quit(void);

int main()
{
	int sign,command;
	char ch[6]; 
	char choose;
	sign = landing();//��½  ������ú�����ʵ��Ϊvoid��ô�Ͳ���Ҫ�� 
	if(sign == 1)
	choose = menu();
	else
	exit(0);
	while(1)
	{
		switch(choose)
	   {
		case '1': ch[0]=balance();
		if(ch[0]==0)
		 exit(0);
		else break;
		case '2': ch[1]=withdrawal();
		if(ch[1]==0)
		 exit(0);
		else break;
		case '3': ch[2]=add();
		if(ch[2]==0)
		 exit(0);
		else break;
		case '4': ch[3]=transfer_accountd();
		if(ch[3]==0)
		 exit(0);
		else break;
		case '5': ch[4]=change_password();
		if(ch[4]==0)
		 exit(0);
		else break;
		case '6': exit(0);break;
    	}
    	choose = menu();
	}

	 
}
int landing(void) 
{
	FILE *fp;
	struct bank zh[5];
	char c[20],d[10];
	int i,j,s;
	fp=fopen("accounts.txt","r");
	if(fp==NULL)
	{
		printf("open file!");
		exit(0);
	}
	for(i=0;i<5;i++)
	{
		fscanf(fp,"%s%s%d",zh[i].number ,zh[i].key ,&zh[i].balance );
	}
	for(i=0;i<3;i++)
	{
		printf("�������˻������룺\n");
		scanf("%s%s",&c[0],&d[0]);
		for(j=0;j<5;j++)
		{
			if(strcmp(c,zh[j].number )==0)
			if(strcmp(d,zh[j].key )==0)
			{
			printf("��¼�ɹ���");
			strcpy(ID,c);
			fclose(fp);
			return 1;
			}
		}
		printf("�㻹ʣ%d�λ��ᣡ\n",2-i);
	}
	if(i==3)
	printf("����������࣬�����˻��ѱ������\n��ǰ����̨����\n");
	fclose(fp);
	return 0;
}
char menu(void)
{
	system("cls");
	printf("**********************\n");
	printf("1.����ѯ  2.ȡ��ҵ��\n");
	printf("3.���ҵ��  4.ת��ҵ��\n");
	printf("5.�޸�����  6.�˳�ATM \n");
	printf("**********************\n");
	printf("��������Ҫ�����ҵ��:");
	char ch[100];
	while(1)
	{
		scanf("%s",ch);
		if(ch[0]<'1'&&ch[0]>'6'||ch[1]!='\0')
		printf("���������룺\n");
		else
		break;
	}
	system("cls");
	return ch[0];
	
}
////////����ѯ//////////////////////////////////// 
int balance(void)
{
    printf("���Ե�,������ת��\n");
    FILE *fp;
	struct bank zh[5];
	char c[20],d[10];
	int i,j,s,k=0;
	char ch[20];
	fp=fopen("accounts.txt","r");
	if(fp==NULL)
	{
		printf("open file!");
		exit(0);
	}
	for(i=0;i<5;i++)
	{
		fscanf(fp,"%s%s%d",zh[i].number ,zh[i].key ,&zh[i].balance );
	} 
	printf("�������˺ţ�\n");
	while(1)
	{
		scanf("%s",ch);
		for(i=0;i<5;i++)
		if(strcmp(zh[i].number,ch)==0)
		{
			printf("���ҳɹ�,���Ϊ��%d",zh[i].balance );
			k=100;
			break; 
		}
		k++;
		if(k==3)
		{
		printf("�˻��������󣬼������ز˵���");
		fclose(fp);
		return 1;
	    }
	    if(k==101)
	    {
	    	printf("\n�Ƿ���� ��_1 ��_0:");
		    scanf("%d",&k);
		    fclose(fp);
		    return k;
		}
	    
	}
} 
//////////////ȡ��ҵ��///////////////////////////////
int withdrawal(void)
{
	printf("���Ե�,������ת��\n");
	FILE *fp;
	struct bank zh[5];
	char c[20],d[10];
	int i,j,s,k=0,money;
	char ch[20];
	fp=fopen("accounts.txt","r");
	if(fp==NULL)
	{
		printf("open file!");
		exit(0);
	}
	for(i=0;i<5;i++)
	{
		fscanf(fp,"%s%s%d",zh[i].number ,zh[i].key ,&zh[i].balance );
	} 
	printf("�������˺ţ�\n");
	while(1)
	{
		scanf("%s",ch);
		for(i=0;i<5;i++)
		if(strcmp(zh[i].number,ch)==0)
		{
			for(int t=0;t<3;t++)
			{
			printf("������ȡ����:" );
			zh[i].balance =zh[i].balance-money;
			if(zh[i].balance <0)
			{
				printf("���㣬����������ȡ���");
				zh[i].balance =zh[i].balance+money;
				continue;
			} 
			break; 
			}
		}
		k++;
		if(k==3)
		{
		printf("�˻��������󣬼������ز˵���");
		fclose(fp);
		return 1;
	    }
	    	fp=fopen("accounts.txt","w");
		for(i=0;i<5;i++)
		{
			fprintf(fp,"%s %s %d\n",zh[i].number ,zh[i].key ,zh[i].balance );
		}
		fclose(fp);
		system("cls");
	    if(k==100)
	    {
	    	printf("�Ƿ���� ��_1 ��_0:");
		    scanf("%d",&k);
		    fclose(fp);
		    return k;
		}
	    
	}
	
} 
////////////////���ҵ��/////////////
int add(void)
{	printf("���Ե�,������ת��\n");
    FILE *fp;
	struct bank zh[5];
	char c[20],d[10];
	int i,j,s;
	fp=fopen("accounts.txt","r");
	if(fp==NULL)
	{
		printf("open file!");
		exit(0);
	}
	for(i=0;i<5;i++)
	{
		fscanf(fp,"%s%s%d",zh[i].number ,zh[i].key ,&zh[i].balance );
	}
	fclose(fp);
	printf("���������");
	scanf("%d",&s);
	for(j=0;j<5;j++)
	{
		if(strcmp(ID,zh[j].number )==0)
	    i=j;
	}
	zh[i].balance+=s;
	fp=fopen("accounts.txt","w");
	for(i=0;i<5;i++)
	{
		fprintf(fp,"%s %s %d\n",zh[i].number ,zh[i].key ,zh[i].balance );
	}
	fclose(fp);
	system("cls");
	printf("�Ƿ���� ��_1 ��_0\n");
	scanf("%d",s);
	return s;
} 
/////////////ת��ҵ��/////////////// 
int transfer_accountd(void)
{
	printf("���Ե�,������ת��\n");
	FILE *fp;
	struct bank zh[5];
	char c[20],d[10];
	int i,j,s=0,k=0;
	char ch[20];
	fp=fopen("accounts.txt","r");
	if(fp==NULL)
	{
		printf("open file!");
		exit(0);
	}
	for(i=0;i<5;i++)
	{
		fscanf(fp,"%s%s%d",zh[i].number ,zh[i].key ,&zh[i].balance );
	} 
	fclose(fp);
	i=0;
	printf("�������˺ţ�\n");
	scanf("%s",c);
	for(j=0;j<5;j++)
	{
		if(strcmp(ID,zh[j].number )==0)
	    i=j;
	}
	for(j=0;j<5;j++)
	{
		if(strcmp(c,zh[j].number )==0)
		{
			printf("�����ת�˽�");
			scanf("%d",&s);
			if(s>zh[i].balance )
			{
				printf("���㣡\n");
				break;
			}
			else
			zh[j].balance =zh[j].balance +s;
		}
	}

	if(j==5)
	{
		zh[i].balance =zh[i].balance -s;
	}
		fp=fopen("accounts.txt","w");
	for(i=0;i<5;i++)
	{
		fprintf(fp,"%s %s %d\n",zh[i].number ,zh[i].key ,zh[i].balance );
	}
	fclose(fp);
	system("cls");
	printf("�Ƿ���� ��_1 ��_0\n");
	scanf("%d",s);
	return s;
} 
int change_password(void)
{printf("���Ե�,������ת��");;} 


