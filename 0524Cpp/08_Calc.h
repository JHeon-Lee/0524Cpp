#pragma once

// ����� : ���

class Calc
{
	int value;

public:
	Calc(int value);

	Calc& Add(int value);
	Calc& Sub(int value);
	Calc& Mul(int value);
	Calc& Div(int value);
	Calc& Mod(int value);
};

