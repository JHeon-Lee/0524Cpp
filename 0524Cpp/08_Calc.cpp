#include "08_Calc.h"

// Cpp : 구현부(정의부)

Calc::Calc(int value) // 클래스 내 함수들은 짧으면 사실상 앞에 inline이 붙어있는것과 같음
	: value(value)
{}

Calc& Calc::Add(int value)
{
	{ this->value += value; return *this; }
}

Calc& Calc::Sub(int value)
{
	{ this->value -= value; return *this; }
}

Calc& Calc::Mul(int value)
{
	{ this->value *= value; return *this; }
}

Calc& Calc::Div(int value)
{
	{ this->value /= value; return *this; }
}

Calc& Calc::Mod(int value)
{
	{ this->value %= value; return *this; }
}
