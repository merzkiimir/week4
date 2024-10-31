#include <iostream>
using namespace std;

char *memory(int n){
    return (char *) malloc(n * sizeof(char));
}


void massiv(int n, char *x){
    for(int i = 0; i < n; i++){
        cout << "¬ведите " << i + 1 << "ую букву: ";
        cin >> x[i];
    }
}


void nwvct(int n1, int n2, char *x, char *y, char *xy){
    for(int i=0, k = 0; i < max(n1, n2); i++){
        if(i < n1){
            xy[k] = x[i];
            k ++;
        } if(i < n2){
            xy[k] = y[i];
            k ++;
        }
    }
}


void prntvct(int n, char *x){
    for(int i = 0; i < n; i++){
        cout << x[i];
    } cout << "\n";
}


int main(){
    setlocale(LC_ALL, "Russian");
    int n1, n2;
    char *a, *b, *ab;
    cout << "¬ведите количество букв n в первом слове: ";
    cin >> n1;
    a = memory(n1);
    massiv(n1, a);
    cout << "¬ведите количество букв n во втором слове: ";
    cin >> n2;
    b = memory(n2);
    massiv(n2, b);
    ab = memory(n1 + n2);
    nwvct(n1, n2, a, b, ab);
    prntvct(n1, a);
    prntvct(n2, b);
    prntvct(n1 + n2, ab);
}