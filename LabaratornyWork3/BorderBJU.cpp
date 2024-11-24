#include "BorderBJU.h"

BorderBJU::BorderBJU(const float& humanMass) : humanMass(humanMass) {}

bool BorderBJU::BorderProteinCheck()
{
	if (proteinsAll < proteinLimit) 
	{
		return true;
	}
	else {
		cout << "�� ����� �� ������� ����� �����!!!" << endl;
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
		cout << "�� ����� �� ������� ����� �����!!!" << endl;
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
		cout << "�� ����� �� ������� ����� ���������!!!" << endl;
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
