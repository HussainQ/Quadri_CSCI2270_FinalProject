#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

//Removed previous pointer, instead uses pointer created in main class file.
//Creating element types in hashtable, used when organizing movies into table.
struct HashElem{
    std::string title;
    int year;
    int index;
    HashElem *next = NULL;
    //HashElem *previous = NULL;
    HashElem(){};


    HashElem(std::string in_title, int in_year,int in_index)
    {
        title = in_title;
        year = in_year;
        index = in_index;
        //next = NULL;
    		//previous = NULL;
    }

};

class HashTable
{
    public:
        HashTable(int);
        ~HashTable();

        bool readFile(std::string);
        void deleteAll();
        void tableSize();
        void totalInventory();
        int sum(std::string);
        void findMoviePlus(std::string);
        int hashSum(std::string, int);
        void insertMovie(std::string in_title, int);
        //void findMovie(std::string in_title);
        void deleteMovie(std::string in_title);
        void printInventory();

    protected:
    private:
        HashElem *hashTable[10];
};

#endif // HASHTABLE_H
