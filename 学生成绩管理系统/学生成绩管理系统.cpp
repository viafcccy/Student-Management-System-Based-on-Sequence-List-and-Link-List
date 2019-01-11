#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct student                        
{  
    char num[20];   //学号  
    char name[20];  //姓名 
	char sex[5];    //性别
	char banji[20]; //班级
    float c;        //C语言成绩  
    float math;     //数学成绩  
    float english;  //英语成绩
    float PE;       //体育成绩  
    float politics; //思修成绩  
	float all;      //总分
	float average;  //平均分
    student * next; //指针域
}student;  

//定义头结点
typedef struct linklist
{
    student * next0;        //头指针
    int length;         //链表的长度，初始值为0
}linklist;

int Input()
{
	system("cls");
	FILE *fp;
	int i ;
	char select;
	student * tail;
	linklist * head;
	head = (linklist * )malloc(sizeof(linklist));
	head->length = 0;
	student person;
    printf("开始输入请按下y\n");
	select = getch();
	if(select == 'y'||select == 'Y')                     
      {  
		tail = (student * )malloc(sizeof(student));
		system ("cls");
		printf("* * * * * * * * * * * * * * * * * * 学生数据输入 * * * * * * * * * * * * * * * * * *\n");  
        printf("请输入姓名：     \n");  
        scanf("%s",tail->name);  
        printf("请输入学号：     \n");  
        scanf("%s",tail->num);
		printf("请输入性别：     \n");
		scanf("%s",tail->sex);
		printf("请输入班级：     \n");  
        scanf("%s",tail->banji);
        printf("请输入C语言成绩：\n");  
        scanf("%f",&tail->c);  
        printf("请输入数学成绩： \n");  
        scanf("%f",&tail->math);  
        printf("请输入英语成绩： \n");  
        scanf("%f",&tail->english);
        printf("请输入体育成绩： \n");  
        scanf("%f",&tail->PE);  
        printf("请输入思修成绩： \n");  
        scanf("%f",&tail->politics); 
		tail->all = tail->c + tail->math + tail->english + tail->PE + tail->politics;
        tail->average = (tail->all) / 5;
		head->next0 = tail;
		head->length++;
        system( "cls ");  
    }
	printf("是否继续添加?(y/n)");  
    select = getch();
	student * node = NULL;
	while(select == 'y'||select == 'Y')                     
    {  
		node = tail;
		tail = (student * )malloc(sizeof(student));
		system ("cls");
		printf("* * * * * * * * * * * * * * * * * * 学生数据输入 * * * * * * * * * * * * * * * * * *\n");  
        printf("请输入姓名：     \n");  
        scanf("%s",tail->name);  
        printf("请输入学号：     \n");  
        scanf("%s",tail->num);
		printf("请输入性别：     \n");
		scanf("%s",tail->sex);
		printf("请输入班级：     \n");  
        scanf("%s",tail->banji);
        printf("请输入C语言成绩：\n");  
        scanf("%f",&tail->c);  
        printf("请输入数学成绩： \n");  
        scanf("%f",&tail->math);  
        printf("请输入英语成绩： \n");  
        scanf("%f",&tail->english);
        printf("请输入体育成绩： \n");  
        scanf("%f",&tail->PE);  
        printf("请输入思修成绩： \n");  
        scanf("%f",&tail->politics); 
		tail->all = tail->c + tail->math + tail->english + tail->PE + tail->politics;
        tail->average = (tail->all) / 5;
		node->next = tail;
		node = tail;
		head->length++;
        printf("是否继续添加?(y/n)");  
    	select = getch();
        system( "cls ");  
    }
	node = NULL;
	fp=fopen("studata.txt","a");  //以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。
	if(fp==NULL)                    
    {  
        printf("cannot open the files\n");  
        system("pause");  
        return -1;//如果文件出现错误返回-1  
    }
	student * p;//遍历指针
	p = head->next0;
    for(i=0;i<head->length||p == NULL;i++)  
    {
        fprintf(fp,"%s %s %s %s %f %f %f %f %f %f %f\n",p->name,p->num,p->sex,p->banji,p->c,p->math,p->english,p->PE,p->politics,p->all,p->average);    //以2进制形式写入文件中,一次写入一个数组 
		p = p->next;		
    }  
    fclose(fp);                                       
	system("pause");
	return 0;//程序正常执行返回0
}

