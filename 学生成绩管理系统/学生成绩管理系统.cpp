#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct student                        
{  
    char num[20];   //ѧ��  
    char name[20];  //���� 
	char sex[5];    //�Ա�
	char banji[20]; //�༶
    float c;        //C���Գɼ�  
    float math;     //��ѧ�ɼ�  
    float english;  //Ӣ��ɼ�
    float PE;       //�����ɼ�  
    float politics; //˼�޳ɼ�  
	float all;      //�ܷ�
	float average;  //ƽ����
    student * next; //ָ����
}student;  

//����ͷ���
typedef struct linklist
{
    student * next0;        //ͷָ��
    int length;         //����ĳ��ȣ���ʼֵΪ0
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
    printf("��ʼ�����밴��y\n");
	select = getch();
	if(select == 'y'||select == 'Y')                     
      {  
		tail = (student * )malloc(sizeof(student));
		system ("cls");
		printf("* * * * * * * * * * * * * * * * * * ѧ���������� * * * * * * * * * * * * * * * * * *\n");  
        printf("������������     \n");  
        scanf("%s",tail->name);  
        printf("������ѧ�ţ�     \n");  
        scanf("%s",tail->num);
		printf("�������Ա�     \n");
		scanf("%s",tail->sex);
		printf("������༶��     \n");  
        scanf("%s",tail->banji);
        printf("������C���Գɼ���\n");  
        scanf("%f",&tail->c);  
        printf("��������ѧ�ɼ��� \n");  
        scanf("%f",&tail->math);  
        printf("������Ӣ��ɼ��� \n");  
        scanf("%f",&tail->english);
        printf("�����������ɼ��� \n");  
        scanf("%f",&tail->PE);  
        printf("������˼�޳ɼ��� \n");  
        scanf("%f",&tail->politics); 
		tail->all = tail->c + tail->math + tail->english + tail->PE + tail->politics;
        tail->average = (tail->all) / 5;
		head->next0 = tail;
		head->length++;
        system( "cls ");  
    }
	printf("�Ƿ�������?(y/n)");  
    select = getch();
	student * node = NULL;
	while(select == 'y'||select == 'Y')                     
    {  
		node = tail;
		tail = (student * )malloc(sizeof(student));
		system ("cls");
		printf("* * * * * * * * * * * * * * * * * * ѧ���������� * * * * * * * * * * * * * * * * * *\n");  
        printf("������������     \n");  
        scanf("%s",tail->name);  
        printf("������ѧ�ţ�     \n");  
        scanf("%s",tail->num);
		printf("�������Ա�     \n");
		scanf("%s",tail->sex);
		printf("������༶��     \n");  
        scanf("%s",tail->banji);
        printf("������C���Գɼ���\n");  
        scanf("%f",&tail->c);  
        printf("��������ѧ�ɼ��� \n");  
        scanf("%f",&tail->math);  
        printf("������Ӣ��ɼ��� \n");  
        scanf("%f",&tail->english);
        printf("�����������ɼ��� \n");  
        scanf("%f",&tail->PE);  
        printf("������˼�޳ɼ��� \n");  
        scanf("%f",&tail->politics); 
		tail->all = tail->c + tail->math + tail->english + tail->PE + tail->politics;
        tail->average = (tail->all) / 5;
		node->next = tail;
		node = tail;
		head->length++;
        printf("�Ƿ�������?(y/n)");  
    	select = getch();
        system( "cls ");  
    }
	node = NULL;
	fp=fopen("studata.txt","a");  //�Ը��ӵķ�ʽ��ֻд�ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ�д������ݻᱻ�ӵ��ļ�β�����ļ�ԭ�ȵ����ݻᱻ������
	if(fp==NULL)                    
    {  
        printf("cannot open the files\n");  
        system("pause");  
        return -1;//����ļ����ִ��󷵻�-1  
    }
	student * p;//����ָ��
	p = head->next0;
    for(i=0;i<head->length||p == NULL;i++)  
    {
        fprintf(fp,"%s %s %s %s %f %f %f %f %f %f %f\n",p->name,p->num,p->sex,p->banji,p->c,p->math,p->english,p->PE,p->politics,p->all,p->average);    //��2������ʽд���ļ���,һ��д��һ������ 
		p = p->next;		
    }  
    fclose(fp);                                       
	system("pause");
	return 0;//��������ִ�з���0
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
	printf(" ����   ѧ��     �Ա�  �༶   c���Գɼ�   ��ѧ�ɼ�   Ӣ��ɼ�   �����ɼ�   ˼�޳ɼ�   �ܷ�      ƽ����\n");
	while(fscanf(fp,"%s%s%s%s%f%f%f%f%f%f%f",head->name,head->num,head->sex,head->banji,&head->c,&head->math,&head->english,&head->PE,&head->politics,&head->all,&head->average)!=EOF)//�򿪱���Ķ������ļ�����copy���ṹ��
	{    
		tail = (student*)malloc(sizeof(student));
		head->next = tail;
		printf("%s %s %s %s %f %f %f %f %f %f %f",head->name,head->num,head->sex,head->banji,head->c,head->math,head->english,head->PE,head->politics,head->all,head->average);//���ṹ�����
		head = tail;
		headnode->length++;
		printf("\n");
		
	}
	fclose(fp);
	system("pause");
    printf("���Ƿ񷵻���һ���˵���y/n");
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
    printf("* * * * * * * * * * ��ѡ���ѯ��ʽ  * * * * * * * * * *\n");  
    printf("*                                                     *\n");  
    printf("*                       1.����                        *\n");  
    printf("*                       2.ѧ��                        *\n");  
    printf("*                       3.����                        *\n");  
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");  
    printf("��������Ҫ�޸ĵķ�ʽ\n");  
    m = getch(); 
    while(m!='1'&&m!='2'&&m!='3')  
        {  
            printf("��������������޸�\n");  
            m = getch(); 
        }  
     if((fp=fopen("studata.txt","r"))==NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ������ж�ָ���Ƿ�ָ��һ����Ч�ļ�  
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
      printf("���������޸ĵ�����:");  
      scanf("%s",s);  
      while(strcmp(person[i].name,s)!=0&&i<n) i++;//���бȽ� �ҵ�����Ҫ����Ϣ  
        if(i==n)  
         {  
            printf("\tͨѶ¼��û�д���!\n");  
            return 1; //��ͨѶ¼û�д��˷��ش���ֵ1 
         }  
        else{  
             printf("������\n");  
             scanf("%s",person[i].name);  
             printf("ѧ��: \n");  
             scanf("%s",person[i].num);  
             printf("�Ա�\n");  
             scanf("%s",person[i].sex);  
             printf("�༶��\n");  
             scanf("%s",person[i].banji);  
             printf("c���� \n");  
             scanf("%f",&person[i].c);
             printf("��ѧ��\n");  
             scanf("%f",&person[i].math);
             printf("Ӣ�\n");  
             scanf("%f",&person[i].english);
			 printf("������\n");  
             scanf("%f",&person[i].PE);
			 printf("˼�ޣ�\n");  
             scanf("%f",&person[i].politics);
			 person[i].all = person[i].c + person[i].english + person[i].PE + person[i].politics + person[i].math;
			 person[i].average = person[i].all/5;
			}
		remove("backup.txt");
		rename("studata.txt","backup.txt");
		fp=fopen("studata.txt","a");  //�Ը��ӵķ�ʽ��ֻд�ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ�д������ݻᱻ�ӵ��ļ�β�����ļ�ԭ�ȵ����ݻᱻ������
	    if(fp==NULL)                    
		{  
         printf("cannot open the files\n");  
         system("pause");  
         return -1;//����ļ����ִ��󷵻�-1  
        }  
        for(i=0;i<n;i++)  
        {
            fprintf(fp,"%s %s %s %s %f %f %f %f %f %f %f\n",person[i].name,person[i].num,person[i].sex,person[i].banji,person[i].c,person[i].math,person[i].english,person[i].PE,person[i].politics,person[i].all,person[i].average);    //��2������ʽд���ļ���,һ��д��һ������  
        
        }  
        fclose(fp);  
	}  
    if(m=='2')  
      {  
      char s[20];  
      int i=0;  
      printf("���������޸ĵ�ѧ��:");  
      scanf("%s",s);  
      while(strcmp(person[i].num,s)!=0&&i<n) i++;                           //���бȽ� �ҵ�����Ҫ����Ϣ  
        if(i==n)  
         {  
            printf("\tͨѶ¼��û�д���!\n");  
            return 1;  
         }  
        else{  
             printf("������\n");  
             scanf("%s",person[i].name);  
             printf("ѧ��: \n");  
             scanf("%s",person[i].num);  
             printf("�Ա�\n");  
             scanf("%s",person[i].sex);  
             printf("�༶��\n");  
             scanf("%s",person[i].banji);  
             printf("c���� \n");  
             scanf("%f",&person[i].c);
             printf("��ѧ��\n");  
             scanf("%f",&person[i].math);
             printf("Ӣ�\n");  
             scanf("%f",&person[i].english);
			 printf("������\n");  
             scanf("%f",&person[i].PE);
			 printf("˼�ޣ�\n");  
             scanf("%f",&person[i].politics);
			 person[i].all = person[i].c + person[i].english + person[i].PE + person[i].politics + person[i].math;
			 person[i].average = person[i].all/5;
			}
		remove("backup.txt");
		rename("studata.txt","backup.txt");
		fp=fopen("studata.txt","a");  //�Ը��ӵķ�ʽ��ֻд�ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ�д������ݻᱻ�ӵ��ļ�β�����ļ�ԭ�ȵ����ݻᱻ������
	    if(fp==NULL)                    
		{  
         printf("cannot open the files\n");  
         system("pause");  
         return -1;//����ļ����ִ��󷵻�-1  
        }  
        for(i=0;i<n;i++)  
        {
            fprintf(fp,"%s %s %s %s %f %f %f %f %f %f %f\n",person[i].name,person[i].num,person[i].sex,person[i].banji,person[i].c,person[i].math,person[i].english,person[i].PE,person[i].politics,person[i].all,person[i].average);    //��2������ʽд���ļ���,һ��д��һ������  
        
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
        printf("* * * * * * * * * * ��ѡ���ѯ��ʽ: * * * * * * * * * * *\n");  
        printf("*                                                       *\n");  
        printf("*                     1.ģ����ѯ                        *\n");  
        printf("*                     2.����                            *\n");  
        printf("*                     3.ѧ��                            *\n");  
        printf("*                     4.����                            *\n");  
        printf("*                                                       *\n");  
        printf("*                 ��������Ҫ��ѯ�ķ�ʽ 1 - 4            *\n");
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        m = getch();  
        while(m !='1' && m !='2' && m !='3' && m !='4')  
        {  
            printf("������������²�ѯ\n");  
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
        if(m=='1')//ģ����ѯ  
        {  
            char s[3];//���������������ռ���ֽ� ��һ������ռ2���ֽ� ���һ��β����\0���˴�С�������  
            int i=0;  
            system("cls");  
            printf("���������ѯ����:\n");  
            scanf("%s",s);  
            for(i=0;i<n-1;i++)//�ļ���Ϣ�Ѿ���ȡ�������� �˴�����ѭ��������һ���Ĳ���  
        {  
  
          if(person[i].name[0]==s[0]&&person[i].name[1]==s[1])//�Ƚ�person[i].name���������ǰ�����ַ��Ƿ���ͬ  
            {  
                printf("����: %s\n",person[i].name);  
                printf("ѧ��: %s\n",person[i].num);
				printf("�Ա�: %s\n",person[i].sex);
				printf("�༶: %s\n",person[i].banji);
                printf("C���Գɼ�: %f\n",person[i].c);  
                printf("��ѧ�ɼ�: %f\n",person[i].math);  
                printf("Ӣ��ɼ�: %f\n",person[i].english);
                printf("�����ɼ�: %f\n",person[i].PE);  
                printf("˼�޳ɼ�: %f\n",person[i].politics); 
				printf("ƽ����: %f\n",person[i].average);
				printf("�ܷ�: %f\n",person[i].all);
            }
		  else
            {  
                printf("ͨѶ¼��û�д���!\n");  
                system("pause");  
                return 1;  
            }  
		}  
		}  
        if(m=='2')//������ѯ  
		{  
            char s[20];  
            int j=0;  
            printf("���������ѯ������:");  
            scanf("\t%s",s);  
        while(strcmp(person[j].name,s)!=0&&j<n) j++;            //�Ƚ�per[i].name�������������Ƿ���ͬ//  
            if(j==n)  
            {  
                printf("ͨѶ¼��û�д���!\n");  
                system("pause");  
                return -1;  
            }  
                printf("����: %s\n",person[j].name);  
                printf("ѧ��: %s\n",person[j].num);
				printf("�Ա�: %s\n",person[j].sex);
				printf("�༶: %s\n",person[j].banji);
                printf("C���Գɼ�: %f\n",person[j].c);  
                printf("��ѧ�ɼ�: %f\n",person[j].math);  
                printf("Ӣ��ɼ�: %f\n",person[j].english);
                printf("�����ɼ�: %f\n",person[j].PE);  
                printf("˼�޳ɼ�: %f\n",person[j].politics); 
				printf("ƽ����: %f\n",person[j].average);
				printf("�ܷ�: %f\n",person[j].all);
            
		}   
        if(m=='3')//ѧ�Ų�ѯ  
		{  
            char s[15];  
            int i=0;  
            printf("���������ѯ��ѧ�ţ�");  
            scanf("\t%s",s);  
            while(strcmp(person[i].num,s)!=0&&i<n)i++; //�Ƚ�person[i].name��������ѧ���Ƿ���ͬ//                                 
            if(i==n)  
            {  
                printf("ͨѶ¼��û�д���!\n");  
                system("pause");  
                return -1;  
            }  
                printf("����: %s\n",person[i].name);  
                printf("ѧ��: %s\n",person[i].num);
				printf("�Ա�: %s\n",person[i].sex);
				printf("�༶: %s\n",person[i].banji);
                printf("C���Գɼ�: %f\n",person[i].c);  
                printf("��ѧ�ɼ�: %f\n",person[i].math);  
                printf("Ӣ��ɼ�: %f\n",person[i].english);
                printf("�����ɼ�: %f\n",person[i].PE);  
                printf("˼�޳ɼ�: %f\n",person[i].politics); 
				printf("ƽ����: %f\n",person[i].average);
				printf("�ܷ�: %f\n",person[i].all);
          }  
		if(m == '4')
		{
		    printf("���Ƿ񷵻���һ���˵���y/n");
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
    printf("��ʼ�����밴��y\n");
	select = getch();
	while(select == 'y'||select == 'Y')                    
    {  
        system("cls");
		printf("* * * * * * * * * * * * * * * * * * ѧ��������� * * * * * * * * * * * * * * * * * *\n");  
        printf("������������     \n");  
        scanf("%s",per[i].name);  
        printf("������ѧ�ţ�     \n");  
        scanf("%s",per[i].num);
		printf("�������Ա�     \n");
		scanf("%s",per[i].sex);
		printf("������༶��     \n");  
        scanf("%s",per[i].banji);
        printf("������C���Գɼ���\n");  
        scanf("%f",&per[i].c);  
        printf("��������ѧ�ɼ��� \n");  
        scanf("%f",&per[i].math);  
        printf("������Ӣ��ɼ��� \n");  
        scanf("%f",&per[i].english);
        printf("�����������ɼ��� \n");  
        scanf("%f",&per[i].PE);  
        printf("������˼�޳ɼ��� \n");  
        scanf("%f",&per[i].politics); 
		per[i].all = per[i].c + per[i].math + per[i].english + per[i].PE + per[i].politics;
        per[i].average = (per[i].all) / 5;
        printf("�Ƿ�������?(y/n)");  
        select = getch(); 
        i++;  
        n=n+1;  
        system( "cls ");  
    }
	if((fp=fopen("studata.txt","a"))==NULL)                    //��2������ʽ�����ļ�β׷�� 
    {  
        printf("cannot open the files\n");  
        system("pause");  
        return -1;                                         //����ļ����ִ��� �ͷ���-1  
    }  
    for(i=0;i<n;i++)  
    {
        fprintf(fp,"%s %s %s %s %f %f %f %f %f %f %f\n",per[i].name,per[i].num,per[i].sex,per[i].banji,per[i].c,per[i].math,per[i].english,per[i].PE,per[i].politics,per[i].all,per[i].average);    //��2������ʽд���ļ���,һ��д��һ������     
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
    struct student temp;                               //������ʱ�������ڽ���ʱ���������Ϣ���ں���Ľ���//                                          //�ܷ�  
    float s[200];  
    int i=0,n=0;  
    int j,k,t;  
    int m;  
    system("cls");  
    printf("* * * * * * * * * * ѡ������ʽ  * * * * * * * * * * *\n");  
    printf("*                                                     *\n");  
    printf("*                     1.c����                         *\n");  
    printf("*                     2.��ѧ                          *\n"); 
    printf("*                     3.Ӣ��                          *\n");  
    printf("*                     4.����                          *\n");  
    printf("*                     5.˼��                          *\n");  
    printf("*                     6.�ܷ�                          *\n");  
    printf("*                     7.����                          *\n");  
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");  
    printf("��������Ҫ����ķ�ʽ\n");  
    m = getch();  
    system("cls");  
    while(m!='1'&&m!='2'&&m!='3'&&m!='4'&&m!='5'&&m!='6'&&m!='7')  
        {  
            printf("�����������������\n");  
            m = getch(); 
        } 
	fp=fopen("studata.txt","r");//��2���Ʒ�ʽ��ȡ�ļ���Ϣ
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
          for(i=0;i<n;i++)//����ð�ݷ��������� 
          {  
            k=i;  
            for(j=i+1;j<n;j++)  
            if(person[j].c>person[k].c)//����Ƚϴ�С  
            k=j;
            temp=person[k];
			person[k]=person[i];
			person[i]=temp;//����������ʱ�������ݽ���
            }  
            printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	        printf(" ����   ѧ��     �Ա�  �༶   c���Գɼ�   ��ѧ�ɼ�   Ӣ��ɼ�   �����ɼ�   ˼�޳ɼ�   �ܷ�      ƽ����\n");
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
	        printf(" ����   ѧ��     �Ա�  �༶   c���Գɼ�   ��ѧ�ɼ�   Ӣ��ɼ�   �����ɼ�   ˼�޳ɼ�   �ܷ�      ƽ����\n"); 
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
	        printf(" ����   ѧ��     �Ա�  �༶   c���Գɼ�   ��ѧ�ɼ�   Ӣ��ɼ�   �����ɼ�   ˼�޳ɼ�   �ܷ�      ƽ����\n");
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
	        printf(" ����   ѧ��     �Ա�  �༶   c���Գɼ�   ��ѧ�ɼ�   Ӣ��ɼ�   �����ɼ�   ˼�޳ɼ�   �ܷ�      ƽ����\n"); 
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
	        printf(" ����   ѧ��     �Ա�  �༶   c���Գɼ�   ��ѧ�ɼ�   Ӣ��ɼ�   �����ɼ�   ˼�޳ɼ�   �ܷ�      ƽ����\n");  
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
	        printf(" ����   ѧ��     �Ա�  �༶   c���Գɼ�   ��ѧ�ɼ�   Ӣ��ɼ�   �����ɼ�   ˼�޳ɼ�   �ܷ�      ƽ����\n"); 
            for(i=0;i<n;i++)  
            {
                printf("%s %s %s %s %f %f %f %f %f %f %f\n",person[i].name,person[i].num,person[i].sex,person[i].banji,person[i].c,person[i].math,person[i].english,person[i].PE,person[i].politics,person[i].all,person[i].average);
            }
                
            fclose(fp);   
        } 
    		if(m == '7')
		{
		        printf("���Ƿ񷵻���һ���˵���y/n");
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
    printf("��������ɾ��ѧ��������:");  
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
	while(fscanf(fpold,"%s%s%s%s%f%f%f%f%f%f%f",head->name,head->num,head->sex,head->banji,&head->c,&head->math,&head->english,&head->PE,&head->politics,&head->all,&head->average)!=EOF)//�򿪱���Ķ������ļ�����copy���ṹ��
	{    
		tail = (student*)malloc(sizeof(student));
		head->next = tail;
		head = tail;
		headnode->length++;		
	}
	student * tmp;//����ָ��
	student * del;//ɾ��ָ��
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
			if (del == NULL)//������Ҳû�ҵ�
			{
				printf("���޴��ˣ�\n");
			}
			else if(!strcmp(del->name,s))//�ҵ�
			{
				printf("��ѯ������");
				printf("%s",tmp->name);
				printf("%s",del->name);
				tmp->next = del->next;//ɾ������ǰһ�����ָ��ɾ�����ĺ�һ�����
				headnode->length--;
				break;
			}
			tmp = del;
			del = del->next;
		}
	}
	student * p;//����ָ��
	p = headnode->next0;
    for(i=0;i<headnode->length||p == NULL;i++)  
    {
        fprintf(fpnew,"%s %s %s %s %f %f %f %f %f %f %f\n",p->name,p->num,p->sex,p->banji,p->c,p->math,p->english,p->PE,p->politics,p->all,p->average);    //��2������ʽд���ļ���,һ��д��һ������ 
		p = p->next;		
    }
	fclose(fpold);
	fclose(fpnew);
	remove("backup.txt");
	rename("studata.txt","backup.txt");
	rename("tmp.txt","studata.txt");
	printf("ɾ���ɹ�");
	system("pause");                                      
	return 0;//��������ִ�з���0
}

int Undelete()
{
    system("cls");
    printf("���Ƿ�Ҫ�ָ�����?y/n");
    if(getch() == 'n')
{
    return 0;
}
if(getch() == 'y')
{
    rename("studata.txt","tmp.txt");
	rename("backup.txt","studata.txt");
    rename("tmp.txt","backups.txt");
	printf("�ָ��ɹ���"); 
}
}

int main()
{
char select;
while(1)//ѭ��ִ�й��ܲ˵�
{
system("cls");//����
printf("* * * * * * * * * * * * * * * * * * *ѧ���ɼ�����ϵͳ�˵� * * * * * * * * * * * * * * * * * * * *\n");
printf("*                                        1. ��������                                            *\n");
printf("*                                        2. ��ʾ����                                            *\n");
printf("*                                        3. �޸�����                                            *\n");
printf("*                                        4. ��������                                            *\n");
printf("*                                        5. �������                                            *\n");
printf("*                                        6. ��������                                            *\n");
printf("*                                        7. ɾ������                                            *\n");
printf("*                                        8. �ָ�ɾ��                                            *\n");
printf("*                                        9. �˳�                                                *\n");
printf("*                                       ��ѡ�� 1 - 9                                            *\n");
printf("*                                                                                               *\n");
printf("*version:2.0                                                             Program author:moonfish*\n");
printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
select = getch();
	if(select == '9')
	{
	   printf("�����Ҫ�˳���y/n");
		if(getch() == 'n')
		{
	  main();
		}
		if(getch() == 'y')
		{
    printf("\nллʹ��:)");
	exit(0);//�˳�����
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
