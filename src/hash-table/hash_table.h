/**
    hash_table.h
    @author Keisuke Suzuki
    @version 1.0 7/28/20
    Purpose: To Define HashTable class
    
    License: Copyright (c) 7/28/20 Keisuke Suzuki
    	This program is free software: you can redistribute it and/or modify
    	it under the terms of the GNU General Public License as published by
    	the Free Software Foundation, either version 3 of the License, or
    	(at your option) any later version.
  
    	This program is distributed in the hope that it will be useful,
    	but WITHOUT ANY WARRANTY; without even the implied warranty of
    	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    	GNU General Public License for more details
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "../hash-item/_hash_item.h"
#include "_hash_table.h"
#include <vector>
#include <string>
#include <exception>

#define DEBUG(x) {std::cout<<x<<endl;}

class HashTable: public __HashTable
{
    
    public:
    
    /** hash-table() is a parametrized constructor
     *  which initialize all the member valuables
     *  @param size=INITIAL_SIZE
     */
    explicit HashTable(int= INITIAL_SIZE);
    
    /** hash-table() is a copy constructor
     *  @param rhs
     */
    HashTable(const HashTable &rhs);
    
    /** hash-table() is an assignment operator
     * @param other
     * @return this pointer
     */
    HashTable &operator =(const HashTable &other);
    
    /** find() searches in table for given item
     *  @precondition: item's key value is initialized
     *  @postcondition: if matching item is found, it is filled with value from
     *                  table.
     *  @param  ItemType [in,out] item : item to search for
     *  @return int 0 if item is not in table, and 1 if it is
     */
    int find(__ItemType &item) const override;
    
    /** insert() inserts the given item into the table
     *  @precondition: item is initialized
     *  @postcondition: if item is not in table already, it is inserted
     *  @param  ItemType [in] item : item to insert
     *  @return int 0 if item is not inserted in table, and 1 if it is
     */
    int insert(__ItemType item) override;
    
    /** remove() removes the specified  item from the table, if it is there
     *  @precondition: item's key is initialized
     *  @postcondition: if item was in table already, it is removed and copied
     *                  into the parameter, item
     *  @param  ItemType [in, out] item : item to remove
     *  @return int 0 if item is not removed from the table, and 1 if it is
     */
    int remove(__ItemType item) override;
    
    /** size() returns the number of items in the table
     *  @precondition: none
     *  @postcondition: none
     *  @return int the number of items in the table
     */
    int size() const override;
    
    /** listall() lists all element in the table and returns number of
     * element in the table
     * @param os
     * @return int
     */
    int listall(ostream &os) const override;
    
    private:
    
    // pointer of vector which stores ItemType of vector
    vector <__ItemType> hash_table;
    
    // pointer of vector which stores states of table
    vector <string> table_status;
    
    //number of elements in the table
    size_t current_size;
    
    /** makeEmpty sets all items in hash_table EMPTY
     *  @precondition: hash_table is initialized
     *  @postcondition: all the elements in hash_table is set as EMPTY
     */
    void makeEmpty();
    
    /** findPos() finds an int value which have not been used as an index
     *  for hash_table and return the value by using quadratic probing
     *  @param item to be hashed
     *  @return an int number as an index for hash_table
     */
    int findPos(const __ItemType &item) const;
    
    /** hash() calculates the value by bit-shifting square method
     *  @param key
     *  @param table_size
     *  @return unsigned int
     */
    unsigned int hash(unsigned int key, int table_size) const;
    
    /** isActive returns if the location of hash_table is Active or not
     *  @param current_pos
     *  @return true if the position in hash_table is active otherwise false
     */
    bool isActive(int current_pos) const;
    
    /** rehash() resize the hash_table to next prime number of twice
     *  of TABLE_SIZE, and insert all the elements in hash_table hashed
     *  by the new size
     *  @precondition current_size is greater than half of TABLE_SIZE
     *  @postcondition TABLE_SIZE is next prime number of double of TABLE_SIZE,
     *  and all elements are with new index values hashed by TABLE_SIZE
     */
    void rehash();
};

#endif /* HASH_TABLE_H */