int Display()
{
    system("cls");
	FILE *fp;
	int n = 0;
	int i = 0;
	linklist * headnode = (linklist*)malloc(sizeof(linklist));
	student * head = (student*)malloc(sizeof(student));
	student * tail;
	headnode->length = 0;
	headnode->next0 = head;
	fp = fopen("studata.txt","rb");
	if(fp==NULL)              
	{  
        printf("cannot open the files\n");  
        system("pause");  
        return -1;  
    }
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" 姓名   学号     性别  班级   c语言成绩   数学成绩   英语成绩   体育成绩   思修成绩   总分      平均分\n");
	while(fscanf(fp,"%s%s%s%s%f%f%f%f%f%f%f",head->name,head->num,head->sex,head->banji,&head->c,&head->math,&head->english,&head->PE,&head->politics,&head->all,&head->average)!=EOF)//打开保存的二进制文件将其copy到结构体
	{    
		tail = (student*)malloc(sizeof(student));
		head->next = tail;
		printf("%s %s %s %s %f %f %f %f %f %f %f",head->name,head->num,head->sex,head->banji,head->c,head->math,head->english,head->PE,head->politics,head->all,head->average);//将结构体输出
		head = tail;
		headnode->length++;
		printf("\n");
		
	}
	fclose(fp);
	system("pause");
    printf("您是否返回上一级菜单？y/n");
	if(getch() == 'y')
	{
        return 0;
	}
    if(getch() == 'n')
    {    
		system("cls");
		Display();
    }
    return 0;    
}

