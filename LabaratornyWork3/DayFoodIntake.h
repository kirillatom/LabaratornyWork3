#ifndef DAY_FOOD_INTAKE_H
#define DAY_FOOD_INTAKE_H

#include <iostream>
#include <string>
#include "AbstractionPFC.h"

using namespace std;

template<typename T>
class DayFoodIntake : public AbstractionPFC<T>
{
public:
    /// <summary>����������� � ����������</summary>
    /// <param name="countIntake"></param>
    DayFoodIntake(const int& countIntake);
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
    virtual bool BorderProteinCheck() const { return true; }
    virtual bool BorderFatCheck() const { return true; }
    virtual bool BorderCarbohydrateCheck() const { return true; }
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
template<typename T>
DayFoodIntake<T>::DayFoodIntake(const int& countIntake)
    : countIntake(countIntake), massG(0), volumeCcal(0), proteinsAll(0), fatsAll(0), carbohydratesAll(0) {

    dynamincProteinArray = new float[countIntake];
    dynamincFatArray = new float[countIntake];
    dynamincCarbohydrateArray = new float[countIntake];

    for (int i = NULLIK; i <= countIntake; i++)
    {
        dynamincProteinArray[i] = NEGATIV_VALUE;
        dynamincFatArray[i] = NEGATIV_VALUE;
        dynamincCarbohydrateArray[i] = NEGATIV_VALUE;
    }
}

template<typename T>
DayFoodIntake<T>::DayFoodIntake(const DayFoodIntake& other)
    : countIntake(other.countIntake),
    volumeCcal(other.volumeCcal),
    massG(other.massG),
    proteinsAll(other.proteinsAll),
    fatsAll(other.fatsAll),
    carbohydratesAll(other.carbohydratesAll) {

    dynamincProteinArray = new float[countIntake];
    dynamincFatArray = new float[countIntake];
    dynamincCarbohydrateArray = new float[countIntake];

    for (int i = NULLIK; i < countIntake; i++)
    {
        dynamincProteinArray[i] = other.dynamincProteinArray[i];
        dynamincFatArray[i] = other.dynamincFatArray[i];
        dynamincCarbohydrateArray[i] = other.dynamincCarbohydrateArray[i];
    }
}

template<typename T>
DayFoodIntake<T>::~DayFoodIntake()
{
    delete[] dynamincProteinArray;
    delete[] dynamincFatArray;
    delete[] dynamincCarbohydrateArray;
}

template<typename T>
T DayFoodIntake<T>::GetMassG() const {
    return massG;
}

template<typename T>
T DayFoodIntake<T>::GetVolumeCcal() const {
    return volumeCcal;
}

template<typename T>
void DayFoodIntake<T>::MealLog(const T& massG, const unsigned int& mealNumber,
    const float& protein, const float& fat, const float& carbohydrate)
{

    if (massG <= NULLIK)
    {
        throw exception((string("������! ������������ ���� ������")
            + ". ������: "
            + to_string(massG)).c_str());
    }

    if (mealNumber < POZITIVCHIK_VALUE)
    {
        throw exception((string("������! ������������ ���� ������")
            + ". ������: "
            + to_string(mealNumber)).c_str());
    }
    if (mealNumber >= ELEVEN)
    {
        throw exception((string("������! ������������ ���� ������")
            + ". ������: "
            + to_string(mealNumber)).c_str());
    }
    if (protein < NULLIK)
    {
        throw exception((string("������! ������������ ���� ������")
            + ". ������: "
            + to_string(protein)).c_str());
    }
    if (fat < NULLIK)
    {
        throw exception((string("������! ������������ ���� ������")
            + ". ������: "
            + to_string(fat)).c_str());
    }
    if (carbohydrate < NULLIK)
    {
        throw exception((string("������! ������������ ���� ������")
            + ". ������: "
            + to_string(carbohydrate)).c_str());
    }


    this->massG += massG;

    dynamincProteinArray[mealNumber - POZITIVCHIK_VALUE] += (protein / ONE_HUNDRED) * massG;
    volumeCcal += dynamincProteinArray[mealNumber - POZITIVCHIK_VALUE] * PROTEIN_CCAL_1G;
    dynamincFatArray[mealNumber - POZITIVCHIK_VALUE] += (fat / ONE_HUNDRED) * massG;
    volumeCcal += dynamincFatArray[mealNumber - POZITIVCHIK_VALUE] * FAT_CCAL_1G;
    dynamincCarbohydrateArray[mealNumber - POZITIVCHIK_VALUE] += (carbohydrate / ONE_HUNDRED) * massG;
    volumeCcal += dynamincCarbohydrateArray[mealNumber - POZITIVCHIK_VALUE] * CARBOHYDRATE_CCAL_1G;

    proteinsAll += (protein / ONE_HUNDRED) * massG;
    fatsAll += (fat / ONE_HUNDRED) * massG;
    carbohydratesAll += (carbohydrate / ONE_HUNDRED) * massG;

}

template<typename T>
void DayFoodIntake<T>::OutputData() const
{
    for (int i = NULLIK; i < countIntake; i++) {
        if (dynamincProteinArray[i] != NEGATIV_VALUE && dynamincFatArray[i] != NEGATIV_VALUE && dynamincCarbohydrateArray[i] != NEGATIV_VALUE)
        {
            cout << "������ ��� �� " << i + POZITIVCHIK_VALUE << " ���� ����: " << endl;
            cout << "�����: " << dynamincProteinArray[i] << " |"
                << " ����: " << dynamincFatArray[i] << " |"
                << " ��������: " << dynamincCarbohydrateArray[i] << endl;
        }
    }
    cout << "����� ���������� ������: " << proteinsAll << endl;
    cout << "����� ���������� �����: " << fatsAll << endl;
    cout << "����� ���������� ���������: " << carbohydratesAll << endl;
}
template<typename T>
void DayFoodIntake<T>::OutputData(unsigned int mealNumber) const
{
    if (mealNumber < POZITIVCHIK_VALUE || mealNumber > countIntake)
    {
        throw exception((string("������! ������������ ����� ������ ����") + ". ������: " + to_string(mealNumber)).c_str());
    }
    int index = mealNumber - POZITIVCHIK_VALUE;
    if (dynamincProteinArray[index] != NEGATIV_VALUE &&
        dynamincFatArray[index] != NEGATIV_VALUE &&
        dynamincCarbohydrateArray[index] != NEGATIV_VALUE) {

        cout << "������ ��� �� " << mealNumber << " ���� ����: " << endl;
        cout << "�����: " << dynamincProteinArray[index] << " |"
            << " ����: " << dynamincFatArray[index] << " |"
            << " ��������: " << dynamincCarbohydrateArray[index] << endl;
    }
    else {
        cout << "������ �� " << mealNumber << " ���� ���� �����������." << endl;
    }
}

template<typename T>
float DayFoodIntake<T>::operator[](unsigned int mealNumber) const
{
    if (mealNumber < POZITIVCHIK_VALUE || mealNumber >= countIntake) {
        throw std::runtime_error("������! ������������ ����� ������ ����. ������: " + std::to_string(mealNumber));
    }

    int index = mealNumber - POZITIVCHIK_VALUE;

    float totalCalories = NULLIK;

    if (dynamincProteinArray[index] != NEGATIV_VALUE) {
        totalCalories += dynamincProteinArray[index] * PROTEIN_CCAL_1G;
    }

    if (dynamincFatArray[index] != NEGATIV_VALUE) {
        totalCalories += dynamincFatArray[index] * FAT_CCAL_1G;
    }

    if (dynamincCarbohydrateArray[index] != NEGATIV_VALUE) {
        totalCalories += dynamincCarbohydrateArray[index] * CARBOHYDRATE_CCAL_1G;
    }

    return totalCalories;
}
template<typename T>
ostream& operator<<(ostream& os, const DayFoodIntake<T>& dayFoodIntake)
{
    os << "������� ���������� � ������� ����:";
    os << "����� �����: " << dayFoodIntake.massG << " �";
    os << "����� ����� �������: " << dayFoodIntake.volumeCcal << " ����";
    os << "����� ������: " << dayFoodIntake.proteinsAll << " �";
    os << "����� �����: " << dayFoodIntake.fatsAll << " �";
    os << "����� ���������: " << dayFoodIntake.carbohydratesAll << " �";
    return os;
}

#endif DAY_FOOD_INTAKE_H
