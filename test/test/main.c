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

	num++;   //��ϵ����������

	printf("��¼��������\n");

	scanf("%s",stu[num].name);

	printf("��¼��绰���룺\n");

	scanf("%s",stu[num].phonenumber);

	printf("��¼���ַ��\n");

	scanf("%s",stu[num].address);

	printf("�Ƿ������ӣ�������1��������0��\n");

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

	printf("������Ҫ���ҵ�����\n");

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

        printf("�޴�����Ϣ��\n");

	}



}



void searchphonenumber(int num)

{

	int i;

	char phone0[11];

	printf("������Ҫ���ҵĺ���\n");

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

        printf("�޴�����Ϣ��\n");

	}



}



void searchaddress(int num)

{

	int i;

	char address0[30];

	printf("������Ҫ���ҵĵ�ַ\n");

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

        printf("�޴�����Ϣ��\n");

	}



}



void deletename(int num)

{

	char name0[20];

	int i;

	int m;

	int a;

	printf("��������Ҫɾ�����˵�������\n");

	scanf("%s",name0);

	for(i=0;i<num;i++)

	{

		if(strcmp(name0,stu[i].name)==0)

		{

		printf("name: %s\n",stu[i].name);

		printf("phonenumber: %s\n",stu[i].phonenumber);

		printf("address: %s\n",stu[i].address);

		printf("�������Ƿ���Ҫɾ����������1��������0��\n");

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

        printf("�޴�����Ϣ��\n");

	}



}



void deletephonenumber(int num)

{

	char phone0[11];

	int i;

	int m;

	int a;

	printf("��������Ҫɾ�����˵ĺ��롣\n");

	scanf("%s",phone0);

	for(i=0;i<num;i++)

	{

		if(strcmp(phone0,stu[i].phonenumber)==0)

		{

		printf("name: %s\n",stu[i].name);

		printf("phonenumber: %s\n",stu[i].phonenumber);

		printf("address: %s\n",stu[i].address);

		printf("�������Ƿ���Ҫɾ����������1��������0��\n");

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

        printf("�޴�����Ϣ��\n");

	}



}



void deleteaddress(int num)

{

	char address0[30];

	int i;

	int m;

	int a;

	printf("��������Ҫɾ�����˵ĵ�ַ��\n");

	scanf("%s",address0);

	for(i=0;i<num;i++)

	{

		if(strcmp(address0,stu[i].address)==0)

		{

		printf("name: %s\n",stu[i].name);

		printf("phonenumber: %s\n",stu[i].phonenumber);

		printf("address: %s\n",stu[i].address);

		printf("�������Ƿ���Ҫɾ����������1��������0��\n");

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

        printf("�޴�����Ϣ��\n");

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

    printf("�޴�����Ϣ\n");





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

    printf("�޴�����Ϣ\n");



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

    printf("�޴�����Ϣ\n");



}

int main(void)

{

	printf("��ӭʹ�õ绰��ϵͳ��\n");

	printf("    **************************************\n");

	printf("    1.¼��\n");

	printf("    2.����\n");

	printf("    3.ɾ��\n");

	printf("    4.�޸�\n");

	printf("    **************************************\n");

	printf("��������Ҫ���еĲ�������Ӧ����ţ�");

	char ch1,ch2,ch3,ch4,ch5;

	int n=0;

		scanf("%c",&ch1);

	switch(ch1)

	{

		case'1':printf("�����¼�������\n");

		n=add(n);

	    break;

		case'2':printf("����в��Ҳ���:\n");

		printf("1.����������\n");

		printf("2.����ַ����\n");

		printf("3.���绰������в���\n");

		scanf("%c",&ch2);

		switch(ch2)

		{

			case'1':printf("����������:");

			searchname(n);

			break;

			case'2':printf("�������ַ:");

			searchaddress(n);

			break;

			case'3':printf("������绰���룺");

			searchphonenumber(n);

			break;

			default:printf("error!");

		}

	    break;

		case'3':printf("�����ɾ��������\n");

		printf("1.������ɾ��\n");

		printf("2.����ַɾ��\n");

		printf("3.���绰�������ɾ��\n");

		scanf("%c",&ch3);

		switch(ch3)

		{

			case'1':printf("����������:");

			deletename(n);

			break;

			case'2':printf("�������ַ:");

			deleteaddress(n);

			break;

			case'3':printf("������绰���룺");

			deletephonenumber(n);

			break;

			default:printf("error!");

		}

		break;

		case'4':printf("������޸Ĳ���:\n");

		printf("�밴����ʾ������Ϣ��\n");

		printf("1.����������\n");

		printf("2.����ַ����\n");

		printf("3.���绰������в���\n");

		scanf("%c",&ch4);

		switch(ch4)

		{

			case'1':printf("����������:");

			searchname(n);

			break;

			case'2':printf("�������ַ:");

			searchaddress(n);

			break;

			case'3':printf("������绰���룺");

			searchphonenumber(n);

			break;

			default:printf("error!");

		}

		break;

		printf("��ѡ����Ҫ�޸ĵ���Ŀ��\n");

		printf("1.�޸�����\n");

		printf("2.�޸ĵ�ַ\n");

		printf("3.�޸ĵ绰����\n");

		scanf("%c",&ch5);

		switch(ch5)

		{

			case'1':printf("�������µ�����:");

			changename(n);

			break;

			case'2':printf("�������µĵ�ַ:");

			changeaddress(n);

			break;

			case'3':printf("�������µĵ绰���룺");

			changephonenumber(n);

			break;

			default:printf("error!");

		}

		break;

		break;





 }

	return 0;

}



