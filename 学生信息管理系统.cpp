#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu
{
	char name[50];
	char ruxue[20];
	char banji[20];
	char phone[20];
	char dress[100];
}t[500];
int renshu;
int xuanze();
void shanchu();
void chazhao();
void tianjia();
void chakan();
void xiugai();
void tongji();
void paixu();
int duqu();
void baocun();
int main()
{
	int x;
	printf("\t\t\t********ѧ����Ϣ����********\n");
	printf("\t\t\t*      1.���ѧ����Ϣ.     *\n");
	printf("\t\t\t*      2.�鿴ѧ����Ϣ.     *\n");
	printf("\t\t\t*      3.����ѧ����Ϣ.     *\n");
	printf("\t\t\t*      4.�޸�ѧ����Ϣ.     *\n");
	printf("\t\t\t*      5.ɾ��ѧ����Ϣ.     *\n");
	printf("\t\t\t*      6.ͳ��ѧ����Ϣ.     *\n");
	printf("\t\t\t*      7.����ѧ����Ϣ.     *\n");
	printf("\t\t\t*      8.����ѧ����Ϣ.     *\n");
	printf("\t\t\t*      9.��ȡѧ����Ϣ.     *\n");
	printf("\t\t\t*      10.�˳�.             *\n");
	printf("\t\t\t****************************\n");                //�˵�
	do
	{
	    printf("����������ѡ��(1-10):\n");
	    x=xuanze();
	    while(x<1||x>10)
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
        case 6:tongji();break;
		case 7:paixu();break;
		case 8:baocun();break;
		case 9:renshu=duqu();break;
		case 10:printf("\t\t\t\tллʹ��\n");exit(0);break;
		}
		system("cls");
		main();
	}while(x!=10);
	return 0;
}



int xuanze()
{
    int n;
	scanf("%d",&n);
	return n;
}


void tianjia()                                    //���ѧ��
{
	int i,n;
	system("cls");
    printf("������Ҫ���ѧ����Ϣ�ĸ���:");
	scanf("%d",&n);	
	printf("!!!!!������δ֪��Ϣ��дΪ���ޣ�wu����,���������ļ�����!!!!!");
	for(i=renshu;i<renshu+n;i++)
	{
		printf("\n");
		if(i==renshu)
			getchar();
		printf("�������%d��ѧ����Ϣ:\n",i+1-renshu);
		printf("������ѧ������:");
        gets(t[i].name);
	    printf("������ѧ����ѧʱ��:");
    	gets(t[i].ruxue);
        printf("������ѧ���༶:");
        gets(t[i].banji);
		printf("������ѧ���绰:");
        gets(t[i].phone);
		printf("������ѧ����ͥ��ַ:");
        gets(t[i].dress);
	}
	system("pause");
	renshu=renshu+n;
}

