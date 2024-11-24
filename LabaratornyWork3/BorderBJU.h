#include "DayFoodIntake.h"

class BorderBJU : public DayFoodIntake
{
public:
	BorderBJU(const float& humanMass);;
	//методы
	bool BorderProteinCheck();
	bool BorderFatCheck() ;
	bool BorderCarbohydrateCheck();
	//селекторы
	float GetProteinLimit() const;
	float GetFatLimit() const;
	float GetCarbohydrateLimit() const;
	float GetHumanMass() const;;

private:
	//поля
	float proteinLimit = (humanMass / 1000) * 0.8;
	float fatLimit = (humanMass / 1000) * 0.9;
	float carbohydrateLimit = (humanMass / 1000) * 2;
	float humanMass;
	
};