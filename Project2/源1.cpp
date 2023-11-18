#include<iostream>
#include<cmath>
#include<Windows.h>

void fun();
int tanger(int aaadsa[]);

void fun() {
	int a;
	std::cin >> a;
	std::cout << a << std::endl;
}

int tanger(int aaadsa[]) {
	std::cout << time << std::endl;
	std::cout << "fuck you" << std::endl;
	int a = 20;
	int ant = (int)std::tan(a);
	std::cout << ant << std::endl;
	int* b = &a;
	std::cout << *b << std::endl << "and address:" << b << std::endl;
	b = b + 1;
	std::cout << b << std::endl << "and it number is" << *b << std::endl;
	int c = 0;
	int *bbb = (int *)1;
	for (int i = 1; i < 20; i++)
	{
		b++;
		a++;
		int *bbb = b;
		int * va = bbb;
		std::cout << b << "and number:" << *b << std::endl;
		int libor = *b;
	}
	std::cout << "bbb == " << *bbb << std::endl;
	std::cout << a << std::endl;
	return CC_NONE;
}

int main() {
	tanger((int*)30);
	//fun();
	//maineee();
}

int open() {
	FILE *fp = fopen("WPFLauncher.txt", "w+");
	fprintf(fp, "%s %s %s %d", "We", "are", "in", 2014);

	fclose(fp);
}
