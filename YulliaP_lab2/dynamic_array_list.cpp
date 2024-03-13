#include "dynamic_array_list.h"


void initDynamicArrayList(DynamicArrayList& list, int initialCapacity) {
    list.size = 0;
    list.capacity = initialCapacity;
    list.ipAddresses = new std::string[list.capacity];
}

void freeDynamicArrayList(DynamicArrayList& list) {
    delete[] list.ipAddresses;
    list.ipAddresses = nullptr;
    list.size = 0;
    list.capacity = 0;
}

void resizeDynamicArrayList(DynamicArrayList& list, int newCapacity) {
    std::string* temp = new std::string[newCapacity];
    for (int i = 0; i < list.size; i++) {
        temp[i] = list.ipAddresses[i];
    }
    delete[] list.ipAddresses;
    list.ipAddresses = temp;
    list.capacity = newCapacity;
}

void addIPAddress(DynamicArrayList& list, const std::string& ipAddress) {
    if (list.size == list.capacity) {
        resizeDynamicArrayList(list, list.capacity * 2); // Збільшуємо розмір у 2 рази
    }
    list.ipAddresses[list.size] = ipAddress;
    list.size++;
}

bool removeIPAddress(DynamicArrayList& list, const std::string& ipAddress) {
    for (int i = 0; i < list.size; i++) {
        if (list.ipAddresses[i] == ipAddress) {
            for (int j = i; j < list.size - 1; j++) {
                list.ipAddresses[j] = list.ipAddresses[j + 1];
            }
            list.size--;
            return true;
        }
    }
    return false;
}

int findIPAddress(const DynamicArrayList& list, const std::string& ipAddress) {
    for (int i = 0; i < list.size; i++) {
        if (list.ipAddresses[i] == ipAddress) {
            return i;
        }
    }
    return -1;
}

void printIPAddresses(const DynamicArrayList& list) {
    std::cout << "IP Addresses:" << std::endl;
    for (int i = 0; i < list.size; i++) {
        std::cout << list.ipAddresses[i] << std::endl;
    }
}






void create_empty(DynamicArrayList& queue) {
    queue.size = 0;
    queue.capacity = 0;
    queue.ipAddresses = nullptr;
}

void enqueue(DynamicArrayList& queue, const std::string& ipAddress) {
    if (queue.size == queue.capacity) {
        int newCapacity = (queue.capacity == 0) ? 1 : (queue.capacity * 2);
        resizeDynamicArrayList(queue, newCapacity);
    }
    queue.ipAddresses[queue.size++] = ipAddress;
}

std::string dequeue(DynamicArrayList& queue) {
    if (queue.size == 0) {
        throw std::out_of_range("Queue is empty");
    }
    std::string result = queue.ipAddresses[0];
    for (int i = 0; i < queue.size - 1; ++i) {
        queue.ipAddresses[i] = queue.ipAddresses[i + 1];
    }
    queue.size--;
    if (queue.size < queue.capacity / 4) {
        resizeDynamicArrayList(queue, queue.capacity / 2);
    }
    return result;
}

bool is_empty(const DynamicArrayList& queue) {
    return queue.size == 0;
}

void interactiveModeDynamicArray() {
    DynamicArrayList queue;
    initDynamicArrayList(queue, 1);  // Початкова ємність встановлена як 1

    int choice;
    std::string value;
    while (true) {
        std::cout << "\n1. Enqueue\n2. Dequeue\n3. Check if Empty\n4. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to enqueue: ";
            std::cin >> value;
            enqueue(queue, value);
            break;
        case 2:
            if (!is_empty(queue)) {
                std::cout << "Dequeued: " << dequeue(queue) << std::endl;
            }
            else {
                std::cout << "Queue is empty.\n";
            }
            break;
        case 3:
            std::cout << (is_empty(queue) ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;
        case 4:
            freeDynamicArrayList(queue);
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void demonstrationModeDynamicArray() {
    DynamicArrayList queue;
    initDynamicArrayList(queue, 2);  // Демонстрація з початковою ємністю 2

    std::cout << "Demonstrating Dynamic Array Queue operations:\n";
    enqueue(queue, "192.168.1.1");
    enqueue(queue, "192.168.1.2");
    std::cout << "After enqueue two elements:\n";
    printIPAddresses(queue);

    std::cout << "Dequeue operation: " << dequeue(queue) << std::endl;
    std::cout << "After dequeue one element:\n";
    printIPAddresses(queue);

    freeDynamicArrayList(queue);
}

void benchmarkModeDynamicArray() {
    DynamicArrayList queue;
    initDynamicArrayList(queue, 1);

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        enqueue(queue, "Item " + std::to_string(i));
    }
    auto mid = std::chrono::high_resolution_clock::now();
    while (!is_empty(queue)) {
        dequeue(queue);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Dynamic Array Queue Enqueue 10000 items: "
        << std::chrono::duration_cast<std::chrono::microseconds>(mid - start).count()
        << " microseconds.\n";
    std::cout << "Dynamic Array Queue Dequeue 10000 items: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end - mid).count()
        << " microseconds.\n";

    freeDynamicArrayList(queue);
}