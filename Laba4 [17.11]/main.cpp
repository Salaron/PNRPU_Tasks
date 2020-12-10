#include <iostream>
#include <time.h>
#include <string>

using namespace std;

// set to true if you want to type all elements by yourself
constexpr auto USER_INPUT = true;

// did you know?
// for (;;) will compile as while (true)
// so there is no any difference between them
// but for (;;) is faster than while (true)
// because it contains fewer characters
// and you can type it faster yooo
//// https://stackoverflow.com/questions/2611246/is-for-faster-than-while-true-if-not-why-do-people-use-it
void printLeft(int* arr, int N, int K) {
    int i = K;
    for (;;) {
        cout << "A[" << i << "] = " << arr[i] << endl;
        i--;
        if (i == -1) i = N - 1;
        if (i == K) break;
    }
}

void printRight(int* arr, int N, int K) {
    int i = K;
    for (;;) {
        cout << "A[" << i << "] = " << arr[i] << endl;
        i++;
        if (i == N) i = 0;
        if (i == K) break;
    }
}

void safeInputInt(string msg, int& dest) {
    for (;;) {
        cout << msg;
        try {
            cin >> dest;
            break;
        }
        catch (std::ios_base::failure const& ex) {
            cout << "Пожалуйста, введите число!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main()
{
    setlocale(LC_ALL, ""); // set Russian lang
    srand(time(0)); // set seed
    cin.exceptions(istream::failbit); // enable cin exceptions to turn on safe input

    int N;
    for (;;) {
        safeInputInt("Введите размер двунаправленного кольца: ", N);
        if (N >= 2)
            break;
        cout << "Размер должен быть больше 1!" << endl;
    }

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        if (!USER_INPUT)
            arr[i] = rand() * 100 / RAND_MAX;
        else {
            safeInputInt("Введите значение " + to_string(i) + " элемента массива: ", arr[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    int K;
    for (;;) {
        safeInputInt("Введите индекс, с которого нужно начать вывод кольца: ", K);
        if (K >= 0 && K < N) break;
        cout << "Индекс должен быть в диапазоне [0; " << N - 1 << "]" << endl;
    }

    printRight(arr, N, K);

    // find max
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > max) max = arr[i];
    }
    cout << "Максимальное значение элемента в массиве: " << max << endl;

    int removed = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == max && removed < N - 1) {
            removed++;
            for (int j = i; j < N - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[N - 1] = 0;
            i--;
        }
    }
    cout << "Было удалено " << removed << " элементов со значением " << max << endl;

    if (K >= N - removed) {
        for (;;) {
            safeInputInt("Введите индекс, с которого нужно начать вывод кольца: ", K);
            if (K >= 0 && K < N - removed) break;
            cout << "Индекс должен быть в диапазоне [0; " << N - 1 - removed << "]" << endl;
        }
    }

    printLeft(arr, N - removed, K);

    delete[] arr; // free memory after use :)
    return 0;
}