#include "DayFoodIntake.h"

DayFoodIntake::DayFoodIntake() {}

DayFoodIntake::DayFoodIntake(unsigned int& countIntake, float& humanMass)
    : countIntake(countIntake), 
    humanMass(humanMass),
    volumeCcal(NULLIK),
    massG(NULLIK) {
    if (countIntake <= NULLIK)
    {
        throw exception((string("������! ������������ ���� ������")
            + ". ������: "
            + to_string(countIntake)).c_str());
    }
    if (humanMass <= NULLIK)
    {
        throw exception((string("������! ������������ ���� ������")
            + ". ������: "
            + to_string(humanMass)).c_str());
    }
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

DayFoodIntake::DayFoodIntake(const DayFoodIntake& other)
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

void DayFoodIntake::OutputData() const
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
void DayFoodIntake::OutputData(unsigned int mealNumber) const
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
    float DayFoodIntake::operator[](unsigned int mealNumber) const {
        if (mealNumber < POZITIVCHIK_VALUE || mealNumber > countIntake) {
            throw std::runtime_error("������! ������������ ����� ������ ����. ������: " + std::to_string(mealNumber));
        }

        int index = mealNumber + NEGATIV_VALUE;

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
    ostream& operator<<(ostream& os, const DayFoodIntake& dayFoodIntake) 
    {
        os << "������� ���������� � ������� ����:";
        os << "����� �����: " << dayFoodIntake.massG << " �";
        os << "����� ����� �������: " << dayFoodIntake.volumeCcal << " ����";
        os << "����� ������: " << dayFoodIntake.proteinsAll << " �";
        os << "����� �����: " << dayFoodIntake.fatsAll << " �";
        os << "����� ���������: " << dayFoodIntake.carbohydratesAll << " �";
        return os;
    }
