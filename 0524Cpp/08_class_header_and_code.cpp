#include <iostream>
#include "08_Calc.h" // ��� �߰��ϸ� ��� ����

int main()
{
	using namespace std; // �̸� �浹 ����

	Calc calc(10);

	calc.Add(5).Div(2).Mul(1);

	return 0;
}