int Modify()
{
	system("cls");
    student person[200];
    FILE *fp;  
    int i=0;
    int n=0;  
    char s[15];  
    char m;   
    printf("* * * * * * * * * * 请选择查询方式  * * * * * * * * * *\n");  
    printf("*                                                     *\n");  
    printf("*                       1.姓名                        *\n");  
    printf("*                       2.学号                        *\n");  
    printf("*                       3.返回                        *\n");  
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");  
    printf("请输入你要修改的方式\n");  
    m = getch(); 
    while(m!='1'&&m!='2'&&m!='3')  
        {  
            printf("输入错误请重新修改\n");  
            m = getch(); 
        }  
     if((fp=fopen("studata.txt","r"))==NULL)                 //以2进制方式读取文件信息后进行判断指针是否指向一个有效文件  
      {  
         printf("cannot open the files\n");  
         system("pause");  
         return -1;  
       }  
       while(fscanf(fp,"%s%s%s%s%f%f%f%f%f%f%f",person[i].name,person[i].num,person[i].sex,person[i].banji,&person[i].c,&person[i].math,&person[i].english,&person[i].PE,&person[i].politics,&person[i].all,&person[i].average)!=EOF)
        {    
             i++;
             n++;
        }
	fclose(fp) ;
    if(m=='1')  
    {  
      char s[20];  
      int i=0;  
      printf("请输入想修改的姓名:");  
      scanf("%s",s);  
      while(strcmp(person[i].name,s)!=0&&i<n) i++;//进行比较 找到所需要的信息  
        if(i==n)  
         {  
            printf("\t通讯录中没有此人!\n");  
            return 1; //若通讯录没有此人返回错误值1 
         }  
        else{  
             printf("姓名：\n");  
             scanf("%s",person[i].name);  
             printf("学号: \n");  
             scanf("%s",person[i].num);  
             printf("性别：\n");  
             scanf("%s",person[i].sex);  
             printf("班级：\n");  
             scanf("%s",person[i].banji);  
             printf("c语言 \n");  
             scanf("%f",&person[i].c);
             printf("数学：\n");  
             scanf("%f",&person[i].math);
             printf("英语：\n");  
             scanf("%f",&person[i].english);
			 printf("体育：\n");  
             scanf("%f",&person[i].PE);
			 printf("思修：\n");  
             scanf("%f",&person[i].politics);
			 person[i].all = person[i].c + person[i].english + person[i].PE + person[i].politics + person[i].math;
			 person[i].average = person[i].all/5;
			}
		remove("backup.txt");
		rename("studata.txt","backup.txt");
		fp=fopen("studata.txt","a");  //以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。
	    if(fp==NULL)                    
		{  
         printf("cannot open the files\n");  
         system("pause");  
         return -1;//如果文件出现错误返回-1  
        }  
        for(i=0;i<n;i++)  
        {
            fprintf(fp,"%s %s %s %s %f %f %f %f %f %f %f\n",person[i].name,person[i].num,person[i].sex,person[i].banji,person[i].c,person[i].math,person[i].english,person[i].PE,person[i].politics,person[i].all,person[i].average);    //以2进制形式写入文件中,一次写入一个数组  
        
        }  
        fclose(fp);  
	}  
    if(m=='2')  
      {  
      char s[20];  
      int i=0;  
      printf("请输入想修改的学号:");  
      scanf("%s",s);  
      while(strcmp(person[i].num,s)!=0&&i<n) i++;                           //进行比较 找到所需要的信息  
        if(i==n)  
         {  
            printf("\t通讯录中没有此人!\n");  
            return 1;  
         }  
        else{  
             printf("姓名：\n");  
             scanf("%s",person[i].name);  
             printf("学号: \n");  
             scanf("%s",person[i].num);  
             printf("性别：\n");  
             scanf("%s",person[i].sex);  
             printf("班级：\n");  
             scanf("%s",person[i].banji);  
             printf("c语言 \n");  
             scanf("%f",&person[i].c);
             printf("数学：\n");  
             scanf("%f",&person[i].math);
             printf("英语：\n");  
             scanf("%f",&person[i].english);
			 printf("体育：\n");  
             scanf("%f",&person[i].PE);
			 printf("思修：\n");  
             scanf("%f",&person[i].politics);
			 person[i].all = person[i].c + person[i].english + person[i].PE + person[i].politics + person[i].math;
			 person[i].average = person[i].all/5;
			}
		remove("backup.txt");
		rename("studata.txt","backup.txt");
		fp=fopen("studata.txt","a");  //以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。
	    if(fp==NULL)                    
		{  
         printf("cannot open the files\n");  
         system("pause");  
         return -1;//如果文件出现错误返回-1  
        }  
        for(i=0;i<n;i++)  
        {
            fprintf(fp,"%s %s %s %s %f %f %f %f %f %f %f\n",person[i].name,person[i].num,person[i].sex,person[i].banji,person[i].c,person[i].math,person[i].english,person[i].PE,person[i].politics,person[i].all,person[i].average);    //以2进制形式写入文件中,一次写入一个数组  
        
        }  
        fclose(fp);  
	}
    if(m = '3')
	return 0;
}

