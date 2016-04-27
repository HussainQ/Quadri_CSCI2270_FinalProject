/*
Author: Hussain Quadri
Final Project: Hash	Table. Hash Functions. Collision	resolution.
Date: April 20, 2016
Assignment: The purpose of this assignment is to manage a hash table, using
collision resolution by chaining, where the keys are movie titles. Added new
features, based on assignment 12 submission.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "HashTable.h"

using namespace std;

void displayMenu(){

    cout<<"======Main Menu======"<<endl;
    cout<<"1. Insert Movie"<<endl;
    cout<<"2. Read-in movies from file (replaces movies in current table)"<<endl;
    cout<<"3. Delete Movie"<<endl;
    cout<<"4. Delete all Movies"<<endl;
    cout<<"5. Find Movie"<<endl;
    cout<<"6. Print table contents"<<endl;
    cout<<"7. Hash Table Size"<<endl;
    cout<<"8. #Indexes in table"<<endl;
    cout<<"9. Quit"<<endl;
}

int main(){
    HashTable table(10);
    string input;

    int selection = 0;

    while(selection != 9){

        displayMenu();    //Displays Menu
        getline(cin,input);

        selection = atoi(input.c_str());    //Converts input to integer form for if/else-if comparisons

        if(selection == 1){
            string inputMovie;      //Initializing variables
            string inputYear;
            int year;

            cout<<"Enter Title of Movie: ";
            getline(cin,inputMovie);

            cout<<"Index: "<<table.hashSum(inputMovie,10)<<endl;
            cout<<"Enter Year: ";
            getline(cin,inputYear);

            year = atoi(inputYear.c_str());
            table.insertMovie(inputMovie,year);
          }

          if(selection == 2){
              cout<<"WARNING: This will remove the contents of the current databse."<<endl;
              while(input != "Y" && input != "N"){
                  cout<<"Would you like to read data from a file? (Y/N): ";
                  getline(cin,input);
              }
              if(input == "Y"){
                  bool checker = false;     //Initializing variable to check if file has been read or not
                  while(checker == false){
                      cout<<"Enter Name of File: ";
                      getline(cin,input);
                      table.deleteAll();      //Coud not get it to append to current table.
                      checker = table.readFile(input);
                  }
              }
          }

          if(selection == 3){
              string inputMovie;
              cout<<"Enter Title of Movie: ";
              getline(cin,inputMovie);
              table.deleteMovie(inputMovie);
          }

          if(selection == 4){
              cout<<"Deleting Table"<<endl;
              table.deleteAll();
          }

        if(selection == 5){
            string inputMovie;
            cout<<"Enter Title of Movie: ";
            getline(cin,inputMovie);
            table.findMoviePlus(inputMovie);
        }

        if(selection == 6){
            cout<<"Printing Contents"<<endl;
            table.printInventory();
        }

        if(selection == 7){
            table.tableSize();
        }

        if(selection == 8){
            table.totalInventory();
        }
    }

    table.~HashTable();
    cout<<"Goodbye!"<<endl;

    return 0;
}
