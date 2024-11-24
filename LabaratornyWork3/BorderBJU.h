#include "DayFoodIntake.h"

class BorderBJU : public DayFoodIntake
{
public:
	BorderBJU();
	//������
	bool BorderProteinCheck();
	bool BorderFatCheck() ;
	bool BorderCarbohydrateCheck();
	//��������� �� ����������� � ��� ������ ��
	float GetProteinLimit() const
	{
		return proteinLimit;
	}
	float GetFatLimit() const
	{
		return fatLimit;
	}
	float GetCarbohydrateLimit() const
	{
		return carbohydrateLimit;
	}

private:
	//����
	float proteinLimit = (humanMass / 1000) * 0.8;
	float fatLimit = (humanMass / 1000) * 0.9;
	float carbohydrateLimit = (humanMass / 1000) * 2;
	
};