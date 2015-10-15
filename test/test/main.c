#include<stdio.h>

#include <string.h>

struct student stu[10];

struct student{

	char name[20];

	char phonenumber[11];

	char address[30];

};



int add(int num)

{   int a;

	num++;   //联系人总数增加

	printf("请录入姓名：\n");

	scanf("%s",stu[num].name);

	printf("请录入电话号码：\n");

	scanf("%s",stu[num].phonenumber);

	printf("请录入地址：\n");

	scanf("%s",stu[num].address);

	printf("是否结束添加？是输入1，否输入0。\n");

	scanf("%d",&a);

	if(a==1)

    printf("success\n");

    else

    add(num);

    return num;

}



void searchname(int num)

{

	int i;

	char name0[20];

	printf("输入需要查找的姓名\n");

	scanf("%s",name0);

	for(i=0;i<num;i++)

	{

		if(strcmp(name0,stu[i].name)==0)

		{

		printf("name: %s\n",stu[i].name);

		printf("phonenumber: %s\n",stu[i].phonenumber);

		printf("address: %s\n",stu[i].address);

		}

		else

        printf("无此人信息。\n");

	}



}



void searchphonenumber(int num)

{

	int i;

	char phone0[11];

	printf("输入需要查找的号码\n");

	scanf("%s",phone0);

	for(i=0;i<num;i++)

	{

		if(strcmp(phone0,stu[i].phonenumber)==0)

		{

		printf("name: %s\n",stu[i].name);

		printf("phonenumber: %s\n",stu[i].phonenumber);

		printf("address: %s\n",stu[i].address);

		}

		else

        printf("无此人信息。\n");

	}



}



void searchaddress(int num)

{

	int i;

	char address0[30];

	printf("输入需要查找的地址\n");

	scanf("%s",address0);

	for(i=0;i<num;i++)

	{

		if(strcmp(address0,stu[i].address)==0)

		{

		printf("name: %s\n",stu[i].name);

		printf("phonenumber: %s\n",stu[i].phonenumber);

		printf("address: %s\n",stu[i].address);

		}

		else

        printf("无此人信息。\n");

	}



}



void deletename(int num)

{

	char name0[20];

	int i;

	int m;

	int a;

	printf("请输入需要删除的人的姓名。\n");

	scanf("%s",name0);

	for(i=0;i<num;i++)

	{

		if(strcmp(name0,stu[i].name)==0)

		{

		printf("name: %s\n",stu[i].name);

		printf("phonenumber: %s\n",stu[i].phonenumber);

		printf("address: %s\n",stu[i].address);

		printf("请问您是否需要删除？是输入1，否输入0。\n");

		if(a==1)

		{

		for(m=i;m<num-1;m++)

		stu[m]=stu[m+1];

		num--;

		printf("success!\n");

		}

		else

		break;

		}

		else

        printf("无此人信息。\n");

	}



}



void deletephonenumber(int num)

{

	char phone0[11];

	int i;

	int m;

	int a;

	printf("请输入需要删除的人的号码。\n");

	scanf("%s",phone0);

	for(i=0;i<num;i++)

	{

		if(strcmp(phone0,stu[i].phonenumber)==0)

		{

		printf("name: %s\n",stu[i].name);

		printf("phonenumber: %s\n",stu[i].phonenumber);

		printf("address: %s\n",stu[i].address);

		printf("请问您是否需要删除？是输入1，否输入0。\n");

		if(a==1)

		{

		for(m=i;m<num-1;m++)

		stu[m]=stu[m+1];

		num--;

		printf("success!\n");

		}

		else

		break;

		}

		else

        printf("无此人信息。\n");

	}



}



void deleteaddress(int num)

{

	char address0[30];

	int i;

	int m;

	int a;

	printf("请输入需要删除的人的地址。\n");

	scanf("%s",address0);

	for(i=0;i<num;i++)

	{

		if(strcmp(address0,stu[i].address)==0)

		{

		printf("name: %s\n",stu[i].name);

		printf("phonenumber: %s\n",stu[i].phonenumber);

		printf("address: %s\n",stu[i].address);

		printf("请问您是否需要删除？是输入1，否输入0。\n");

		if(a==1)

		{

		for(m=i;m<num-1;m++)

		stu[m]=stu[m+1];

		num--;

		printf("success!\n");

		}

		else

		break;

		}

		else

        printf("无此人信息。\n");

	}



}

