#include "fixed_array_list.h"

void initializeFixedArrayList(FixedArrayList& list) {
    list.size = 0;
}

bool addIPAddress(FixedArrayList& list, const std::string& ipAddress) {
    if (list.size >= MAX_SIZE) {
        std::cerr << "Error: List is full. Cannot add more IP addresses." << std::endl;
        return false; // Повернення значення false, якщо не вдалось додати адресу.
    }
    list.ipAddresses[list.size] = ipAddress;
    list.size++;
    return true; // Повернення значення true, якщо адреса успішно додана.
}

bool removeIPAddress(FixedArrayList& list, const std::string& ipAddress) {
    for (int i = 0; i < list.size; i++) {
        if (list.ipAddresses[i] == ipAddress) {
            // Зсуваємо всі наступні елементи на одиницю вліво
            for (int j = i; j < list.size - 1; j++) {
                list.ipAddresses[j] = list.ipAddresses[j + 1];
            }
            list.size--;
            return true;
        }
    }
    return false; // Якщо IP-адреса не знайдена
}

int findIPAddress(const FixedArrayList& list, const std::string& ipAddress) {
    for (int i = 0; i < list.size; i++) {
        if (list.ipAddresses[i] == ipAddress) {
            return i; // Повертаємо індекс IP-адреси у списку
        }
    }
    return -1; // Якщо IP-адреса не знайдена
}

void printIPAddresses(const FixedArrayList& list) {
    std::cout << "IP Addresses in the list:" << std::endl;
    for (int i = 0; i < list.size; i++) {
        std::cout << list.ipAddresses[i] << std::endl;
    }
}






void create_empty(FixedArrayList& queue) {
    queue.size = 0;
}

bool enqueue(FixedArrayList& queue, const std::string& ipAddress) {
    if (queue.size >= MAX_SIZE) {
        return false;
    }
    queue.ipAddresses[queue.size++] = ipAddress;
    return true;
}

std::string dequeue(FixedArrayList& queue) {
    if (queue.size == 0) {
        throw std::out_of_range("Queue is empty");
    }
    std::string result = queue.ipAddresses[0];
    for (int i = 0; i < queue.size - 1; ++i) {
        queue.ipAddresses[i] = queue.ipAddresses[i + 1];
    }
    queue.size--;
    return result;
}

bool is_empty(const FixedArrayList& queue) {
    return queue.size == 0;
}

void interactiveModeFixedSizeArray() {
    FixedArrayList queue;
    initializeFixedArrayList(queue); // Створення пустої черги

    std::string value;
    int choice;

    while (true) {
        std::cout << "\n1. Enqueue \n2. Dequeue \n3. Check if Empty\n4. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to enqueue: ";
            std::cin >> value;
            if (!enqueue(queue, value)) {
                std::cout << "Queue is full.\n";
            }
            break;
        case 2:
            if (is_empty(queue)) {
                std::cout << "Queue is empty.\n";
            }
            else {
                std::cout << "Dequeued: " << dequeue(queue) << std::endl;
            }
            break;
        case 3:
            std::cout << (is_empty(queue) ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;
        case 4:
            return;
        default:
            std::cout << "Invalid choice.\n";
        }
    }
}

void demonstrationModeFixedSizeArray() {
    FixedArrayList queue;
    initializeFixedArrayList(queue); // Створення пустої черги

    std::cout << "\n--- Demonstration of Fixed-size Array Queue ---\n";

    enqueue(queue, "192.168.1.1");
    std::cout << "Enqueued: 192.168.1.1\n";

    enqueue(queue, "192.168.1.2");
    std::cout << "Enqueued: 192.168.1.2\n";

    std::cout << "Dequeued: " << dequeue(queue) << "\n";
    std::cout << "Dequeued: " << dequeue(queue) << "\n";

    std::cout << (is_empty(queue) ? "Queue is empty now.\n" : "Queue is not empty.\n");
}

void benchmarkModeFixedSizeArray() {
    FixedArrayList queue;
    initializeFixedArrayList(queue); // Створення пустої черги

    auto start = std::chrono::high_resolution_clock::now();

    // Enqueue operation benchmark
    for (int i = 0; i < MAX_SIZE; ++i) {
        enqueue(queue, "Item " + std::to_string(i));
    }

    auto mid = std::chrono::high_resolution_clock::now();

    // Dequeue operation benchmark
    while (!is_empty(queue)) {
        dequeue(queue);
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Enqueue operation for " << MAX_SIZE << " elements took "
        << std::chrono::duration_cast<std::chrono::milliseconds>(mid - start).count() << " ms.\n";
    std::cout << "Dequeue operation for " << MAX_SIZE << " elements took "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - mid).count() << " ms.\n";
}
