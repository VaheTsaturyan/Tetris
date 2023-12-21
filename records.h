#ifndef RECORD
#define RECORD

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

inline const size_t NUMBER_OF_RECORD_STORED = 5;
inline const std::string ADDRESS = "records.txt";



void saveToFile(int value);
void pushRecords(std::vector<int>& chemps);


#endif