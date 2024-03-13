#pragma once

#ifndef FIXED_ARRAY_LIST_HPP
#define FIXED_ARRAY_LIST_HPP

#include <iostream>
#include <string>
#include <chrono>

const int MAX_SIZE = 100; 

struct FixedArrayList {
    std::string ipAddresses[MAX_SIZE]; // Масив для зберігання IP-адрес
    int size = 0; // Поточна кількість збережених IP-адрес
};

void initializeFixedArrayList(FixedArrayList& list); 
bool addIPAddress(FixedArrayList& list, const std::string& ipAddress); 
bool removeIPAddress(FixedArrayList& list, const std::string& ipAddress); 
int findIPAddress(const FixedArrayList& list, const std::string& ipAddress); 
void printIPAddresses(const FixedArrayList& list); 


void create_empty(FixedArrayList& queue);
bool enqueue(FixedArrayList& queue, const std::string& ipAddress);
std::string dequeue(FixedArrayList& queue);
bool is_empty(const FixedArrayList& queue);
void interactiveModeFixedSizeArray();
void demonstrationModeFixedSizeArray();
void benchmarkModeFixedSizeArray();

#endif 

