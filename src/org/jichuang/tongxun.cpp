#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct man
{
	char name[50];
	char phone[15];
	char qq[15];
	char dress[100];
}t[500];
int renshu;
int xuanze();
void shanchu();
void chazhao();
void tianjia();
void chakan();
void xiugai();
int duqu();
void baocun();
int main()
{
	int x;
	printf("\t\t\t**********ͨѶ¼**********\n");
	printf("\t\t\t*      1.�����ϵ��.     *\n");
	printf("\t\t\t*      2.�鿴��ϵ��.     *\n");
	printf("\t\t\t*      3.������ϵ��.     *\n");
	printf("\t\t\t*      4.�޸���ϵ��.     *\n");
	printf("\t\t\t*      5.ɾ����ϵ��.     *\n");
	printf("\t\t\t*      6.������ϵ��.     *\n");
	printf("\t\t\t*      7.��ȡ��ϵ��.     *\n");
	printf("\t\t\t*      8.�˳�.           *\n");
	printf("\t\t\t**************************\n");
	do
	{
	    printf("����������ѡ��(1-8):\n");
	    x=xuanze();
	    while(x<1||x>8)
		{
			printf("�������,����������:\n");
	        x=xuanze();
		}
		switch(x)
		{
		case 1:tianjia();break;
		case 2:chakan();break;
		case 3:chazhao();break;
		case 4:xiugai();break;
		case 5:shanchu();break;
		case 6:baocun();break;
		case 7:renshu=duqu();break;
		case 8:printf("\t\t\t\tллʹ��\n");exit(0);break;
		}
		system("cls");
		main();
	}while(x!=8);
	return 0;
}



int xuanze()
{
    int n;
	scanf("%d",&n);
	return n;
}


void tianjia()
{
	int i,n;
	system("cls");
    printf("������Ҫ������ϵ�˵ĸ���:");
	scanf("%d",&n);	
	printf("!!!!!������δ֪��Ϣ��дΪ���ޣ�wu����,���������ļ�����!!!!!");
	for(i=renshu;i<renshu+n;i++)
	{
		printf("\n");
		if(i==renshu)
			getchar();
		printf("�������%d����ϵ����Ϣ:\n",i+1-renshu);
		printf("��������ϵ������:");
        gets(t[i].name);
	    printf("��������ϵ�˵绰:");
    	gets(t[i].phone);
        printf("��������ϵ��QQ����:");
        gets(t[i].qq);
        printf("��������ϵ�˼�ͥ��ַ:");
        gets(t[i].dress);
	}
	system("pause");
	renshu=renshu+n;
}

void chakan()
{
	int i;
	system("cls");
	printf("������%d����ϵ��:\n",renshu);
	if(renshu!=0)
		for(i=0;i<renshu;i++)
		{
			printf("��%d����ϵ��:\n\t\t����:%s\n\t\t�绰:%s\n\t\tQQ:%s\n\t\t��ͥ��ַ:%s\n",i+1,t[i].name,t[i].phone,t[i].qq,t[i].dress);
	        printf("\n");
		}
	else
		printf("����ͨѶ¼��û����ϵ��!\n");
	system("pause");
}

void shanchu()
{
	system("cls");
	if(renshu!=0)
	{
		printf("������Ҫɾ������ϵ������:");
	    int h,j,i,m;
	    getchar();
        gets(t[renshu].name);
	    for(i=0;i<renshu;i++)
		{
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("�ҵ���ϵ��:\n");
			    printf("\t��%d����ϵ��:\n\t\t����:%s\n\t\t�绰:%s\n\t\tQQ:%s\n\t\t��ͥ��ַ:%s\n",i+1,t[i].name,t[i].phone,t[i].qq,t[i].dress);
                printf("�Ƿ�ɾ������ϵ��:\n\t\t1.ɾ��\t\t2.��ɾ��\n��ѡ��:");
			    scanf("%d",&h);
			    while(h!=1&&h!=2)
				{
					printf("�������,����������!");
				    scanf("%d",&h);
				};
			    if(h==1)
				{
			        for(j=i;j<renshu;j++)
				    t[j]=t[j+1];
			        renshu=renshu-1;
				    printf("��ϵ����ɾ��\n");
				    printf("����ɾ��?\n\t\t1.��\t\t2.��\n��ѡ��:");
				    scanf("%d",&m);
			        while(m!=1&&m!=2)
					{
						printf("�������,����������!");
				        scanf("%d",&m);
					};
			        if(m==1)
						shanchu();
				}
			    break;
			}
		    if(i==(renshu-1)&&strcmp(t[renshu].name,t[i].name)!=0)
			{
				printf("û���ҵ���ϵ��!\n");
			    printf("1.����������ϵ������.\n2.�ص����˵�\n��ѡ��:");
			    scanf("%d",&m);
			    while(m!=1&&m!=2)
				{
					printf("�������,����������!");
				    scanf("%d",&m);
				};
			    if(m==1)
					shanchu();
				system("pause");
			}
		}
	}
	else
	{
		printf("����ͨѶ¼��û����ϵ��!\n");
        system("pause");
	}
}

