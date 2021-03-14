#pragma once

struct List {
	int value;
	List* prev = nullptr;
	List* next = nullptr;
};