void changename(int num)

{

	char name0[20];

	scanf("%c",name0);

	int i=0,m=0;

	for(i=0;i<=num;i++)

	if(strcmp(stu[i].name,name0)==0)

{

	for(m=0;m<20;m++)

	stu[i].name[m]=name0[m];

}	else

    printf("无此人信息\n");





}

void changeaddress(int num)

{

	char address0[30];

	scanf("%c",address0);

	int i=0,m=0;

	for(i=0;i<=num;i++)

	if(strcmp(stu[i].address,address0)==0)

{

	for(m=0;m<30;m++)

	stu[i].address[m]=address0[m];

}	else

    printf("无此人信息\n");



}

void changephonenumber(int num)

{

	char phonenumber0[11];

	scanf("%c",phonenumber0);

	int i=0,m=0;

	for(i=0;i<=num;i++)

	if(strcmp(stu[i].phonenumber,phonenumber0)==0)

	{

	for(m=0;m<11;m++)

	stu[i].phonenumber[m]=phonenumber0[m];

}	else

    printf("无此人信息\n");



}

int main(void)

{

	printf("欢迎使用电话本系统！\n");

	printf("    **************************************\n");

	printf("    1.录入\n");

	printf("    2.查找\n");

	printf("    3.删除\n");

	printf("    4.修改\n");

	printf("    **************************************\n");

	printf("请输入需要进行的操作所对应的序号：");

	char ch1,ch2,ch3,ch4,ch5;

	int n=0;

		scanf("%c",&ch1);

	switch(ch1)

	{

		case'1':printf("请进行录入操作：\n");

		n=add(n);

	    break;

		case'2':printf("请进行查找操作:\n");

		printf("1.按姓名查找\n");

		printf("2.按地址查找\n");

		printf("3.按电话号码进行查找\n");

		scanf("%c",&ch2);

		switch(ch2)

		{

			case'1':printf("请输入姓名:");

			searchname(n);

			break;

			case'2':printf("请输入地址:");

			searchaddress(n);

			break;

			case'3':printf("请输入电话号码：");

			searchphonenumber(n);

			break;

			default:printf("error!");

		}

	    break;

		case'3':printf("请进行删除操作：\n");

		printf("1.按姓名删除\n");

		printf("2.按地址删除\n");

		printf("3.按电话号码进行删除\n");

		scanf("%c",&ch3);

		switch(ch3)

		{

			case'1':printf("请输入姓名:");

			deletename(n);

			break;

			case'2':printf("请输入地址:");

			deleteaddress(n);

			break;

			case'3':printf("请输入电话号码：");

			deletephonenumber(n);

			break;

			default:printf("error!");

		}

		break;

		case'4':printf("请进行修改操作:\n");

		printf("请按照提示查找信息：\n");

		printf("1.按姓名查找\n");

		printf("2.按地址查找\n");

		printf("3.按电话号码进行查找\n");

		scanf("%c",&ch4);

		switch(ch4)

		{

			case'1':printf("请输入姓名:");

			searchname(n);

			break;

			case'2':printf("请输入地址:");

			searchaddress(n);

			break;

			case'3':printf("请输入电话号码：");

			searchphonenumber(n);

			break;

			default:printf("error!");

		}

		break;

		printf("请选择需要修改的项目：\n");

		printf("1.修改姓名\n");

		printf("2.修改地址\n");

		printf("3.修改电话号码\n");

		scanf("%c",&ch5);

		switch(ch5)

		{

			case'1':printf("请输入新的姓名:");

			changename(n);

			break;

			case'2':printf("请输入新的地址:");

			changeaddress(n);

			break;

			case'3':printf("请输入新的电话号码：");

			changephonenumber(n);

			break;

			default:printf("error!");

		}

		break;

		break;





 }

	return 0;

}



