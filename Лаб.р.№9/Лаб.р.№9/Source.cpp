#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>
#include<windows.h>

struct Info
{
	char nos[21];
	int V;
	char name[21];
	char author[21];

}block[10] = { { "Flash cards", 1024, "N1","Lubov" } , { "HDDs", 1024, "N2","Maksim" }, { "CD-ROM", 1, "N3","Artem" }, { "DVD-ROM", 9, "N4","Nikita" } , { "Blu-ray", 128, "N5","Angelina"}, { "Floppy disks", 128, "N6","Misha" }, { "SSD drives", 1024, "N7","Helga" }, { "0", 0, "0","0" }, { "0", 0, "0","0" }, { "0", 0, "0","0" } };
struct Info buf;
int vvod_mas(int);
void vvod(int);
void vivod_mas(int);
void menu();
void sort();
void poisk();
void vivod(int i);
void izmenit();
void udalit();
int proverca(int* x);
void v_file(struct Info* block, const char* f_name);
void iz_file(const char* f_name);

int main()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
	return 0;
}


void menu()
{
	int pr = 1, a, kol = 10;int num = 7, n = 0; FILE* f;

	do
	{
		do
		{
			printf("Сделайте выбор!\n1 - Ввод массива структур;\n2 - Сортировка массива структур;\n3 - Поиск в массиве структур по заданному параметру;\n4 - Изменение заданной структуры;\n5 - Удаление структуры из массива;\n6 - Вывод на экран массива структур;\n7 - сохранение данных в файл;\n8 - считывание данных с  файла;\n9 - Выход;\n");
			a = proverca(&a);

		} while (a < 1 || a > 9);

		switch (a)
		{
		case 1:
		{
			num = num - n;
			int result = vvod_mas(num);
			if (result)
				num = result;
			n = 0;
			break;
		}
		case 2:
		{
			puts("изначальный массив структур: ");
			vivod_mas(kol);
			puts("то, что получилось: ");
			sort();
			vivod_mas(kol);break;
		}
		case 3: poisk();break;
		case 4: izmenit();break;
		case 5:
		{
			udalit();
			kol--;
			n++;
			break;
		}
		case 6: vivod_mas(kol);break;
		case 7:

		{

			v_file(block, "file.bin");break;
		}
		case 8:
		{

			iz_file("file.bin");
			break;
		}
		case 9: pr = 0;
		}
	} while (pr == 1);
}


int vvod_mas(int num)
{
	int bum, i, kol = 0;
	for (i = num; i < 10; i++)
	{
		printf("Введите носитель[%d]: ", i);
		getchar();
		gets_s(block[i].nos, 21);
		printf("Введите обЪем[%d]: ", i);
		block[i].V = proverca(&block[i].V);
		printf("Введите название[%d]: ", i);
		getchar();
		gets_s(block[i].name, 21);
		printf("Введите автор[%d]: ", i);
		fgets(block[i].author, 21, stdin);
		if (block[i].author[strlen(block[i].author) - 1] == '\n') {
			block[i].author[strlen(block[i].author) - 1] = '\0';
		}
		kol++;
		printf("если вы больше не хотите заполнять поля структуры, введите любое число отличное от 1\n");
		bum = proverca(&bum);
		if (bum != 1)
			i = 10;
	}
	num = kol + num;
	return (num);
}



void vvod(int i)
{
	printf("Введите носитель[%d]: ", i);
	getchar();
	gets_s(block[i].nos, 21);
	printf("Введите обЪем[%d]: ", i);
	block[i].V = proverca(&block[i].V);
	printf("Введите название[%d]: ", i);
	getchar();
	gets_s(block[i].name, 21);
	printf("Введите автор[%d]: ", i);
	fgets(block[i].author, 21, stdin);
	if (block[i].author[strlen(block[i].author) - 1] == '\n') {
		block[i].author[strlen(block[i].author) - 1] = '\0';
	}
}


void vivod_mas(int kol)
{
	for (int i = 0; i <= kol;i++)
	{
		if (block[i].V != 0)
		{
			printf("Носитель[%d]: ", i);
			puts(block[i].nos);
			printf("обЪем[%d]: %d", i, block[i].V);
			printf("\nНазвание[%d]: ", i);
			puts(block[i].name);
			printf("Автор[%d]: ", i);
			puts(block[i].author);
			printf("\n");
		}
	}
}


