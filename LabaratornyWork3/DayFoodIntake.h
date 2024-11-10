#include <iostream>
#include <string>

using namespace std;

class DayFoodIntake
{
public:
    /// </summary>Конструктор с параметром</summary>
    /// <param name="countIntake"></param>
    DayFoodIntake(unsigned int& countIntake);
    //Конструктор копирования
    DayFoodIntake(const DayFoodIntake& other);
    // Деструктор
    ~DayFoodIntake();
    // Геттеры
    float GetMassG() const;
    float GetVolumeCcal() const;
    /// <summary>Метод расчёта данных</summary>
    void MealLog(const float& massG, const unsigned int& mealNumber,
        const float& protein, const float& fat, const float& carbohydrate);
    /// <summary> Метод вывода данных </summary>
    void OutputData();
    void OutputData(unsigned int mealNumber);
    float operator[](unsigned int mealNumber) const;
    friend ostream& operator<<(ostream& os, const DayFoodIntake& DayFoodIntake);
private:
    //Массивы
    float* dynamincProteinArray;
    float* dynamincFatArray;
    float* dynamincCarbohydrateArray;
    //Поля
    float massG; //Масса продукта в граммах
    float volumeCcal; //Объём кило каллорий
    unsigned int countIntake; //Количество приёмов пищи
    unsigned int mealNumber; //Номер приёма пищи 
    float protein;
    float fat;
    float carbohydrate;
    float proteinsAll = 0;
    float fatsAll = 0;
    float carbohydratesAll = 0;
    //Константы
    static const unsigned int PROTEIN_CCAL_1G = 4;
    static const unsigned int FAT_CCAL_1G = 9;
    static const unsigned int CARBOHYDRATE_CCAL_1G = 4;
    static const int NEGATIV_VALUE = -1;

};

