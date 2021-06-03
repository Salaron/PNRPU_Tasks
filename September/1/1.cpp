#include <iostream>
#include <Windows.h>

int main()
{
	system("chcp 1251>nul");
    WCHAR fileName[] = L"\\\\.\\globalroot\\device\\condrv\\kernelconnect";
    WIN32_FILE_ATTRIBUTE_DATA data;
    GetFileAttributesEx(fileName, GetFileExInfoStandard, &data);
}