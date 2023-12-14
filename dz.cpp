#include <iostream>
#include <vector>
#include <string>

class Room {
public:
    Room(const std::string& name, double length, double width, bool wallpaperCeiling)
        : name(name), length(length), width(width), wallpaperCeiling(wallpaperCeiling) {}

    double calculateWallArea() const {
        return 2 * (length + width) * length;
    }

    double calculateCeilingArea() const {
        return wallpaperCeiling ? length * width : 0;
    }

    std::string getName() const {
        return name;
    }

private:
    std::string name;
    double length;
    double width;
    bool wallpaperCeiling;
};

class WallpaperRoll {
public:
    WallpaperRoll(const std::string& name, double length, double width, double price)
        : name(name), length(length), width(width), price(price) {}

    double calculateArea() const {
        return length * width;
    }

    double getPrice() const {
        return price;
    }

    std::string getName() const {
        return name;
    }

private:
    std::string name;
    double length;
    double width;
    double price;
};

class Apartment {
public:
    void addRoom(const Room& room) {
        rooms.push_back(room);
    }

    void addWallpaperRoll(const WallpaperRoll& roll) {
        rolls.push_back(roll);
    }

    void calculateCost() const {
        double totalCost = 0;
        std::cout << "калькулятор стоимости:" << std::endl;

        for (const Room& room : rooms) {
            double roomArea = room.calculateWallArea() + room.calculateCeilingArea();

            std::cout << "комната: " << room.getName() << ", Область: " << roomArea << " квадратных местров" << std::endl;

            for (const WallpaperRoll& roll : rolls) {
                double rollsNeeded = roomArea / roll.calculateArea();
                double rollCost = rollsNeeded * roll.getPrice();
                totalCost += rollCost;

                std::cout << "  обои: " << roll.getName() << ", количество рулонов: " << rollsNeeded
                          << ", цена: $" << rollCost << std::endl;
            }
        }

        std::cout << "суммарная стоимость: $" << totalCost << std::endl;
    }

private:
    std::vector<Room> rooms;
    std::vector<WallpaperRoll> rolls;
};

int main() {
    Apartment apartment;

    // Добавляем комнаты и рулоны обоев
    apartment.addRoom(Room("зал", 5.0, 4.0, true));
    apartment.addRoom(Room("спальня", 4.0, 3.5, false));

    apartment.addWallpaperRoll(WallpaperRoll("классические", 10.0, 0.5, 25.0));
    apartment.addWallpaperRoll(WallpaperRoll("современные", 8.0, 0.6, 30.0));

    // Рассчитываем стоимость
    apartment.calculateCost();

    return 0;
}
