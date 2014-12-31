#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int b;
int c,l=0,y=0;
char z='%';
struct  vocabulary
{
	char voca[50];
}vo[3000],co[3000],so[3000];

struct _mark
{
	float total;
	float right;
	float fault;
	float ki;
}ko[100];


void start()
{
	printf("\t-----------单词助手-----------\n");
	printf("\t-        1.单词预览          -\n");
	printf("\t-        2.单词测试          -\n");            //开始页面 
	printf("\t-        3.成绩记录          -\n");
 	printf("\t-        4.选择词库          -\n");
 	printf("\t-        5.退出              -\n");
	printf("\t------------------------------\n");
}

void first()
{	int a;
	system("cls");
	printf("\n");
	printf("\n");
	printf("\t         欢迎使用单词助手     \n");
	printf("\t**************************************\n");
	printf("\n");
	printf("\t  o(∩_∩)o  别着急...请先选择词库：\n\n");
	printf("\t1.四级词汇\t2.六级词汇\n");                  //载入词库 
	scanf("%d",&a);
		if(a<1||a>2)
		 {
 			printf("输入有误，请重新输入:");
 			scanf("%d",&a);
	   	}
		FILE *fp1,*fp2,*fp3,*fp4,*fp5;
        if((fp1=fopen("4.txt","rb"))==0)
        {
            printf("不能打开文件：4.txt");
        }
        if((fp2=fopen("5.txt","wb+"))==0)
        {
            printf("不能打开文件：5.txt");
        }   
        
        int i=0;
        
        if(a==1)
        {
        	  while (fread(&vo[i],sizeof(struct  vocabulary),1,fp1))
        	{	

        	fwrite(&vo[i],sizeof(struct  vocabulary),1,fp2);
        		i++;
      	    }
        }
        if(a==2)
        {
			if((fp5=fopen("2.txt","rb+"))==0)
      		  {
        	    printf("不能打开文件：5.txt");
      		  }
        	  while (fread(&vo[i],sizeof(struct  vocabulary),1,fp5))
        	{	

        		fwrite(&vo[i],sizeof(struct  vocabulary),1,fp2);
        		i++;
      	    }
      	    fclose(fp5);
        }
        fclose(fp2);
		fclose(fp1);
		
        if((fp2=fopen("5.txt","rb"))==0)
        {
            printf("不能打开文件：4.txt");
        }

		char d[50],e[50];
		i=0;int q=0,f=0,j=0,p=0,s,t;
        char ch;
        ch=fgetc(fp2);
        while(ch!=-1)
        {
        	if(ch>='a'&&ch<='z')
        		{
	       		 	d[i]=ch;
					i++;
	    	    }
			
			if(ch<'a'||ch>'z')
				{
						if(ch=='\n')
						{
							p=0;
							e[q]='\0';
							strcpy(so[f].voca,e);
							for(t=0;t<=q;t++)
							e[t]='\0';
							f++;
							q=0;
						}
						else
						{	
							if(p==0)
							{
								d[i]='\0';
								strcpy(co[j].voca,d);
								s=0;
								for(s=0;s<=i;s++)
								d[s]='\0';
								j++;
								p=1;
								i=0;
							}
							e[q]=ch;
							q++;
						}
				}

        	ch=fgetc(fp2);
        	
        }
 		system("cls"); 
 		printf("\n");
		printf("\t*****************************************\n");
		printf("\n");
		printf("\t o(*^__^*)o   导入成功！按任意键进入...\n");
        fclose(fp2);
	  	getch();
	return;

}


void ciku()
{	int a;
	system("cls");
	printf("\t*****************************\n");
	printf("\n");
	printf("\t  o(∩_∩)o  请先选择词库：\n\n");
	printf("\t1.四级词汇\t2.六级词汇\n");                //载入词库 
	scanf("%d",&a);
		if(a<1||a>2)
		 {
 			printf("输入有误，请重新输入:");
 			scanf("%d",&a);
	   	}
		FILE *fp1,*fp2,*fp3,*fp4,*fp5;
        if((fp1=fopen("4.txt","rb"))==0)
        {
            printf("不能打开文件：4.txt");
        }
        if((fp2=fopen("5.txt","wb+"))==0)
        {
            printf("不能打开文件：5.txt");
        }   
        
        int i=0;
        
        if(a==1)
        {
        	  while (fread(&vo[i],sizeof(struct  vocabulary),1,fp1))
        	{	

        	fwrite(&vo[i],sizeof(struct  vocabulary),1,fp2);
        		i++;
      	    }
        }
        if(a==2)
        {
			if((fp5=fopen("2.txt","rb+"))==0)
      		  {
        	    printf("不能打开文件：5.txt");
      		  }
        	  while (fread(&vo[i],sizeof(struct  vocabulary),1,fp5))
        	{	

        		fwrite(&vo[i],sizeof(struct  vocabulary),1,fp2);
        		i++;
      	    }
      	    fclose(fp5);
        }
        fclose(fp2);
		fclose(fp1);
		
        if((fp2=fopen("5.txt","rb"))==0)
        {
            printf("不能打开文件：4.txt");
        }

		char d[50],e[50];
		i=0;int q=0,f=0,j=0,p=0,s,t;
        char ch;
        ch=fgetc(fp2);
        while(ch!=-1)
        {
        	if(ch>='a'&&ch<='z')
        		{
	       		 	d[i]=ch;
					i++;
	    	    }
			
			if(ch<'a'||ch>'z')
				{
						if(ch=='\n')
						{
							p=0;
							e[q]='\0';
							strcpy(so[f].voca,e);
							for(t=0;t<=q;t++)
							e[t]='\0';
							f++;
							q=0;
						}
						else
						{	
							if(p==0)
							{
								d[i]='\0';
								strcpy(co[j].voca,d);
								s=0;
								for(s=0;s<=i;s++)
								d[s]='\0';
								j++;
								p=1;
								i=0;
							}
							e[q]=ch;
							q++;
						}
				}

        	ch=fgetc(fp2);
        	
        }
 		system("cls"); 
 		printf("\n");
		printf("\t*****************************************\n");
		printf("\n");
		printf("\t o(*^__^*)o   导入成功！按任意键返回...\n");
        fclose(fp2);
	  	getch();
	return;

}


