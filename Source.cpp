// Autor: Temple Of Horus

#include "header.h"

int main()
{
    // List of games.
    const vector<string> Games{ "Tomb Raider 3",
                                "Tomb Raider 3: The Lost Artifact",
                                "Tomb Raider 4",
                                "Tomb Raider 4: The Times Exclusive",
                                "Tomb Raider 5" };
    // Print games.
    print_list_items(Games, "Games");

    // Select game.
    uint8_t SelectGame = select_list_item(Games, "game");

    // List of game systems.
    vector<string> GameSystems;

    if (Games[SelectGame] == "Tomb Raider 3") {
        const vector<string> GameSystems1{ "Personal Computer",
                                           "Sony Playstation (Bizhawk 2.8, core: OctoShock)" };
        GameSystems = GameSystems1;
    }

    else if (Games[SelectGame] == "Tomb Raider 4" || Games[SelectGame] == "Tomb Raider 5") {
        const vector<string> GameSystems2{ "Personal Computer",
                                           "Sony Playstation (Bizhawk 2.8, core: OctoShock)" };
                                        // "Sega Dreamcast (Bizhawk, core: )"
        GameSystems = GameSystems2;
    }

    else {
        const vector<string> GameSystems3{ "Personal Computer" };
        GameSystems = GameSystems3;
    }

    // Print game systems.
    print_list_items(GameSystems, "\nSystems");

    // Select game system.
    uint8_t SelectGameSystem = select_list_item(GameSystems, "game system");

    // Version selection.
    vector<string> GameVersions; // List of game versions.
    const wchar_t* ProcessName = L""; // Process name.
    const wchar_t* ModuleName = L""; // Module name.
    uintptr_t NumberOfRoomsAddress = 0x0; // Address where is stored number of rooms.
    uintptr_t RoomPointer = 0x0; // Pointer to room data.
    uintptr_t FloorDataPointer = 0x0; // Pointer to floor data.

    uint8_t SelectVersion;

    // Game system: Personal Computer (MD5 hash of main executable).
    if (GameSystems[SelectGameSystem] == "Personal Computer") {
        if (Games[SelectGame] == "Tomb Raider 3") { // Tomb Raider 3.
            GameVersions = { "B33B79D08C2F6BAD5723E61B1C02F2B5" };
            print_versions(Games, SelectGame, GameVersions);
            SelectVersion = select_version(GameVersions);

            if (GameVersions[SelectVersion] == "B33B79D08C2F6BAD5723E61B1C02F2B5") { // B33B79D08C2F6BAD5723E61B1C02F2B5
                ProcessName = L"tomb3.exe";
                ModuleName = L"tomb3.exe";
                NumberOfRoomsAddress = 0x2E2880;
                RoomPointer = 0x29FCAC;
                FloorDataPointer = 0x233E24;
            }
        }

        else if (Games[SelectGame] == "Tomb Raider 3: The Lost Artifact") { // Tomb Raider 3: The Lost Artifact.
            GameVersions = { "7C820C372F3CA0B7E97E09CC91A0F033" };
            print_versions(Games, SelectGame, GameVersions);
            SelectVersion = select_version(GameVersions);

            if (GameVersions[SelectVersion] == "7C820C372F3CA0B7E97E09CC91A0F033") { // 7C820C372F3CA0B7E97E09CC91A0F033
                ProcessName = L"tr3gold.exe";
                ModuleName = L"tr3gold.exe";
                NumberOfRoomsAddress = 0x2DB4A0;
                RoomPointer = 0x298B64;
                FloorDataPointer = 0x22CD08;
            }
        }

        else if (Games[SelectGame] == "Tomb Raider 4") { // Tomb Raider 4.
            GameVersions = { "649DA89EAC273BFD92E151C6627FD910",
                             "41482ADFA00D187DC51B161E9F377C23",
                             "835ABCC1E4F035CE5B1ACEE2E353ADA3",
                             "47E7BC96120F8FEBE3B759D4DD7F7FEE",
                             "BFF3FEA78480671EE81831CC6C6E8805" };
            print_versions(Games, SelectGame, GameVersions);
            SelectVersion = select_version(GameVersions);

            if (GameVersions[SelectVersion] == "649DA89EAC273BFD92E151C6627FD910") { // 649DA89EAC273BFD92E151C6627FD910
                ProcessName = L"tomb4.exe";
                ModuleName = L"tomb4.exe";
                NumberOfRoomsAddress = 0x133A5C;
                RoomPointer = 0x133A64;
                FloorDataPointer = 0x133A78;
            }
            else if (GameVersions[SelectVersion] == "41482ADFA00D187DC51B161E9F377C23") { // 41482ADFA00D187DC51B161E9F377C23
                ProcessName = L"tomb4.exe";
                ModuleName = L"tomb4.exe";
                NumberOfRoomsAddress = 0x132A5C;
                RoomPointer = 0x132A64;
                FloorDataPointer = 0x132A78;
            }
            else if (GameVersions[SelectVersion] == "835ABCC1E4F035CE5B1ACEE2E353ADA3") { // 835ABCC1E4F035CE5B1ACEE2E353ADA3
                ProcessName = L"tomb4.exe";
                ModuleName = L"tomb4.exe";
                NumberOfRoomsAddress = 0x132A5C;
                RoomPointer = 0x132A64;
                FloorDataPointer = 0x132A78;
            }
            else if (GameVersions[SelectVersion] == "47E7BC96120F8FEBE3B759D4DD7F7FEE") { // 47E7BC96120F8FEBE3B759D4DD7F7FEE
                ProcessName = L"tomb4.exe";
                ModuleName = L"tomb4.exe";
                NumberOfRoomsAddress = 0x133A5C;
                RoomPointer = 0x133A64;
                FloorDataPointer = 0x133A78;
            }
            else if (GameVersions[SelectVersion] == "BFF3FEA78480671EE81831CC6C6E8805") { // BFF3FEA78480671EE81831CC6C6E8805
                ProcessName = L"tomb4.exe";
                ModuleName = L"tomb4.exe";
                NumberOfRoomsAddress = 0x133A5C;
                RoomPointer = 0x133A64;
                FloorDataPointer = 0x133A78;
            }
        }

        else if (Games[SelectGame] == "Tomb Raider 4: The Times Exclusive") { // Tomb Raider 4: The Times Exclusive.
            GameVersions = { "106F76BF6867B294035074EE005AB91A" };
            print_versions(Games, SelectGame, GameVersions);
            SelectVersion = select_version(GameVersions);

            if (GameVersions[SelectVersion] == "106F76BF6867B294035074EE005AB91A") { // 106F76BF6867B294035074EE005AB91A
                ProcessName = L"tomb4.exe";
                ModuleName = L"tomb4.exe";
                NumberOfRoomsAddress = 0x133A9C;
                RoomPointer = 0x133AA4;
                FloorDataPointer = 0x133AB8;
            }
        }

        else if (Games[SelectGame] == "Tomb Raider 5") { // Tomb Raider 5.
            GameVersions = { "B079C1A336FFEDD0AD4D81E50B60E308",
                             "0524A3314CF1DB10B1F632F02115854E",
                             "54C65C82FBED56DD47A9914AA1A60482",
                             "6109746B01578580C8A8838A354F9CD6" };
            print_versions(Games, SelectGame, GameVersions);
            SelectVersion = select_version(GameVersions);

            if (GameVersions[SelectVersion] == "B079C1A336FFEDD0AD4D81E50B60E308") { // B079C1A336FFEDD0AD4D81E50B60E308
                ProcessName = L"PCTomb5.exe";
                ModuleName = L"PCTomb5.exe";
                NumberOfRoomsAddress = 0x47514C;
                RoomPointer = 0x475154;
                FloorDataPointer = 0x475168;
            }
            else if (GameVersions[SelectVersion] == "0524A3314CF1DB10B1F632F02115854E") { // 0524A3314CF1DB10B1F632F02115854E
                ProcessName = L"PCTomb5.exe";
                ModuleName = L"PCTomb5.exe";
                NumberOfRoomsAddress = 0x47514C;
                RoomPointer = 0x475154;
                FloorDataPointer = 0x475168;
            }
            else if (GameVersions[SelectVersion] == "54C65C82FBED56DD47A9914AA1A60482") { // 54C65C82FBED56DD47A9914AA1A60482
                ProcessName = L"PCTomb5.exe";
                ModuleName = L"PCTomb5.exe";
                NumberOfRoomsAddress = 0x475244;
                RoomPointer = 0x47524C;
                FloorDataPointer = 0x475260;
            }
            else if (GameVersions[SelectVersion] == "6109746B01578580C8A8838A354F9CD6") { // 6109746B01578580C8A8838A354F9CD6
                ProcessName = L"PCTomb5.exe";
                ModuleName = L"PCTomb5.exe";
                NumberOfRoomsAddress = 0x47514C;
                RoomPointer = 0x475154;
                FloorDataPointer = 0x475168;
            }
        }
    }

    // Game system: Sony Playstation (MD5 hash of main executable).
    uintptr_t BizhawkPSXMainRAM = 0x317F80;
    if (GameSystems[SelectGameSystem] == "Sony Playstation (Bizhawk 2.8, core: OctoShock)") {
        if (Games[SelectGame] == "Tomb Raider 3") { // Tomb Raider 3.
            GameVersions = { "312AC2583E9C31DE9C9F477285E9E9E5",
                             "982E1081556072D858B356A7D36F9334",
                             "07F4090741A1B0E8467784C6E2865AA3" };
            print_versions(Games, SelectGame, GameVersions);
            SelectVersion = select_version(GameVersions);

            if (GameVersions[SelectVersion] == "312AC2583E9C31DE9C9F477285E9E9E5") { // 312AC2583E9C31DE9C9F477285E9E9E5
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"octoshock.dll";
                NumberOfRoomsAddress = 0x099AEC;
                RoomPointer = 0x099A00;
                FloorDataPointer = 0x09B848;
            }
            else if (GameVersions[SelectVersion] == "982E1081556072D858B356A7D36F9334") { // 982E1081556072D858B356A7D36F9334
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"octoshock.dll";
                NumberOfRoomsAddress = 0x099998;
                RoomPointer = 0x0998AC;
                FloorDataPointer = 0x09B6F4;
            }
            else if (GameVersions[SelectVersion] == "07F4090741A1B0E8467784C6E2865AA3") { // 07F4090741A1B0E8467784C6E2865AA3
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"octoshock.dll";
                NumberOfRoomsAddress = 0x099F88;
                RoomPointer = 0x099E9C;
                FloorDataPointer = 0x09BD50;
            }
        }

        else if (Games[SelectGame] == "Tomb Raider 4") { // Tomb Raider 4.
            GameVersions = { "0A1112720D39A0025CC0A64C5E66BEB1",
                             "1A5FFA851F7FDED2784B56E07DE9E253",
                             "C6FF61A2B33FD46DD5BF0CFD0C778772",
                             "BAFAE783FF4FACE6E1C317CB5BD0F5C3" };
            print_versions(Games, SelectGame, GameVersions);
            SelectVersion = select_version(GameVersions);

            if (GameVersions[SelectVersion] == "0A1112720D39A0025CC0A64C5E66BEB1") { // 0A1112720D39A0025CC0A64C5E66BEB1
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"octoshock.dll";
                NumberOfRoomsAddress = 0x0A92FC;
                RoomPointer = 0x0A91F4;
                FloorDataPointer = 0x0AB248;
            }
            else if (GameVersions[SelectVersion] == "1A5FFA851F7FDED2784B56E07DE9E253") { // 1A5FFA851F7FDED2784B56E07DE9E253
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"octoshock.dll";
                NumberOfRoomsAddress = 0x0A8570;
                RoomPointer = 0x0A8464;
                FloorDataPointer = 0x0AA4BC;
            }
            else if (GameVersions[SelectVersion] == "C6FF61A2B33FD46DD5BF0CFD0C778772") { // C6FF61A2B33FD46DD5BF0CFD0C778772
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"octoshock.dll";
                NumberOfRoomsAddress = 0x0A828C;
                RoomPointer = 0x0A8180;
                FloorDataPointer = 0x0AA1D8;
            }
            else if (GameVersions[SelectVersion] == "BAFAE783FF4FACE6E1C317CB5BD0F5C3") { // BAFAE783FF4FACE6E1C317CB5BD0F5C3
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"octoshock.dll";
                NumberOfRoomsAddress = 0x0A9864;
                RoomPointer = 0x0A9758;
                FloorDataPointer = 0x0AB778;
            }
        }

        else if (Games[SelectGame] == "Tomb Raider 5") { // Tomb Raider 5.
            GameVersions = { "4EF523E708D7A7D6571F39C6E47784F9",
                             "479247A76D048687ACE42D2CBC1E99F0",
                             "9CF3FF2BB2E562F806E6DECCACA26724",
                             "4F79BCDB1821E529DEBCD202469C1C91" };
            print_versions(Games, SelectGame, GameVersions);
            SelectVersion = select_version(GameVersions);

            if (GameVersions[SelectVersion] == "4EF523E708D7A7D6571F39C6E47784F9") { // 4EF523E708D7A7D6571F39C6E47784F9
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"octoshock.dll";
                NumberOfRoomsAddress = 0x0A4030;
                RoomPointer = 0x0A4088;
                FloorDataPointer = 0x0A60B0;
            }
            else if (GameVersions[SelectVersion] == "479247A76D048687ACE42D2CBC1E99F0") { // 479247A76D048687ACE42D2CBC1E99F0
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"octoshock.dll";
                NumberOfRoomsAddress = 0x0A4030;
                RoomPointer = 0x0A4088;
                FloorDataPointer = 0x0A60B0;
            }
            else if (GameVersions[SelectVersion] == "9CF3FF2BB2E562F806E6DECCACA26724") { // 9CF3FF2BB2E562F806E6DECCACA26724
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"octoshock.dll";
                NumberOfRoomsAddress = 0x0A40B0;
                RoomPointer = 0x0A4108;
                FloorDataPointer = 0x0A6130;
            }
            else if (GameVersions[SelectVersion] == "4F79BCDB1821E529DEBCD202469C1C91") { // 4F79BCDB1821E529DEBCD202469C1C91
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"octoshock.dll";
                NumberOfRoomsAddress = 0x0A4B98;
                RoomPointer = 0x0A4BF0;
                FloorDataPointer = 0x0A6C28;
            }
        }
    }

    /*
    // Game system: Sega Dreamcast (MD5 hash of main executable).
    uintptr_t BizhawkDreamcastRAM = 0x;
    if (GameSystems[SelectGameSystem] == "Sega Dreamcast (Bizhawk, core: )") {
       if (Games[SelectGame] == "Tomb Raider 4") { // Tomb Raider 4.
            GameVersions = { "783C5835E95DF837FEB87DB6367C1C9A",
                             "C57D42CEB15BF4314C296653E2F5A55D",
                             "8C36CD2580BA32C87CFB80AD732FB38B" };
            print_versions(Games, SelectGame, GameVersions);
            SelectVersion = select_version(GameVersions);

            if (GameVersions[SelectVersion] == "783C5835E95DF837FEB87DB6367C1C9A") { // 783C5835E95DF837FEB87DB6367C1C9A
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"";
                NumberOfRoomsAddress = 0x;
                RoomPointer = 0x;
                FloorDataPointer = 0x;
            }
            else if (GameVersions[SelectVersion] == "C57D42CEB15BF4314C296653E2F5A55D") { // C57D42CEB15BF4314C296653E2F5A55D
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"";
                NumberOfRoomsAddress = 0x;
                RoomPointer = 0x;
                FloorDataPointer = 0x;
            }
            else if (GameVersions[SelectVersion] == "8C36CD2580BA32C87CFB80AD732FB38B") { // 8C36CD2580BA32C87CFB80AD732FB38B
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"";
                NumberOfRoomsAddress = 0x;
                RoomPointer = 0x;
                FloorDataPointer = 0x;
            }
        }
        else if (Games[SelectGame] == "Tomb Raider 5") { // Tomb Raider 5.
            GameVersions = { "B020DFE54C4EC0B7D32DD1C68F61E038",
                             "1D7B952AA49FF5474D994CE686539E82" };
            print_versions(Games, SelectGame, GameVersions);
            SelectVersion = select_version(GameVersions);

            if (GameVersions[SelectVersion] == "B020DFE54C4EC0B7D32DD1C68F61E038") { // B020DFE54C4EC0B7D32DD1C68F61E038
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"";
                NumberOfRoomsAddress = 0x;
                RoomPointer = 0x;
                FloorDataPointer = 0x;
            }
            else if (GameVersions[SelectVersion] == "1D7B952AA49FF5474D994CE686539E82") { // 1D7B952AA49FF5474D994CE686539E82
                ProcessName = L"EmuHawk.exe";
                ModuleName = L"";
                NumberOfRoomsAddress = 0x;
                RoomPointer = 0x;
                FloorDataPointer = 0x;
            }
        }
    }
    */

    // Get process id of game.
    DWORD dwProcessId = get_process_id(ProcessName);

    // Get base address of module.
    uintptr_t ModuleBaseAddress = get_module_base_address(dwProcessId, ModuleName);
    if (ModuleBaseAddress == 0x0) {
        return 1;
    }

    // Gain access to read memory of game.
    Color(6);
    cout << endl << "Gaining access to memory of game: ";
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
    if (hProcess == NULL) {
        Color(12);
        cout << endl << "Unable to gain access. Please turn on game or run program as administrator." << endl;
        cout << "Press enter to close program: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }
    else {
        Color(10);
        cout << "Allowed" << endl;
    }

    // Waiting on user input to get addresses of triggers catchable by trigger_index in current level.
    Color(15);
    cout << endl << "Press enter to get addresses of triggers catchable by trigger_index in current level: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Create Triggers.txt file where will be addresses of triggers in level catchable by trigger_index.
    ofstream AddressesFile("Triggers.txt");
    while (!(AddressesFile.is_open())) {
        Color(12);
        cout << endl << "Unable to create Triggers.txt file." << endl;
        cout << "Press enter to create file again: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ofstream AddressesFile("Triggers.txt");
    }

    // Get base address of room data, base address of floor data, number of rooms in level.
    if (GameSystems[SelectGameSystem] == "Sony Playstation (Bizhawk 2.8, core: OctoShock)") {
        NumberOfRoomsAddress += BizhawkPSXMainRAM;
        RoomPointer += BizhawkPSXMainRAM;
        FloorDataPointer += BizhawkPSXMainRAM;
    }
    /*
    else if (GameSystems[SelectGameSystem] == "Sega Dreamcast (Bizhawk, core: )") {
        NumberOfRoomsAddress += BizhawkDreamcastRAM;
        RoomPointer += BizhawkDreamcastRAM;
        FloorDataPointer += BizhawkDreamcastRAM;
    }
    */

    uint16_t NumberOfRooms = 0; // Number of rooms in level.
    ReadProcessMemory(hProcess, (LPCVOID)(ModuleBaseAddress + NumberOfRoomsAddress), &NumberOfRooms, 2, NULL);
    uintptr_t RoomBaseAddress = 0x0; // Base address of room data.
    ReadProcessMemory(hProcess, (LPCVOID)(ModuleBaseAddress + RoomPointer), &RoomBaseAddress, 4, NULL);
    uintptr_t FloorDataBaseAddress = 0x0; // Base address of floor data.
    ReadProcessMemory(hProcess, (LPCVOID)(ModuleBaseAddress + FloorDataPointer), &FloorDataBaseAddress, 4, NULL);

    if (GameSystems[SelectGameSystem] == "Sony Playstation (Bizhawk 2.8, core: OctoShock)") {
        RoomBaseAddress += ModuleBaseAddress + BizhawkPSXMainRAM;
        FloorDataBaseAddress += ModuleBaseAddress + BizhawkPSXMainRAM;
    }
    /*
    else if (GameSystems[SelectGameSystem] == "Sega Dreamcast (Bizhawk, core: )") {
        RoomBaseAddress += ModuleBaseAddress + BizhawkDreamcastRAM;
        FloorDataBaseAddress += ModuleBaseAddress + BizhawkDreamcastRAM;
    }
    */

    // FDSetup, EndData.
    uint16_t FDSetup = 0x0;
    uint16_t EndData = 0x0;

    // Get addresses of triggers in level catchable by trigger_index.
    // Setting multiplier value according to system and game.
    uint16_t Multiplier = 0;
    if (GameSystems[SelectGameSystem] == "Personal Computer") {
        if (Games[SelectGame] == "Tomb Raider 3" || Games[SelectGame] == "Tomb Raider 3: The Lost Artifact") {
            Multiplier = 80;
        }
        else if (Games[SelectGame] == "Tomb Raider 4" || Games[SelectGame] == "Tomb Raider 4: The Times Exclusive") {
            Multiplier = 148;
        }
        else if (Games[SelectGame] == "Tomb Raider 5") {
            Multiplier = 208;
        }
    }
    else if (GameSystems[SelectGameSystem] == "Sony Playstation (Bizhawk 2.8, core: OctoShock)") {
        Multiplier = 80;
    }
    /*
    else if (GameSystems[SelectGameSystem] == "Sega Dreamcast (Bizhawk, core: )") {
        if (Games[SelectGame] == "Tomb Raider 4") {
            Multiplier = 148;
        }
        else if (Games[SelectGame] == "Tomb Raider 5") {
            Multiplier = 208;
        }
    }
    */

    for (uint16_t RoomNumber = 0; RoomNumber < NumberOfRooms; RoomNumber++) {
        // Get pointer to start address of data of specific room, start address of data of specific room.
        uintptr_t StartRoomPointer = StartRoomPointer = RoomBaseAddress + (RoomNumber * Multiplier) + 8; // Pointer to start address of data of specific room.
        uintptr_t StartRoomData = 0x0; // Start address of data of specific room.
        ReadProcessMemory(hProcess, (LPCVOID)(StartRoomPointer), &StartRoomData, 4, NULL);

        // Get pointer to height sector of specific room, height sector of specific room.
        uintptr_t NumXsectorsPointer = NumXsectorsPointer = RoomBaseAddress + (RoomNumber * Multiplier) + 40; // Pointer to height sector of specific room.
        uint16_t NumXsectors = 0; // Height sector of specific room.
        ReadProcessMemory(hProcess, (LPCVOID)(NumXsectorsPointer), &NumXsectors, 2, NULL);

        // Get pointer to width sector of specific room, width sector of specific room.
        uintptr_t NumZsectorsPointer = NumZsectorsPointer = RoomBaseAddress + (RoomNumber * Multiplier) + 42; // Pointer to width sector of specific room.
        uint16_t NumZsectors = 0; // Width sector of specific room.
        ReadProcessMemory(hProcess, (LPCVOID)(NumZsectorsPointer), &NumZsectors, 2, NULL);

        // Get end address of data of specific room.
        uintptr_t EndRoomData = StartRoomData + ((NumXsectors * NumZsectors) * 8);

        if (GameSystems[SelectGameSystem] == "Sony Playstation (Bizhawk 2.8, core: OctoShock)") {
            StartRoomData += ModuleBaseAddress + BizhawkPSXMainRAM;
            EndRoomData += ModuleBaseAddress + BizhawkPSXMainRAM;
        }
        /*
        else if (GameSystems[SelectGameSystem] == "Sega Dreamcast (Bizhawk, core: )") {
            StartRoomData += ModuleBaseAddress + BizhawkDreamcastRAM;
            EndRoomData += ModuleBaseAddress + BizhawkDreamcastRAM;
        }
        */

        // Sector number.
        uint16_t Sector = 0;
        for (StartRoomData; StartRoomData < EndRoomData; StartRoomData += 8) {
            Sector += 1; // Increase sector number by 1.
            uint16_t FDIndex = 0x0; // Floor data index of sector.
            ReadProcessMemory(hProcess, (LPCVOID)(StartRoomData), &FDIndex, 2, NULL);
            if (FDIndex != 0x0) {
                uintptr_t SectorFloorDataAddress = FloorDataBaseAddress + (FDIndex * 2); // Start address of floor data for specific sector.
                EndData = 0x0;
                do {
                    FDSetup = 0x0;
                    ReadProcessMemory(hProcess, (LPCVOID)(SectorFloorDataAddress), &FDSetup, 2, NULL);
                    EndData = FDSetup & 0x8000;
                    switch (FDSetup & 0x1F) {
                    case 0x01: // Portal.
                    case 0x02: // Floor Slant.
                    case 0x03: // Ceiling Slant.
                    case 0x07: // Triangulation.
                    case 0x08: // Triangulation.
                    case 0x09: // Triangulation.
                    case 0x0A: // Triangulation.
                    case 0x0B: // Triangulation.
                    case 0x0C: // Triangulation.
                    case 0x0D: // Triangulation.
                    case 0x0E: // Triangulation.
                    case 0x0F: // Triangulation.
                    case 0x10: // Triangulation.
                    case 0x11: // Triangulation.
                    case 0x12: // Triangulation.
                        SectorFloorDataAddress += 4;
                        break;
                    case 0x04: // Trigger.
                    case 0x05: // Kill Lara.
                    case 0x06: // Climbable Walls.
                    case 0x13: // Monkey Swing.
                    case 0x14: // Function 0x14.
                    case 0x15: // Function 0x15.
                        EndData = 0x1;
                        if (GameSystems[SelectGameSystem] == "Personal Computer") {
                            AddressesFile << "Address: 0x" << hex << uppercase << SectorFloorDataAddress << dec << " Room: " << (unsigned short int)RoomNumber << " Sector: " << (unsigned short int)Sector << endl;
                        }
                        else if (GameSystems[SelectGameSystem] == "Sony Playstation (Bizhawk 2.8, core: OctoShock)") {
                            AddressesFile << "Address: 0x" << hex << uppercase << SectorFloorDataAddress << " (PSXMainRAM: 0x" << (SectorFloorDataAddress - ModuleBaseAddress - BizhawkPSXMainRAM) << ")" << dec << " Room: " << (unsigned short int)RoomNumber << " Sector: " << (unsigned short int)Sector << endl;
                        }
                        /*
                        else if (GameSystems[SelectGameSystem] == "Sega Dreamcast (Bizhawk, core: )") {
                            AddressesFile << "Address: 0x" << hex << uppercase << SectorFloorDataAddress << " (DreamcastRAM: 0x"<< (SectorFloorDataAddress - ModuleBaseAddress - BizhawkDreamcastRAM) << ")" << dec << " Room: " << (unsigned short int)RoomNumber << " Sector: " << (unsigned short int)Sector << endl;
                        }
                        */
                        break;
                    }
                } while (EndData == 0x0);
            }
        }
    }

    // Close Triggers.txt file.
    AddressesFile.close();

    // Waiting on user input to check what triggers addresses from previous level would do in current level when Lara is no space.
    Color(15);
    cout << endl << "Press enter to check what triggers addresses from previous level would do in current level when Lara is no space: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Create Test Triggers.txt file where will be information what triggers addresses from previous level would do in current level.
    ofstream CheckFile("Test Triggers.txt");
    while (!(CheckFile.is_open())) {
        Color(12);
        cout << endl << "Unable to create Test Triggers.txt file." << endl;
        cout << "Press enter to create file again: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ofstream CheckFile("Test Triggers.txt");
    }

    // Open Triggers.txt file to get information.
    ifstream GetInfoFromFile("Triggers.txt");
    while (!(GetInfoFromFile.is_open())) {
        Color(12);
        cout << endl << "Unable to open Triggers.txt file." << endl;
        cout << "Press enter to open file again: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ifstream GetInfoFromFile("Triggers.txt");
    }

    // Check what triggers addresses from previous level would do in current level.
    string GetLineString; // One line of file - contains address, room of address, sector of address.
    string StartString; // String before address or room of address or sector of address.
    string EndString; // String after address or room of address or sector of address.
    string StringResult; // String result between StarString and EndString. Result is address or room of address or sector of address.
    while (getline(GetInfoFromFile, GetLineString)) {
        // Get address from line.
        StartString = "Address: 0x"; // String before address.
        EndString = " Room:"; // String after address.
        StringResult = get_string_between(GetLineString, StartString, EndString); // Result is address.
        uintptr_t AddressToCheck;
        istringstream ConvertAd(StringResult);
        ConvertAd >> hex >> AddressToCheck; // Convert StringResult to hexadecimal number and save it to AddressToCheck.
        // Get room from line.
        StartString = "Room: "; // String before room of address.
        EndString = " Sector:";  // String after room of address.
        StringResult = get_string_between(GetLineString, StartString, EndString); // Result is room of address.
        uint16_t AddressRoom;
        istringstream ConvertR(StringResult);
        ConvertR >> dec >> AddressRoom; // Convert StringResult to decimal number and save it to AddressRoom.
        // Get sector from line.
        StartString = "Sector: "; // String before sector of address.
        EndString = "\n"; // String after sector of address.
        StringResult = get_string_between(GetLineString, StartString, EndString); // Result is sector of address.
        uint16_t AddressSector;
        istringstream ConvertS(StringResult);
        ConvertS >> dec >> AddressSector; // Convert StringResult to decimal number and save it to AddressSector.

        // Write address, room of address, sector of address to Test Triggers.txt file.
        if (GameSystems[SelectGameSystem] == "Personal Computer") {
            CheckFile << "Address: 0x" << hex << uppercase << AddressToCheck << " (Room: " << dec << (unsigned short int)AddressRoom << ", Sector: " << (unsigned short int)AddressSector << ")" << endl;
        }
        else if (GameSystems[SelectGameSystem] == "Sony Playstation (Bizhawk 2.8, core: OctoShock)") {
            CheckFile << "Address: 0x" << hex << uppercase << AddressToCheck << " (PSXMainRAM: 0x" << (AddressToCheck - ModuleBaseAddress - BizhawkPSXMainRAM) << ")" << " (Room: " << dec << (unsigned short int)AddressRoom << ", Sector: " << (unsigned short int)AddressSector << ")" << endl;
        }
        /*
        else if (GameSystems[SelectGameSystem] == "Sega Dreamcast (Bizhawk, core: )") {
            CheckFile << "Address: 0x" << hex << uppercase << AddressToCheck << " (DreamcastRAM: 0x" << (AddressToCheck - ModuleBaseAddress - BizhawkDreamcastRAM) << ")" << " (Room: " << dec << (unsigned short int)AddressRoom << ", Sector: " << (unsigned short int)AddressSector << ")" << endl;
        }
        */

        // TriggerSetup field.
        uint16_t TriggerSetup = 0x0; // TriggerSetup.
        uint8_t TR3Timer = 0; // Timer of TriggerSetup.
        int8_t TR4TR5Timer = 0; // Timer of TriggerSetup. Since TR4, timer field became signed.
        uint8_t Mask = 0; // Mask of TriggerSetup.
        uint8_t OneShot = 0; // One shot of TriggerSetup.

        // ActionList field.
        uint16_t ActionList = 0x0; // ActionList.
        uint16_t Parameter = 0; // Parameter of ActionList.
        uint16_t TrigAction = 0x0; // Trigger action of ActionList.
        uint16_t ContBit = 0x0; // ContBit of ActionList.
        uint16_t SwitchKeyholePickup; // Switch entity for trigger type: switch, keyhole entity for trigger type: key, pick-up entity for trigger type: pickup.
        uint8_t TrigTypeKey = 0; // Changes to value 1 if trigger type is Key. Used to bypasss ContBit in first Key ActionList.

        // Extra entries field.
        uint16_t CameraExtra = 0x0; // Extra uint16_t entry of trigger action: camera.
        uint16_t CameraTimer = 0; // Timer of extra uint16_t entry of trigger action: camera.
        uint16_t FlybyExtra = 0x0; // Extra uint16_t entry of trigger action: flyby. TR4,TR5 only.
        uint8_t TrigActionCamera = 0; // Changes to value 1 if ActionList case is Camera.
        uint8_t TrigActionFlyby = 0; // Changes to value 1 if ActionList case is Flyby.

        AddressToCheck -= 2;
        EndData = 0x0;
        do {
            ReadProcessMemory(hProcess, (LPCVOID)(AddressToCheck += 2), &FDSetup, 2, NULL);
            EndData = FDSetup & 0x8000;
            switch (FDSetup & 0x1F) {
            case 0x05: // Kill Lara.
                CheckFile << "-Function: Kill Lara" << endl;
                break;
            case 0x06: // Climbable Walls.
                CheckFile << "-Function: Climbable Walls" << endl;
                break;
            case 0x13: // Monkey Swing.
                CheckFile << "-Function: Monkeyswing" << endl;
                break;
            case 0x14: // Function 0x14.
                // Function 0x14 for Tomb Raider 3 and Tomb Raider 3: The Lost Artifact.
                if (Games[SelectGame] == "Tomb Raider 3" || Games[SelectGame] == "Tomb Raider 3: The Lost Artifact") {
                    CheckFile << "-Function: Minecart vehicle - turn left 90 degrees" << endl;
                }
                // Function 0x14 for Tomb Raider 4, Tomb Raider 4: The Times Exclusive and Tomb Raider 5.
                else {
                    EndData = 0x1;
                    CheckFile << "-Function: Trigger Triggerer" << endl;
                }
                break;
            case 0x15: // Function 0x15.
                // Function 0x15 for Tomb Raider 3 and Tomb Raider 3: The Lost Artifact.
                if (Games[SelectGame] == "Tomb Raider 3" || Games[SelectGame] == "Tomb Raider 3: The Lost Artifact") {
                    CheckFile << "-Function: Minecart vehicle - turn right 90 degrees" << endl;
                }
                // Function 0x15 for Tomb Raider 4, Tomb Raider 4: The Times Exclusive.
                else if (Games[SelectGame] == "Tomb Raider 4" || Games[SelectGame] == "Tomb Raider 4: The Times Exclusive") {
                    CheckFile << "-Function: Mechanical Beetle" << endl;
                }
                // Function 0x15 for Tomb Raider 5.
                else {
                    CheckFile << "-Function: 0x15" << endl;
                }
                break;
            default: // All other cases behave as trigger function when Lara is in no space.
                EndData = 0x1;
                CheckFile << "-Function: Trigger (";
                ReadProcessMemory(hProcess, (LPCVOID)(AddressToCheck += 2), &TriggerSetup, 2, NULL);

                // Timer of TriggerSetup.
                // Timer for Tomb Raider 3 and Tomb Raider 3: The Lost Artifact.
                if (Games[SelectGame] == "Tomb Raider 3" || Games[SelectGame] == "Tomb Raider 3: The Lost Artifact") {
                    TR3Timer = TriggerSetup & 0xFF;
                    CheckFile << "Timer: " << (unsigned short int)TR3Timer << ", ";
                }
                // Timer for Tomb Raider 4, Tomb Raider 4: The Times Exclusive and Tomb Raider 5.
                else {
                    TR4TR5Timer = TriggerSetup & 0xFF;
                    CheckFile << "Timer: " << (signed short int)TR4TR5Timer << ", ";
                }

                // Mask of TriggerSetup.
                Mask = (TriggerSetup & 0x3E00) >> 9;
                Mask = reverse_mask(Mask);
                CheckFile << "Mask: " << bitset<5>(Mask);

                // OneShot.
                OneShot = (TriggerSetup & 0x100) >> 8;
                if (OneShot == 0) {
                    CheckFile << ", Only Once: No)" << endl;
                }
                else {
                    CheckFile << ", Only Once: Yes)" << endl;
                }

                ContBit = 0x0;

                // Get trigger type of function.
                switch ((FDSetup >> 8) & 0x3F) {
                case 0x01: // Pad.
                    CheckFile << "Trigger Type: Pad {" << endl;
                    break;
                case 0x02: // Switch.
                case 0x03: // Key.
                case 0x04: // Pickup.
                    ReadProcessMemory(hProcess, (LPCVOID)(AddressToCheck += 2), &ActionList, 2, NULL);
                    SwitchKeyholePickup = ActionList & 0x3FF;
                    if (((FDSetup >> 8) & 0x3F) == 0x02) {
                        CheckFile << "Trigger Type: Switch (Switch: " << (unsigned short int)SwitchKeyholePickup << ") {" << endl;
                        ContBit = ActionList & 0x8000;
                    }
                    else if (((FDSetup >> 8) & 0x3F) == 0x03) {
                        CheckFile << "Trigger Type: Key (Keyhole: " << (unsigned short int)SwitchKeyholePickup << ") (Trigger is triggered without key){" << endl;
                        TrigTypeKey = 1;
                        AddressToCheck -= 2;
                    }
                    else if (((FDSetup >> 8) & 0x3F) == 0x04) {
                        CheckFile << "Trigger Type: Pickup (Pick-up: " << (unsigned short int)SwitchKeyholePickup << ") {" << endl;
                        ContBit = ActionList & 0x8000;
                    }
                    // Read ActionList.
                    if (ContBit == 0x0) {
                        do {
                            ReadProcessMemory(hProcess, (LPCVOID)(AddressToCheck += 2), &ActionList, 2, NULL);
                            TrigAction = (ActionList & 0x3FFF) >> 10;
                            switch (TrigAction) {
                            case 0x00: // Object.
                                Parameter = ActionList & 0x3FF;
                                CheckFile << "Trigger Action: Object (Entity index: " << (unsigned short int)Parameter << ")" << endl;
                                break;
                            case 0x01: // Camera.
                                Parameter = ActionList & 0x3FF;
                                ReadProcessMemory(hProcess, (LPCVOID)(AddressToCheck += 2), &CameraExtra, 2, NULL);
                                CheckFile << "Trigger Action: Camera (Camera index: " << (unsigned short int)Parameter << ") (Timer: " << (unsigned short int)(CameraExtra & 0xFF);
                                OneShot = CameraExtra & 0x100;
                                if (OneShot == 0) {
                                    CheckFile << ", Only Once: No";
                                }
                                else {
                                    CheckFile << ", Only Once: Yes";
                                }
                                CheckFile << ", Speed: " << (unsigned short int)(((CameraExtra & 0x3E00) >> 6) + 1) << ")" << endl;
                                ContBit = CameraExtra & 0x8000;
                                TrigActionCamera = 1;
                                break;
                            case 0x02: // Underwater Current.
                                Parameter = ActionList & 0x3FF;
                                CheckFile << "Trigger Action: Underwater Current (Current index: " << (unsigned short int)Parameter << ")" << endl;
                                break;
                            case 0x03: // Flip Map.
                                Parameter = ActionList & 0x3FF;
                                CheckFile << "Trigger Action: Flip Map (" << (unsigned short int)Parameter << ")" << endl;
                                break;
                            case 0x04: // Flip On.
                                Parameter = ActionList & 0x3FF;
                                CheckFile << "Trigger Action: Flip On (" << (unsigned short int)Parameter << ")" << endl;
                                break;
                            case 0x05: // Flip Off.
                                Parameter = ActionList & 0x3FF;
                                CheckFile << "Trigger Action: Flip Off (" << (unsigned short int)Parameter << ")" << endl;
                                break;
                            case 0x06: // Look at Item.
                                Parameter = ActionList & 0x3FF;
                                CheckFile << "Trigger Action: Look at Item (Entity index: " << (unsigned short int)Parameter << ")" << endl;
                                break;
                            case 0x07: // End Level.
                                if (Games[SelectGame] == "Tomb Raider 4" || Games[SelectGame] == "Tomb Raider 4: The Times Exclusive") {
                                    Parameter = ActionList & 0x3FF;
                                    if (Parameter != 0) {
                                        CheckFile << "Trigger Action: End Level (Level to load: " << (unsigned short int)Parameter << ", Start position: " << (signed short int)TR4TR5Timer << ")" << endl;
                                    }
                                    else {
                                        CheckFile << "Trigger Action: End Level (Level to load: (None), Start position: " << (signed short int)TR4TR5Timer << ")" << endl;
                                    }
                                }
                                else if (Games[SelectGame] == "Tomb Raider 5") {
                                    CheckFile << "Trigger Action: End Level (Start position: " << (signed short int)TR4TR5Timer << ")" << endl;
                                }
                                else {
                                    CheckFile << "Trigger Action: End Level" << endl;
                                }
                                break;
                            case 0x08: // Play Soundtrack.
                                Parameter = ActionList & 0x3FF;
                                CheckFile << "Trigger Action: Play Soundtrack (Soundtrack: " << (unsigned short int)Parameter << ")" << endl;
                                break;
                            case 0x09: // Flipeffect.
                                CheckFile << "Trigger Action: Flip effect" << endl;
                                break;
                            case 0x0A: // Secret Found.
                                Parameter = ActionList & 0x3FF;
                                CheckFile << "Trigger Action: Secret Found (Secret index: " << (unsigned short int)Parameter << ")" << endl;
                                break;
                            case 0x0B: // Clear bodies.
                                // For Tomb Raider 3 and Tomb Raider 3: The Lost Artifact.
                                if (Games[SelectGame] == "Tomb Raider 3" || Games[SelectGame] == "Tomb Raider 3: The Lost Artifact") {
                                    CheckFile << "Trigger Action: Clear bodies" << endl;
                                }
                                // For Tomb Raider 4, Tomb Raider 4: The Times Exclusive and Tomb Raider 5.
                                else {
                                    CheckFile << "Trigger Action: Unknown (0x" << hex << (unsigned short int)((ActionList & 0x3FFF) >> 10) << ")" << dec << endl;
                                }
                                break;
                            case 0x0C: // Flyby.
                                if (Games[SelectGame] != "Tomb Raider 3" && Games[SelectGame] != "Tomb Raider 3: The Lost Artifact") {
                                    Parameter = ActionList & 0x3FF;
                                    ReadProcessMemory(hProcess, (LPCVOID)(AddressToCheck += 2), &FlybyExtra, 2, NULL);
                                    CheckFile << "Trigger Action: Flyby Camera (Flyby camera sequence: " << (unsigned short int)Parameter;
                                    OneShot = FlybyExtra & 0x100;
                                    if (OneShot == 0) {
                                        CheckFile << ", Infinite loop: Yes)" << endl;
                                    }
                                    else {
                                        CheckFile << ", Infinite loop: No)" << endl;
                                    }
                                    ContBit = FlybyExtra & 0x8000;
                                }
                                else {
                                    CheckFile << "Trigger Action: Unknown (0x" << hex << (unsigned short int)((ActionList & 0x3FFF) >> 10) << ")" << dec << endl;
                                }
                                TrigActionFlyby = 1;
                                break;
                            case 0x0D: // Cutscene.
                                if (Games[SelectGame] != "Tomb Raider 3" && Games[SelectGame] != "Tomb Raider 3: The Lost Artifact") {
                                    Parameter = ActionList & 0x3FF;
                                    CheckFile << "Trigger Action: Cutscene (Cutscene ID: " << (unsigned short int)Parameter << ")" << endl;
                                }
                                else {
                                    CheckFile << "Trigger Action: Unknown (0x" << hex << (unsigned short int)((ActionList & 0x3FFF) >> 10) << ")" << dec << endl;
                                }
                                break;
                            default: // Unknown.
                                CheckFile << "Trigger Action: Unknown (0x" << hex << (unsigned short int)((ActionList & 0x3FFF) >> 10) << ")" << dec << endl;
                                break;
                            }
                            if (TrigActionCamera == 0 && TrigActionFlyby == 0 && TrigTypeKey == 0) {
                                ContBit = ActionList & 0x8000;
                            }
                            if (TrigTypeKey == 1) {
                                TrigTypeKey = 0;
                            }
                            TrigActionCamera = 0;
                            TrigActionFlyby = 0;
                        } while (ContBit == 0x0);
                    }
                    break;
                case 0x05: // Heavytrigger.
                    CheckFile << "Trigger Type: Heavytrigger {" << endl;
                    break;
                case 0x06: // Antipad.
                    CheckFile << "Trigger Type: Antipad {" << endl;
                    break;
                case 0x07: // Combat.
                    CheckFile << "Trigger Type: Combat {" << endl;
                    break;
                case 0x08: // Dummy.
                    CheckFile << "Trigger Type: Dummy {" << endl;
                    break;
                case 0x09: // Antitrigger.
                    CheckFile << "Trigger Type: Antitrigger {" << endl;
                    break;
                case 0x0A: // Heavy switch.
                    // For Tomb Raider 4, Tomb Raider 4: The Times Exclusive and Tomb Raider 5.
                    if (Games[SelectGame] != "Tomb Raider 3" && Games[SelectGame] != "Tomb Raider 3: The Lost Artifact") {
                        CheckFile << "Trigger Type: Heavy switch {" << endl;
                    }
                    // For Tomb Raider 3 and Tomb Raider 3: The Lost Artifact.
                    else {
                        CheckFile << "Trigger Type: Trigger {" << endl;
                    }
                    break;
                case 0x0B: // Heavy antitrigger.
                    // For Tomb Raider 4, Tomb Raider 4: The Times Exclusive and Tomb Raider 5.
                    if (Games[SelectGame] != "Tomb Raider 3" && Games[SelectGame] != "Tomb Raider 3: The Lost Artifact") {
                        CheckFile << "Trigger Type: Heavy antitrigger {" << endl;
                    }
                    // For Tomb Raider 3 and Tomb Raider 3: The Lost Artifact.
                    else {
                        CheckFile << "Trigger Type: Trigger {" << endl;
                    }
                    break;
                case 0x0C: // Monkey.
                    // For Tomb Raider 4, Tomb Raider 4: The Times Exclusive and Tomb Raider 5.
                    if (Games[SelectGame] != "Tomb Raider 3" && Games[SelectGame] != "Tomb Raider 3: The Lost Artifact") {
                        CheckFile << "Trigger Type: Monkey {" << endl;
                    }
                    // For Tomb Raider 3 and Tomb Raider 3: The Lost Artifact.
                    else {
                        CheckFile << "Trigger Type: Trigger {" << endl;
                    }
                    break;
                case 0x0D: // Skeleton.
                    // For Tomb Raider 5.
                    if (Games[SelectGame] == "Tomb Raider 5") {
                        CheckFile << "Trigger Type: Skeleton {" << endl;
                    }
                    // For Tomb Raider 3, Tomb Raider 3: The Lost Artifact, Tomb Raider 4 and Tomb Raider 4: The Times Exclusive.
                    else {
                        CheckFile << "Trigger Type: Trigger {" << endl;
                    }
                    break;
                case 0x0E: // Tightrope.
                    // For Tomb Raider 5.
                    if (Games[SelectGame] == "Tomb Raider 5") {
                        CheckFile << "Trigger Type: Tightrope {" << endl;
                    }
                    // For Tomb Raider 3, Tomb Raider 3: The Lost Artifact, Tomb Raider 4 and Tomb Raider 4: The Times Exclusive.
                    else {
                        CheckFile << "Trigger Type: Trigger {" << endl;
                    }
                    break;
                case 0x0F: // Crawl.
                    // For Tomb Raider 5.
                    if (Games[SelectGame] == "Tomb Raider 5") {
                        CheckFile << "Trigger Type: Crawl {" << endl;
                    }
                    // For Tomb Raider 3, Tomb Raider 3: The Lost Artifact, Tomb Raider 4 and Tomb Raider 4: The Times Exclusive.
                    else {
                        CheckFile << "Trigger Type: Trigger {" << endl;
                    }
                    break;
                case 0x10: // Climb.
                    // For Tomb Raider 5.
                    if (Games[SelectGame] == "Tomb Raider 5") {
                        CheckFile << "Trigger Type: Climb {" << endl;
                    }
                    // For Tomb Raider 3, Tomb Raider 3: The Lost Artifact, Tomb Raider 4 and Tomb Raider 4: The Times Exclusive.
                    else {
                        CheckFile << "Trigger Type: Trigger {" << endl;
                    }
                    break;
                default: // All other cases have trigger type trigger when Lara is in no space.
                    CheckFile << "Trigger Type: Trigger {" << endl;
                    break;
                }

                // Read ActionList.
                if (ContBit == 0x0) {
                    do {
                        ReadProcessMemory(hProcess, (LPCVOID)(AddressToCheck += 2), &ActionList, 2, NULL);
                        TrigAction = (ActionList & 0x3FFF) >> 10;
                        switch (TrigAction) {
                        case 0x00: // Object.
                            Parameter = ActionList & 0x3FF;
                            CheckFile << "Trigger Action: Object (Entity index: " << (unsigned short int)Parameter << ")" << endl;
                            break;
                        case 0x01: // Camera.
                            Parameter = ActionList & 0x3FF;
                            ReadProcessMemory(hProcess, (LPCVOID)(AddressToCheck += 2), &CameraExtra, 2, NULL);
                            CheckFile << "Trigger Action: Camera (Camera index: " << (unsigned short int)Parameter << ") (Timer: " << (unsigned short int)(CameraExtra & 0xFF);
                            OneShot = CameraExtra & 0x100;
                            if (OneShot == 0) {
                                CheckFile << ", Only Once: No";
                            }
                            else {
                                CheckFile << ", Only Once: Yes";
                            }
                            CheckFile << ", Speed: " << (unsigned short int)(((CameraExtra & 0x3E00) >> 6) + 1) << ")" << endl;
                            ContBit = CameraExtra & 0x8000;
                            TrigActionCamera = 1;
                            break;
                        case 0x02: // Underwater Current.
                            Parameter = ActionList & 0x3FF;
                            CheckFile << "Trigger Action: Underwater Current (Current index: " << (unsigned short int)Parameter << ")" << endl;
                            break;
                        case 0x03: // Flip Map.
                            Parameter = ActionList & 0x3FF;
                            CheckFile << "Trigger Action: Flip Map (" << (unsigned short int)Parameter << ")" << endl;
                            break;
                        case 0x04: // Flip On.
                            Parameter = ActionList & 0x3FF;
                            CheckFile << "Trigger Action: Flip On (" << (unsigned short int)Parameter << ")" << endl;
                            break;
                        case 0x05: // Flip Off.
                            Parameter = ActionList & 0x3FF;
                            CheckFile << "Trigger Action: Flip Off (" << (unsigned short int)Parameter << ")" << endl;
                            break;
                        case 0x06: // Look at Item.
                            Parameter = ActionList & 0x3FF;
                            CheckFile << "Trigger Action: Look at Item (Entity index: " << (unsigned short int)Parameter << ")" << endl;
                            break;
                        case 0x07: // End Level.
                            if (Games[SelectGame] == "Tomb Raider 4" || Games[SelectGame] == "Tomb Raider 4: The Times Exclusive") {
                                Parameter = ActionList & 0x3FF;
                                if (Parameter != 0) {
                                    CheckFile << "Trigger Action: End Level (Level to load: " << (unsigned short int)Parameter << ", Start position: " << (signed short int)TR4TR5Timer << ")" << endl;
                                }
                                else {
                                    CheckFile << "Trigger Action: End Level (Level to load: (None), Start position: " << (signed short int)TR4TR5Timer << ")" << endl;
                                }
                            }
                            else if (Games[SelectGame] == "Tomb Raider 5") {
                                CheckFile << "Trigger Action: End Level (Start position: " << (signed short int)TR4TR5Timer << ")" << endl;
                            }
                            else {
                                CheckFile << "Trigger Action: End Level" << endl;
                            }
                            break;
                        case 0x08: // Play Soundtrack.
                            Parameter = ActionList & 0x3FF;
                            CheckFile << "Trigger Action: Play Soundtrack (Soundtrack: " << (unsigned short int)Parameter << ")" << endl;
                            break;
                        case 0x09: // Flipeffect.
                            CheckFile << "Trigger Action: Flip effect" << endl;
                            break;
                        case 0x0A: // Secret Found.
                            Parameter = ActionList & 0x3FF;
                            CheckFile << "Trigger Action: Secret Found (Secret index: " << (unsigned short int)Parameter << ")" << endl;
                            break;
                        case 0x0B: // Clear bodies.
                            // For Tomb Raider 3 and Tomb Raider 3: The Lost Artifact.
                            if (Games[SelectGame] == "Tomb Raider 3" || Games[SelectGame] == "Tomb Raider 3: The Lost Artifact") {
                                CheckFile << "Trigger Action: Clear bodies" << endl;
                            }
                            // For Tomb Raider 4, Tomb Raider 4: The Times Exclusive and Tomb Raider 5.
                            else {
                                CheckFile << "Trigger Action: Unknown (0x" << hex << (unsigned short int)((ActionList & 0x3FFF) >> 10) << ")" << dec << endl;
                            }
                            break;
                        case 0x0C: // Flyby.
                            if (Games[SelectGame] != "Tomb Raider 3" && Games[SelectGame] != "Tomb Raider 3: The Lost Artifact") {
                                Parameter = ActionList & 0x3FF;
                                ReadProcessMemory(hProcess, (LPCVOID)(AddressToCheck += 2), &FlybyExtra, 2, NULL);
                                CheckFile << "Trigger Action: Flyby Camera (Flyby camera sequence: " << (unsigned short int)Parameter;
                                OneShot = FlybyExtra & 0x100;
                                if (OneShot == 0) {
                                    CheckFile << ", Infinite loop: Yes)" << endl;
                                }
                                else {
                                    CheckFile << ", Infinite loop: No)" << endl;
                                }
                                ContBit = FlybyExtra & 0x8000;
                            }
                            else {
                                CheckFile << "Trigger Action: Unknown (0x" << hex << (unsigned short int)((ActionList & 0x3FFF) >> 10) << ")" << dec << endl;
                            }
                            TrigActionFlyby = 1;
                            break;
                        case 0x0D: // Cutscene.
                            if (Games[SelectGame] != "Tomb Raider 3" && Games[SelectGame] != "Tomb Raider 3: The Lost Artifact") {
                                Parameter = ActionList & 0x3FF;
                                CheckFile << "Trigger Action: Cutscene (Cutscene ID: " << (unsigned short int)Parameter << ")" << endl;
                            }
                            else {
                                CheckFile << "Trigger Action: Unknown (0x" << hex << (unsigned short int)((ActionList & 0x3FFF) >> 10) << ")" << dec << endl;
                            }
                            break;
                        default: // Unknown.
                            CheckFile << "Trigger Action: Unknown (0x" << hex << (unsigned short int)((ActionList & 0x3FFF) >> 10) << ")" << dec << endl;
                            break;
                        }
                        if (TrigActionCamera == 0 && TrigActionFlyby == 0) {
                            ContBit = ActionList & 0x8000;
                        }
                        TrigActionCamera = 0;
                        TrigActionFlyby = 0;
                    } while (ContBit == 0x0);
                }
                CheckFile << "}" << endl;
                break;
            }
        } while (EndData == 0x0);
        CheckFile << endl;
    }
    // Close Triggers.txt file and Test Triggers.txt file.
    GetInfoFromFile.close();
    CheckFile.close();

    Color(15);
    return 0;
}