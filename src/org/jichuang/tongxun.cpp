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
	printf("\t\t\t**********通讯录**********\n");
	printf("\t\t\t*      1.添加联系人.     *\n");
	printf("\t\t\t*      2.查看联系人.     *\n");
	printf("\t\t\t*      3.查找联系人.     *\n");
	printf("\t\t\t*      4.修改联系人.     *\n");
	printf("\t\t\t*      5.删除联系人.     *\n");
	printf("\t\t\t*      6.保存联系人.     *\n");
	printf("\t\t\t*      7.读取联系人.     *\n");
	printf("\t\t\t*      8.退出.           *\n");
	printf("\t\t\t**************************\n");
	do
	{
	    printf("请输入您的选择(1-8):\n");
	    x=xuanze();
	    while(x<1||x>8)
		{
			printf("输入错误,请重新输入:\n");
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
		case 8:printf("\t\t\t\t谢谢使用\n");exit(0);break;
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
    printf("请输入要加入联系人的个数:");
	scanf("%d",&n);	
	printf("!!!!!请您将未知信息填写为“无（wu）”,否则会造成文件混乱!!!!!");
	for(i=renshu;i<renshu+n;i++)
	{
		printf("\n");
		if(i==renshu)
			getchar();
		printf("请输入第%d名联系人信息:\n",i+1-renshu);
		printf("请输入联系人姓名:");
        gets(t[i].name);
	    printf("请输入联系人电话:");
    	gets(t[i].phone);
        printf("请输入联系人QQ号码:");
        gets(t[i].qq);
        printf("请输入联系人家庭地址:");
        gets(t[i].dress);
	}
	system("pause");
	renshu=renshu+n;
}

void chakan()
{
	int i;
	system("cls");
	printf("您共有%d名联系人:\n",renshu);
	if(renshu!=0)
		for(i=0;i<renshu;i++)
		{
			printf("第%d名联系人:\n\t\t姓名:%s\n\t\t电话:%s\n\t\tQQ:%s\n\t\t家庭地址:%s\n",i+1,t[i].name,t[i].phone,t[i].qq,t[i].dress);
	        printf("\n");
		}
	else
		printf("您的通讯录内没有联系人!\n");
	system("pause");
}

void shanchu()
{
	system("cls");
	if(renshu!=0)
	{
		printf("请输入要删除的联系人姓名:");
	    int h,j,i,m;
	    getchar();
        gets(t[renshu].name);
	    for(i=0;i<renshu;i++)
		{
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("找到联系人:\n");
			    printf("\t第%d名联系人:\n\t\t姓名:%s\n\t\t电话:%s\n\t\tQQ:%s\n\t\t家庭地址:%s\n",i+1,t[i].name,t[i].phone,t[i].qq,t[i].dress);
                printf("是否删除此联系人:\n\t\t1.删除\t\t2.不删除\n请选择:");
			    scanf("%d",&h);
			    while(h!=1&&h!=2)
				{
					printf("输入错误,请重新输入!");
				    scanf("%d",&h);
				};
			    if(h==1)
				{
			        for(j=i;j<renshu;j++)
				    t[j]=t[j+1];
			        renshu=renshu-1;
				    printf("联系人已删除\n");
				    printf("继续删除?\n\t\t1.是\t\t2.否\n请选择:");
				    scanf("%d",&m);
			        while(m!=1&&m!=2)
					{
						printf("输入错误,请重新输入!");
				        scanf("%d",&m);
					};
			        if(m==1)
						shanchu();
				}
			    break;
			}
		    if(i==(renshu-1)&&strcmp(t[renshu].name,t[i].name)!=0)
			{
				printf("没有找到联系人!\n");
			    printf("1.重新输入联系人姓名.\n2.回到主菜单\n请选择:");
			    scanf("%d",&m);
			    while(m!=1&&m!=2)
				{
					printf("输入错误,请重新输入!");
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
		printf("您的通讯录内没有联系人!\n");
        system("pause");
	}
}

void chazhao()
{
	system("cls");
	if(renshu!=0)
	{
		printf("请输入要查找的联系人姓名:");
	    int i,m;
	    getchar();
        gets(t[renshu].name);
	    for(i=0;i<renshu;i++)
		{
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("找到联系人:\n");
			    printf("\t第%d名联系人:\n\t\t姓名:%s\n\t\t电话:%s\n\t\tQQ:%s\n\t\t家庭地址:%s\n",i+1,t[i].name,t[i].phone,t[i].qq,t[i].dress);
                break;			
			}
            if(i==(renshu-1)&&strcmp(t[renshu].name,t[i].name)!=0)
			{
				printf("没有找到联系人!\n");
			    printf("1.重新输入联系人姓名.\n2.回到主菜单\n请选择:");
			    scanf("%d",&m);
			    while(m!=1&&m!=2)
				{
					printf("输入错误,请重新输入!");
				    scanf("%d",&m);
				};
			    if(m==1)
					chazhao();
			}
		}
	}
	else
		printf("您的通讯录内没有联系人!\n");
	system("pause");
}


void xiugai()
{
	system("cls");
	if(renshu!=0)
	{
		printf("请输入要修改的联系人姓名:");
	    int j,i,m;
	    getchar();
        gets(t[renshu].name);
	    for(i=0;i<renshu;i++)
		{
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("找到联系人:\n");
			    printf("\t第%d名联系人:\n\t\t姓名:%s\n\t\t电话:%s\n\t\tQQ:%s\n\t\t家庭地址:%s\n",i+1,t[i].name,t[i].phone,t[i].qq,t[i].dress);
                j=i;
				break;			
			}
            if(i==(renshu-1)&&strcmp(t[renshu].name,t[i].name)!=0)
			{
				printf("没有找到联系人!\n");
			    printf("1.重新输入联系人姓名.\n2.回到主菜单\n请选择:");
			    scanf("%d",&m);
			    while(m!=1&&m!=2)
				{
					printf("输入错误,请重新输入!");
				    scanf("%d",&m);
				};
			    if(m==1)
					chazhao();
			}
		}
		int k;
	printf("请选择要修改的信息:\n\t1.姓名\t2.电话\t3.QQ\t4.家庭地址\n请选择:");
	scanf("%d",&k);
	while(k<1||k>4)
	{
		printf("输入错误,请重新输入!");
		scanf("%d",&k);
	}
	printf("请输入新的信息:");
	switch(k)
	{
	case 1:getchar();gets(t[j].name);break;
	case 2:getchar();gets(t[j].phone);break;
	case 3:getchar();gets(t[j].qq);break;
	case 4:getchar();gets(t[j].dress);break;
	}
	printf("修改成功!\n");
	}
	else
		printf("您的通讯录内没有联系人!\n");
	system("pause");
}

int duqu()
{
	FILE *tx=NULL;
	int i=0,renshu=0;
	if((tx=fopen("tongxun.txt","r+"))==NULL)
	{
		printf("不能打开文件:tongxun.txt\n");
		system("pause");
		exit(0);
	}
	fscanf(tx,"%d",&renshu);
	printf("\n\t\t\t******开始读取文件******\n");
	for(i=0;i<renshu;i++)
		fscanf(tx,"%s\n%s\n%s\n%s\n",t[i].name,t[i].phone,t[i].qq,t[i].dress);
    fclose(tx);
	printf("\t\t\t********读取成功********\n");
	system("pause");
	return renshu;
}


void baocun()
{
	FILE *tx;
	int i;
    tx=fopen("tongxun.txt","w");
	printf("\t\t\t******开始保存文件******\n");
	fprintf(tx,"%d",renshu);
	fprintf(tx,"\r\n");
	for(i=0;i<renshu;i++)
	{
		fprintf(tx,"%s\n%s\n%s\n%s\n",t[i].name,t[i].phone,t[i].qq,t[i].dress);
        fprintf(tx,"\r\n");
	}
	fclose(tx);
	printf("\t\t\t********保存成功********\n");
	system("pause");


}
