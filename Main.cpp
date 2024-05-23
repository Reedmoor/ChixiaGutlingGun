#pragma once

#include <stdio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

using namespace std;

int main(void) {
	srand(time(0));
	while (1)
	{
		this_thread::sleep_for(chrono::microseconds(5));
		while (GetAsyncKeyState(VK_XBUTTON2))
		{
			keybd_event(0x47, 0, 0, 0);
			keybd_event(0x47, 0, KEYEVENTF_KEYUP, 0);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			this_thread::sleep_for(chrono::microseconds(5));
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			this_thread::sleep_for(chrono::microseconds(7));
		}
	}

	return 0;
}