int Find()
{
	    system("cls");
        student person[200];
        FILE *fp1;  
        int i=0;
        int n=0;  
        char m;   
        printf("* * * * * * * * * * 请选择查询方式: * * * * * * * * * * *\n");  
        printf("*                                                       *\n");  
        printf("*                     1.模糊查询                        *\n");  
        printf("*                     2.姓名                            *\n");  
        printf("*                     3.学号                            *\n");  
        printf("*                     4.返回                            *\n");  
        printf("*                                                       *\n");  
        printf("*                 请输入你要查询的方式 1 - 4            *\n");
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        m = getch();  
        while(m !='1' && m !='2' && m !='3' && m !='4')  
        {  
            printf("输入错误请重新查询\n");  
            m = getch();
        }  
        if((fp1=fopen("studata.txt","rb"))==NULL)                   
        {  
            printf("cannot open the files\n");  
        }    
        while(fscanf(fp1,"%s%s%s%s%f%f%f%f%f%f%f",person[i].name,person[i].num,person[i].sex,person[i].banji,&person[i].c,&person[i].math,&person[i].english,&person[i].PE,&person[i].politics,&person[i].all,&person[i].average)!=EOF)
        {    
             i++;
             n=n+1;
        }               
        if(m=='1')//模糊查询  
        {  
            char s[3];//定义输入的文字所占的字节 （一个汉字占2个字节 外加一结尾符‘\0’此处小心溢出）  
            int i=0;  
            system("cls");  
            printf("请输入想查询的姓:\n");  
            scanf("%s",s);  
            for(i=0;i<n-1;i++)//文件信息已经读取到数组中 此处进行循环用于下一语句的查找  
        {  
  
          if(person[i].name[0]==s[0]&&person[i].name[1]==s[1])//比较person[i].name与所输入的前俩个字符是否相同  
            {  
                printf("姓名: %s\n",person[i].name);  
                printf("学号: %s\n",person[i].num);
				printf("性别: %s\n",person[i].sex);
				printf("班级: %s\n",person[i].banji);
                printf("C语言成绩: %f\n",person[i].c);  
                printf("数学成绩: %f\n",person[i].math);  
                printf("英语成绩: %f\n",person[i].english);
                printf("体育成绩: %f\n",person[i].PE);  
                printf("思修成绩: %f\n",person[i].politics); 
				printf("平均分: %f\n",person[i].average);
				printf("总分: %f\n",person[i].all);
            }
		  else
            {  
                printf("通讯录中没有此人!\n");  
                system("pause");  
                return 1;  
            }  
		}  
		}  
        if(m=='2')//姓名查询  
		{  
            char s[20];  
            int j=0;  
            printf("请输入想查询的姓名:");  
            scanf("\t%s",s);  
        while(strcmp(person[j].name,s)!=0&&j<n) j++;            //比较per[i].name与所输入姓名是否相同//  
            if(j==n)  
            {  
                printf("通讯录中没有此人!\n");  
                system("pause");  
                return -1;  
            }  
                printf("姓名: %s\n",person[j].name);  
                printf("学号: %s\n",person[j].num);
				printf("性别: %s\n",person[j].sex);
				printf("班级: %s\n",person[j].banji);
                printf("C语言成绩: %f\n",person[j].c);  
                printf("数学成绩: %f\n",person[j].math);  
                printf("英语成绩: %f\n",person[j].english);
                printf("体育成绩: %f\n",person[j].PE);  
                printf("思修成绩: %f\n",person[j].politics); 
				printf("平均分: %f\n",person[j].average);
				printf("总分: %f\n",person[j].all);
            
		}   
        if(m=='3')//学号查询  
		{  
            char s[15];  
            int i=0;  
            printf("请输入想查询的学号：");  
            scanf("\t%s",s);  
            while(strcmp(person[i].num,s)!=0&&i<n)i++; //比较person[i].name与所输入学号是否相同//                                 
            if(i==n)  
            {  
                printf("通讯录中没有此人!\n");  
                system("pause");  
                return -1;  
            }  
                printf("姓名: %s\n",person[i].name);  
                printf("学号: %s\n",person[i].num);
				printf("性别: %s\n",person[i].sex);
				printf("班级: %s\n",person[i].banji);
                printf("C语言成绩: %f\n",person[i].c);  
                printf("数学成绩: %f\n",person[i].math);  
                printf("英语成绩: %f\n",person[i].english);
                printf("体育成绩: %f\n",person[i].PE);  
                printf("思修成绩: %f\n",person[i].politics); 
				printf("平均分: %f\n",person[i].average);
				printf("总分: %f\n",person[i].all);
          }  
		if(m == '4')
		{
		    printf("您是否返回上一级菜单？y/n");
	        if(getch() == 'y')
			{
                return 0;
			}
            if(getch() == 'n')
			{    
		        system("cls");
		        return 0;
			}
		}
        fclose(fp1); 
        system("pause");
	    return 0;
}
       
