#pragma once

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <string>
#include <chrono>
#include <iostream>
#include <stdexcept>

struct ListNode {
    std::string ipAddress;
    ListNode* next;
};

struct LinkedList {
    ListNode* head;
    int size;
};

void initializeLinkedList(LinkedList& list);
void addIPAddressToList(LinkedList& list, const std::string& ipAddress);
bool removeIPAddressFromList(LinkedList& list, const std::string& ipAddress);
bool findIPAddressInList(const LinkedList& list, const std::string& ipAddress);
void printIPAddressesFromList(const LinkedList& list);
void freeLinkedList(LinkedList& list);




void create_empty(LinkedList& queue);
void enqueue(LinkedList& queue, const std::string& value);
std::string dequeue(LinkedList& queue);
bool is_empty(const LinkedList& queue);
void interactiveModeLinkedList();
void demonstrationModeLinkedList();
void benchmarkModeLinkedList();


#endif 
