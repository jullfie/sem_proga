#include <iostream>

class cashRegister {
private:
    int cashOnHand; // переменная для хранения количества денег в кассе

public:
    cashRegister() {
        cashOnHand = 500; // инициализация начального значения денег в кассе
    }

    cashRegister(int cash) {
        cashOnHand = cash; // инициализация начального значения денег в кассе заданным значением
    }

    int getCurrentBalance() {
        return cashOnHand; // возвращает текущее количество денег в кассе
    }

    void acceptAmount(int amount) {
        cashOnHand += amount; // увеличивает количество денег в кассе на заданную сумму
    }
};

class dispenserType {
private:
    int numberOfItems; // переменная для хранения количества товаров в автомате
    int cost; // переменная для хранения стоимости товара

public:
    dispenserType() {
        numberOfItems = 50; // инициализация начального значения количества товаров в автомате
        cost = 50; // инициализация начальной стоимости товара
    }

    dispenserType(int items, int itemCost) {
        numberOfItems = items; // инициализация начального значения количества товаров в автомате заданным значением
        cost = itemCost; // инициализация начальной стоимости товара заданным значением
    }

    int getNoOfItems() {
        return numberOfItems; // возвращает текущее количество товаров в автомате
    }

    int getCost() {
        return cost; // возвращает текущую стоимость товара
    }

    void makeSale() {
        if (numberOfItems > 0) {
            numberOfItems--; // уменьшает количество товаров в автомате на 1
        }
    }
};

void showSelection() {
    std::cout << "1. Конфеты\n";
    std::cout << "2. Чипсы\n";
    std::cout << "3. Жевательная резинка\n";
    std::cout << "4. Печенье\n";
}

void sellProduct(dispenserType& dispenser, cashRegister& cashReg) {
    int choice;
    std::cout << "Выберите товар: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Стоимость конфет: " << dispenser.getCost() << std::endl;
            break;
        case 2:
            std::cout << "Стоимость чипсов: " << dispenser.getCost() << std::endl;
            break;
        case 3:
            std::cout << "Стоимость жевательной резинки: " << dispenser.getCost() << std::endl;
            break;
        case 4:
            std::cout << "Стоимость печенья: " << dispenser.getCost() << std::endl;
            break;
        default:
            std::cout << "Неверный выбор товара\n";
            return;
    }

    int amount;
    std::cout << "Введите сумму: ";
    std::cin >> amount;

    if (amount >= dispenser.getCost()) {
        dispenser.makeSale(); // уменьшает количество товаров в автомате на 1
        cashReg.acceptAmount(dispenser.getCost()); // увеличивает количество денег в кассе на стоимость товара
        std::cout << "Товар продан\n";
    } else {
        std::cout << "Недостаточно средств\n";
    }
}

int main() {
    cashRegister cashReg; // создание объекта кассы
    dispenserType dispenser; // создание объекта автомата

    showSelection(); // вывод списка товаров
    sellProduct(dispenser, cashReg); // продажа товара

    return 0;
}