int Add()
{
    system("cls");
    FILE *fp;
	int i = 0 ,n = 0;
	char select;
	student per[200];
    printf("开始输入请按下y\n");
	select = getch();
	while(select == 'y'||select == 'Y')                    
    {  
        system("cls");
		printf("* * * * * * * * * * * * * * * * * * 学生数据添加 * * * * * * * * * * * * * * * * * *\n");  
        printf("请输入姓名：     \n");  
        scanf("%s",per[i].name);  
        printf("请输入学号：     \n");  
        scanf("%s",per[i].num);
		printf("请输入性别：     \n");
		scanf("%s",per[i].sex);
		printf("请输入班级：     \n");  
        scanf("%s",per[i].banji);
        printf("请输入C语言成绩：\n");  
        scanf("%f",&per[i].c);  
        printf("请输入数学成绩： \n");  
        scanf("%f",&per[i].math);  
        printf("请输入英语成绩： \n");  
        scanf("%f",&per[i].english);
        printf("请输入体育成绩： \n");  
        scanf("%f",&per[i].PE);  
        printf("请输入思修成绩： \n");  
        scanf("%f",&per[i].politics); 
		per[i].all = per[i].c + per[i].math + per[i].english + per[i].PE + per[i].politics;
        per[i].average = (per[i].all) / 5;
        printf("是否继续添加?(y/n)");  
        select = getch(); 
        i++;  
        n=n+1;  
        system( "cls ");  
    }
	if((fp=fopen("studata.txt","a"))==NULL)                    //以2进制形式进行文件尾追加 
    {  
        printf("cannot open the files\n");  
        system("pause");  
        return -1;                                         //如果文件出现错误 就返回-1  
    }  
    for(i=0;i<n;i++)  
    {
        fprintf(fp,"%s %s %s %s %f %f %f %f %f %f %f\n",per[i].name,per[i].num,per[i].sex,per[i].banji,per[i].c,per[i].math,per[i].english,per[i].PE,per[i].politics,per[i].all,per[i].average);    //以2进制形式写入文件中,一次写入一个数组     
    }  
    fclose(fp);                                       
	system("pause");
	return 0; 
}

