#pragma once
#include "Vector.h"
#include "Event.h"

class Dialog : public Vector {
private:
	int EndState;
public:
	Dialog();
	~Dialog();

	void GetEvent(TEvent& event);
	void Execute();
	void HandleEvent(TEvent& event);
	void ClearEvent(TEvent& event);
};
