#include "BorderBJU.h"

BorderBJU::BorderBJU(unsigned int& countIntake, float& humanMass)
	: DayFoodIntake(countIntake, humanMass) {}

// ������
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
		cout << "�� ����� �� ������� ����� �����!!!" << endl;
		cout << "�� ����� " << proteinsAll << " ����� �����" << endl;
		cout << "���� ������� ����� �����: " << proteinLimit << endl;
	}
	else
	{
		cout << "�� ������ ������ ��� " << proteinsAll - proteinLimit << " ����� �����" << endl;
	}
	if (!BorderFatCheck())
	{
		cout << "�� ����� �� ������� ����� �����!!!" << endl;
		cout << "�� ����� " << fatsAll << "����� �����" << endl;
		cout << "���� ������� ����� �����: " << fatLimit << endl;
	}
	else
	{
		cout << "�� ������ ������ ��� " << fatsAll - fatLimit << " ����� �����" << endl;
	}
	if (!BorderCarbohydrateCheck())
	{
		cout << "�� ����� �� ������� ����� ���������!!!" << endl;
		cout << "�� ����� " << carbohydratesAll << " ����� ���������" << endl;
		cout << "���� ������� ����� ���������: " << carbohydrateLimit << endl;
	}
	else
	{
		cout << "�� ������ ������ ��� " << carbohydratesAll - carbohydrateLimit << " ����� ���������" << endl;
	}
}
