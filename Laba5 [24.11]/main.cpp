#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

int* InitArray(int N) {
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = N + (rand() % N * 10);
	}
	return arr;
}

int** InitMatrix(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}
	// init the matrix with zero
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

void FillMatrix(int* arr, int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		int av = arr[i] / size;
		int ost = max(arr[i] - av * size, 0);
		for (int j = 0; j < size; j++) {
			matrix[j][i] = av + ost;
			ost = 0;
		}
	}
}

void PrintArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void PrintMatrix(int** matrx, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrx[i][j] << "\t";
		}
		cout << endl;
	}
}

void DeleteMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
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

int main() {
	srand(time(0));
	setlocale(LC_ALL, "");
	cin.exceptions(istream::failbit);

	int N;
	for (;;) {
		safeInputInt("Введите размер массива: ", N);
		if (N >= 1) break;
		cout << "Размер массива должен быть больше 0!" << endl;
	}

	int* arr = InitArray(N);
	int** matrix = InitMatrix(N, N); // matrix NxN -- square matrix
	FillMatrix(arr, matrix, N);

	cout << "Одномерный массив: " << endl;
	PrintArray(arr, N);
	cout << endl << "Сгенерированный двумерный массив: " << endl;
	PrintMatrix(matrix, N);

	delete[] arr;
	DeleteMatrix(matrix, N);
	return 0;
}