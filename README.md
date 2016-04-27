# Quadri_CSCI2270_FinalProject
# Project Summary:

The plan for this project is to expand on the movie assignment we did a few months ago, and to incorporate hash functions, as well as add a few more extra options to make the program more suitable to the user.
The final project is built off of Assignment 12. It uses the Movies text file from assignment 5 (but can also work without one, just making the user add all the movies manually). The user will be able to add/delete movies from the hash table, even by choosing to copy data from an external text file. Also include options to search hashTable for movies, delete a single/all movies from the table, view table contents, view table size and number of indexes created within the table. The findMovie function has been improved to use the hash indexes in order to search for a movie, making the process more effecient and faster.
The program works by running the main driver file (explained later).

# How to Run:

In order to run the files, you must download the .cpp, .h, and Movies.txt files. Make sure all these files are in the same directory.
This guide assumes the user is using the G++ compiler. The code is written in C++11 standard, hence the following command:
```
g++ -std=c++11 mainDriver.cpp HashTable.cpp HashTable.h
```
Once compiled, an executable file will be formed. From terminal, run the executable and you will be met with the following:
```
======Main Menu======
1. Insert Movie
2. Read-in movies from file (replaces movies in current table)
3. Delete Movie
4. Delete all Movies
5. Find Movie
6. Print table contents
7. Hash Table Size
8. #Indexes in table
9. Quit
```
You are recommended to run option 2 first in order to read in the file. Just enter "Y", then the name of the file (with extention) when prompted:
```
2
WARNING: This will remove the contents of the current databse.
Would you like to read data from a file? (Y/N): Y
Enter Name of File: Movies.txt
```
Once the data is read in, you may use all the other options.
Options 1, 3, 5 are similar. All will prompt you for the name of the movie you would like to find/delete/insert. Follow the prompts and input the reuired data.

Option 4 simply calls the deleteMovie function on each element in the hash table.

Option 6 Prints out the contents of the hash table. 
Option 7 prints out the number of elements in the hash table.
Option 8 prints the number of indexes in the hash table.

To quit the program, just enter 9 at the main menu. Alternately to end the program anywhere, use ctrl +C on your keyboard to force quit.

NOTE: Please enter year in 4 digit integers. All strings must be proper. Parameters for search/delete must be exact (take a look at the Movies text file to be sure). 

# System requirements:
- Linux or Windows OS with C++ compiler software.
- Decent processor
- > 512 MB RAM (Why not?)

# Group Members:
None

Contributers: 
[Insert Here]

# Open Issues/Bugs:

Option 8 tends to work correctly when the user has inserted atleast two more movies atop the data file.