void yulan()
{	
	system("cls");
	printf("\n");
	int i=0,j=0,sum=15,t=0;
	for(j=0;j<15;j++) 
	printf("\t%s\t%s\n",co[j].voca,so[j].voca);
	printf("\n\t1.上一页\t2.下一页\t9.返回主菜单\t");
	printf("\n\n请选择：");
	scanf("%d",&c);
	if(c==9)return;
	while(1)
	{
		if(c==1)
		{
			if(t>=1)
				{	
					t--;
					system("cls");
					printf("\n");
					for(i=sum*t;i<(t+1)*sum;i++)
					printf("\t%s\t%s\n",co[i].voca,so[i].voca);
					printf("\n\t1.上一页\t2.下一页\t9.返回主菜单\t");
					printf("\n\n请选择：");
  					
				}
			else
				{	t=0;
					system("cls");
					printf("\n");
					for(j=0;j<15;j++) 
					printf("\t%s\t%s\n",co[j].voca,so[j].voca);
					printf("\n\t1.上一页\t2.下一页\t9.返回主菜单\t\n");
				    printf("\n已是第一页！\n");
				    printf("请选择："); 
				}
  	
		}
	
		if(c==2)
			{  	
				t++;
				system("cls");
				printf("\n");
				for(i=sum*t;i<(t+1)*sum;i++)
				printf("\t%s\t%s\n",co[i].voca,so[i].voca);
				printf("\n\t1.上一页\t2.下一页\t9.返回主菜单\t");
				printf("\n\n请选择：");
				
			}
  		scanf("%d",&c);
		if(c==9)return;
	}
}

void ceshi()
{	
	int f,i;
	float v=0.0,x=0.0,k,m;
	char a[50],b[5]="9";
	system("cls");
	printf("\n\n");
	printf("\t请输入测试的单词个数：\n");
	printf("\n\t输入'0'返回\n\n\t");
	scanf("%d",&f);
	if(f==0)return;
	while(f)
		{
			i=y;
			system("cls");
			printf("\n");
			printf("\t输入9返回主菜单\n"); 
			printf("\n\t%s\n",so[i].voca);
			printf("\n\t您的答案：");
			scanf("%s",a);
			if(strcmp(b,a)==0){
				break;
			}
			if(strcmp(co[i].voca,a)==0)
			{
				v=v+1.0;
				system("cls");
				printf("\n");
				printf("\to(∩_∩)o 哈哈..好厉害！再接再励！\n");
				printf("\n");
				printf("\n\t正确单词：%s\t%s\n",so[i].voca,co[i].voca);
				printf("\n\t您的答案：%s\n",a);
				printf("\n\t按任意键继续..");
				getch();
				
			}
			else
			{
				x=x+1.0;
				system("cls");
				printf("\n");
				printf("\to(︶︿︶)o 唉..错了耶。别灰心，再来！\n");
				printf("\n");
				printf("\n\t正确单词：%s\t%s\n",so[i].voca,co[i].voca);
				printf("\n\t您的答案：%s\n",a);
				printf("\n\t按任意键继续..");
				getch();
			}
			y++;
			f--;
		}
	m=(v+x);
	k=v/m;
	ko[l].right=v;
	ko[l].total=m;
	ko[l].fault=x;
	ko[l].ki=k*100;
	system("cls");
	printf("\n\n\to(∩_∩)o ..测试完成！\n");
	printf("\n\t共测试%2.0f个\n\n\t正确%2.0f个\t错误%2.0f个\n\n\t正确率%5.2f%c\n",ko[l].total,ko[l].right,ko[l].fault,ko[l].ki,z);
	l++;
	printf("\n\t按任意键继续..");
	getch();
}

void jilu()
{
	int e;
	system("cls");
	printf("\n");
	printf(" \t    0o(^_^)o0 看一看您的成绩榜吧~~\n");
	printf("\n\t次数\t总共\t正确\t错误\t正确率\n");
	for(e=0;e<l;e++)
	printf("\n\t%d\t%2.0f\t%2.0f\t%2.0f\t%2.0f%c\n",e+1,ko[e].total,ko[e].right,ko[e].fault,ko[e].ki,z);
	printf("\n");
	printf("\t按任意键返回...");
	getch();
}

int main ()
{	
	first();
	system("cls");
	int n;
 	start();
 	printf("请选择功能 0~5：");
 	scanf("%d",&n);
 	while(n<1||n>5)
	 {
 		printf("输入有误，请重新输入:");
 		scanf("%d",&n);
 	}
 	while(n!=5)
 	{
	 	if(n==1)yulan();
	 	if(n==2)ceshi();
	 	if(n==3)jilu();
	 	if(n==4)ciku();
	 	system("cls");
	 	start();
	 	printf("请选择功能 0~5：");
	 	scanf("%d",&n);

		if(n<1||n>5)
		 {
 			printf("输入有误，请重新输入:");
 			scanf("%d",&n);
	   	}

	 }
	system("cls");
	printf("\n");
	printf("\n");
	printf("\t    o( ^_^ )/~~  Bye..    感谢使用！     \n");
	printf("\t**************************************\n");
 	printf("\n\n\n");
	return 0;
}