void chakan()                            //�鿴����ѧ��
{
	int i;
	system("cls");
	printf("����%d��ѧ��:\n",renshu);
	if(renshu!=0)
		for(i=0;i<renshu;i++)
		{
			printf("��%d��ѧ��:\n\t\t����:%s\n\t\t��ѧʱ��:%s\n\t\t�༶:%s\n\t\t�绰:%s\n\t\t��ͥ��ַ:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);
	        printf("\n");
		}
	else
		printf("��ѧ����Ϣ!\n");
	system("pause");
}

void shanchu()                           //ɾ��ѧ����Ϣ
{
	system("cls");
	if(renshu!=0)
	{
		printf("������Ҫɾ����ѧ������:");
	    int h,j,i,m;
	    getchar();
        gets(t[renshu].name);
	    for(i=0;i<renshu;i++)
		{
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("�ҵ�ѧ��:\n");
			    printf("\t��%d��ѧ��:\n\t\t����:%s\n\t\t��ѧʱ��:%s\n\t\t�༶:%s\n\t\t�绰:%s\n\t\t��ͥ��ַ:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);
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
				    printf("ѧ����Ϣ��ɾ��\n");
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
				printf("û���ҵ�ѧ��!\n");
			    printf("1.��������ѧ������.\n2.�ص����˵�\n��ѡ��:");
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
		printf("��ѧ����Ϣ!\n");
        system("pause");
	}
}

void chazhao()                             //����ѧ��
{
	system("cls");
	int v,h=0;
	if(renshu!=0)
	{
		printf("\t1.����������.\t\t2.����ѧʱ�����\n��ѡ��:");
		scanf("%d",&v);
	    while(v!=1&&v!=2)
		{
			printf("�������,����������!");
		    scanf("%d",&v);
		};
	    if(v==1)
		{
		  printf("������Ҫ���ҵ�ѧ������:");
	      int i,m;
	      getchar();
          gets(t[renshu].name);
	      for(i=0;i<renshu;i++)
		  {
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("�ҵ�ѧ��:\n");
			    printf("\t��%d��ѧ��:\n\t\t����:%s\n\t\t��ѧʱ��:%s\n\t\t�༶:%s\n\t\t�绰:%s\n\t\t��ͥ��ַ:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);			
			    h=1;
			}
            if(i==(renshu-1)&&h==0)
			{
				printf("û���ҵ�ѧ��!\n");
			    printf("1.���²���.\n2.�ص����˵�\n��ѡ��:");
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
		if(v==2)
		{
		  printf("������Ҫ���ҵ�ѧ����ѧʱ��:");
	      int i,m;
	      getchar();
          gets(t[renshu].ruxue);
	      for(i=0;i<renshu;i++)
		  {
			if(strcmp(t[renshu].ruxue,t[i].ruxue)==0)
			{
				printf("�ҵ�ѧ��:\n");
			    printf("\t��%d��ѧ��:\n\t\t����:%s\n\t\t��ѧʱ��:%s\n\t\t�༶:%s\n\t\t�绰:%s\n\t\t��ͥ��ַ:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);			
			    h=1;
			}
            if(i==(renshu-1)&&h==0)
			{
				printf("û���ҵ�ѧ��!\n");
			    printf("1.���²���.\n2.�ص����˵�\n��ѡ��:");
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
	}
	else
		printf("��ѧ����Ϣ!\n");
	system("pause");
}


void xiugai()                               //�޸�ѧ����Ϣ
{
	system("cls");
	if(renshu!=0)
	{
		printf("������Ҫ�޸ĵ�ѧ������:");
	    int j,i,m;
	    getchar();
        gets(t[renshu].name);
	    for(i=0;i<renshu;i++)
		{
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("�ҵ�ѧ��:\n");
			    printf("\t��%d��ѧ��:\n\t\t����:%s\n\t\t��ѧʱ��:%s\n\t\t�༶:%s\n\t\t�绰:%s\n\t\t��ͥ��ַ:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);
                j=i;
				break;			
			}
            if(i==(renshu-1)&&strcmp(t[renshu].name,t[i].name)!=0)
			{
				printf("û���ҵ�ѧ��!\n");
			    printf("1.���²���.\n2.�ص����˵�\n��ѡ��:");
			    scanf("%d",&m);
			    while(m!=1&&m!=2)
				{
					printf("�������,����������!");
				    scanf("%d",&m);
				};
			    if(m==1)
					xiugai();
			}
		}
		int k;
	printf("��ѡ��Ҫ�޸ĵ���Ϣ:\n\t1.����\t2.��ѧʱ��\t3.�༶\t4.�绰\t5.��ͥ��ַ\n��ѡ��:");
	scanf("%d",&k);
	while(k<1||k>5)
	{
		printf("�������,����������!");
		scanf("%d",&k);
	}
	printf("�������µ���Ϣ:");
	switch(k)
	{
	case 1:getchar();gets(t[j].name);break;
	case 2:getchar();gets(t[j].ruxue);break;
	case 3:getchar();gets(t[j].banji);break;
	case 4:getchar();gets(t[j].phone);break;
	case 5:getchar();gets(t[j].dress);break;
	}
	printf("�޸ĳɹ�!\n");
	}
	else
		printf("��ѧ����Ϣ!\n");
	system("pause");
}
void tongji()
{
	system("cls");
	printf("������ѧ����ѧʱ��:");
	int i,m,h=0;
	getchar();
    gets(t[renshu].ruxue);
	for(i=0;i<renshu;i++)
	{
	    if(strcmp(t[renshu].ruxue,t[i].ruxue)==0)
		{
		    printf("\t��%d��ѧ��:\n\t\t����:%s\n\t\t��ѧʱ��:%s\n\t\t�༶:%s\n\t\t�绰:%s\n\t\t��ͥ��ַ:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);			
			h=1;
		}
        if(i==(renshu-1)&&h==0)
		{
			printf("û���ҵ�ѧ��!\n");
			printf("1.���²���.\n2.�ص����˵�\n��ѡ��:");
			scanf("%d",&m);
			while(m!=1&&m!=2)
			{
		      	printf("�������,����������!");
				scanf("%d",&m);
			};
			if(m==1)
			tongji();
		}
	}
	system("pause");
}

void paixu()
{
    system("cls");
	int i,n,j;
	for(i=0;i<renshu;i++)
	{
	strcpy(t[renshu+1+i].name,t[i].name);
	strcpy(t[renshu+1+i].banji,t[i].banji);
	strcpy(t[renshu+1+i].ruxue,t[i].ruxue);
	strcpy(t[renshu+1+i].phone,t[i].phone);
	strcpy(t[renshu+1+i].dress,t[i].dress);
	}
	for(n=1;n<renshu+1;n++)
	{
		strcpy(t[renshu].name,t[renshu+n].name);
	    strcpy(t[renshu].banji,t[renshu+n].banji);
        strcpy(t[renshu].ruxue,t[renshu+n].ruxue);
	    strcpy(t[renshu].phone,t[renshu+n].phone);
        strcpy(t[renshu].dress,t[renshu+n].dress);
	    for(i=renshu+n;i<renshu*2+1;i++)
		{
	
		    if(strcmp(t[i].banji,t[renshu].banji)<0||(strcmp(t[i].banji,t[renshu].banji)==0&&strcmp(t[i].name,t[renshu].name)<0))
			{
			    strcpy(t[renshu].name,t[i].name);
           	    strcpy(t[renshu].banji,t[i].banji);
			    strcpy(t[renshu].ruxue,t[i].ruxue);
	            strcpy(t[renshu].phone,t[i].phone);
			    strcpy(t[renshu].dress,t[i].dress);
			    j=i;
			}
		}
		printf("\t�༶:%s\t����:%s\t��ѧʱ��:%s\t�绰:%s\t��ͥ��ַ:%s\n",t[renshu].banji,t[renshu].name,t[renshu].ruxue,t[renshu].phone,t[renshu].dress);
	    strcpy(t[j].name,t[renshu+n].name);
        strcpy(t[j].banji,t[renshu+n].banji);
	    strcpy(t[j].ruxue,t[renshu+n].ruxue);
	    strcpy(t[j].phone,t[renshu+n].phone);
        strcpy(t[j].dress,t[renshu+n].dress);
	}

	
	system("pause");
}

int duqu()
{
	FILE *x=NULL;
	int i=0,renshu=0;
	if((x=fopen("t.txt","r+"))==NULL)
	{
		printf("���ܴ��ļ�:t.txt\n");
		system("pause");
		exit(0);
	}
	fscanf(x,"%d",&renshu);
	printf("\n\t\t\t******��ʼ��ȡ�ļ�******\n");
	for(i=0;i<renshu;i++)
		fscanf(x,"%s\n%s\n%s\n%s\n%s\n",t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);
    fclose(x);
	printf("\t\t\t********��ȡ�ɹ�********\n");
	system("pause");
	return renshu;
}


void baocun()
{
	FILE *x;
	int i;
    x=fopen("t.txt","w");
	printf("\t\t\t******��ʼ�����ļ�******\n");
	fprintf(x,"%d",renshu);
	fprintf(x,"\r\n");
	for(i=0;i<renshu;i++)
	{
		fprintf(x,"%s\n%s\n%s\n%s\n%s\n",t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);
        fprintf(x,"\r\n");
	}
	fclose(x);
	printf("\t\t\t********����ɹ�********\n");
	system("pause");


}
