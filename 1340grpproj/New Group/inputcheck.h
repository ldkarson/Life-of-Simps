#include <iostream>
#include <string>

using namespace std;

int inputcheck(char flag){
    int check = 0;
    while(check == 0){
        if (flag == 'y'){
            check = 1;
            return 1;
        }
        if (flag == 'n'){
            check = 1;
            return 0;
        }
        cout << "Invalid input, please input again! " << endl;
        cin >> flag;
    }
    return 0;
}
