#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <ctime> 


void initializeTrain(int train[18][36], bool randomFill);
void printTrain(const int train[18][36]);
bool bookSeat(int train[18][36], int wagon, int seat);
bool freeSeat(int train[18][36], int wagon, int seat);
int freeSeatsInWagon(const int train[18][36], int wagon);
int totalFreeSeats(const int train[18][36]);
void menu();


int train[18][36];

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned int>(time(NULL)));
    menu();
    return 0;
}


void initializeTrain(int train[18][36], bool randomFill)
{
    for (int i = 0; i < 18; ++i) 
    {
        for (int j = 0; j < 36; ++j) 
        {
            if (randomFill) 
            {
                train[i][j] = rand() % 2;
            }
            else
            {
                train[i][j] = 0;
            }
        }
    }
}


void printTrain(const int train[18][36])
{
    system("cls");
    std::cout << "Обзор вагонов и мест:\n\n";
    for (int i = 0; i < 18; ++i)
    {
        std::cout << "Вагон " << std::setw(2) << i + 1 << ": ";
        for (int j = 0; j < 36; ++j) {
            std::cout << train[i][j] << " ";
        }
        std::cout << "\n";
    }
}


bool bookSeat(int train[18][36], int wagon, int seat) 
{
    if (wagon < 0 || wagon >= 18 || seat < 0 || seat >= 36)
        return false;
    if (train[wagon][seat] == 0) 
    {
        train[wagon][seat] = 1;
        return true;
    }
    return false;
}


bool freeSeat(int train[18][36], int wagon, int seat) 
{
    if (wagon < 0 || wagon >= 18 || seat < 0 || seat >= 36)
        return false;
    if (train[wagon][seat] == 1) 
    {
        train[wagon][seat] = 0;
        return true;
    }
    return false;
}


int freeSeatsInWagon(const int train[18][36], int wagon) 
{
    if (wagon < 0 || wagon >= 18)
        return -1;
    int count = 0;
    for (int j = 0; j < 36; ++j) 
    {
        if (train[wagon][j] == 0)
            ++count;
    }
    return count;
}


int totalFreeSeats(const int train[18][36]) 
{
    int total = 0;
    for (int i = 0; i < 18; ++i) 
    {
        for (int j = 0; j < 36; ++j)
        {
            if (train[i][j] == 0)
                ++total;
        }
    }
    return total;
}


void menu() 
{
    bool initialized = false;

    while (true) 
    {
        std::cout << "\nМеню:\n";
        std::cout << "1. Инициализация массива\n";
        std::cout << "2. Вывод таблицы\n";
        std::cout << "3. Забронировать место\n";
        std::cout << "4. Освободить место\n";
        std::cout << "5. Количество свободных мест в вагоне\n";
        std::cout << "6. Общее количество свободных\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите: ";
        int choice;
        std::cin >> choice;

        if (choice == 0) 
        {
            std::cout << "Выход...\n";
            Sleep(1000);
            system("cls");
            break;
        }
        else if (choice == 1) 
        {
            std::cout << "Выберите:\n1. Рандомное заполнение\n2. Всё пусто\nВыбор: ";
            int ch;
            std::cin >> ch;
            if (ch == 1) 
            {
                initializeTrain(train, true);
            }
            else 
            {
                initializeTrain(train, false);
            }
            initialized = true;
        }
        else if (choice == 2) 
        {
            if (!initialized) 
            {
                std::cout << "Сначала инициализируйте массив!\n";
                Sleep(1000);
                system("cls");
            }
            else 
            {
                printTrain(train);
            }
        }
        else if (choice == 3)
        {
            if (!initialized) 
            {
                std::cout << "Сначала инициализация!\n";
                Sleep(1000);
                system("cls");
                continue;
            }
            int w, s;
            std::cout << "Введите номер вагона (1-18): ";
            std::cin >> w;
            std::cout << "Введите номер места (1-36): ";
            std::cin >> s;
            if (bookSeat(train, w - 1, s - 1))
            {
                std::cout << "Место забронировано.\n";
                Sleep(1000);
                system("cls");
            }
            else
            {
                std::cout << "Невозможно забронировать. Проверьте правильность номера или занятость.\n";
                Sleep(1000);
                system("cls");
            }
        }
        else if (choice == 4) 
        {
            if (!initialized) 
            {
                std::cout << "Сначала инициализация!\n";
                Sleep(1000);
                system("cls");
                continue;
            }
            int w, s;
            std::cout << "Введите номер вагона (1-18): ";
            std::cin >> w;
            std::cout << "Введите номер места (1-36): ";
            std::cin >> s;
            if (freeSeat(train, w - 1, s - 1))
            {
                std::cout << "Место освобождено.\n";
                Sleep(1000);
                system("cls");
            }
            else
            {
                std::cout << "Невозможно освободить. Проверьте правильность введенных данных.\n";
                Sleep(1000);
                system("cls");
            }
        }
        else if (choice == 5) 
        {
            if (!initialized) 
            {
                std::cout << "Сначала инициализация!\n";
                Sleep(1000);
                system("cls");
                continue;
            }
            int w;
            std::cout << "Введите номер вагона (1-18): ";
            std::cin >> w;
            int freeCount = freeSeatsInWagon(train, w - 1);
            if (freeCount >= 0)
            {
                std::cout << "В вагоне " << w << " свободно мест: " << freeCount << "\n";
            }
            else
            {
                std::cout << "Некорректный номер вагона.\n";
                Sleep(1000);
                system("cls");
            }
        }
        else if (choice == 6) 
        {
            if (!initialized) 
            {
                std::cout << "Сначала инициализация!\n";
                Sleep(1000);
                system("cls");
                continue;
            }
            int total = totalFreeSeats(train);
            std::cout << "Общее количество свободных мест: " << total << "\n";
        }
        else
        {
            std::cout << "Некорректный выбор.\n";
            Sleep(1000);
            system("cls");
        }
   
    }
}
