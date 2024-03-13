#include <iostream>
#include "fixed_array_list.h"
#include "dynamic_array_list.h"
#include "linked_list.h"

// Функції для інтерактивного режиму
void interactiveMode() {
    std::cout << "Select the data structure:\n";
    std::cout << "1. Fixed-size Array\n";
    std::cout << "2. Dynamic Array\n";
    std::cout << "3. Linked List\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        interactiveModeFixedSizeArray();
        break;
    case 2:
        interactiveModeDynamicArray();
        break;
    case 3:
        interactiveModeLinkedList();
        break;
    default:
        std::cout << "Invalid choice.\n";
    }
}

// Функції для демонстраційного режиму
void demonstrationMode() {
    std::cout << "Select the data structure for demonstration:\n";
    std::cout << "1. Fixed-size Array\n";
    std::cout << "2. Dynamic Array\n";
    std::cout << "3. Linked List\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        demonstrationModeFixedSizeArray();
        break;
    case 2:
        demonstrationModeDynamicArray();
        break;
    case 3:
        demonstrationModeLinkedList();
        break;
    default:
        std::cout << "Invalid choice.\n";
    }
}

// Функції для бенчмарк режиму
void benchmarkMode() {
    std::cout << "Select the data structure for benchmark:\n";
    std::cout << "1. Fixed-size Array\n";
    std::cout << "2. Dynamic Array\n";
    std::cout << "3. Linked List\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        benchmarkModeFixedSizeArray();
        break;
    case 2:
        benchmarkModeDynamicArray();
        break;
    case 3:
        benchmarkModeLinkedList();
        break;
    default:
        std::cout << "Invalid choice.\n";
    }
}

int main() {
    while (true) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Interactive Mode\n";
        std::cout << "2. Demonstration Mode\n";
        std::cout << "3. Benchmark Mode\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        int mainChoice;
        std::cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            interactiveMode();
            break;
        case 2:
            demonstrationMode();
            break;
        case 3:
            benchmarkMode();
            break;
        case 4:
            std::cout << "Exiting program.\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
