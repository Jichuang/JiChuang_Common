#include<stdio.h>
#include<stdlib.h>                        //stdlib ͷ�ļ��������C���Ե�һЩ�����������ļ������˵�C���Ա�׼�⺯���Ķ��塡��stdlib.h���涨�����������͡�һЩ���ͨ�ù��ߺ�������������size_t��wchar_t��div_t��ldiv_t��lldiv_t��������EXIT_FAILURE��EXIT_SUCCESS��RAND_MAX��MB_CUR_MAX�ȵȣ����õĺ�����malloc()��calloc()��realloc()��free()()��system()��atoi()��atol()��rand()()�� srand()()��exit()�ȵȡ� 
int menu()                               //�������˵�
{
	int c;
	printf("��ӭ����Сѧ������ϵͳ\n");
	printf("1.��ģʽ\n");
	printf("2.����ģʽ\n");
	printf("3.�˳�\n");
	printf("����������ѡ��\n");
	scanf("%d",&c);
	return c;
}
void simple()          //����simple����
{
	int i,score=0,a,b,c,result,k,m,j=0;    //����
	char t[2]={'+','-'};                  //�����ַ�����
	char g;
	for(i=0;i<10;i++)
	{
		while(1)                           //����ѭ��   ֱ������
		{
			a=rand()%51;                   //�������0��50��һ����
			b=rand()%51;                   //�������0��50��һ����
			c=rand()%2;                    //�������0��1��һ����
			if(c==0)                       //���c����0������a��b�����c����1������a��b
				result=a+b;
			else
				result=a-b;
			if(result>=0&&result<=50)      //���������ڵ���0����С�ڵ���50   ����   ѡ��a��b��c
				break;                     //����ѭ��
		}
		
		system("cls");                      //����
		
		printf("��%d����:\n%d %c %d=",i+1,a,t[c],b);   //����ڼ����⣬��ǰѡ����a��c��b
		for(k=0;k<3;k++)
		{
			scanf("%d",&m);                           //�����
			if(m==result)                             //�������ֵ��ȷ
			{
				if(k==0)                              //�����һ��������ȷ
				{
					score=score+10;                   //�ɼ��ڱ����ϼ�10��
					printf("�ش���ȷ!\n");           //���  �ش���ȷ
					printf("���Ѵ��%d����\n",j+1);   //���  ���Ѵ�Լ�����
					system("pause");                  // system("pause")  ʹ��Ļ��ͣ
					j++;                              //��Ե�������1
					

					break;                            //�����˴�ѭ��  
				}
				else if(k==1)                        //����ڶ���������ȷ
				{
					score=score+7;                   //�ɼ��ڱ����ϼ�7�� 
					printf("�ش���ȷ!\n");          //���  �ش���ȷ
					printf("���Ѵ��%d����\n",j+1);  //���  ���Ѵ�Լ����� 
					system("pause");                 // system("pause")  ʹ��Ļ��ͣ  
					j++;                             //��Ե�������1
					break;                           //�����˴�ѭ��                    
				}
				
				else if(k==2)                        //���������������ȷ 
				{
					score=score+5;                   //�ɼ��ڱ����ϼ�5��
					printf("�ش���ȷ!\n");          //���  �ش���ȷ
					printf("���Ѵ��%d����\n",j+1);  //���  ���Ѵ�Լ�����
					system("pause");                 // system("pause")  ʹ��Ļ��ͣ 
					j++;                             //��Ե�������1  
					break;                           //�����˴�ѭ��
				}
			}
			else
			{
				if(k!=2)                             //����������  �����������3��
				{
					printf("�㻹��%d�λ���,��������!\n",2-k);   //���  �㻹�м��λ��ᣬ����������
					
				}
				else if(i!=9)                        //���3�ζ��������      ����������ǵ�10��
				{
					printf("�������������������һ��!\n");   //���   �������������������һ�⣡
					system("pause");                            //system("pause")  ʹ��Ļ��ͣ 
					break;                                      //�����˴�ѭ��
					        
				}
				else                                  //��������ǵ�10��                                  
				{
					printf("���Խ���,��ӭʹ��!\n");  //���   ���Խ���,��ӭʹ��
				}

			}	
			
		}
	}
	
	printf("�㹲�����%d����!\n",j);                 //���    �㹲����˼�����
	printf("��ĵ÷�:%d\n",score);                   //���    ��ĵ÷�
	   switch(score/10)
	   {
	   case 10:printf("smart!\n");break;              
	   case 9:printf("smart!\n");break;               // 90������  ��� smart 
	   case 8:printf("good!\n");break;                // 80��90������  ��� good    
	   case 7:printf("Ok!\n");break;                  // 70��80������  ��� ok    
	   case 6:printf("pass!\n");break;                // 60��70������  ��� pass    
	   case 5:
	   case 4:
	   case 3:
	   case 2:
       case 1:
	   case 0:printf("try again!\n");                 
		      system("pause");system("cls");          
		      printf("�Ƿ����¿�ʼ����(Y/N)?\n");
			  getchar();  
		      g=getchar();
			  if(g=='y'||g=='Y')
                   simple();
			   else if(g=='n'||g=='N')
				   printf("���Խ���\n");
			   else
				   printf("�������!���������г���.\n");break;       
	   }
}

