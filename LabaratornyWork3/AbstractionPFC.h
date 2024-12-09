#pragma once
template<typename T>
class AbstractionPFC
{
public:
	virtual void MealLog(const T& massG, const unsigned int& mealNumber,
		const float& protein, const float& fat, const float& carbohydrate) = 0;
	virtual void OutputData() const = 0;
	virtual void OutputData(unsigned int mealNumber) const = 0;
	virtual float operator[](unsigned int mealNumber) const = 0;
	virtual T GetMassG() const = 0;
	virtual T GetVolumeCcal() const = 0;
	virtual bool BorderProteinCheck() const = 0;
	virtual bool BorderFatCheck() const = 0;
	virtual bool BorderCarbohydrateCheck() const = 0;
	~AbstractionPFC();
};

template<typename T>
AbstractionPFC<T>::~AbstractionPFC()
{
}
