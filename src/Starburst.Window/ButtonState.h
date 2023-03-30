#pragma once
struct ButtonState {
	bool IsDown;
	bool Changed;
};

enum {
	ButtonUp,
	ButtonDown,
	ButtonLeft,
	ButtonRight,
	ButtonCount
};

struct Input {
	ButtonState Buttons[ButtonCount];
};