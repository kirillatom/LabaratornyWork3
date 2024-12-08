#include "BorderBJU.h"

#include "BorderBJU.h"
#include <iostream>

template<typename T>
BorderBJU<T>::BorderBJU(unsigned int& countIntake, T& humanMass)
    : DayFoodIntake<T>(countIntake, humanMass) {
    // Устанавливаем пороговые значения БЖУ
    proteinLimit = (humanMass / 1000) * 0.8; 
    fatLimit = (humanMass / 1000) * 0.9;     
    carbohydrateLimit = (humanMass / 1000) * 2; 
}

template<typename T>
bool BorderBJU<T>::BorderProteinCheck() const {
    return this->proteinsAll < proteinLimit;
}

template<typename T>
bool BorderBJU<T>::BorderFatCheck() const {
    return this->fatsAll < fatLimit;
}

template<typename T>
bool BorderBJU<T>::BorderCarbohydrateCheck() const {
    return this->carbohydratesAll < carbohydrateLimit;
}

template<typename T>
T BorderBJU<T>::GetProteinLimit() const {
    return proteinLimit;
}

template<typename T>
T BorderBJU<T>::GetFatLimit() const {
    return fatLimit;
}

template<typename T>
T BorderBJU<T>::GetCarbohydrateLimit() const {
    return carbohydrateLimit;
}

template<typename T>
T BorderBJU<T>::GetHumanMass() const {
    return this->humanMass;
}

template<typename T>
void BorderBJU<T>::setHumanMass(T humanMassGr) {
    this->humanMass = humanMassGr;
}

template<typename T>
void BorderBJU<T>::setProteinLimit(T proteinLimit) {
    this->proteinLimit = proteinLimit;
}

template<typename T>
void BorderBJU<T>::setFatLimit(T fatLimit) {
    this->fatLimit = fatLimit;
}

template<typename T>
void BorderBJU<T>::setCarbohydrateLimit(T carbohydrateLimit) {
    this->carbohydrateLimit = carbohydrateLimit;
}

template<typename T>
void BorderBJU<T>::OutputData() const {
    DayFoodIntake<T>::OutputData();

    if (!BorderProteinCheck()) {
        cout << "Вы вышли за дневную норму белка!!!" << endl;
        cout << "Вы съели " << this->proteinsAll << " грамм белка" << endl;
        cout << "Ваша дневная норма белка: " << proteinLimit << endl;
    }
    else {
        cout << "Вы можете кушать ещё " << proteinLimit - this->proteinsAll << " грамм белка" << endl;
    }

    if (!BorderFatCheck()) {
        cout << "Вы вышли за дневную норму жиров!!!" << endl;
        cout << "Вы съели " << this->fatsAll << " грамм жиров" << endl;
        cout << "Ваша дневная норма жиров: " << fatLimit << endl;
    }
    else {
        cout << "Вы можете кушать ещё " << fatLimit - this->fatsAll << " грамм жиров" << endl;
    }

    if (!BorderCarbohydrateCheck()) {
       cout << "Вы вышли за дневную норму углеводов!!!" << endl;
       cout << "Вы съели " << this->carbohydratesAll << " грамм углеводов" << endl;
       cout << "Ваша дневная норма углеводов: " << carbohydrateLimit << endl;
    }
    else {
       cout << "Вы можете кушать ещё " << carbohydrateLimit - this->carbohydratesAll << " грамм углеводов" << endl;
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const BorderBJU<T>& borderBJU) {
    os << "Сводная информация о приеме пищи:" << endl;
    os << "Общая масса: " << borderBJU.GetMassG() << " " << (sizeof(T) == 8 ? "кг" : "г") << endl;
    os << "Общий объем калорий: " << borderBJU.GetVolumeCcal() << " ккал" << endl;
    os << "Всего белков: " << borderBJU.proteinsAll << " г" << endl;
    os << "Всего жиров: " << borderBJU.fatsAll << " г" << endl;
    os << "Всего углеводов: " << borderBJU.carbohydratesAll << " г" << endl;
    return os;
}

template class BorderBJU<int>;
template class BorderBJU<double>;