void chazhao()
{
	system("cls");
	if(renshu!=0)
	{
		printf("������Ҫ���ҵ���ϵ������:");
	    int i,m;
	    getchar();
        gets(t[renshu].name);
	    for(i=0;i<renshu;i++)
		{
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("�ҵ���ϵ��:\n");
			    printf("\t��%d����ϵ��:\n\t\t����:%s\n\t\t�绰:%s\n\t\tQQ:%s\n\t\t��ͥ��ַ:%s\n",i+1,t[i].name,t[i].phone,t[i].qq,t[i].dress);
                break;			
			}
            if(i==(renshu-1)&&strcmp(t[renshu].name,t[i].name)!=0)
			{
				printf("û���ҵ���ϵ��!\n");
			    printf("1.����������ϵ������.\n2.�ص����˵�\n��ѡ��:");
			    scanf("%d",&m);
			    while(m!=1&&m!=2)
				{
					printf("�������,����������!");
				    scanf("%d",&m);
				};
			    if(m==1)
					chazhao();
			}
		}
	}
	else
		printf("����ͨѶ¼��û����ϵ��!\n");
	system("pause");
}


void xiugai()
{
	system("cls");
	if(renshu!=0)
	{
		printf("������Ҫ�޸ĵ���ϵ������:");
	    int j,i,m;
	    getchar();
        gets(t[renshu].name);
	    for(i=0;i<renshu;i++)
		{
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("�ҵ���ϵ��:\n");
			    printf("\t��%d����ϵ��:\n\t\t����:%s\n\t\t�绰:%s\n\t\tQQ:%s\n\t\t��ͥ��ַ:%s\n",i+1,t[i].name,t[i].phone,t[i].qq,t[i].dress);
                j=i;
				break;			
			}
            if(i==(renshu-1)&&strcmp(t[renshu].name,t[i].name)!=0)
			{
				printf("û���ҵ���ϵ��!\n");
			    printf("1.����������ϵ������.\n2.�ص����˵�\n��ѡ��:");
			    scanf("%d",&m);
			    while(m!=1&&m!=2)
				{
					printf("�������,����������!");
				    scanf("%d",&m);
				};
			    if(m==1)
					chazhao();
			}
		}
		int k;
	printf("��ѡ��Ҫ�޸ĵ���Ϣ:\n\t1.����\t2.�绰\t3.QQ\t4.��ͥ��ַ\n��ѡ��:");
	scanf("%d",&k);
	while(k<1||k>4)
	{
		printf("�������,����������!");
		scanf("%d",&k);
	}
	printf("�������µ���Ϣ:");
	switch(k)
	{
	case 1:getchar();gets(t[j].name);break;
	case 2:getchar();gets(t[j].phone);break;
	case 3:getchar();gets(t[j].qq);break;
	case 4:getchar();gets(t[j].dress);break;
	}
	printf("�޸ĳɹ�!\n");
	}
	else
		printf("����ͨѶ¼��û����ϵ��!\n");
	system("pause");
}

int duqu()
{
	FILE *tx=NULL;
	int i=0,renshu=0;
	if((tx=fopen("tongxun.txt","r+"))==NULL)
	{
		printf("���ܴ��ļ�:tongxun.txt\n");
		system("pause");
		exit(0);
	}
	fscanf(tx,"%d",&renshu);
	printf("\n\t\t\t******��ʼ��ȡ�ļ�******\n");
	for(i=0;i<renshu;i++)
		fscanf(tx,"%s\n%s\n%s\n%s\n",t[i].name,t[i].phone,t[i].qq,t[i].dress);
    fclose(tx);
	printf("\t\t\t********��ȡ�ɹ�********\n");
	system("pause");
	return renshu;
}


void baocun()
{
	FILE *tx;
	int i;
    tx=fopen("tongxun.txt","w");
	printf("\t\t\t******��ʼ�����ļ�******\n");
	fprintf(tx,"%d",renshu);
	fprintf(tx,"\r\n");
	for(i=0;i<renshu;i++)
	{
		fprintf(tx,"%s\n%s\n%s\n%s\n",t[i].name,t[i].phone,t[i].qq,t[i].dress);
        fprintf(tx,"\r\n");
	}
	fclose(tx);
	printf("\t\t\t********����ɹ�********\n");
	system("pause");


}
