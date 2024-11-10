#include "DayFoodIntake.h"

DayFoodIntake::DayFoodIntake(unsigned int& countIntake)
    : countIntake(countIntake), volumeCcal(0), massG(0) {

    dynamincProteinArray = new float[countIntake];
    dynamincFatArray = new float[countIntake];
    dynamincCarbohydrateArray = new float[countIntake];

    for (int i = 0; i <= countIntake; i++) {
        dynamincProteinArray[i] = -1;
        dynamincFatArray[i] = -1;
        dynamincCarbohydrateArray[i] = -1;
    }
}

DayFoodIntake::DayFoodIntake(const DayFoodIntake& other)
    : countIntake(other.countIntake), volumeCcal(other.volumeCcal), massG(other.massG),
    proteinsAll(other.proteinsAll), fatsAll(other.fatsAll), carbohydratesAll(other.carbohydratesAll) {

    dynamincProteinArray = new float[countIntake];
    dynamincFatArray = new float[countIntake];
    dynamincCarbohydrateArray = new float[countIntake];

    // Копируем данные из другого объекта
    for (int i = 0; i < countIntake; i++) {
        dynamincProteinArray[i] = other.dynamincProteinArray[i];
        dynamincFatArray[i] = other.dynamincFatArray[i];
        dynamincCarbohydrateArray[i] = other.dynamincCarbohydrateArray[i];
    }
}
DayFoodIntake::~DayFoodIntake()
{
    delete[] dynamincProteinArray;
    delete[] dynamincFatArray;
    delete[] dynamincCarbohydrateArray;
}

float DayFoodIntake::GetMassG() const
{
    return massG;
}

float DayFoodIntake::GetVolumeCcal() const
{
    return volumeCcal;
}

void DayFoodIntake::MealLog(const float& massG, const unsigned int& mealNumber, const float& protein, const float& fat, const float& carbohydrate) {

    if (massG <= 0)
    {
        throw exception((string("Ошибка! Некорректный ввод данных")
            + ". Пришло: "
            + to_string(massG)).c_str());
    }

    if (mealNumber < 1)
    {
        throw exception((string("Ошибка! Некорректный ввод данных")
            + ". Пришло: "
            + to_string(mealNumber)).c_str());
    }
    if (mealNumber >= 11)
    {
        throw exception((string("Ошибка! Некорректный ввод данных")
            + ". Пришло: "
            + to_string(mealNumber)).c_str());
    }
    if (protein < 0)
    {
        throw exception((string("Ошибка! Некорректный ввод данных")
            + ". Пришло: "
            + to_string(protein)).c_str());
    }
    if (fat < 0)
    {
        throw exception((string("Ошибка! Некорректный ввод данных")
            + ". Пришло: "
            + to_string(fat)).c_str());
    }
    if (carbohydrate < 0)
    {
        throw exception((string("Ошибка! Некорректный ввод данных")
            + ". Пришло: "
            + to_string(carbohydrate)).c_str());
    }


    this->massG += massG; 

    dynamincProteinArray[mealNumber - 1] += (protein / 100) * massG;
    volumeCcal += dynamincProteinArray[mealNumber - 1] * PROTEIN_CCAL_1G;
    dynamincFatArray[mealNumber - 1] += (fat / 100) * massG;
    volumeCcal += dynamincFatArray[mealNumber - 1] * FAT_CCAL_1G;
    dynamincCarbohydrateArray[mealNumber - 1] += (carbohydrate / 100) * massG;
    volumeCcal += dynamincCarbohydrateArray[mealNumber - 1] * CARBOHYDRATE_CCAL_1G;

    proteinsAll += (protein / 100) * massG;
    fatsAll += (fat / 100) * massG;
    carbohydratesAll += (carbohydrate / 100) * massG;

}

void DayFoodIntake::OutputData()
{
    for (int i = 0; i < countIntake; i++) {
        if (dynamincProteinArray[i] != NEGATIV_VALUE && dynamincFatArray[i] != NEGATIV_VALUE && dynamincCarbohydrateArray[i] != NEGATIV_VALUE)
        {
            cout << "Сводка БЖУ за " << i + 1 << " приём пищи: " << endl;
            cout << "Белки: " << dynamincProteinArray[i] << " |"
                << " Жиры: " << dynamincFatArray[i] << " |"
                << " Углеводы: " << dynamincCarbohydrateArray[i] << endl;
        }
    }
    cout << "Общее количество белков: " << proteinsAll << endl;
    cout << "Общее количество жиров: " << fatsAll << endl;
    cout << "Общее количество углеводов: " << carbohydratesAll << endl;


}
void DayFoodIntake::OutputData(unsigned int mealNumber) 
{
    if (mealNumber < 1 || mealNumber > countIntake)
    {
        throw exception((string("Ошибка! Некорректный номер приема пищи") + ". Пришло: " + to_string(mealNumber)).c_str());
    }
    int index = mealNumber - 1;
    if (dynamincProteinArray[index] != NEGATIV_VALUE &&
        dynamincFatArray[index] != NEGATIV_VALUE &&
        dynamincCarbohydrateArray[index] != NEGATIV_VALUE) {

        cout << "Сводка БЖУ за " << mealNumber << " приём пищи: " << endl;
        cout << "Белки: " << dynamincProteinArray[index] << " |"
            << " Жиры: " << dynamincFatArray[index] << " |"
            << " Углеводы: " << dynamincCarbohydrateArray[index] << endl;
    }
    else {
        cout << "Данные за " << mealNumber << " приём пищи отсутствуют." << endl;
    }
}
    float DayFoodIntake::operator[](unsigned int mealNumber) const {
        if (mealNumber < 1 || mealNumber > countIntake) {
            throw std::runtime_error("Ошибка! Некорректный номер приема пищи. Пришло: " + std::to_string(mealNumber));
        }

        int index = mealNumber - 1;

        float totalCalories = 0;

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
    ostream& operator<<(ostream& os, const DayFoodIntake& dayFoodIntake) 
    {
        os << "Сводная информация о приемах пищи:";
        os << "Общая масса: " << dayFoodIntake.massG << " гn";
        os << "Общий объем калорий: " << dayFoodIntake.volumeCcal << " ккалn";
        os << "Всего белков: " << dayFoodIntake.proteinsAll << " гn";
        os << "Всего жиров: " << dayFoodIntake.fatsAll << " гn";
        os << "Всего углеводов: " << dayFoodIntake.carbohydratesAll << " гn";
    }
