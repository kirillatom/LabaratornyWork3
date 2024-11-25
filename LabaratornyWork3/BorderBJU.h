#pragma once
#include "DayFoodIntake.h"

class BorderBJU : public DayFoodIntake
{
public:
	BorderBJU(unsigned int& countIntake, const float& humanMass);
	// ������
	bool BorderProteinCheck() const;
	bool BorderFatCheck() const;
	bool BorderCarbohydrateCheck() const;
	//���������
	float GetProteinLimit() const;
	float GetFatLimit() const;
	float GetCarbohydrateLimit() const;
	float GetHumanMass() const;

	void setHumanMass(float humanMassGr);
	void setProteinLimit(float proteinLimit);
	void setFatLimit(float fatLimit);
	void setCarbohydrateLimit(float carbohydrateLimit);
	void OutputData() const;
	

private:
	//����
	float proteinLimit = (humanMassGr / 1000) * 0.8;
	float fatLimit = (humanMassGr / 1000) * 0.9;
	float carbohydrateLimit = (humanMassGr / 1000) * 2;
	float humanMassGr;
	
};