#include <iostream>
#include <cmath>
using namespace std;

int *allocate_memory(int n){
    return (int *) malloc(n * sizeof(int));
}


void invct(int n, int *x, int *y){
    for (int i = 1; i <= n; i++){
        cout << "Точка " << i << ": ";
        cin >> x[i-1] >> y[i-1];
    }
    
}


int summa(int n, int *x){
    int summ = 0;
    for (int i = 0; i < n; i++){
        summ += x[i];
    }
    return summ;
}


float summa1(int n, int *x, int *y){
    float summ = 0;
    for(int i = 0; i < n; i++){
        summ += x[i] * y[i];
    }
    return summ;
}


float summa2(int n, int *x){
    float summ = 0;
    for(int i = 0; i < n; i++){
        summ += pow(x[i], 2);
    }
    return summ;
}


int main(){
    setlocale(LC_ALL, "Russian");
    char cont;
    int n, *x, *y;
    cout << "[1]. Введите с клавиатуры количество точек n, которое будет иметь набор данных." << endl;
    cin >> n;

    x = allocate_memory(n);
    y = allocate_memory(n);

    cout << "Введите точки" << endl;
    invct(n, x, y);

    float xs = (float)summa(n, x) / n;
    float ys = (float)summa(n, y) / n;
    float beta1;
    beta1 = (summa1(n, x, y) - (float)n * xs * ys)/(summa2(n, x)-(pow(summa(n, x), 2))/n);
    float beta0 = ys - beta1 * xs;
    cout << "y = " << beta0 << " + " << beta1 << " * x" << endl;
    int x0, y0;
    cout << "[6]. Введите новую точку" << endl;
    cin >> x0 >> y0;
    cout << "y ожидаемое: " << beta0 + beta1 * x0 << endl;
    cout << "error = " << fabs(y0 - (beta0 + beta1 * x0)) << endl;
}