void mid()
{
	int i,score=0,a,b,c,result,k,m,j=0;
	char t[4]={'+','-','*'};
	char g;
	for(i=0;i<10;i++)
	{
		while(1)
		{
			a=rand()%100;
			b=rand()%100;
			c=rand()%3;
			if(c==0)
				result=a+b;
			else if(c==1)
				result=a-b;
		    else
				result=a*b;
			
			if(result>=0&&result<=500)
				break;
		}
		system("cls");
	    printf("��%d����:\n%d %c %d=",i+1,a,t[c],b);
		for(k=0;k<3;k++)
		{
			scanf("%d",&m);
			if(m==result)
			{
				if(k==0)
				{
					score=score+10;
					printf("�ش���ȷ��\n");
					printf("���Ѵ��%d����\n",j+1);
					system("pause");
					j++;

					break;
				}
				else if(k==1)
				{
					score=score+7;
					printf("�ش���ȷ!\n");
					printf("���Ѵ��%d����\n",j+1);
					system("pause");
					j++;
					break;
				}
				
				else if(k==2)
				{
					score=score+5;
					printf("�ش���ȷ!\n");
					printf("���Ѵ��%d����\n",j+1);
					system("pause");
					j++;
					break;
				}
			}
			else
			{
				if(k!=2)
				{
					printf("�㻹��%d�λ���,��������!\n",2-k);
				}
				else if(i!=9)
				{
					printf("�������������������һ��!\n");
					system("pause");
					break;
					
				}
				else
				{
					printf("���Խ���,��ӭʹ��!\n");
				}
			}	
			
		}
	}
	
	printf("�㹲�����%d����!\n",j);
	printf("��ĵ÷�:%d\n",score);
	   switch(score/10)
	   {
	   case 10:printf("smart!\n");break;
	   case 9:printf("smart!\n");break;
	   case 8:printf("good!\n");break;
	   case 7:printf("Ok!\n");break;
	   case 6:printf("pass!\n");break;
	   case 5:
	   case 4:
	   case 3:
	   case 2:
	   case 1:
	   case 0:printf("try again!\n");                 
		      system("pause");system("cls");          
		      printf("�Ƿ����¿�ʼ����(Y/N)?\n");
			  getchar();  
		      g=getchar();
			  if(g=='y'||g=='Y')
                   mid();
			   else if(g=='n'||g=='N')
				   printf("���Խ���\n");
			   else
				   printf("�������!���������г���.\n");break;    
	   }
	   


}
int main()
{
	int k;
	k=menu();                 //����int menu�����������
	switch(k)                 //���жԱ� ִ����Ӧ���
	{
	case 1:simple();break;     //ִ��simple()����
	case 2:mid();break;        //ִ��mid()����
	case 3:exit(-1);break;                                   //�˳�
	default:printf("��������,���س�����!\n");getchar();getchar();system("cls");main();break;
	}
	   return 0;
}

