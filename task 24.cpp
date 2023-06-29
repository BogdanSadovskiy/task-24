using namespace std;
#include <iostream>
#include <string>
#define task 3
// task1 - creating 2d array and fill it by stars
// task2 - creating two 2d arrays and making the third by addition first and second
// task3 - deleting the space from array 

/////////////////////////////////////////////
//task1
void outTask1(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "--";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "|";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << "--";
    }
    cout << endl;
}
void configTask1(int* arr, int size, char**& str) {
    for (int i = 0; i < size; i++) {
        str[i] = new char[arr[i]];
        for (int j = 0; j < arr[i]; j++) {
            str[i][j] = '*';
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << str[i][j] << " ";
        }
        cout << endl;
    }
}
//////////////////////////////////////////////////

/////////////////////////////////////////////////
//task 2
void create_arrTask2(int**& arr, int**& arr2, int size) {
    int size2;
    for (int i = 0; i < size; i++) {
        cout << "Input of " << i + 1 << " index size ";
        cin >> size2;
        arr[i] = new int[size2+1];
        arr2[i] = new int[size2+1];
        for (int j = 1; j < size2+1; j++) {
            arr[i][j] = rand() % 25 + 1;
            arr2[i][j] = rand() % 16 + 1;
        }
        arr[i][0] = size2;
        arr2[i][0] = size2;
    }
    
}
void outTask2(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < arr[i][0]+1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void addTask2(int** arr, int** arr2, int size) {
    for (int i = 0; i < size; i++) {
        
        for (int j = 1; j < arr[i][0]+1; j++) {
            arr[i][j] = arr[i][j] + arr2[i][j];
        }
    }
    cout << "\nSum of two arrays:\n";
    outTask2(arr, size);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//task3
void delspace(string*& str, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; str[i][j] != '\0'; j++) {
            if (str[i][j] == ' ') {
                for (int k = j; str[i][k] != '\0'; k++) {
                    str[i][k] = str[i][k + 1];
                }
            }
        }
    }
}
int main()
{
#if task == 1
    int size = 0;
    cout << "Input size of arr  ";
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "input " << i + 1 << " element ";
        cin >> arr[i];
    }
    outTask1(arr, size);
    char** str = new char*[size];
    configTask1(arr, size, str);

#elif task ==2
    int size = 0;
    cout << "Input size of arr  ";
    cin >> size;
    int** arr = new int*[size];
    int** arr2 = new int* [size];
    create_arrTask2(arr, arr2, size);
    cout << "\nFirst arr:\n";
    outTask2(arr, size);
    cout << "\nSecond arr:\n";
    outTask2(arr2, size);
    addTask2(arr, arr2, size);

#endif
    const int size = 4;
    string* str = new string[size];
    for (int i = 0; i < size; i++) {
        cout << "Input " << i + 1 << " string\n";
        getline(cin, str[i]);
    }
    cout << "You inputed:\n";
    for (int i = 0; i < size; i++) {
        cout << str[i]<< endl<<endl;
    }
    delspace(str, size);
    cout << "Without spaces:\n";
    for (int i = 0; i < size; i++) {
        cout << str[i] << endl;
    }
}

