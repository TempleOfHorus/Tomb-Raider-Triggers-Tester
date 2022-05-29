// Autor: Temple Of Horus

#include <iostream>
#include <sstream>
#include <fstream> 
#include <string>
#include <vector>
#include <bitset>
#define NOMINMAX
#include <windows.h>
#include <tlhelp32.h>
#include <memoryapi.h>

using namespace std;

// Function to change color of text.
void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to print list items.
void print_list_items(const vector<string>& ListItems, string ListName)
{
    Color(15);
    cout << ListName + ": " << endl;
    for (uint8_t ListItemsIndex = 0; ListItemsIndex < ListItems.size(); ListItemsIndex++) {
        Color(15);
        cout << "(" << (unsigned short int)ListItemsIndex << ") ";
        Color(6);
        cout << ListItems.at(ListItemsIndex) << endl;
    }
}

// Function to select list item.
uint8_t select_list_item(const vector<string>& ListItem, string ListName)
{
    vector<string> ListItemIndexes(ListItem.size());
    for (uint8_t ListItemIndex = 0; ListItemIndex < ListItem.size(); ListItemIndex++) {
        ListItemIndexes[ListItemIndex] = to_string(ListItemIndex);
    }

    Color(15);
    cout << "Select " + ListName + ": ";
    string UserInput;
    do {
        cin >> UserInput;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (find(ListItemIndexes.begin(), ListItemIndexes.end(), UserInput) == ListItemIndexes.end());

    uint8_t SelectListItem = find(ListItemIndexes.begin(), ListItemIndexes.end(), UserInput) - ListItemIndexes.begin();
    return SelectListItem;
}

// Function to print versions of game.
void print_versions(const vector<string>& Games, uint8_t SelectGame, vector<string>& GameVersions)
{
    cout << endl;
    Color(15);
    cout << "Versions:" << endl;
    for (uint8_t VersionIndex = 0; VersionIndex < GameVersions.size(); VersionIndex++) {
        Color(15);
        cout << "(" << (unsigned short int)VersionIndex << ") ";
        Color(6);
        cout << GameVersions.at(VersionIndex) << endl;
    }
}

// Function to select version of game.
uint8_t select_version(vector<string>& GameVersions)
{
    vector<string> VersionsIndexes(GameVersions.size());
    for (uint8_t VersionIndex = 0; VersionIndex < GameVersions.size(); VersionIndex++) {
        VersionsIndexes[VersionIndex] = to_string(VersionIndex);
    }

    Color(15);
    cout << "Select version: ";
    string UserInput;
    do {
        cin >> UserInput;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (find(VersionsIndexes.begin(), VersionsIndexes.end(), UserInput) == VersionsIndexes.end());

    uint8_t SelectVersion = find(VersionsIndexes.begin(), VersionsIndexes.end(), UserInput) - VersionsIndexes.begin();
    return SelectVersion;
}

// Function to retrieve process identifier of specified process.
DWORD ret_process_id(const wchar_t* ProcessName)
{
    PROCESSENTRY32 pe;
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    pe.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(hSnapShot, &pe)) {
        do {
            if (!lstrcmp(pe.szExeFile, ProcessName)) {
                CloseHandle(hSnapShot);
                return pe.th32ProcessID;
            }
        } while (Process32Next(hSnapShot, &pe));
    }
    CloseHandle(hSnapShot);
    return 0;
}

// Function to retrieve base address of module.
uintptr_t ret_module_base_address(DWORD dwProcessId, const wchar_t* ModuleName)
{
    MODULEENTRY32 me;
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwProcessId);
    me.dwSize = sizeof(MODULEENTRY32);
    if (Module32First(hSnapShot, &me)) {
        do {
            if (!_wcsicmp(me.szModule, ModuleName)) {
                CloseHandle(hSnapShot);
                return (uintptr_t)me.modBaseAddr;
            }
        } while (Module32Next(hSnapShot, &me));
    }
    CloseHandle(hSnapShot);
    return 0;
}

// Function to get process id of game.
DWORD get_process_id(const wchar_t* ProcessName)
{
    DWORD dwProcessId = 0x0;
    do {
        Color(6);
        cout << endl << "Searching for process id of game:" << endl;
        dwProcessId = ret_process_id(ProcessName);
        if (dwProcessId == 0x0) {
            Color(12);
            cout << "Process id of game was not found. Please turn on game or run program as administrator." << endl;
            cout << "Press enter to continue searching for process id of game: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            Color(10);
            cout << "Process id of game was found: 0x" << hex << uppercase << dwProcessId << endl;
        }
    } while (dwProcessId == 0x0);

    return dwProcessId;
}

// Function to get base address of module.
uintptr_t get_module_base_address(DWORD dwProcessId, const wchar_t* ModuleName)
{
    Color(6);
    cout << endl << "Searching for base address of module:" << endl;
    uintptr_t ModuleBaseAddress = ret_module_base_address(dwProcessId, ModuleName);
    if (ModuleBaseAddress == 0x0) {
        Color(12);
        cout << "Base address of module was not found. Please turn on game or run program as administrator." << endl;
        cout << "Press enter to close program: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 0;
    }
    else {
        Color(10);
        cout << "Base address of module was found: 0x" << hex << uppercase << ModuleBaseAddress << endl;
    }
    return ModuleBaseAddress;
}

// Function to get string between two strings.
string get_string_between(string& GetLineString, string& StartString, string& EndString)
{
    unsigned int Start_String = GetLineString.find(StartString);
    unsigned int End_Start_String = Start_String + StartString.length();
    unsigned int End_String = GetLineString.find(EndString);

    return GetLineString.substr(End_Start_String, End_String - End_Start_String);
}

// Function to reverse first 5 bits of mask.
uint8_t reverse_mask(uint8_t Mask) {
    Mask = (Mask & 0xF0) >> 4 | (Mask & 0x0F) << 4;
    Mask = (Mask & 0xCC) >> 2 | (Mask & 0x33) << 2;
    Mask = (Mask & 0xAA) >> 1 | (Mask & 0x55) << 1;
    Mask = Mask >> 3;
    return Mask;
}