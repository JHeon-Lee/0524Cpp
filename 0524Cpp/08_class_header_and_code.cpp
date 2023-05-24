#include <iostream>
#include "08_Calc.h" // 헤더 추가하면 사용 가능

int main()
{
	using namespace std; // 이름 충돌 방지

	Calc calc(10);

	calc.Add(5).Div(2).Mul(1);

	return 0;
}