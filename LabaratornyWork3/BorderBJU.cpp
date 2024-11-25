#include "BorderBJU.h"

BorderBJU::BorderBJU(unsigned int& countIntake,const float& humanMass) : DayFoodIntake(countIntake), humanMassGr(humanMass)
{ 
	if (humanMassGr <= 400 || humanMassGr >= 645000)
	{
		throw exception((string("������! ������������ ���� ������")
			+ ". ������: "
			+ to_string(humanMassGr)).c_str());
	}
}

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
	return humanMassGr;
}

void BorderBJU::setHumanMass(float humanMassGr) 
{
	this->humanMassGr = humanMassGr;
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
