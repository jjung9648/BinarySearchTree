#include <iostream>
#include <string>
#include <fstream>
#include "BinarySearchTree.h"
#include "LinearDataStorage.h"
using namespace std;
#include <chrono>
using namespace std::chrono;
#include <iomanip>

int main()//Test two classes in BinarySearchTree.h
{
    int key;//get key from the file
    string s;//get value from the file
    string files[7] = {"areacode.txt", "pokemon.txt", "california.txt", "stooges.txt", "halloween calories 2.txt", "years.txt", "halloween calories.txt" };

    // only for test.
    int testArr[7] = {949, 1, 53, 40, 200, 2023, 920};

    // to check duration
    double avgTimeLin = 0;
    double avgTime = 0;

    for(int i = 0; i < 7; i++)//make results of all 7 files in files array with for loop
    {
        BinarySearchTree b;
        ofstream output(to_string(i)+"th_testfile.txt");//make output file to write result. Name will be ith_testfile.txt
        output << b.About() << endl;//test About() method
        output << files[i] << "(Empty tree test):" << endl << b.ToTree() << endl << endl;//testing the case tree is empty. No ascii tree will be made
        output << b.ToSortedList() << endl << endl << endl;//testing the case tree is empty. No sorted tree will be made
        cout << "what do you want to find at " + files[i] + "?(Result must empty): ";//testing the case tree is empty, nothing will be found
        output << "what do you want to find at " + files[i] + "?(Result must empty): ";//printing the result at both terminal and output file
        // int number;
        // cin >> number;
        // for test
        int number = testArr[i];
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
        // cin >> number;
        output << number << endl;
        auto start = high_resolution_clock::now();// check duration of find method
        found = b.Find(number);//test Find() method and write result at the output file and terminal
        auto end = high_resolution_clock::now();// finish checking duraton
        auto duration = duration_cast<microseconds>(end - start);
        avgTime = avgTime + duration.count() / 1000.0;
        cout << found << endl;
        output << found << endl;
        output.close();//close the output file
    }

    for(int i = 0; i < 7; i++)//make results of all 7 files in files array with for loop
    {
        LinearDataStorage b;
        ofstream output(to_string(i)+"th_testfile_linear.txt");//make output file to write result. Name will be ith_testfile.txt
        output << b.About() << endl;//test About() method
        output << files[i] << "(Empty tree test):" << endl << b.ToTree() << endl << endl;//testing the case tree is empty. No ascii tree will be made
        // output << b.ToSortedList() << endl << endl << endl;//testing the case tree is empty. No sorted tree will be made
        cout << "what do you want to find at " + files[i] + "?(Result must empty): ";//testing the case tree is empty, nothing will be found
        output << "what do you want to find at " + files[i] + "?(Result must empty): ";//printing the result at both terminal and output file
        // int number;
        // cin >> number;
        // for test
        int number = testArr[i];
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
        // output << b.ToSortedList() << endl << endl << endl;//test ToSortedList() method and write result at the output file
        cout << "what do you want to find at " + files[i] + "?(type key): ";
        output << "what do you want to find at " + files[i] + "?(type key): ";
        // cin >> number;
        output << number << endl;
        auto start = high_resolution_clock::now();// check duration of find method
        found = b.Find(number);//test Find() method and write result at the output file and terminal
        auto end = high_resolution_clock::now();// finish checking duraton
        auto duration = duration_cast<microseconds>(end - start);
        avgTimeLin = avgTimeLin + duration.count() / 1000.0;
        cout << found << endl;
        output << found << endl;
        output.close();//close the output file
    }

    cout << "BST average time: " << fixed << setprecision(3) << avgTime/7 << " μs" << endl;
    cout << "Linear average time: " << fixed << setprecision(3) << avgTimeLin/7 << " μs" << endl;

    double improvement = (avgTimeLin/7) / (avgTime/7);
    cout << "BST is " << fixed << setprecision(1) << improvement << "times faster" << endl;

    cout << "\n \"Achieved " << (int)improvement << "x faster search performance\"" << endl;

}