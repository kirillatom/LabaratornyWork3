#include "BorderBJU.h"

BorderBJU::BorderBJU() {}

bool BorderBJU::BorderProteinCheck()
{
	if (proteinsAll < proteinLimit) 
	{
		return true;
	}
	else {
		cout << "Вы вышли за дневную норму белка!!!" << endl;
		return false;
	}
}

bool BorderBJU::BorderFatCheck()
{
	if(fatsAll < fatLimit)
	{
		return true;
	}
	else {
		cout << "Вы вышли за дневную норму жиров!!!" << endl;
		return false;
	}
}

bool BorderBJU::BorderCarbohydrateCheck()
{
	if(carbohydratesAll < carbohydrateLimit)
	{
		return true;
	}
	else {
		cout << "Вы вышли за дневную норму углеводов!!!" << endl;
		return false;
	}
}
