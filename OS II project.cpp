// osproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
void FirstFit(int* MemoryBlockSize, int MemoryblockNo, int* Processes, int processnumbers)
{
    int* ProcessAllocation = new int[processnumbers];

    for (int a = 0; a < processnumbers; a++)
    {
        ProcessAllocation[a] = -1;
    }

    for (int i = 0; i < processnumbers; i++)
    {
        for (int j = 0; j < MemoryblockNo; j++)
        {
            if (MemoryBlockSize[j] >= Processes[i])
            {
                ProcessAllocation[i] = j;
                MemoryBlockSize[j] = 0;
                break;
            }
        }
    }

    cout << "**********************************************";
    cout << "\n PROCESS NO \t PROCESS SIZE \t BLOCK NO\n";
    for (int i = 0; i < processnumbers; i++)
    {
        cout << " " << i + 1 << "\t\t ";
        Sleep(100);
        cout << Processes[i] << "\t\t ";
        Sleep(100);
        if (ProcessAllocation[i] != -1)
        {
            cout << ProcessAllocation[i] + 1;
            Sleep(100);
        }
        else
        {
            cout << "Not Allocated";
            Sleep(100);
        }
        cout << "\n";
        Sleep(100);
    }
    cout << "**********************************************\n";

}
void BestFit(int* MemoryBlockSize, int MemoryblockNo, int* Processes, int processnumbers)
{
    int* ProcessAllocation = new int[processnumbers];

    for (int a = 0; a < processnumbers; a++)
    {
        ProcessAllocation[a] = -1;
    }

    for (int i = 0; i < processnumbers; i++)
    {
        int BestIndex = -1;
        for (int j = 0; j < MemoryblockNo; j++)
        {
            if (MemoryBlockSize[j] >= Processes[i])
            {
                if (BestIndex == -1)
                {
                    BestIndex = j;
                }
                else if (MemoryBlockSize[BestIndex] > MemoryBlockSize[j])
                {
                    BestIndex = j;
                }
            }
        }
        if (BestIndex != -1)
        {
            ProcessAllocation[i] = BestIndex;
            MemoryBlockSize[BestIndex] = 0;
        }
    }

    cout << "**********************************************";
    cout << "\n PROCESS NO \t PROCESS SIZE \t BLOCK NO\n";
    for (int i = 0; i < processnumbers; i++)
    {
        cout << " " << i + 1 << "\t\t ";
        Sleep(100);
        cout << Processes[i] << "\t\t ";
        Sleep(100);
        if (ProcessAllocation[i] != -1)
        {
            cout << ProcessAllocation[i] + 1;
            Sleep(100);
        }
        else
        {
            cout << "Not Allocated";
            Sleep(100);
        }
        cout << "\n";
        Sleep(100);
    }
    cout << "**********************************************\n";
}
void WorstFit(int* MemoryBlockSize, int MemoryblockNo, int* Processes, int processnumbers)
{
    int* ProcessAllocation = new int[processnumbers];

    for (int a = 0; a < processnumbers; a++)
    {
        ProcessAllocation[a] = -1;
    }


    for (int i = 0; i < processnumbers; i++)
    {
        int WorstIndex = -1;
        for (int j = 0; j < MemoryblockNo; j++)
        {
            if (MemoryBlockSize[j] >= Processes[i])
            {
                if (WorstIndex == -1)
                {
                    WorstIndex = j;
                }
                else if (MemoryBlockSize[WorstIndex] < MemoryBlockSize[j])
                {
                    WorstIndex = j;
                }
            }
        }
        if (WorstIndex != -1)
        {
            ProcessAllocation[i] = WorstIndex;
            MemoryBlockSize[WorstIndex] =0;
        }
    }

    cout << "**********************************************";
    cout << "\n PROCESS NO \t PROCESS SIZE \t BLOCK NO\n";
    for (int i = 0; i < processnumbers; i++)
    {
        cout << " " << i + 1 << "\t\t ";
        Sleep(100);
        cout << Processes[i] << "\t\t ";
        Sleep(100);
        if (ProcessAllocation[i] != -1)
        {
            cout << ProcessAllocation[i] + 1;
            Sleep(100);
        }
        else
        {
            cout << "Not Allocated";
            Sleep(100);
        }
        cout << "\n";
        Sleep(100);
    }
    cout << "**********************************************\n";
}
void Runprogram()
{
    cout << "Enter number of the Memory Blocks:\n";
    cout << "-- ";
    int NumberOFBlock;
    int MemoryBlockSize;
    cin >> NumberOFBlock;
    int* block = new int[NumberOFBlock];

    cout << "Fill the Memory Block Size:\n";
    for (int i = 0; i < NumberOFBlock; i++)
    {
        cout << i + 1 << ") ";
        cin >> MemoryBlockSize;
        block[i] = MemoryBlockSize;
    }


    cout << "Enter number of the Processes:\n";
    cout << "-- ";
    int NumberOFProcess;
    int ProcessSize;
    cin >> NumberOFProcess;
    int* process = new int[NumberOFProcess];

    cout << "Fill the Process Size:\n";
    for (int i = 0; i < NumberOFProcess; i++)
    {
        cout << i + 1 << ") ";
        cin >> ProcessSize;
        process[i] = ProcessSize;
    }


    cout << "Choose Memory Allocation Algorithm:\n";
    cout << "FirstFit (f,F)\t BestFit (b,B)\t WorstFit (w,W)\n";
    char FitType;
    cin >> FitType;
    if (FitType == 'b' || FitType == 'B')
    {
        BestFit(block, NumberOFBlock, process, NumberOFProcess);
    }
    else if (FitType == 'f' || FitType == 'F')
    {
        FirstFit(block, NumberOFBlock, process, NumberOFProcess);
    }
    else if (FitType == 'w' || FitType == 'W')
    {
        WorstFit(block, NumberOFBlock, process, NumberOFProcess);
    }
    else
    {
        cout << "There is no fit my this char\n";
    }


    string Continue;
    cout << "Type yes to try one more, and type anything else to EXIT \n";
    cin >> Continue;
    if (Continue == "yes" || Continue == "YES" || Continue == "y" || Continue == "Y")
    {
        system("cls");
        Runprogram();
    }
    else
    {
        system("cls");
        cout << "Thank you for using our program\n";
    }
}
int main()
{
    Runprogram();
}