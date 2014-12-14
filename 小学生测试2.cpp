#include<stdio.h>
#include<stdlib.h>                        //stdlib 头文件里包含了C语言的一些函数　　该文件包含了的C语言标准库函数的定义　　stdlib.h里面定义了五种类型、一些宏和通用工具函数。类型例如size_t、wchar_t、div_t、ldiv_t和lldiv_t；宏例如EXIT_FAILURE、EXIT_SUCCESS、RAND_MAX和MB_CUR_MAX等等；常用的函数如malloc()、calloc()、realloc()、free()()、system()、atoi()、atol()、rand()()、 srand()()、exit()等等。 
int menu()                               //定义主菜单
{
	int c;
	printf("欢迎进人小学生测试系统\n");
	printf("1.简单模式\n");
	printf("2.困难模式\n");
	printf("3.退出\n");
	printf("请输入您的选择：\n");
	scanf("%d",&c);
	return c;
}
void simple()          //定义simple函数
{
	int i,score=0,a,b,c,result,k,m,j=0;    //定义
	char t[2]={'+','-'};                  //定义字符数组
	char g;
	for(i=0;i<10;i++)
	{
		while(1)                           //无限循环   直到成立
		{
			a=rand()%51;                   //随机产生0到50中一个数
			b=rand()%51;                   //随机产生0到50中一个数
			c=rand()%2;                    //随机产生0到1中一个数
			if(c==0)                       //如果c等于0，计算a加b，如果c等于1，计算a减b
				result=a+b;
			else
				result=a-b;
			if(result>=0&&result<=50)      //如果结果大于等于0或者小于等于50   结束   选定a，b，c
				break;                     //结束循环
		}
		
		system("cls");                      //清屏
		
		printf("第%d道题:\n%d %c %d=",i+1,a,t[c],b);   //输出第几道题，先前选定的a，c，b
		for(k=0;k<3;k++)
		{
			scanf("%d",&m);                           //输入答案
			if(m==result)                             //如果输入值正确
			{
				if(k==0)                              //如果第一次输入正确
				{
					score=score+10;                   //成绩在本身上加10分
					printf("回答正确!\n");           //输出  回答正确
					printf("你已答对%d道题\n",j+1);   //输出  你已答对几道题
					system("pause");                  // system("pause")  使屏幕暂停
					j++;                              //答对的题数加1
					

					break;                            //结束此次循环  
				}
				else if(k==1)                        //如果第二次输入正确
				{
					score=score+7;                   //成绩在本身上加7分 
					printf("回答正确!\n");          //输出  回答正确
					printf("你已答对%d道题\n",j+1);  //输出  你已答对几道题 
					system("pause");                 // system("pause")  使屏幕暂停  
					j++;                             //答对的题数加1
					break;                           //结束此次循环                    
				}
				
				else if(k==2)                        //如果第三次输入正确 
				{
					score=score+5;                   //成绩在本身上加5分
					printf("回答正确!\n");          //输出  回答正确
					printf("你已答对%d道题\n",j+1);  //输出  你已答对几道题
					system("pause");                 // system("pause")  使屏幕暂停 
					j++;                             //答对的题数加1  
					break;                           //结束此次循环
				}
			}
			else
			{
				if(k!=2)                             //如果输入错误  错误次数不到3次
				{
					printf("你还有%d次机会,请重输入!\n",2-k);   //输出  你还有几次机会，请重新输入
					
				}
				else if(i!=9)                        //如果3次都输入错误      如果题数不是第10道
				{
					printf("计算错误次数过多进入下一题!\n");   //输出   计算错误次数过多进入下一题！
					system("pause");                            //system("pause")  使屏幕暂停 
					break;                                      //结束此次循环
					        
				}
				else                                  //如果题数是第10道                                  
				{
					printf("测试结束,欢迎使用!\n");  //输出   测试结束,欢迎使用
				}

			}	
			
		}
	}
	
	printf("你共答对了%d道题!\n",j);                 //输出    你共答对了几道题
	printf("你的得分:%d\n",score);                   //输出    你的得分
	   switch(score/10)
	   {
	   case 10:printf("smart!\n");break;              
	   case 9:printf("smart!\n");break;               // 90分以上  输出 smart 
	   case 8:printf("good!\n");break;                // 80到90分以上  输出 good    
	   case 7:printf("Ok!\n");break;                  // 70到80分以上  输出 ok    
	   case 6:printf("pass!\n");break;                // 60到70分以上  输出 pass    
	   case 5:
	   case 4:
	   case 3:
	   case 2:
       case 1:
	   case 0:printf("try again!\n");                 
		      system("pause");system("cls");          
		      printf("是否重新开始测试(Y/N)?\n");
			  getchar();  
		      g=getchar();
			  if(g=='y'||g=='Y')
                   simple();
			   else if(g=='n'||g=='N')
				   printf("测试结束\n");
			   else
				   printf("输入错误!请重新运行程序.\n");break;       
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
	    printf("第%d道题:\n%d %c %d=",i+1,a,t[c],b);
		for(k=0;k<3;k++)
		{
			scanf("%d",&m);
			if(m==result)
			{
				if(k==0)
				{
					score=score+10;
					printf("回答正确！\n");
					printf("你已答对%d道题\n",j+1);
					system("pause");
					j++;

					break;
				}
				else if(k==1)
				{
					score=score+7;
					printf("回答正确!\n");
					printf("你已答对%d道题\n",j+1);
					system("pause");
					j++;
					break;
				}
				
				else if(k==2)
				{
					score=score+5;
					printf("回答正确!\n");
					printf("你已答对%d道题\n",j+1);
					system("pause");
					j++;
					break;
				}
			}
			else
			{
				if(k!=2)
				{
					printf("你还有%d次机会,请重输入!\n",2-k);
				}
				else if(i!=9)
				{
					printf("计算错误次数过多进入下一题!\n");
					system("pause");
					break;
					
				}
				else
				{
					printf("测试结束,欢迎使用!\n");
				}
			}	
			
		}
	}
	
	printf("你共答对了%d道题!\n",j);
	printf("你的得分:%d\n",score);
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
		      printf("是否重新开始测试(Y/N)?\n");
			  getchar();  
		      g=getchar();
			  if(g=='y'||g=='Y')
                   mid();
			   else if(g=='n'||g=='N')
				   printf("测试结束\n");
			   else
				   printf("输入错误!请重新运行程序.\n");break;    
	   }
	   


}
int main()
{
	int k;
	k=menu();                 //接受int menu中输入的数字
	switch(k)                 //进行对比 执行相应语句
	{
	case 1:simple();break;     //执行simple()函数
	case 2:mid();break;        //执行mid()函数
	case 3:exit(-1);break;                                   //退出
	default:printf("输入有误,按回车返回!\n");getchar();getchar();system("cls");main();break;
	}
	   return 0;
}

