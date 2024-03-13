#include "linked_list.h"


void initializeLinkedList(LinkedList& list) {
    list.head = nullptr;
    list.size = 0;
}

void addIPAddressToList(LinkedList& list, const std::string& ipAddress) {
    ListNode* newNode = new ListNode{ ipAddress, nullptr };
    if (!list.head) {
        list.head = newNode;
    }
    else {
        ListNode* current = list.head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    list.size++;
}

bool removeIPAddressFromList(LinkedList& list, const std::string& ipAddress) {
    ListNode* current = list.head, * prev = nullptr;
    while (current) {
        if (current->ipAddress == ipAddress) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                list.head = current->next;
            }
            delete current;
            list.size--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

bool findIPAddressInList(const LinkedList& list, const std::string& ipAddress) {
    ListNode* current = list.head;
    while (current) {
        if (current->ipAddress == ipAddress) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void printIPAddressesFromList(const LinkedList& list) {
    ListNode* current = list.head;
    while (current) {
        std::cout << current->ipAddress << std::endl;
        current = current->next;
    }
}

void freeLinkedList(LinkedList& list) {
    ListNode* current = list.head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
    list.head = nullptr;
    list.size = 0;
}





void create_empty(LinkedList& queue) {
    queue.head = nullptr;
}

void enqueue(LinkedList& queue, const std::string& value) {
    ListNode* newNode = new ListNode{ value, nullptr };
    if (!queue.head) {
        queue.head = newNode;
    }
    else {
        ListNode* current = queue.head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

std::string dequeue(LinkedList& queue) {
    if (!queue.head) {
        throw std::out_of_range("Queue is empty");
    }
    ListNode* temp = queue.head;
    std::string value = temp->ipAddress;
    queue.head = queue.head->next;
    delete temp;
    return value;
}

bool is_empty(const LinkedList& queue) {
    return queue.head == nullptr;
}

void interactiveModeLinkedList() {
    LinkedList queue;
    initializeLinkedList(queue); // Створення пустої черги

    std::string value;
    int choice;

    while (true) {
        std::cout << "\n1. Enqueue \n2. Dequeue \n3. Check if Empty\n4. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to enqueue: ";
            std::cin >> value;
            enqueue(queue, value);  // Припускаємо, що функція enqueue не обмежена розміром черги
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
            return;  // Вихід із інтерактивного режиму
        default:
            std::cout << "Invalid choice.\n";
        }
    }
}

void demonstrationModeLinkedList() {
    LinkedList queue;
    initializeLinkedList(queue); // Створення пустої черги

    std::cout << "\n--- Demonstration of Linked List Queue ---\n";

    enqueue(queue, "10.0.0.1");
    std::cout << "Enqueued: 10.0.0.1\n";

    enqueue(queue, "10.0.0.2");
    std::cout << "Enqueued: 10.0.0.2\n";

    std::cout << "Dequeued: " << dequeue(queue) << "\n";
    std::cout << "Dequeued: " << dequeue(queue) << "\n";

    std::cout << (is_empty(queue) ? "Queue is empty now.\n" : "Queue is not empty.\n");
}

void benchmarkModeLinkedList() {
    LinkedList queue;
    initializeLinkedList(queue); // Створення пустої черги

    auto start = std::chrono::high_resolution_clock::now();

    // Enqueue operation benchmark
    for (int i = 0; i < 10000; ++i) {  // Припустимо, MAX_SIZE = 10000
        enqueue(queue, "Item " + std::to_string(i));
    }

    auto mid = std::chrono::high_resolution_clock::now();

    // Dequeue operation benchmark
    while (!is_empty(queue)) {
        dequeue(queue);
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Enqueue operation for 10000 elements took "
        << std::chrono::duration_cast<std::chrono::milliseconds>(mid - start).count() << " ms.\n";
    std::cout << "Dequeue operation for 10000 elements took "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - mid).count() << " ms.\n";
}


