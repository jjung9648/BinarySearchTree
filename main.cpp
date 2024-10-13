#include <iostream>
#include <string>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;

int main()//Test two classes in BinarySearchTree.h
{
    int key;//get key from the file
    string s;//get value from the file
    string files[7] = {"areacode.txt", "pokemon.txt", "california.txt", "stooges.txt", "halloween calories 2.txt", "years.txt", "halloween calories.txt" };

    for(int i = 0; i < 7; i++)//make results of all 7 files in files array with for loop
    {
        BinarySearchTree b;
        ofstream output(to_string(i)+"th_testfile.txt");//make output file to write result. Name will be ith_testfile.txt
        output << b.About() << endl;//test About() method
        output << files[i] << "(Empty tree test):" << endl << b.ToTree() << endl << endl;//testing the case tree is empty. No ascii tree will be made
        output << b.ToSortedList() << endl << endl << endl;//testing the case tree is empty. No sorted tree will be made
        cout << "what do you want to find at " + files[i] + "?(Result must empty): ";//testing the case tree is empty, nothing will be found
        output << "what do you want to find at " + files[i] + "?(Result must empty): ";//printing the result at both terminal and output file
        int number;
        cin >> number;
        output << number << endl;
        string found = b.Find(number);//test Find() method. Get the result at found string(no result)
        cout << found << endl;
        output << found << endl;
        ifstream input(files[i]);//open the input file to add the contents of tree
        input >> key;//get key from the file
        getline(input,s);//remove the empty space
        getline(input,s);//get value from the file
        while (isspace(s.back()))//remove space at the end of the string of s
        {
            s.pop_back();
        }
        while (s != "END")//read the file and get key and values until value got is END
        {
            b.Add(key, s);//add method() test
            input >> key;//get key from the file
            getline(input,s);//remove the empty space
            getline(input,s);//get value from the file
            while (isspace(s.back()))//remove space at the end of the string of s
            {
                s.pop_back();
            }
        }
        input.close();//close the input file
        output << files[i] << ":" << endl << b.ToTree() << endl << endl;//test ToTree() method and write result at the output file
        output << b.ToSortedList() << endl << endl << endl;//test ToSortedList() method and write result at the output file
        cout << "what do you want to find at " + files[i] + "?(type key): ";
        output << "what do you want to find at " + files[i] + "?(type key): ";
        cin >> number;
        output << number << endl;
        found = b.Find(number);//test Find() method and write result at the output file and terminal
        cout << found << endl;
        output << found << endl;
        output.close();//close the output file
    }
}