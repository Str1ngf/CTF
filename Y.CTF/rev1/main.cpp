#include <iostream>
#include <string>
#include <Windows.h>
#include "string.h"

using namespace std;


string string_Encrypt(string static_key, string Input) {
    string out_string;

    for (int i = 0; i < static_key.length(); i++) {
        out_string += static_cast<char> (static_key.at(i) ^ Input.at(i % Input.length()));
    }
    return out_string;

}


string Create_key(string Input) {
    string static_key = String_Part2[1];
    string out_key = string_Encrypt(static_key, Input);
    return out_key;
}


void FakeRender() {
    HANDLE hConsole;
    for (int i = 0; i < 70; i++) {
        printf("%s\n", String_Part[i]);
    }
}

bool CompareText(string Input) {
    int Inputlength = Input.length();
    size_t CommandLength = 15;
    char* allocatedCommand = (char*)malloc(CommandLength + 1);
    if (allocatedCommand != NULL) {
        strcpy(allocatedCommand, String_Part2[0]);//GiveMeTheHint ,  : End of Transmission
    }

    string InputFlag;
    HANDLE hConsole;

    if (!Input.compare(allocatedCommand)) {
        for (int i = 0; i < 70; i++) {
            if (i == 43) {
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("%s\n", String_Part[i]);
            }
            else {
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("%s\n", String_Part[i]);
            }
        }
        free(allocatedCommand);

        cin >> InputFlag;
        if (Inputlength != 14) {
            return FALSE;
        }

        size_t stringLength = 23;
        char* allocatedString = (char*)malloc(stringLength + 1);
        if (allocatedString != NULL) {
           //E4_Syr_ev3_rSI_ngEx_amp
            strcpy(allocatedString, "\x75\x04\x6F\x12\x3B\x31\x1B\x20\x30\x74\x17\x3B\x19\x02\x6F\x5E\x57\x75\x48\x6F\x51\x37\x2A");
        }

       string compareMe = Create_key(InputFlag);
       int InputFlaglength = InputFlag.length();
       if (!compareMe.compare(allocatedString) && InputFlaglength == 23) {
            free(allocatedString);
            return TRUE;
        }
  }
    else {
      FakeRender();
      free(allocatedCommand);
      return FALSE;
  }
    return FALSE;
}


int main() {
    string Input;
    bool check;
    string InputPause;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

    HANDLE hConsolefont = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsolefont, FALSE, &fontInfo);
    wcscpy(fontInfo.FaceName, L"NSimSun");
    SetCurrentConsoleFontEx(hConsolefont, FALSE, &fontInfo);
    cout << "______         _             _   \n";
    cout << "| ___ \\       | |           | |  \n";
    cout << "| |_/ /  ___  | |__    ___  | |_ \n";
    cout << "|    /  / _ \\ | '_ \\  / _ \\ | __|\n";
    cout << "| |\\ \\ | (_) || |_) || (_) || |_ \n";
    cout << "\\_| \\_| \\___/ |_.__/  \\___/  \\__|\n";
    cout << "                                 \n";
    cout << "Hello i'm Robot.\n";
    std::cin >> Input;
    check = CompareText(Input);
    if (check == 1) {
        cout << "OK\n";
    }
    cin >> InputPause;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}