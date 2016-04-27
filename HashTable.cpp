#include "HashTable.h"
using namespace std;

HashTable::HashTable(int tableSize)
{
    for(int i = 0;i < tableSize;i++){
        hashTable[i] = NULL;
    }
    //ctor
}

int HashTable::hashSum(string hashString, int size){    //x is string to hash, s is size of array
    int sum = 0;

    for(int i = 0; i < hashString.length(); i++){
        sum = sum + hashString[i];
    }

    sum = sum % size;
    return sum;
}

int HashTable::sum(string hashString){
    int sum = 0;

    for(int i = 0; i < hashString.length(); i++){
        sum = sum + hashString[i];
    }

    return sum;
}

void HashTable::insertMovie(string name,int year){
    int index = hashSum(name, 10);
    bool firstSearch = true;

    if(hashTable[index] == NULL){
        hashTable[index] = new HashElem(name, year, index);
    }

    else{
        HashElem* previous = hashTable[index];
        HashElem* tempC = hashTable[index];
        HashElem* Insert = new HashElem(name, year, index);

        while(tempC->next != NULL){

            if(name.compare(tempC->title) >= 0){
                previous = tempC;
                tempC = tempC->next;
            }

            else{
                Insert->next = tempC->next;
                break;
            }

            firstSearch = false;
        }

        if(firstSearch == true){
            if(name.compare(hashTable[index]->title)<0){
                Insert->next = hashTable[index];
                hashTable[index] = Insert;
                return;
            }

            else{
                hashTable[index]->next = Insert;
                return;
            }
        }

        if(name.compare(tempC->title) < 0){
            Insert->next = tempC;
            previous->next = Insert;
        }

        else{
            tempC->next = Insert;
        }
    }
}

void HashTable::printInventory(){
    for(int i = 0; i < 10; i++){

        if(hashTable[i] != NULL){
            HashElem * tempC = hashTable[i];

            while(tempC != NULL){
                cout<<" Index "<<tempC->index<<": "<<tempC->title<<": "<<tempC->year<<endl;
                tempC = tempC->next;
            }
        }
    }
}

void HashTable::deleteMovie(string name){

    HashElem * previous;
    for(int i = 0; i < 10; i++){

        if(hashTable[i] != NULL){

            previous = hashTable[i];
            HashElem * tempC = hashTable[i];

            if(tempC->title == name && tempC->next == NULL){
                delete tempC;
                hashTable[i] = NULL;
                return;
            }

            if(tempC->title == name && tempC->next != NULL){
                hashTable[i] = tempC->next;
                delete tempC;
                return;
            }

            while(tempC->next != NULL){

                if(tempC->title == name){

                    if(tempC->next != NULL && previous != tempC){
                        HashElem * temp = tempC->next;
                        previous->next = temp;

                        delete tempC;
                        return;
                    }
                }

                previous = tempC;
                tempC = tempC->next;
            }

            if(tempC->title == name){
                delete tempC;
                previous->next = NULL;

                return;
            }
        }
    }

    cout<<"Movie not found."<<endl;
}

//Implemented more effeicient search function that uses hashSum for faster results
/*void HashTable::findMovie(std::string name){

    int index = hashSum(name,tableSize);
    bool found = false;

    if (hashTable[index] != NULL){

        HashElem *temp = new HashElem;
        temp = hashTable[index];

        while(temp!= NULL){

            if (temp->title == name){

                cout << index << ":" << temp->title << ":" << temp->year <<endl;
                found = true;
                break;
            }
            else{
                temp = temp->next;
            }
        }
        if (!found){

            cout << "not found" << endl;
        }
    }
}*/

bool HashTable::readFileIntoTable(string filename){
    ifstream file;
    file.open(filename.c_str());

    if(!file){
        cout<<"Unable to open file. Please try again."<<endl;
        return false;
    }

    string line;
    string segment;
    string title;
    string yearString;
    int year;

    while(!file.eof()){

        getline(file,line);
        istringstream ss(line);
        getline(ss,segment,',');
        getline(ss,title,',');
        getline(ss,yearString);

        year = atoi(yearString.c_str());
        insertMovie(title,year);
    }

    return true;
}

void HashTable::deleteAll(){
    for(int i = 0;i < 10;i++){

        while(hashTable[i] != NULL){
            deleteMovie(hashTable[i]->title);
        }
    }
}


void HashTable::tableSize(){
    int tableSize;

    for(int i = 0; i < 10; i++){

        if(hashTable[i] != NULL){
            HashElem * tempC = hashTable[i];

            while(tempC != NULL){
                tableSize++;
                tempC = tempC->next;
            }
        }
    }

    cout<<"Number of elements in table: "<<tableSize<<endl;
    return;
}

void HashTable::totalInventory(){

    int movieTotal = 0;

    for(int i = 0; i < 10; i++){

        if(hashTable[i] != NULL){
            HashElem * tempC = hashTable[i];

            while(tempC != NULL){
                movieTotal += sum(tempC->title);
                tempC = tempC->next;
            }
        }
    }

    movieTotal = movieTotal % 10;
    cout<<"Total Indexes in table: "<<movieTotal<<endl;
}

void HashTable::findMoviePlus(string name){

    int index = hashSum(name, 10);

    for(int i = 0; i < 10; i++){

        if(i == index && hashTable[i] != NULL){
            HashElem *tempC = hashTable[i];

            while(tempC != NULL){

                if(tempC->title == name){
                    cout<<"Movie Found!"<<endl;
                    cout<<"Index"<<tempC->index<<": "<<tempC->title<<": "<<tempC->year<<endl;

                    return;
                }

                tempC = tempC->next;
            }
        }
    }
    cout<<"Movie not found."<<endl;
}

HashTable::~HashTable()
{
    deleteAll();
    //dtor
}
