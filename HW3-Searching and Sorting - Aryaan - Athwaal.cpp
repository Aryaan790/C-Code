#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include<ctime>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& a);

void printVector(vector<int> a);

void searchVector(vector<int> vec);

int binarySearch(vector<int> vec, int a, int b, int c);

int counter = 0;

int main()
{
    //Create vector 1 and vector 2
    vector<int> vec1, vec2;


    // Use current time as seed for random generator
    srand((unsigned)time(0));


    int N, ranSize;

    cout << "How many numbers to generate ? : "; // Ask user for vector size
    cin >> N; // Save user vector size


    vec1.reserve(N);

    //Ask user for range of random numbers
    cout << "Enter how large the random numbers should be: ";
    cin >> ranSize;

    //Generate Random Numbers and add to vector
    for (int i = 0; i < N; i++) {
        int randomNum = 1 + (rand() % ranSize);
        vec1.push_back(randomNum);
    }

    //Print out Vector Content
    cout << "\nVector Contents: ";
    for (int i = N - 1; i >= 0; i--) {
        cout << vec1[i] << " ";
    }
    cout << "\nVector Size: " << (int)vec1.size() << " numbers.\n";
    cout << "Vector Capacity: " << (int)vec1.capacity() << " numbers.\n";

    //Copy Vector 1 to Vector 2
    for (int i = 0; i < vec1.size(); i++)
        vec2.push_back(vec1[i]);

    //Print New Vector 2 Elements
    cout << "\nVector 2 elements are : ";

    for (int i = 0; i < vec2.size(); i++)
        cout << vec2[i] << " ";
    cout << endl;

    //Sort Vector 1
    sort(vec1.begin(), vec1.end());

    //Print Sorted Vector 1
    cout << "\nSorted Vector 1: ";
    printVector(vec1);


    //Sort Vector 2 Using Bubble Sort
    bubbleSort(vec2);

    //Print Vector 2 Elements after Bubble sort
    cout << "\n\nVector 2 elements after bubble sort are: " << endl;
    printVector(vec2);


    cout << "\n\nThe values of Vector 1 are : " << endl;
    printVector(vec1);

    int searchValue;
    int n = vec1.size() - 1;

    cout << "\nEnter search value: " << endl;
    cin >> searchValue;

    int index = binarySearch(vec1, 0, n, searchValue);
    if (index == -1) {
        cout << searchValue << " was not found." << endl;
    }
    else {
        cout << searchValue << " is present at index " << index << endl;
        cout << searchValue << " was found " << counter << " times." << endl;
    }

    // Delete Duplicates
    for (int i = 0; i < vec1.size(); i++) {
        for (int j = i + 1; j < vec1.size(); j++) {
            if (vec1[i] == vec1[j]) {
                cout << "Duplicate value " << vec1[i]
                    << " at indices " << i << ", " << j << endl;
                vec1.erase(vec1.begin() + i);
            }
        }
    }
    cout << "Vector after deletion of duplicates: ";
    printVector(vec1);



    return 0;
}

void bubbleSort(vector<int>& a)
{
    bool swapp = true;
    while (swapp) {
        swapp = false;
        for (size_t i = 0; i < a.size() - 1; i++) {
            if (a[i] > a[i + 1]) {
                a[i] += a[i + 1];
                a[i + 1] = a[i] - a[i + 1];
                a[i] -= a[i + 1];
                swapp = true;
            }
        }
    }
}

void printVector(vector<int> a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << " ";

    }
}

void searchVector(vector<int> vec) {

    int ser, count = 0;

    cout << "Enter a number to search in Vector: " << endl;
    cin >> ser;

    sort(vec.begin(), vec.end());
    for (int i = 0; i <= vec.size(); i++) {
        if (ser == vec[i]) {
            count++;
        }
    }
    if (count > 0) {
        cout << "Element Found " << count << " times." << endl;
    }
    else {
        cout << "Element Not Found." << endl;
    }

}
int binarySearch(vector<int> v, int start, int finish, int num) {

    if (start <= finish) {
        int mid = (start + finish) / 2;
        if (v[mid] == num) {
            counter++;
            if ((v[mid + 1] == num) && (v[mid - 1] == num)) {
                counter += 2;
            }
            else if (v[mid + 1] == num) {
                counter++;
            }
            else if (v[mid - 1] == num) {
                counter++;
            }
            return mid;
        } if (v[mid] > num) {
            return binarySearch(v, start, mid - 1, num);
        } if (v[mid] < num) {
            return binarySearch(v, mid + 1, finish, num);
        }
    }
    return -1;
}
