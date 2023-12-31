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
			printf("�������� �����!\n1 - ���� ������� ��������;\n2 - ���������� ������� ��������;\n3 - ����� � ������� �������� �� ��������� ���������;\n4 - ��������� �������� ���������;\n5 - �������� ��������� �� �������;\n6 - ����� �� ����� ������� ��������;\n7 - ���������� ������ � ����;\n8 - ���������� ������ �  �����;\n9 - �����;\n");
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
			puts("����������� ������ ��������: ");
			vivod_mas(kol);
			puts("��, ��� ����������: ");
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
		printf("������� ��������[%d]: ", i);
		getchar();
		gets_s(block[i].nos, 21);
		printf("������� �����[%d]: ", i);
		block[i].V = proverca(&block[i].V);
		printf("������� ��������[%d]: ", i);
		getchar();
		gets_s(block[i].name, 21);
		printf("������� �����[%d]: ", i);
		fgets(block[i].author, 21, stdin);
		if (block[i].author[strlen(block[i].author) - 1] == '\n') {
			block[i].author[strlen(block[i].author) - 1] = '\0';
		}
		kol++;
		printf("���� �� ������ �� ������ ��������� ���� ���������, ������� ����� ����� �������� �� 1\n");
		bum = proverca(&bum);
		if (bum != 1)
			i = 10;
	}
	num = kol + num;
	return (num);
}



void vvod(int i)
{
	printf("������� ��������[%d]: ", i);
	getchar();
	gets_s(block[i].nos, 21);
	printf("������� �����[%d]: ", i);
	block[i].V = proverca(&block[i].V);
	printf("������� ��������[%d]: ", i);
	getchar();
	gets_s(block[i].name, 21);
	printf("������� �����[%d]: ", i);
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
			printf("��������[%d]: ", i);
			puts(block[i].nos);
			printf("�����[%d]: %d", i, block[i].V);
			printf("\n��������[%d]: ", i);
			puts(block[i].name);
			printf("�����[%d]: ", i);
			puts(block[i].author);
			printf("\n");
		}
	}
}


void vivod(int i)
{
	if (block[i].V != 0)
	{
		printf("��������[%d]: ", i);
		puts(block[i].nos);
		printf("�����[%d]: %d", i, block[i].V);
		printf("\n��������[%d]: ", i);
		puts(block[i].name);
		printf("�����[%d]: ", i);
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


		puts("������� ����� �� ��������� Author");
		puts("������� ������ ��� Author");
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
			puts("���� ����������. �������� ��� ���. �� ��������, ���� ��� ���������!");
		puts("���� �� ������ ����� �� ������, ������� ����� �����, �������� �� ����");
		puts("���� ������ ��������, ������� ����");
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
		puts("������ ����� ���������, ������� �� ����� �� ��������");
		num = proverca(&num);
	} while (num < 0 || num>9);
	vvod(num);
	do
	{
		puts("����� 1, ���� ������ ���������� ���������� ������ ���������");
		puts("����� 2, ���� ������ ���������� ���������� ����� ���������");
		puts("����� 3, ���� �� ������ �������� ���������");
		boom = proverca(&boom);
	} while (boom < 1 || boom>3);
	switch (boom)
	{
	case 1: vivod_mas(kol);break;
	case 2: vivod(num);break;
	case 3: puts("��� ������...");
	}

}


void udalit()
{
	int ud, nul = 0;int kol = 9;
	do
	{
		puts("������ ������ ���������, ������� ����� �������.");
		ud = proverca(&ud);
	} while (ud < 0 || ud>9);
	block[ud] = { "0", 0, "0","0" };
	for (ud;ud < 9;ud++)
	{
		block[ud] = block[ud + 1];
	}
	puts("���������� ������ ��������: ");
	vivod_mas(kol);
}


int proverca(int* x)
{
	while (scanf_s("%d", x) == 0)
	{
		printf("������, ����� ������������� ��������");
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
		puts("������ ������� �������� � ����");
	}
	else {
		printf("�� ������� ������� ���� %s\n", f_name);
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
		printf("�� ������� ������� ���� %s\n", f_name);
	}
}