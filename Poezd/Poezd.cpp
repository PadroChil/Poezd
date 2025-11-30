#include <iostream>
#include <iomanip>
#include <Windows.h>


const int NUM_WAGONS = 18;
const int SEATS_PER_WAGON = 36;


int seatsArrangement[NUM_WAGONS][SEATS_PER_WAGON];


void fillRandomly() 
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < NUM_WAGONS; ++i) 
    {
        for (int j = 0; j < SEATS_PER_WAGON; ++j) 
        {
            seatsArrangement[i][j] = std::rand() % 2; 
        }
    }
}


void clearSeats() 
{
    for (int i = 0; i < NUM_WAGONS; ++i) 
    {
        for (int j = 0; j < SEATS_PER_WAGON; ++j) 
        {
            seatsArrangement[i][j] = 0;
        }
    }
}


void displayTrain() 
{
    std::cout << "Раскладка мест по вагонам:\n";
    for (int i = 0; i < NUM_WAGONS; ++i)
    {
        std::cout << "Вагон " << i + 1 << ": ";
        for (int j = 0; j < SEATS_PER_WAGON; ++j) 
        {
            std::cout << seatsArrangement[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void toggleSeat() 
{
    int wagonIdx, seatIdx;
    std::cout << "Введите номер вагона (1-" << NUM_WAGONS << "): ";
    std::cin >> wagonIdx;
    std::cout << "Введите номер места (1-" << SEATS_PER_WAGON << "): ";
    std::cin >> seatIdx;

    
    if (wagonIdx < 1 || wagonIdx > NUM_WAGONS || seatIdx < 1 || seatIdx > SEATS_PER_WAGON) 
    {
        std::cout << "Некорректный ввод.\n";
        return;
    }

    int vIdx = wagonIdx - 1;
    int sIdx = seatIdx - 1;
    if (seatsArrangement[vIdx][sIdx] == 0) 
    {
        seatsArrangement[vIdx][sIdx] = 1;
        std::cout << "Место занято.\n";
    }
    else 
    {
        seatsArrangement[vIdx][sIdx] = 0;
        std::cout << "Место освобождено.\n";
    }
}


int countFreeSeatsInWagon(int wagonNumber) 
{
    int freeCount = 0;
    for (int j = 0; j < SEATS_PER_WAGON; ++j) 
    {
        if (seatsArrangement[wagonNumber][j] == 0) 
        {
            ++freeCount;
        }
    }
    return freeCount;
}


int totalFreeSeats() 
{
    int total = 0;
    for (int i = 0; i < NUM_WAGONS; ++i) 
    {
        total += countFreeSeatsInWagon(i);
    }
    return total;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
   
    while (true) 
    {
        int mode;
        std::cout << "Выберите режим заполнения:\n"
            << "1 - случайная расстановка\n"
            << "2 - очистка (все места свободны)\n"
            << "Ваш выбор: ";
        std::cin >> mode;

        if (mode == 1) 
        {
            fillRandomly();
        }
        else if (mode == 2) 
        {

            clearSeats();
        }
        else 
        {
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
            continue;
        }

        while (true) 
        {
            int choice;
            std::cout << "\nМеню:\n"
                << "1 - Показать все места\n"
                << "2 - Забронировать/освободить место\n"
                << "3 - Посчитать свободные места в вагоне\n"
                << "4 - Общее количество свободных мест\n"
                << "5 - Выход в главное меню\n"
                << "Выбор: ";
            std::cin >> choice;

            if (choice == 1) 
            {
                displayTrain();
            }
            else if (choice == 2) 
            {
                toggleSeat();
            }
            else if (choice == 3) 
            {
                int wagonNumber;
                std::cout << "Введите номер вагона (1-" << NUM_WAGONS << "): ";
                std::cin >> wagonNumber;
                if (wagonNumber < 1 || wagonNumber > NUM_WAGONS) 
                {


                    std::cout << "Некорректный номер вагона.\n";
                }
                else 
                {
                    int freeSeats = countFreeSeatsInWagon(wagonNumber - 1);
                    std::cout << "Свободных мест в вагоне " << wagonNumber << ": " << freeSeats << "\n";
                }
            }
            else if (choice == 4) 
            {
                std::cout << "Общее количество свободных мест: " << totalFreeSeats() << "\n";
            }
            else if (choice == 5) 
            {
                std::cout << "Возврат в главное меню.\n";
                break;
            }
            else 
            {
                std::cout << "Некорректный выбор. Попробуйте снова.\n";
            }
        }
    }
    return 0;
}