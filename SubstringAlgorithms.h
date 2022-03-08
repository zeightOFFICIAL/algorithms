// main functions =============================================

// Boyer-Moore algorithm
void Substring_Boyer_Moore(char* Array, int Length);
// Rabin-Karp algorithm
void Substring_Rabin_Karp(char* Array, int Length, int Mode);
// Naive algorithm
void Substring_Naive(char* Array, int Length);

//tools =======================================================

void Tool_Badchar(std::string Array, int PatternLength, int* Badchar, int Length);
int Tool_Max(int a, int b);
void Tool_ClearTxt();