#include <iostream>
using namespace std;
//Функции к заданию 1
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

int differenceInDays(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days1 = day1;
    for (int i = 1; i < month1; ++i) {
        days1 += daysInMonth(i, year1);
    }

    int days2 = day2;
    for (int i = 1; i < month2; ++i) {
        days2 += daysInMonth(i, year2);
    }

    for (int i = year1 + 1; i < year2; ++i) {
        days2 += isLeapYear(i) ? 366 : 365;
    }

    return days2 - days1;
}
//функция к заданию 2
double average(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}
//функция к заданию 3
void countElements(int* arr_1, int size_1, int& positive, int& negative, int& zeros) {
    positive = 0;
    negative = 0;
    zeros = 0;

    for (int i = 0; i < size_1; i++) {
        if (arr_1[i] > 0) {
            positive++;
        }
        else if (arr_1[i] < 0) {
            negative++;
        }
        else {
            zeros++;
        }
    }
}
int main() {
    //Task_1
    setlocale(LC_ALL, "RUS");
    int day1, month1, year1, day2, month2, year2;

    cout << "Введите первую дату (день месяц год): ";
    cin >> day1 >> month1 >> year1;

    cout << "Введите вторую дату (день месяц год): ";
    cin >> day2 >> month2 >> year2;

    int difference = differenceInDays(day1, month1, year1, day2, month2, year2);

    cout << "Разность в днях: " << difference << "\n";
    cout << "\n";
    //Task_2
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    double avg = average(arr, size);
    cout << "Среднее арифметическое: " << avg << "\n";
    cout << "\n";
    //Task_3
    int arr_1[] = { -1, 0, 2, 0, -3, 4 };
    int size_1 = sizeof(arr_1) / sizeof(arr_1[0]);

    int positive, negative, zeros;
    countElements(arr_1, size_1, positive, negative, zeros);

    cout << "Положительных элементов: " << positive << "\n";
    cout << "Отрицательных элементов: " << negative << "\n";
    cout << "Нулевых элементов: " << zeros << "\n";
}
