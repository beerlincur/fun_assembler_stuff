
#include <omp.h>
#include <iostream>
//#include <windows.h>
#include <stdio.h>
//#include <conio.h>

using namespace std;

void func()
{
	for (int i = 0; i < 500000; i++)
	{
		rand();
	}
}

int main()
{
	omp_set_num_threads(2);

	#pragma omp parallel for
	for (int i = 0; i < 100; i++)
	{
		cout << 0;
		func();
	}

	#pragma omp parallel
	{
		#pragma omp sections nowait
		{
			#pragma omp section
			for (int i = 0; i < 10; i++)
			{
				cout << 1;
				func();
			}
			#pragma omp section
			for (int i = 0; i < 20; i++)
			{
				cout << 2;
				func();
			}
		}
		#pragma omp barrier
		for (int i = 0; i < 10; i++)
		{
			cout << 3;
			func();
		}
	}


	return 0;
}