int Sort()
{
    system("cls");
    student person[200];
    FILE *fp;  
    struct student temp;                               //定义临时数组用于交换时存放数组信息用于后面的交换//                                          //总分  
    float s[200];  
    int i=0,n=0;  
    int j,k,t;  
    int m;  
    system("cls");  
    printf("* * * * * * * * * * 选择排序方式  * * * * * * * * * * *\n");  
    printf("*                                                     *\n");  
    printf("*                     1.c语言                         *\n");  
    printf("*                     2.数学                          *\n"); 
    printf("*                     3.英语                          *\n");  
    printf("*                     4.体育                          *\n");  
    printf("*                     5.思修                          *\n");  
    printf("*                     6.总分                          *\n");  
    printf("*                     7.返回                          *\n");  
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");  
    printf("请输入你要排序的方式\n");  
    m = getch();  
    system("cls");  
    while(m!='1'&&m!='2'&&m!='3'&&m!='4'&&m!='5'&&m!='6'&&m!='7')  
        {  
            printf("输入错误请重新输入\n");  
            m = getch(); 
        } 
	fp=fopen("studata.txt","r");//以2进制方式读取文件信息
    if(fp==NULL)                  
    {  
         printf("cannot open the files\n");  
         system("pause");  
         return -1;  
     }  
  
     while(fscanf(fp,"%s%s%s%s%f%f%f%f%f%f%f",person[i].name,person[i].num,person[i].sex,person[i].banji,&person[i].c,&person[i].math,&person[i].english,&person[i].PE,&person[i].politics,&person[i].all,&person[i].average)!=EOF)
     {    
          i++;
          n++;
     }   
    if(m=='1')  
      {  
          for(i=0;i<n;i++)//采用冒泡法进行排序 
          {  
            k=i;  
            for(j=i+1;j<n;j++)  
            if(person[j].c>person[k].c)//排序比较大小  
            k=j;
            temp=person[k];
			person[k]=person[i];
			person[i]=temp;//当符合条件时进行数据交换
            }  
            printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	        printf(" 姓名   学号     性别  班级   c语言成绩   数学成绩   英语成绩   体育成绩   思修成绩   总分      平均分\n");
            for(i=0;i<n;i++)  
            {
               			printf("%s %s %s %s %f %f %f %f %f %f %f\n",person[i].name,person[i].num,person[i].sex,person[i].banji,person[i].c,person[i].math,person[i].english,person[i].PE,person[i].politics,person[i].all,person[i].average);   
            }
                
            fclose(fp);  
        }  
  
    if(m=='2')  
      {  
        for(i=0;i<n;i++)  
         {  
              k=i;  
           for(j=i+1;j<n;j++)  
            if(person[j].math>person[k].math)  
              k=j;  
            temp=person[k];person[k]=person[i];person[i]=temp;  
          }  
            printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	        printf(" 姓名   学号     性别  班级   c语言成绩   数学成绩   英语成绩   体育成绩   思修成绩   总分      平均分\n"); 
            for(i=0;i<n;i++)  
            {
                printf("%s %s %s %s %f %f %f %f %f %f %f\n",person[i].name,person[i].num,person[i].sex,person[i].banji,person[i].c,person[i].math,person[i].english,&person[i].PE,person[i].politics,person[i].all,person[i].average);  
            }
                
            fclose(fp);  
        }
    if(m=='3')  
      {  
        for(i=0;i<n;i++)  
         {  
              k=i;  
           for(j=i+1;j<n;j++)  
            if(person[j].english>person[k].english)  
              k=j;  
            temp=person[k];person[k]=person[i];person[i]=temp;  
          }  
            printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	        printf(" 姓名   学号     性别  班级   c语言成绩   数学成绩   英语成绩   体育成绩   思修成绩   总分      平均分\n");
            for(i=0;i<n;i++)  
            {
               printf("%s %s %s %s %f %f %f %f %f %f %f\n",person[i].name,person[i].num,person[i].sex,person[i].banji,person[i].c,person[i].math,person[i].english,person[i].PE,person[i].politics,person[i].all,person[i].average);
            }
                
            fclose(fp);  
        } 
        if(m=='4')  
      {  
        for(i=0;i<n;i++)  
         {  
              k=i;  
           for(j=i+1;j<n;j++)  
            if(person[j].PE>person[k].PE)  
              k=j;  
            temp=person[k];person[k]=person[i];person[i]=temp;  
          }  
            printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	        printf(" 姓名   学号     性别  班级   c语言成绩   数学成绩   英语成绩   体育成绩   思修成绩   总分      平均分\n"); 
            for(int i=0;i<n;i++)  
            {
                 printf("%s %s %s %s %f %f %f %f %f %f %f\n",person[i].name,person[i].num,person[i].sex,person[i].banji,&person[i].c,person[i].math,person[i].english,person[i].PE,person[i].politics,person[i].all,person[i].average);
            }
                
            fclose(fp);  
        }  
    if(m=='5')  
      {  
        for(i=0;i<n;i++)  
         {  
              k=i;  
           for(j=i+1;j<n;j++)  
            if(person[j].politics>person[k].politics)  
              k=j;  
            temp=person[k];person[k]=person[i];person[i]=temp;  
          }  
            printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	        printf(" 姓名   学号     性别  班级   c语言成绩   数学成绩   英语成绩   体育成绩   思修成绩   总分      平均分\n");  
            for(i=0;i<n;i++)  
            {
                printf("%s %s %s %s %f %f %f %f %f %f %f\n",person[i].name,person[i].num,person[i].sex,person[i].banji,&person[i].c,person[i].math,person[i].english,person[i].PE,person[i].politics,person[i].all,person[i].average);
            }
                
            fclose(fp);   
        }
	    if(m=='6')  
      {  
        for(i=0;i<n;i++)  
         {  
              k=i;  
           for(j=i+1;j<n;j++)  
            if(person[j].all>person[k].all)  
              k=j;  
            temp=person[k];person[k]=person[i];person[i]=temp;  
          }  
            printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	        printf(" 姓名   学号     性别  班级   c语言成绩   数学成绩   英语成绩   体育成绩   思修成绩   总分      平均分\n"); 
            for(i=0;i<n;i++)  
            {
                printf("%s %s %s %s %f %f %f %f %f %f %f\n",person[i].name,person[i].num,person[i].sex,person[i].banji,person[i].c,person[i].math,person[i].english,person[i].PE,person[i].politics,person[i].all,person[i].average);
            }
                
            fclose(fp);   
        } 
    		if(m == '7')
		{
		        printf("您是否返回上一级菜单？y/n");
	        if(getch() == 'y')
			{
                return 0;
			}
            if(getch() == 'n')
			{    
		        system("cls");
		        return 0;
			}
		}
        fclose(fp); 
        system("pause");     
	    return 0;
}

