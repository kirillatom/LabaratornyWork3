#ifndef DAY_FOOD_INTAKE_H
#define DAY_FOOD_INTAKE_H

#include <iostream>
#include <string>
#include "AbstractionPFC.h"

using namespace std;


class DayFoodIntake : public AbstractionPFC
{
public:
    /// <summary>Конструктор с параметром</summary>
    /// <param name="countIntake"></param>
    DayFoodIntake(const int& countIntake, float& humanMass);
    // <summary> Конструктор копирования  </summary>
    DayFoodIntake(const DayFoodIntake& other);
    //  <summary> Деструктор  </summary>
    ~DayFoodIntake();
    // <summary> Геттеры  </summary>
    float GetMassG() const override;
    float GetVolumeCcal() const override;
    // <summary> Метод расчёта данных</summary>
    void MealLog(const float& massG, const unsigned int& mealNumber,
        const float& protein, const float& fat, const float& carbohydrate) override;
    // <summary> Метод вывода данных </summary>
    void OutputData() const override;
    // <summary> Перегрузка метода вывода </summary>
    void OutputData(unsigned int mealNumber) const override;
    virtual bool BorderProteinCheck() const;
    virtual bool BorderFatCheck() const;
    virtual bool BorderCarbohydrateCheck() const;
    // <summary> Перегрузка [] </summary>
    float operator[](unsigned int mealNumber) const override;
    //  <summary> Перегрузка <<  </summary>
    friend ostream& operator<<(ostream& os, const DayFoodIntake& DayFoodIntake);
protected:
    //поля
    float proteinsAll = 0;
    float fatsAll = 0;
    float carbohydratesAll = 0;
    const int countIntake; //Количество приёмов пищи
    float humanMass;
private:
    //Массивы
    float* dynamincProteinArray;
    float* dynamincFatArray;
    float* dynamincCarbohydrateArray;
    //Поля
    float volumeCcal; //Объём кило каллорий
    float massG; //Масса продукта в граммах
    unsigned int mealNumber; //Номер приёма пищи 
    float protein;
    float fat;
    float carbohydrate;
    //Константы
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
