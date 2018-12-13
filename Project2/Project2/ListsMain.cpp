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
		puts("Выберите действие:");
		puts("1)Начальное формирование списка"); 
		puts("2)Добавление нового узла с упорядочением по ключу");
		puts("3)Удаление узла c заданным ключом");
		puts("4)Вывод данных всех узлов списка на экран");
		puts("5)Поиск узла по ключу"); 
		puts("6)Определение длины списка");
		puts("7)Очистка списка");
		puts("0)Выход\n");
		i = test();
		system("cls");
		if (i == 0) break;
		else
		{
			switch (i)
			{
			case 1: if (create(&start) == 1)
			{
				puts("Первый узел уже создан!");
			}
					break;
			case 2: if (add(&start) == 1)
			{
				puts("Первый узел еще не создан!");
			}
					break;
			case 3: printf("Введите /№ карточки, которая будет удалена: ");
				n = test();
				if (delete_elem(&start, n) == 1)
				{
					puts("Карточка не найдена");
				}
				else
				{
					puts("Карточка удалена.");
				}
				break;

			case 4: if (read(start) == 1)
			{
				puts("Список пуст.");
			}
					break;
			case 5: printf("Введите /№ карточки, по которой будет поиск: ");
				n = test();
				output = search(start, n);
				if (output == NULL)
				{
					puts("Карточка не найдена");
				}
				else
				{
					printf("%-5d %-10s %-10d %-10d\n", output->number, output->name, output->code, output->sum);
				}
				break;
			case 6: int l;
				l = length(start);
				printf("Длина списка: %d\n", l);
				break;


			case 7: if (delete_q(&start) == 1)
			{
				puts("Список пуст.");
			}
					else
					{
						puts("Список очищен.");
					}
					break;
			default: puts("Выберите действие от 0 до 6");
			}
		}
		_getch();
	}
	return 0;
}

