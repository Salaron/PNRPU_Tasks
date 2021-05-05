#pragma once
#include <iostream>
#include <vector>

template <typename T>
void inline printMatrix(T** matrix, int rows, int cols) {
	std::cout << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <typename T>
void inline printVectorMatrix(std::vector<std::vector<T>> matrix) {
	std::cout << std::endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <typename T>
void inline printVector(std::vector<T> vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}