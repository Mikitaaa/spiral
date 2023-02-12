#include<iostream>
#include<iomanip>
#include<time.h>

using namespace std;

int main()
{
    struct timespec tw={0,100000000};
    struct timespec tr;
    int  num_rows,num_colls,num_value=1;
    cin>>num_rows>>num_colls;

    int mas[num_rows][num_colls];
    
    //В квадрате нечетноого размера нужно доставить
    //последнее число в середину
    if(num_rows%2!=0 && num_colls==num_rows){mas[num_rows/2][num_colls/2]=num_rows*num_colls;}
        
    //→ → → → → → →
    for (int sdvig = 0; num_value<num_rows*num_colls; sdvig++){
        for (int i = sdvig; i < num_colls  - sdvig - 1;i++){
            if(num_value>num_rows*num_colls)break;
            mas[sdvig][i] = num_value;
            
            num_value++;
        }
    //↓ ↓ ↓ ↓ ↓ ↓ ↓
        for (int i = sdvig; i < num_rows - sdvig - 1; i++){
            if(num_value>num_rows*num_colls)break;
            mas[i][ num_colls - 1 - sdvig] = num_value;
            num_value++;
        }
    //← ← ← ← ← ← ←
        for (int i = num_colls - sdvig - 1; i > sdvig; i--){
            if(num_value>num_rows*num_colls)break;
            mas[num_rows - sdvig - 1][i] = num_value;
            num_value++;
        }
    //↑ ↑ ↑ ↑ ↑ ↑ ↑
        for (int i = num_rows - 1 - sdvig; i > sdvig; i--){
            if(num_value>num_rows*num_colls)break;
            mas[i][sdvig] = num_value;
            num_value++;
        }
    }
   //Вывод в консоль
    for (int i = 0; i < num_rows; i++){
        for (int j = 0; j < num_colls; j++){
            cout<<setw(4)<<mas[i][j];
            nanosleep(&tw, &tr);
        }
        cout << endl;
    }
    return 0;
}
