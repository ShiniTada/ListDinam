#ifndef LISTS_H
#define LISTS_H

#include <stdio.h> 
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h> 

struct node
{
	int number;         //� ��������
	char name[30];      //������������ �����
	int code;           //������ ���
	int sum;            //�����
	node *next;  		//��������� 
};

int test();
void input(node **);
int create(node **);
int add(node **);
int delete_elem(node **, int);
int read(node *);
node *search(node *, int);
int length(node *);
int delete_q(node **);
#endif

