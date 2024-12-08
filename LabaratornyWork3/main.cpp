#include "DayFoodIntake.h"
#include "BorderBJU.h"
#include "AbstractionPFC.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    float mass;
    unsigned int meal;
    int count = 0;
    unsigned int massAll = 0;
    bool continueInput = true;
    bool productInput = true;
    bool mealInput = true;
    float b = 0, j = 0, u = 0;
    const int countIntake = 15;
    char choice4;
    double humanMass;

    cout << "\t\t\t------------------------------------------------------------------" << endl;
    cout << "\t\t\t|Программа хранения и обработки данных о суточном рационе питания|" << endl;
    cout << "\t\t\t------------------------------------------------------------------" << endl << endl;

    cout << "Введите ваш вес в граммах" << endl;
    cin >> humanMass;
 
    AbstractionPFC* Intake[countIntake];
    Intake[0] = new DayFoodIntake(countIntake, humanMass);
    //DayFoodIntake Intake(countIntake);
   // BorderBJU Intake2(countIntake,humanMass);

    while (continueInput) {
        cout << "Введите номер приёма пищи : ";
        cin >> meal;
        productInput = true;
        while (productInput) {

            cout << "Введите массу продукта в граммах: ";
            cin >> mass;

            cout << "Введите количество белков на 100г: ";
            cin >> b;

            cout << "Введите количество жиров на 100г: ";
            cin >> j;

            cout << "Введите количество углеводов на 100г: ";
            cin >> u;
            Intake[meal]->MealLog(mass, meal, b, j, u);
            Intake[meal]->BorderProteinCheck();
            Intake[meal]->BorderFatCheck();
            Intake[meal]->BorderCarbohydrateCheck();

            char choice2;

            cout << "Хотите ввести еще один продукт? Y (yes) / N (no) : ";
            cin >> choice2;

            if (choice2 != 'Y' && choice2 != 'y')
            {
                productInput = false;
            }
        }
        char choice;
        cout << "Хотите ввести еще один приём пищи? Y (yes) / N (no) : ";
        cin >> choice;
        if (choice != 'Y' && choice != 'y')
        {
            continueInput = false;
        }

    }
    while (mealInput) 
    {
        char choice3;
        cout << "Хотели бы вы вывести сводную информацию БЖУ за конкретный приём пищи? Y (yes) / N (no) : ";
        cin >> choice3;
        if (choice3 != 'Y' && choice3 != 'y')
        {
            mealInput = false;
        }
        else {
            int mealNumb;
            cout << "Введите число, за какой приём пищи хотели бы получить информацию : " ;
            cin >> mealNumb;
            Intake[mealNumb]->OutputData();
            cout << "Калории за " << mealNumb << " прием пищи : " << Intake[mealNumb] << endl;
           
        }
    }
    cout << "Хотели бы вы получить общую сводку БЖУ за все приёмы пищи? Y (yes) / N (no) : ";
    cin >> choice4;
    if (choice4 != 'Y' && choice4 != 'y')
    {
        return 0;
    }
    else 
    {
        cout << Intake;
    }
    for (int i = 0; i < countIntake; ++i) 
    {
        delete Intake[i]; 
    }

}