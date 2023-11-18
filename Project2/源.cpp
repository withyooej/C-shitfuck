#include<Windows.h>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
#include<time.h>

int SearchMemory(HANDLE hProcess, WORD FeatureCode[], BYTE FeatureCodeSize, DWORD64 StartAddress, DWORD64 EndAddress, std::vector<DWORD64>& ResultArray) {
	MEMORY_BASIC_INFORMATION Memorylnformation;
	FeatureCodeSize -= 1;
	while (VirtualQueryEx(hProcess,(LPCVOID)StartAddress,&Memorylnformation,sizeof(Memorylnformation)))
	{
		if (Memorylnformation.State == MEM_COMMIT && Memorylnformation.Protect == PAGE_EXECUTE_READWRITE || Memorylnformation.Protect == PAGE_READWRITE) {
			BYTE* MemoryData = new BYTE[Memorylnformation.RegionSize];
			if (!ReadProcessMemory(hProcess, (LPCVOID)StartAddress, MemoryData, Memorylnformation.RegionSize, nullptr))
				return 0;
			Memorylnformation.RegionSize -= FeatureCodeSize;
			for (int i = 0; i < Memorylnformation.RegionSize; i++)
			{
				for (int i2 = 0; i2 <= FeatureCodeSize; i2++)
				{
					if (MemoryData[i + i2] != FeatureCode[i2] && FeatureCode[i2] <= 255)
						break;
					if (i2 == FeatureCodeSize)
					{
						ResultArray.push_back(StartAddress + i2);
						i2 += FeatureCodeSize + 1;
					}
				};  
			};
			delete MemoryData;
		};
		StartAddress += Memorylnformation.RegionSize;
		if (StartAddress >= EndAddress)
		{
			return ResultArray.size();
		}
	}
}

int maine() {
	HANDLE Game_HANDLE = OpenProcess(PROCESS_ALL_ACCESS,false,9800);
	WORD FeatureCode[4] = { 0x64,0x00,0x00,0x00 };
	std::vector<DWORD64>ResultArray;
	SearchMemory(Game_HANDLE, FeatureCode, 4, 0x41000, 0x7fffffff, ResultArray);
	printf("ok");
	return 0;
}