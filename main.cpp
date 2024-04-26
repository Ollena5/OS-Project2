#include <iostream>
#include <fstream>
#include <string>
using namespace std;
  
const int PROCESSES = 5;
const int RESOURCES = 3;

bool checkIfSafe(int processes[], int available[], int max[][RESOURCES], int allocated[][RESOURCES]);

int main() {
    int processes[] = { 0, 1, 2, 3, 4 };
    
    //need to check if file can be opened
    ifstream DataTable("dataTable.txt");
    if (!DataTable) {
        cout <<"Failed to open file" <<endl;
        return 0;
    }

//create max, allocation, and available matricies 
    int max[PROCESSES][RESOURCES];
    int allocated[PROCESSES][RESOURCES];
    int available[RESOURCES];

    for (int i = 0; i < PROCESSES; ++i) {
        for (int j = 0; j < RESOURCES; ++j) DataTable >> allocated[i][j];
        for (int j = 0; j < RESOURCES; ++j) DataTable >> max[i][j];
        // first row of file will contain avaliable resources
        if (i == 0) for (int j = 0; j < RESOURCES; ++j) DataTable >> available[j];
    }
//print out the allocated resources
    cout << "Allocated resources: ";
    for (int i = 0; i < PROCESSES; ++i)
        for (int j = 0; j < RESOURCES; ++j) cout << allocated[i][j] << ' ';
    cout <<endl;
//print out the max resources
    cout << "Max resources: ";
    for (int i = 0; i < PROCESSES; ++i)
        for (int j = 0; j < RESOURCES; ++j) cout << max[i][j] << ' ';
    cout <<endl;
//print out the available resources
    cout << "Available resources: ";
    for (int i = 0; i < RESOURCES; ++i) cout << available[i] << ' ';
    cout <<endl;
    checkIfSafe(processes, available, max, allocated);
    return 1;
}
  
bool checkIfSafe(int processes[], int available[], int max[][RESOURCES], int allocated[][RESOURCES]) {
//need matrix
    int need[PROCESSES][RESOURCES];
    for (int i = 0 ; i < PROCESSES ; i++) {
        for (int j = 0 ; j < RESOURCES ; j++) need[i][j] = max[i][j] - allocated[i][j];
    }
    bool done[PROCESSES] = {0};
    int sequence[PROCESSES];
    int work[RESOURCES];
    for (int i = 0; i < RESOURCES; i++) work[i] = available[i];
    int count = 0;
    while (count < PROCESSES) {
        bool found = false;
        for (int p =0; p < PROCESSES; p++) {
            if (done[p] == 0) {
                int j =0;
                for (j =0; j <RESOURCES; j++) {
                    if (need[p][j] > work[j]) break;
                }
                if (j ==RESOURCES) {
                    for (int k =0 ; k <RESOURCES; k++) work[k] +=allocated[p][k];
                    sequence[count++] = p;
                    done[p] = 1;
                    found = true;
                }
            }
        }
        if (!found) {
            cout <<"The system is not in a safe state." <<endl;
            return false;
        }
    }
    cout <<"The system is in a safe state. The safe sequence is: ";
    for (int i = 0; i < PROCESSES ; i++) cout<< sequence[i] <<' ';
    cout <<endl;
    return true;
}