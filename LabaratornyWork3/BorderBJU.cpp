#include "BorderBJU.h"

BorderBJU::BorderBJU(unsigned int& countIntake, float& humanMass)
	: DayFoodIntake(countIntake, humanMass) {}

// методы
bool BorderBJU::BorderProteinCheck() const
{
	if (proteinsAll < proteinLimit) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BorderBJU::BorderFatCheck() const
{
	if(fatsAll < fatLimit)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool BorderBJU::BorderCarbohydrateCheck() const
{
	if(carbohydratesAll < carbohydrateLimit)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

float BorderBJU::GetProteinLimit() const
{
	return proteinLimit;
}

float BorderBJU::GetFatLimit() const
{
	return fatLimit;
}

float BorderBJU::GetCarbohydrateLimit() const
{
	return carbohydrateLimit;
}

float BorderBJU::GetHumanMass() const 
{
	return humanMass;
}

void BorderBJU::setHumanMass(float humanMassGr) 
{
	this->humanMass = humanMass;
}

void BorderBJU::setProteinLimit(float proteinLimit) 
{
	this->proteinLimit = proteinLimit;
}

void BorderBJU::setFatLimit(float fatLimit) 
{
	this->fatLimit = fatLimit;
}

void BorderBJU::setCarbohydrateLimit(float carbohydrateLimit) 
{
	this->carbohydrateLimit = carbohydrateLimit;
}

void BorderBJU::OutputData() const
{
	DayFoodIntake::OutputData();
	if (!BorderProteinCheck())
	{
		cout << "Вы вышли за дневную норму белка!!!" << endl;
		cout << "Вы съели " << proteinsAll << " грамм белка" << endl;
		cout << "Ваша дневная норма белка: " << proteinLimit << endl;
	}
	else
	{
		cout << "Вы можете кушать ещё " << proteinsAll - proteinLimit << " грамм белка" << endl;
	}
	if (!BorderFatCheck())
	{
		cout << "Вы вышли за дневную норму жиров!!!" << endl;
		cout << "Вы съели " << fatsAll << "грамм жиров" << endl;
		cout << "Ваша дневная норма жиров: " << fatLimit << endl;
	}
	else
	{
		cout << "Вы можете кушать ещё " << fatsAll - fatLimit << " грамм жиров" << endl;
	}
	if (!BorderCarbohydrateCheck())
	{
		cout << "Вы вышли за дневную норму углеводов!!!" << endl;
		cout << "Вы съели " << carbohydratesAll << " грамм углеводов" << endl;
		cout << "Ваша дневная норма углеводов: " << carbohydrateLimit << endl;
	}
	else
	{
		cout << "Вы можете кушать ещё " << carbohydratesAll - carbohydrateLimit << " грамм углеводов" << endl;
	}
}
