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
	printf("\t-----------��������-----------\n");
	printf("\t-        1.����Ԥ��          -\n");
	printf("\t-        2.���ʲ���          -\n");            //��ʼҳ�� 
	printf("\t-        3.�ɼ���¼          -\n");
 	printf("\t-        4.ѡ��ʿ�          -\n");
 	printf("\t-        5.�˳�              -\n");
	printf("\t------------------------------\n");
}

void first()
{	int a;
	system("cls");
	printf("\n");
	printf("\n");
	printf("\t         ��ӭʹ�õ�������     \n");
	printf("\t**************************************\n");
	printf("\n");
	printf("\t  o(��_��)o  ���ż�...����ѡ��ʿ⣺\n\n");
	printf("\t1.�ļ��ʻ�\t2.�����ʻ�\n");                  //����ʿ� 
	scanf("%d",&a);
		if(a<1||a>2)
		 {
 			printf("������������������:");
 			scanf("%d",&a);
	   	}
		FILE *fp1,*fp2,*fp3,*fp4,*fp5;
        if((fp1=fopen("4.txt","rb"))==0)
        {
            printf("���ܴ��ļ���4.txt");
        }
        if((fp2=fopen("5.txt","wb+"))==0)
        {
            printf("���ܴ��ļ���5.txt");
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
        	    printf("���ܴ��ļ���5.txt");
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
            printf("���ܴ��ļ���4.txt");
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
		printf("\t o(*^__^*)o   ����ɹ��������������...\n");
        fclose(fp2);
	  	getch();
	return;

}


void ciku()
{	int a;
	system("cls");
	printf("\t*****************************\n");
	printf("\n");
	printf("\t  o(��_��)o  ����ѡ��ʿ⣺\n\n");
	printf("\t1.�ļ��ʻ�\t2.�����ʻ�\n");                //����ʿ� 
	scanf("%d",&a);
		if(a<1||a>2)
		 {
 			printf("������������������:");
 			scanf("%d",&a);
	   	}
		FILE *fp1,*fp2,*fp3,*fp4,*fp5;
        if((fp1=fopen("4.txt","rb"))==0)
        {
            printf("���ܴ��ļ���4.txt");
        }
        if((fp2=fopen("5.txt","wb+"))==0)
        {
            printf("���ܴ��ļ���5.txt");
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
        	    printf("���ܴ��ļ���5.txt");
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
            printf("���ܴ��ļ���4.txt");
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
		printf("\t o(*^__^*)o   ����ɹ��������������...\n");
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
	printf("\n\t1.��һҳ\t2.��һҳ\t9.�������˵�\t");
	printf("\n\n��ѡ��");
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
					printf("\n\t1.��һҳ\t2.��һҳ\t9.�������˵�\t");
					printf("\n\n��ѡ��");
  					
				}
			else
				{	t=0;
					system("cls");
					printf("\n");
					for(j=0;j<15;j++) 
					printf("\t%s\t%s\n",co[j].voca,so[j].voca);
					printf("\n\t1.��һҳ\t2.��һҳ\t9.�������˵�\t\n");
				    printf("\n���ǵ�һҳ��\n");
				    printf("��ѡ��"); 
				}
  	
		}
	
		if(c==2)
			{  	
				t++;
				system("cls");
				printf("\n");
				for(i=sum*t;i<(t+1)*sum;i++)
				printf("\t%s\t%s\n",co[i].voca,so[i].voca);
				printf("\n\t1.��һҳ\t2.��һҳ\t9.�������˵�\t");
				printf("\n\n��ѡ��");
				
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
	printf("\t��������Եĵ��ʸ�����\n");
	printf("\n\t����'0'����\n\n\t");
	scanf("%d",&f);
	if(f==0)return;
	while(f)
		{
			i=y;
			system("cls");
			printf("\n");
			printf("\t����9�������˵�\n"); 
			printf("\n\t%s\n",so[i].voca);
			printf("\n\t���Ĵ𰸣�");
			scanf("%s",a);
			if(strcmp(b,a)==0){
				break;
			}
			if(strcmp(co[i].voca,a)==0)
			{
				v=v+1.0;
				system("cls");
				printf("\n");
				printf("\to(��_��)o ����..���������ٽ�������\n");
				printf("\n");
				printf("\n\t��ȷ���ʣ�%s\t%s\n",so[i].voca,co[i].voca);
				printf("\n\t���Ĵ𰸣�%s\n",a);
				printf("\n\t�����������..");
				getch();
				
			}
			else
			{
				x=x+1.0;
				system("cls");
				printf("\n");
				printf("\to(����)o ��..����Ү������ģ�������\n");
				printf("\n");
				printf("\n\t��ȷ���ʣ�%s\t%s\n",so[i].voca,co[i].voca);
				printf("\n\t���Ĵ𰸣�%s\n",a);
				printf("\n\t�����������..");
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
	printf("\n\n\to(��_��)o ..������ɣ�\n");
	printf("\n\t������%2.0f��\n\n\t��ȷ%2.0f��\t����%2.0f��\n\n\t��ȷ��%5.2f%c\n",ko[l].total,ko[l].right,ko[l].fault,ko[l].ki,z);
	l++;
	printf("\n\t�����������..");
	getch();
}

void jilu()
{
	int e;
	system("cls");
	printf("\n");
	printf(" \t    0o(^_^)o0 ��һ�����ĳɼ����~~\n");
	printf("\n\t����\t�ܹ�\t��ȷ\t����\t��ȷ��\n");
	for(e=0;e<l;e++)
	printf("\n\t%d\t%2.0f\t%2.0f\t%2.0f\t%2.0f%c\n",e+1,ko[e].total,ko[e].right,ko[e].fault,ko[e].ki,z);
	printf("\n");
	printf("\t�����������...");
	getch();
}

int main ()
{	
	first();
	system("cls");
	int n;
 	start();
 	printf("��ѡ���� 0~5��");
 	scanf("%d",&n);
 	while(n<1||n>5)
	 {
 		printf("������������������:");
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
	 	printf("��ѡ���� 0~5��");
	 	scanf("%d",&n);

		if(n<1||n>5)
		 {
 			printf("������������������:");
 			scanf("%d",&n);
	   	}

	 }
	system("cls");
	printf("\n");
	printf("\n");
	printf("\t    o( ^_^ )/~~  Bye..    ��лʹ�ã�     \n");
	printf("\t**************************************\n");
 	printf("\n\n\n");
	return 0;
}