int Delete()
{
    system("cls");
	FILE *fpold,*fpnew;
	int n ;
	int i = 0;  
	char s[20];
    printf("请输入想删除学生的姓名:");  
    scanf("%s",s); 
	linklist * headnode = (linklist*)malloc(sizeof(linklist));
	student * head = (student*)malloc(sizeof(student));
	student * tail;
	headnode->length = 0;
	headnode->next0 = head;
	fpold = fopen("studata.txt","rb");
	fpnew = fopen("tmp.txt","a");
	if(fpold==NULL)              
	{  
        printf("cannot open the files\n");  
        system("pause");  
        return -1;  
    }
	while(fscanf(fpold,"%s%s%s%s%f%f%f%f%f%f%f",head->name,head->num,head->sex,head->banji,&head->c,&head->math,&head->english,&head->PE,&head->politics,&head->all,&head->average)!=EOF)//打开保存的二进制文件将其copy到结构体
	{    
		tail = (student*)malloc(sizeof(student));
		head->next = tail;
		head = tail;
		headnode->length++;		
	}
	student * tmp;//索引指针
	student * del;//删除指针
	del = headnode->next0;
	if(!strcmp(del->name,s))
	{
		headnode->next0 = del->next;
		printf("%s",headnode->next0);
		printf("1");
		headnode->length--;
	}
	else
	{
		for(i=0;i<headnode->length;i++)  
		{
			if (del == NULL)//遍历完也没找到
			{
				printf("查无此人！\n");
			}
			else if(!strcmp(del->name,s))//找到
			{
				printf("查询到此人");
				printf("%s",tmp->name);
				printf("%s",del->name);
				tmp->next = del->next;//删除结点的前一个结点指向删除结点的后一个结点
				headnode->length--;
				break;
			}
			tmp = del;
			del = del->next;
		}
	}
	student * p;//遍历指针
	p = headnode->next0;
    for(i=0;i<headnode->length||p == NULL;i++)  
    {
        fprintf(fpnew,"%s %s %s %s %f %f %f %f %f %f %f\n",p->name,p->num,p->sex,p->banji,p->c,p->math,p->english,p->PE,p->politics,p->all,p->average);    //以2进制形式写入文件中,一次写入一个数组 
		p = p->next;		
    }
	fclose(fpold);
	fclose(fpnew);
	remove("backup.txt");
	rename("studata.txt","backup.txt");
	rename("tmp.txt","studata.txt");
	printf("删除成功");
	system("pause");                                      
	return 0;//程序正常执行返回0
}

int Undelete()
{
    system("cls");
    printf("您是否要恢复备份?y/n");
    if(getch() == 'n')
{
    return 0;
}
if(getch() == 'y')
{
    rename("studata.txt","tmp.txt");
	rename("backup.txt","studata.txt");
    rename("tmp.txt","backups.txt");
	printf("恢复成功！"); 
}
}

int main()
{
char select;
while(1)//循环执行功能菜单
{
system("cls");//清屏
printf("* * * * * * * * * * * * * * * * * * *学生成绩管理系统菜单 * * * * * * * * * * * * * * * * * * * *\n");
printf("*                                        1. 输入数据                                            *\n");
printf("*                                        2. 显示数据                                            *\n");
printf("*                                        3. 修改数据                                            *\n");
printf("*                                        4. 查找数据                                            *\n");
printf("*                                        5. 添加数据                                            *\n");
printf("*                                        6. 排序数据                                            *\n");
printf("*                                        7. 删除数据                                            *\n");
printf("*                                        8. 恢复删除                                            *\n");
printf("*                                        9. 退出                                                *\n");
printf("*                                       请选择 1 - 9                                            *\n");
printf("*                                                                                               *\n");
printf("*version:2.0                                                             Program author:moonfish*\n");
printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
select = getch();
	if(select == '9')
	{
	   printf("您真的要退出吗？y/n");
		if(getch() == 'n')
		{
	  main();
		}
		if(getch() == 'y')
		{
    printf("\n谢谢使用:)");
	exit(0);//退出程序
	}
	}
	else switch(select)
	{
	case '1': Input()    ;break;
	case '2': Display()  ;break;
	case '3': Modify()   ;break;
	case '4': Find()     ;break;
	case '5': Add()      ;break;
	case '6': Sort()     ;break;
	case '7': Delete()   ;break;
	case '8': Undelete() ;break;
	}
}
return 0 ;
}
