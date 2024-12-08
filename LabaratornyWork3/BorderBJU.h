#pragma once
#include "DayFoodIntake.h"

template<typename T>
class BorderBJU : public DayFoodIntake<T> {
public:
    BorderBJU(unsigned int& countIntake, T& humanMass);

    // ������ �������� ���� ���
    bool BorderProteinCheck() const;
    bool BorderFatCheck() const;
    bool BorderCarbohydrateCheck() const;

    // ���������
    T GetProteinLimit() const;
    T GetFatLimit() const;
    T GetCarbohydrateLimit() const;
    T GetHumanMass() const;

    void setHumanMass(T humanMass);
    void setProteinLimit(T proteinLimit);
    void setFatLimit(T fatLimit);
    void setCarbohydrateLimit(T carbohydrateLimit);

    // ����� ������
    void OutputData() const;

private:
    T proteinLimit;
    T fatLimit;
    T carbohydrateLimit;
};