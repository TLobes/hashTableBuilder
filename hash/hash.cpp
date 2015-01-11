//
//  hash.cpp
//  hash
//
//  Created by Tim Lobes on 1/11/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#include "hash.h"
#include <iostream>
#include <string>

hash::hash() {
    for (int i = 0; i < tableSize; i++) {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
    }
}

void hash::AddItem(std::string name, std::string drink) {
    int index = Hash(name);
    
    if (HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else
    {
        item* Ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        
        while(Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }
        
        Ptr->next = n;
    }
        
};

int hash::Hash(std::string key) {
    int hash = 0;
    //int index;
    
    for (int i = 0; i < key.length(); i++) {
        hash = hash + (int)key[i];
        std::cout << "hash = " << hash << std::endl;
    }
    
    return hash % tableSize;
};