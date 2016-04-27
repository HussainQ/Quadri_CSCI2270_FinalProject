# Quadri_CSCI2270_FinalProject
# Project Summary:

The plan for this project is to expand on the movie assignment we did a few months ago, and to incorporate hash functions, as well as add a few more extra options to make the program more suitable to the user.
The final project is built off of Assignment 12. It uses the Movies text file from assignment 5 (but can also work without one, just making the user add all the movies manually). The user will be able to add/delete movies from the hash table, even by choosing to copy data from an external text file. Also include options to search hashTable for movies, delete a single/all movies from the table, view table contents, view table size and number of indexes created within the table. The findMovie function has been improved to use the hash indexes in order to search for a movie, making the process more effecient and faster.
The program works by running the main driver file (explained later).

# How to Run:

In order to run the files, you must download the .cpp, .h, and Movies.txt files. Once compiled, run the main executable file created.
You will be met with the following:

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

You are recommended to run option 2 first in order to read in the file. Just enter "Y", then the name of the file (with extention) when prompted:

2
WARNING: This will remove the contents of the current databse.
Would you like to read data from a file? (Y/N): Y
Enter Name of File: Movies.txt

Once the data is read in, you may use all the other options.
