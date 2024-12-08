#ifndef DAY_FOOD_INTAKE_H
#define DAY_FOOD_INTAKE_H

#include <iostream>
#include <string>
#include "AbstractionPFC.h"

using namespace std;

template<typename T>
class DayFoodIntake : public AbstractionPFC
{
public:
    /// <summary>����������� � ����������</summary>
    /// <param name="countIntake"></param>
    DayFoodIntake(const int& countIntake, T& humanMass);
    // <summary> ����������� �����������  </summary>
    DayFoodIntake(const DayFoodIntake& other);
    //  <summary> ����������  </summary>
    ~DayFoodIntake();
    // <summary> �������  </summary>
    T GetMassG() const override;
    T GetVolumeCcal() const override;
    // <summary> ����� ������� ������</summary>
    void MealLog(const T& massG, const unsigned int& mealNumber,
        const float& protein, const float& fat, const float& carbohydrate) override;
    // <summary> ����� ������ ������ </summary>
    void OutputData() const override;
    // <summary> ���������� ������ ������ </summary>
    void OutputData(unsigned int mealNumber) const override;
    virtual bool BorderProteinCheck() const;
    virtual bool BorderFatCheck() const;
    virtual bool BorderCarbohydrateCheck() const;
    // <summary> ���������� [] </summary>
    float operator[](unsigned int mealNumber) const override;
    //  <summary> ���������� <<  </summary>
    friend ostream& operator<<(ostream& os, const DayFoodIntake& DayFoodIntake);
protected:
    //����
    T massG;
    T volumeCcal;
    T proteinsAll, fatsAll, carbohydratesAll;
    const int countIntake;
    float humanMass;
private:
    //�������
    float* dynamincProteinArray;
    float* dynamincFatArray;
    float* dynamincCarbohydrateArray;
    //����
   
    unsigned int mealNumber; //����� ����� ���� 
    float protein;
    float fat;
    float carbohydrate;
    //���������
    static const unsigned int PROTEIN_CCAL_1G = 4;
    static const unsigned int FAT_CCAL_1G = 9;
    static const unsigned int CARBOHYDRATE_CCAL_1G = 4;
    static const int NEGATIV_VALUE = -1;
    static const unsigned int POZITIVCHIK_VALUE = 1;
    static const int NULLIK = 0;
    static const unsigned int ONE_HUNDRED = 100;
    static const unsigned int ELEVEN = 11;

};

#endif DAY_FOOD_INTAKE_H
