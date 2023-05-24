#include "08_Calc.h"

// Cpp : ������(���Ǻ�)

Calc::Calc(int value) // Ŭ���� �� �Լ����� ª���� ��ǻ� �տ� inline�� �پ��ִ°Ͱ� ����
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
