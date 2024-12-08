#include "BorderBJU.h"

#include "BorderBJU.h"
#include <iostream>

template<typename T>
BorderBJU<T>::BorderBJU(unsigned int& countIntake, T& humanMass)
    : DayFoodIntake<T>(countIntake, humanMass) {
    // ������������� ��������� �������� ���
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
        cout << "�� ����� �� ������� ����� �����!!!" << endl;
        cout << "�� ����� " << this->proteinsAll << " ����� �����" << endl;
        cout << "���� ������� ����� �����: " << proteinLimit << endl;
    }
    else {
        cout << "�� ������ ������ ��� " << proteinLimit - this->proteinsAll << " ����� �����" << endl;
    }

    if (!BorderFatCheck()) {
        cout << "�� ����� �� ������� ����� �����!!!" << endl;
        cout << "�� ����� " << this->fatsAll << " ����� �����" << endl;
        cout << "���� ������� ����� �����: " << fatLimit << endl;
    }
    else {
        cout << "�� ������ ������ ��� " << fatLimit - this->fatsAll << " ����� �����" << endl;
    }

    if (!BorderCarbohydrateCheck()) {
       cout << "�� ����� �� ������� ����� ���������!!!" << endl;
       cout << "�� ����� " << this->carbohydratesAll << " ����� ���������" << endl;
       cout << "���� ������� ����� ���������: " << carbohydrateLimit << endl;
    }
    else {
       cout << "�� ������ ������ ��� " << carbohydrateLimit - this->carbohydratesAll << " ����� ���������" << endl;
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const BorderBJU<T>& borderBJU) {
    os << "������� ���������� � ������ ����:" << endl;
    os << "����� �����: " << borderBJU.GetMassG() << " " << (sizeof(T) == 8 ? "��" : "�") << endl;
    os << "����� ����� �������: " << borderBJU.GetVolumeCcal() << " ����" << endl;
    os << "����� ������: " << borderBJU.proteinsAll << " �" << endl;
    os << "����� �����: " << borderBJU.fatsAll << " �" << endl;
    os << "����� ���������: " << borderBJU.carbohydratesAll << " �" << endl;
    return os;
}

template class BorderBJU<int>;
template class BorderBJU<double>;
