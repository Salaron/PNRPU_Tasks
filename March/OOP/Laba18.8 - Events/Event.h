#pragma once

enum EVENTS {
	evNothing = 0,
	evMessage = 100
};

enum COMMANDS {
	cmdMake = 1,
	cmdAdd = 2,
	cmdDel = 3,
	cmdShow = 4,
	cmdName = 5,
	cmdQuit = 6
};

struct TEvent {
	int what; // ��� �������
	union {
		int command; // ��� �������
		struct {
			int message;
			int param; // ��������
		};
	};
};