#pragma once
#define Qneue_Num 8

class Qunee8
{
public:
	Qunee8();
	~Qunee8();
	void EinghtQunee(int row);
private:
	int Cherr[Qneue_Num][Qneue_Num];
	int _qcount;
	void Qprint();
	bool safe(int row, int line);
	void Initchree();
};