void vivod(int i)
{
	if (block[i].V != 0)
	{
		printf("Носитель[%d]: ", i);
		puts(block[i].nos);
		printf("обЪем[%d]: %d", i, block[i].V);
		printf("\nНазвание[%d]: ", i);
		puts(block[i].name);
		printf("Автор[%d]: ", i);
		puts(block[i].author);
	}
}

void sort()
{
	int num = 0;int kol = 1, i;


	for (i = 0; i < 10;i++)
	{
		if (block[i].V != 0)
			num++;
	}

	while (kol != 0)
	{
		kol = 0;
		for (i = 0; i < num - 1;i++)
		{
			if (strncmp(block[i + 1].nos, block[i].nos, 1) < 0)
			{
				buf = block[i];
				block[i] = block[i + 1];
				block[i + 1] = buf;
				kol++;
			}
		}
	}
}

void poisk()
{
	int index;
	int kol = 0, flag;char sss[21];
	do
	{


		puts("Сделаем поиск по параметру Author");
		puts("Введите нужный вам Author");
		getchar();
		fgets(sss, sizeof(sss), stdin);
		if (sss[strlen(sss) - 1] == '\n')
			sss[strlen(sss) - 1] = '\0';
		for (int i = 0; i < 10; i++)
		{
			if (strcmp(sss, block[i].author) == 0)
			{
				index = i;kol = kol + 1;
				vivod(index);
			}
		}
		if (kol == 0)
			puts("нету совпадений. Попробуй еще раз. Не волнуйся, тебя все получится!");
		puts("если вы хотите ВЫЙТИ из поиска, введите любое число, отличное от нуля");
		puts("если хотите остаться, введите нуль");
		flag = proverca(&flag);
		kol = flag;
	} while (kol == 0);
}

void izmenit()
{
	int kol = 10;
	int num, boom;
	do
	{
		puts("выбери номер структуры, которую ты хотел бы изменить");
		num = proverca(&num);
	} while (num < 0 || num>9);
	vvod(num);
	do
	{
		puts("нажми 1, если хочешь посмотреть измененный массив структуры");
		puts("нажми 2, если хочешь посмотреть измененную тобой структуру");
		puts("нажми 3, если не хочешь смотреть изменения");
		boom = proverca(&boom);
	} while (boom < 1 || boom>3);
	switch (boom)
	{
	case 1: vivod_mas(kol);break;
	case 2: vivod(num);break;
	case 3: puts("как хочешь...");
	}

}


void udalit()
{
	int ud, nul = 0;int kol = 9;
	do
	{
		puts("выбери индекс структуры, которая будет удалена.");
		ud = proverca(&ud);
	} while (ud < 0 || ud>9);
	block[ud] = { "0", 0, "0","0" };
	for (ud;ud < 9;ud++)
	{
		block[ud] = block[ud + 1];
	}
	puts("полученный массив структур: ");
	vivod_mas(kol);
}


int proverca(int* x)
{
	while (scanf_s("%d", x) == 0)
	{
		printf("ошибка, введи целочисленное значение");
		printf("\n");
		while (getchar() != '\n');
	}
	return *x;
}


void v_file(struct Info* block, const char* f_name)
{
	FILE* file = fopen(f_name, "wb");
	if (file != NULL) {
		fwrite(block, sizeof(struct Info), 10, file);
		fclose(file);
		puts("данные успешно занесены в файл");
	}
	else {
		printf("Не удалось открыть файл %s\n", f_name);
	}
}

void iz_file(const char* f_name)
{

	FILE* file = fopen(f_name, "rb");
	struct Info block[10];
	if (file != NULL) {
		fread(block, sizeof(struct Info), 10, file);
		fclose(file);

		for (int i = 0; i < 10; i++)
		{
			printf("numver%d:    nos: %s, V: %d, name: %s, author: %s\n", i, block[i].nos, block[i].V, block[i].name, block[i].author);

		}
	}
	else {
		printf("Не удалось открыть файл %s\n", f_name);
	}
}