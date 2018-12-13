#include "Lists.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	node *start = NULL;
	node *output;
	int n;
	int i;
	while (1)
	{
		system("cls");
		puts("�������� ��������:");
		puts("1)��������� ������������ ������"); 
		puts("2)���������� ������ ���� � ������������� �� �����");
		puts("3)�������� ���� c �������� ������");
		puts("4)����� ������ ���� ����� ������ �� �����");
		puts("5)����� ���� �� �����"); 
		puts("6)����������� ����� ������");
		puts("7)������� ������");
		puts("0)�����\n");
		i = test();
		system("cls");
		if (i == 0) break;
		else
		{
			switch (i)
			{
			case 1: if (create(&start) == 1)
			{
				puts("������ ���� ��� ������!");
			}
					break;
			case 2: if (add(&start) == 1)
			{
				puts("������ ���� ��� �� ������!");
			}
					break;
			case 3: printf("������� /� ��������, ������� ����� �������: ");
				n = test();
				if (delete_elem(&start, n) == 1)
				{
					puts("�������� �� �������");
				}
				else
				{
					puts("�������� �������.");
				}
				break;

			case 4: if (read(start) == 1)
			{
				puts("������ ����.");
			}
					break;
			case 5: printf("������� /� ��������, �� ������� ����� �����: ");
				n = test();
				output = search(start, n);
				if (output == NULL)
				{
					puts("�������� �� �������");
				}
				else
				{
					printf("%-5d %-10s %-10d %-10d\n", output->number, output->name, output->code, output->sum);
				}
				break;
			case 6: int l;
				l = length(start);
				printf("����� ������: %d\n", l);
				break;


			case 7: if (delete_q(&start) == 1)
			{
				puts("������ ����.");
			}
					else
					{
						puts("������ ������.");
					}
					break;
			default: puts("�������� �������� �� 0 �� 6");
			}
		}
		_getch();
	}
	return 0;
}

