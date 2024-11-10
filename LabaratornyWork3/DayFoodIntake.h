#include <iostream>
#include <string>

using namespace std;

class DayFoodIntake
{
public:
    /// </summary>����������� � ����������</summary>
    /// <param name="countIntake"></param>
    DayFoodIntake(unsigned int& countIntake);
    //����������� �����������
    DayFoodIntake(const DayFoodIntake& other);
    // ����������
    ~DayFoodIntake();
    // �������
    float GetMassG() const;
    float GetVolumeCcal() const;
    /// <summary>����� ������� ������</summary>
    void MealLog(const float& massG, const unsigned int& mealNumber,
        const float& protein, const float& fat, const float& carbohydrate);
    /// <summary> ����� ������ ������ </summary>
    void OutputData();
    void OutputData(unsigned int mealNumber);
    float operator[](unsigned int mealNumber) const;
    friend ostream& operator<<(ostream& os, const DayFoodIntake& DayFoodIntake);
private:
    //�������
    float* dynamincProteinArray;
    float* dynamincFatArray;
    float* dynamincCarbohydrateArray;
    //����
    float massG; //����� �������� � �������
    float volumeCcal; //����� ���� ��������
    unsigned int countIntake; //���������� ������ ����
    unsigned int mealNumber; //����� ����� ���� 
    float protein;
    float fat;
    float carbohydrate;
    float proteinsAll = 0;
    float fatsAll = 0;
    float carbohydratesAll = 0;
    //���������
    static const unsigned int PROTEIN_CCAL_1G = 4;
    static const unsigned int FAT_CCAL_1G = 9;
    static const unsigned int CARBOHYDRATE_CCAL_1G = 4;
    static const int NEGATIV_VALUE = -1;

};
