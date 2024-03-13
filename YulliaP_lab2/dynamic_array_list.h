#pragma once

#ifndef DYNAMIC_ARRAY_LIST_HPP
#define DYNAMIC_ARRAY_LIST_HPP

#include <iostream>
#include <string>
#include <chrono>

struct DynamicArrayList {
    std::string* ipAddresses; // Вказівник на динамічний масив для зберігання IP-адрес
    int size; // Поточна кількість збережених IP-адрес
    int capacity; // Поточний розмір масиву
};

void initDynamicArrayList(DynamicArrayList& list, int initialCapacity); 
void freeDynamicArrayList(DynamicArrayList& list); 
void resizeDynamicArrayList(DynamicArrayList& list, int newCapacity); 
void addIPAddress(DynamicArrayList& list, const std::string& ipAddress); 
bool removeIPAddress(DynamicArrayList& list, const std::string& ipAddress); 
int findIPAddress(const DynamicArrayList& list, const std::string& ipAddress); 
void printIPAddresses(const DynamicArrayList& list); 


void create_empty(DynamicArrayList& queue);
void enqueue(DynamicArrayList& queue, const std::string& ipAddress);
std::string dequeue(DynamicArrayList& queue);
bool is_empty(const DynamicArrayList& queue);
void interactiveModeDynamicArray();
void demonstrationModeDynamicArray();
void benchmarkModeDynamicArray();

#endif 