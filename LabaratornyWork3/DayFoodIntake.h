#ifndef DAY_FOOD_INTAKE_H
#define DAY_FOOD_INTAKE_H

#include <iostream>
#include <string>

using namespace std;

class DayFoodIntake
{
public:
    /// <summary>����������� � ����������</summary>
    /// <param name="countIntake"></param>
    DayFoodIntake(unsigned int& countIntake);
    // <summary> ����������� �����������  </summary>
    DayFoodIntake(const DayFoodIntake& other);
    //  <summary> ����������  </summary>
    ~DayFoodIntake();
    // <summary> �������  </summary>
    float GetMassG() const;
    float GetVolumeCcal() const;
    // <summary> ����� ������� ������</summary>
    void MealLog(const float& massG, const unsigned int& mealNumber,
        const float& protein, const float& fat, const float& carbohydrate);
    // <summary> ����� ������ ������ </summary>
    void OutputData() const;
    // <summary> ���������� ������ ������ </summary>
    void OutputData(unsigned int mealNumber) const;
    // <summary> ���������� [] </summary>
    float operator[](unsigned int mealNumber) const;
    //  <summary> ���������� <<  </summary>
    friend ostream& operator<<(ostream& os, const DayFoodIntake& DayFoodIntake);
protected:
    //����
    float proteinsAll = 0;
    float fatsAll = 0;
    float carbohydratesAll = 0;
    unsigned int countIntake; //���������� ������ ����
private:
    //�������
    float* dynamincProteinArray;
    float* dynamincFatArray;
    float* dynamincCarbohydrateArray;
    //����
   
    float volumeCcal; //����� ���� ��������
    float massG; //����� �������� � �������
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
