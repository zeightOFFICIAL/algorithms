#include <iostream>
#include <cstring>
#include <random>
#include <fstream>
#include <vector>

const unsigned long int EXTREME_LENGTH = 10000000;  

char* GenerateCustomString(unsigned long &length)
{    
    static char array[EXTREME_LENGTH];
    int local_length = 0;
    
    std::cout<<"String: ";
    std::cin.getline(array,EXTREME_LENGTH);
    local_length = strlen(array);
    length = local_length;
    return array;
}

char* GenerateRandomString(unsigned long length, char alphabet_type)
{
    static char array[EXTREME_LENGTH];
    std::string alphabet_set;
    int this_symbol_index = -1;
    
    if (alphabet_type==1)
        alphabet_set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
    else if (alphabet_type==2)
        alphabet_set = "ABC123 ";
    else {
        std::cout << "Wrong alphabet type. Another will be selected."<<"\n";
        alphabet_set = "ABC123 ";
        }
    int set_length = alphabet_set.length();
    
    srand((int)time(0));
    for (auto i = 0; i < length; i++)    {
            this_symbol_index = rand()%set_length;
            array[i]=alphabet_set[this_symbol_index];
        }
    return array;
}

char* GenerateArrayFile(std::string filename, unsigned long &length)
{
    static char array[EXTREME_LENGTH];
    unsigned long i = 0;
    std::ifstream file;
    file.open(filename);
	if (!file)
        std::cout << "No such file.";
	else  {
        char ch;
        while (file >> std::noskipws >> ch) {
            array[i]=ch;
            i++;
        }
	}
    file.close();
    length = i;
    return array;
}

void PrintArray(char* array, unsigned long length)
{
    for (unsigned long i = 0; i < length; i++)
        std::cout<<array[i];
    std::cout<<"\n";
}
void PrintArray(std::vector<unsigned long> array)
{
    for (unsigned long i = 0; i < array.size(); i++) {
        std::cout<<array[i]<<"\n";
        if (i >= 0 && array[i+1] == 0)
            break;
        }
}

void WriteArray(std::string filename, std::vector<unsigned long> array)
{
    std::ofstream file;
    file.open(filename, std::ios::trunc);
	if (!file)
        std::cout << "No such file.";
	else 
        for (int i = 0; i < array.size(); i++)
            file << array[i] << "\n";
    file.close();
}
void WriteArray(std::string filename, char* array, unsigned long length)
{
    std::ofstream file;
    file.open(filename, std::ios::trunc);
	if (!file)
        std::cout << "No such file.";
	else 
        for (int i = 0; i < length; i++)
            file << array[i];
    file.close();
}

std::vector<unsigned long> EveloperWithCustomText(char* text,unsigned long length, std::vector<unsigned long>(*func)(char*, std::string,unsigned long))
{
    std::string pattern_string;
    std::cout<<"Enter a pattern: ";
    std::cin>>pattern_string;
    return func(text,pattern_string,length);
}    