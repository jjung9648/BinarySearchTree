#include <iostream>
#include <string>
using namespace std;

class Nodel//linear tree will be consist with Node
{
public:
    Nodel *apRight;//right child
    int aKey;//The key to find the value.
    string aValue;//The value that the node contains.
    Nodel(int rKey, string rValue)//constructor
    {
        aKey = rKey;
        aValue = rValue;
    }
    string ToTree()//Returns a string of the tree’s structure. 
    {
        string result = "";
        result = result + " --> " + "(" + to_string(aKey) + ") " + aValue;//add label, key, and value of the node

        if (apRight != nullptr)//if right child of current node exists, change current node to that and and rIndent+1
        {
            result += apRight->ToTree();
        }
        return result;
    }
    // string ToSortedList()//Returns a string sorted by the key.
    // {
    //     string result = "";
    //     if (apLeft != nullptr)//if left child is not null, change current node to that
    //     {
    //         result += apLeft->ToSortedList();
    //     }
    //     result = result + "(" + to_string(aKey) + ") " + aValue + ", " ;//add key, value, and comma at string
    //     if (apRight != nullptr)//if right child is not null, change current node to that
    //     {
    //         result += apRight->ToSortedList();
    //     }
    //     return result;
    // }
    void Add(int rKey, string rValue)//Adds the key to the correct position in the BST. If the key already exists, do nothing.
    {
        if (apRight == nullptr)//if right child of current node is null, set current node to right child
        {
            apRight = new Nodel(rKey, rValue);
        }
        else//if right child of current node is not null, set current node to right child
        {
            apRight->Add(rKey, rValue);
        }
    }
    string Find(int rKey)//Finds a node with the key and returns its value. If the node is not found, you can return an empty string.
    {
        string result;
        if (aKey == rKey)//if current aKey and rKey is same, result is the value of current node
        {
            result = aValue;
        }
        else
        {
            if (apRight == nullptr){
                return "";
            }
            result = apRight->Find(rKey);
        }
        return result;//return result which is a value or empty string.
    }
};

class LinearDataStorage//simply starts recursion of the root itself
{
private:
    Nodel *apRoot;//root node of the binary tree
public:
    LinearDataStorage() : apRoot(nullptr) {}//Constructor
    string About()//Returns text about you – the author of this class.
    {
        return "This program is made by Jaehee Jung in class 130";
    }
    void Add(int rKey, string rValue)//Adds the key to the correct position in the BST. If the key already exists, do nothing.
    {
        if (apRoot == nullptr)//if apRoot is null, it means added node will be the root. set apRoot to new node
        {
            apRoot = new Nodel(rKey, rValue);
        }
        else//if root node exists, start recursion from root node
        {
            apRoot->Add(rKey, rValue);
        }
    }
    string ToTree()//Returns a string of the tree’s structure. It will start recursion from the root node with indent 0 and a label of "Root".
    {
        string result;
        if (apRoot == nullptr)//if root node does not exists, it means there's nothing to print, result is empty space.
        {
            result = "";
        }
        else//if root node exists,start recursion from root node
        {
            result = apRoot->ToTree();
        }
        return result;
    }

    // string ToSortedList()//Returns a string sorted by the key.
    // {
    //     string result;
    //     if (apRoot == nullptr)//if root node does not exists, it means there's nothing to print, result is empty space.
    //     {
    //         result = "";
    //     }
    //     else//if root node exists,start recursion from root node
    //     {
    //         result = apRoot->ToSortedList();
    //         result.pop_back();//pop back space and comma at the end of the string
    //         result.pop_back();
    //     }
    //     return result;
    // }

    string Find(int rKey)//Finds a node with the key and returns the value. If the node is not found, you can return an empty string.
    {
        string result;
        if (apRoot == nullptr)//if no root node, nothing in the tree. result is empty string
        {
            result = "";
        }
        else//if root node exists,start recursion from root node
        {
            result = apRoot->Find(rKey);
        }
        return result;
    }
};