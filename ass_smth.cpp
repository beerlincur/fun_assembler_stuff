
#include <iostream>
using namespace std;

/*int main()
{
	_asm {
		mov ebx, 0 // BB 00 00 00 00
		add ebx, eax // 03 D8
		dec ecx // 49
		and edx, 111b // 83 E2 07
		sal eax, 3 // C1 E0 03 
		or eax, ebx // 0B C3
		mov ax, 43013 // 66 B8 05 A8
		shr ax, 1 // 66 D1 E8
	}

}*/

/*int main()
{
	setlocale(LC_ALL, "Russian");
	int i, A[10], B[10];
	cout << "Введите элементы массива:" << endl;
	for (i = 0; i < 10; ++i) 
	{
		cin >> A[i];
	}
	_asm {
		mov ebx, 0
		lea esi, A[0]
		lea edi, B[0]
		metka:
		mov eax, [esi]
		mov [edi], eax
		add esi, 4
		add edi, 4
		inc ebx
		cmp ebx, 10
		jl metka
	}
	cout << "Второй массив:" << endl;
	for (i = 0; i < 10; ++i)
	{
		cout << B[i] << endl;
	}
	system("pause");
	return 0;
}*/

/*int main()
{
	setlocale(LC_ALL, "Russian");
	int i, A[10], B[10];
	cout << "Введите элементы массива:" << endl;
	for (i = 0; i < 10; ++i)
	{
		cin >> A[i];
	}
	_asm {
		lea esi, A[0]
		lea edi, B[0]
		mov cx, 10
		lp1:
		mov eax, [esi]
		mov[edi], eax
		add esi, 4
		add edi, 4
		loop lp1
	}
	cout << "Второй массив:" << endl;
	for (i = 0; i < 10; ++i)
	{
		cout << B[i] << endl;
	}
	system("pause");
	return 0;
}*/

int main()
{
	int i, A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, B[10];
	_asm {
		mov rbx, 0
		lea rsi, A[0]
		lea rdi, B[0]
		mov rcx, 10
		// mov ecx, 40 (if rep movsb)
		rep movsd
	}
	cout << "Second: " << endl;
	for (i = 0; i < 10; ++i)
	{
		cout << B[i] << endl;
	}
	system("pause");
	return 0;
}