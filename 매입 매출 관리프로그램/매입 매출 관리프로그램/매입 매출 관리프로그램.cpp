// ���� ���� �������α׷�.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>


int money = 10000;
int sellprice = 500;
int restment_quantity = 0;

int main()
{
	struct customer {
		char name[20];
		int age;
		int birthday;
		int phonenumber;
		int bought;
		int perchased;
	}arr_c[10];

	struct factory {
		char name[20];
		int price;
	}arr_f[3];

	int temp;
	printf("�����׸� �Է�(������:1,����ó����:2,���԰���:3,������:4,�������:5,���Ͱ���:6)");
	scanf_s("%d", &temp);
	switch (temp) {
	case 1:
		int a;
		printf("���� �׸� �Է�(�������Է�:1,������ ��ȸ:2)");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			int i;
			customer *ptr_c;
			ptr_c = new customer;
			ptr_c = arr_c;
			for (i = 0; i < 10; i++) {
				printf("���� �̸�,����,����,��ȭ��ȣ,���Լ�,�������� �Է�\n");
				scanf_s("%s%d%d%d%d%d", ptr_c->name, ptr_c->age, ptr_c->birthday, ptr_c->phonenumber, ptr_c->bought, ptr_c->perchased);
				ptr_c++;
			}
			delete ptr_c;
		case 2:
			int i_4;
			char temp[20];
			ptr_c = arr_c;
			printf("��ȸ�Ϸ��� ���̸� �Է�==>\n");
			scanf_s("%s", &temp);
			for (i_4 = 0; i_4 < 20; i_4++) {
				if (strcmp(temp, ptr_c->name) == 0) {
					printf("%s���� ����:%d\n",ptr_c->name,ptr_c->age);
					printf("%s���� ����:%d\n", ptr_c->name, ptr_c->birthday);
					printf("%s���� ��ȭ��ȣ:%d\n", ptr_c->name, ptr_c->phonenumber);
					printf("%s���� ���Լ�:%d\n", ptr_c->name, ptr_c->bought);
					printf("%s���� ��������:%d\n", ptr_c->name, ptr_c->perchased);
					ptr_c++;
				}
				else {
					ptr_c++;
				}
			}
			delete ptr_c;
			
		}
		
	case 2:
		int i_2;
		factory *ptr_f;
		ptr_f = new factory;
		ptr_f = arr_f;
		for (i_2 = 0; i_2 < 3; i_2++) {
			printf("����ó��� ��ǰ ������ ���� �Է�\n");
			scanf_s("%s%d", ptr_f->name, ptr_f->price);
			ptr_f++;
		}
		delete ptr_f;
	case 3:
		int i_3;
		char name[20];
		int bought;
		ptr_f = arr_f;
		printf("����ó�� �� ���Լ��� �Է�\n");
		scanf_s("%s%d", &name, &bought);
		for (i_3 = 0; i_3 < 3; i_3++) {
			if (strcmp(name, ptr_f->name)==0) {
				money = money - ptr_f->price*bought;
				restment_quantity = restment_quantity + bought;
				ptr_f++;
			}
			else {
				ptr_f++;
			}
		}
		delete ptr_f;
	case 4:
		printf("���� ���:%d\n", restment_quantity);
	case 5:
		int i_4;
		char temp_n[20];
		int bought_c;
		customer *ptr_c;
		ptr_c = new customer;
		ptr_c = arr_c;
		printf("�����ڸ� �� �Ǹż��� �Է�\n");
		scanf_s("%s%d", &name, &bought_c);
		for (i_4 = 0; i_4 < 20; i_4++) {
			if (strcmp(name, ptr_c->name) == 0) {
				money = money + ptr_c->bought*bought_c;
				restment_quantity = restment_quantity - bought_c;
				ptr_c++;
			}
			else {
				ptr_c++;
			}
		}
		delete ptr_c;
	case 6:
		printf("���� �Ǹŷ�:%d\n",restment_quantity );
		printf("�����ܰ�:%d\n", money);
	}
}


