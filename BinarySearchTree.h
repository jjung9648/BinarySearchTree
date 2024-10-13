#include <iostream>
#include <string>
using namespace std;

class Node//binary tree will be consist with Node
{
public:
    Node *apLeft;//left child
    Node *apRight;//right child
    int aKey;//The key to find the value.
    string aValue;//The value that the node contains.
    Node(int rKey, string rValue)//constructor
    {
        aKey = rKey;
        aValue = rValue;
    }
    string ToTree(string rLabel, int rIndent)//Returns a string of the tree’s structure. 
    {
        string result = "";
        for (int i = 0; i < rIndent; i++)//make rIndent numbers of indents at the front of the string
        {
            result = result + "    ";
        }
        result = result + rLabel + ": " + "(" + to_string(aKey) + ") " + aValue + "\n";//add label, key, and value of the node

        if (apLeft != nullptr)//if left child of current node exists, change current node to that and and rIndent+1
        {
            result += apLeft->ToTree("L", rIndent+1);
        }
        if (apRight != nullptr)//if right child of current node exists, change current node to that and and rIndent+1
        {
            result += apRight->ToTree("R", rIndent+1);
        }
        return result;
    }
    string ToSortedList()//Returns a string sorted by the key.
    {
        string result = "";
        if (apLeft != nullptr)//if left child is not null, change current node to that
        {
            result += apLeft->ToSortedList();
        }
        result = result + "(" + to_string(aKey) + ") " + aValue + ", " ;//add key, value, and comma at string
        if (apRight != nullptr)//if right child is not null, change current node to that
        {
            result += apRight->ToSortedList();
        }
        return result;
    }
    void Add(int rKey, string rValue)//Adds the key to the correct position in the BST. If the key already exists, do nothing.
    {
        if (rKey < aKey)//if rKey is less than current aKey
        {
            if (apLeft == nullptr)//if left child of current node is null, set left child to new node that has rKey and rValue
            {
                apLeft = new Node(rKey, rValue);
            }
            else//if left child of current node is not null, set current node to left child.
            {
                apLeft->Add(rKey, rValue);
            }
        }
        if (rKey > aKey)//if rKey is greater than current aKey
        {
            if (apRight == nullptr)//if right child of current node is null, set current node to right child
            {
                apRight = new Node(rKey, rValue);
            }
            else//if right child of current node is not null, set current node to right child
            {
                apRight->Add(rKey, rValue);
            }
        }
    }
    string Find(int rKey)//Finds a node with the key and returns its value. If the node is not found, you can return an empty string.
    {
        string result;
        if (aKey == rKey)//if current aKey and rKey is same, result is the value of current node
        {
            result = aValue;
        }
        else if ((aKey > rKey && apLeft == nullptr) || (aKey < rKey && apRight == nullptr))//if not same, but the next node will be null, result is empty string
        {
            result = "";
        }
        else if (aKey > rKey)//if not same, but also has next node, change current node to left child or right child depending on the relationship between aKey and rKey.
        {
            result = apLeft->Find(rKey);
        }
        else
        {
            result = apRight->Find(rKey);
        }
        return result;//return result which is a value or empty string.
    }
};

class BinarySearchTree//simply starts recursion of the root itself
{
private:
    Node *apRoot;//root node of the binary tree
public:
    BinarySearchTree() : apRoot(nullptr) {}//Constructor
    string About()//Returns text about you – the author of this class.
    {
        return "This program is made by Jaehee Jung in class 130";
    }
    void Add(int rKey, string rValue)//Adds the key to the correct position in the BST. If the key already exists, do nothing.
    {
        if (apRoot == nullptr)//if apRoot is null, it means added node will be the root. set apRoot to new node
        {
            apRoot = new Node(rKey, rValue);
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
            result = apRoot->ToTree("Root", 0);
        }
        return result;
    }

    string ToSortedList()//Returns a string sorted by the key.
    {
        string result;
        if (apRoot == nullptr)//if root node does not exists, it means there's nothing to print, result is empty space.
        {
            result = "";
        }
        else//if root node exists,start recursion from root node
        {
            result = apRoot->ToSortedList();
            result.pop_back();//pop back space and comma at the end of the string
            result.pop_back();
        }
        return result;
    }

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