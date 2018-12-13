#include "Lists.h"

int test()
{
	int res2, i;
	do {
		res2 = scanf_s("%d", &i);
		while (getchar() != '\n');
		if (res2 != 1) printf("¬ведите число!\n");
	} while (res2 != 1);
	return i;
}

void input(node **p)
{
	printf("¬ведите є карточки: ");
	(*p)->number = test();
	printf("¬ведите наименование банка: ");
	scanf_s("%s", &(*p)->name, 30);
	printf("¬ведите личный код: ");
	(*p)->code = test();
	printf("¬ведите сумму: ");
	(*p)->sum = test();
}

int create(node **start)
{
	if (*start != NULL) return 1;
	else
	{
		node *p = new node;
		input(&p);
		p->next = NULL;
		*start = p;
		return 0;
	}
}
  
int add(node **start)
{
	if (*start == NULL) return 1;
	else
	{
		node *p = new node;
		input(&p);

		node *prev = *start, *post = *start;
		while (post != NULL)
		{
			if (post->number > p->number)
			{
				//поместим новый узел между узлами, задаваемыми prev и post
				p->next = post;
				if (post == *start)
					*start = p;
				else
					prev->next = p;
				return 0;
			}
			prev = post;
			post = post->next;
		}
		//поместим новый узел в конец списка
		p->next = NULL;
		prev->next = p;
		return 0;
	}
}

int read(node *start)
{
	if (start == NULL) return 1;
	else
	{
		node *p = start;
		while (p != NULL)
		{
			printf("%-5d %-10s %-10d %-10d\n", p->number, p->name, p->code, p->sum);
			p = p->next;
		}
		return 0;
	}
}

node *search(node *start, int key)
{
	if (start == NULL) return NULL;
	else
	{
		node *p = start;
		while (p != NULL)
		{
			if (p->number == key)
			{
				return p;
			}
			p = p->next;
		}
		return NULL;
	}
}

int delete_elem(node **start, int key)
{
	node *p;
	p = search(*start, key);
	if (p == NULL) return 1;
	
	else
	{
		//node *pre = *start;
		if (p == *start)
		{
			*start = (*start)->next;
		}
		else
		{
			node *pre = *start;
			while (pre != NULL)
			{
				if (pre->next == p)
					break;            //нашли предшествующий узел и выходим из цикла
				pre = pre->next;
			}
			pre->next = p->next;
		}
		delete p;
		return 0;
	}
}

int delete_q(node **start)
{
	if (*start == NULL) return 1;
	else
	{
		node *p = *start;
		//node *sub = new node;
		while (p != NULL)
		{
			*start = p->next;
			free(p);
			p = *start;
		}
		*start = NULL;
		return 0;
	}
}

int length(node *start)
{
	node *p = start;
	int count = 0;

	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}












