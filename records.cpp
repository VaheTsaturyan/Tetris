#include "records.h"

void saveToFile(int value){
	std::ofstream fout;
	fout.open(ADDRESS,std::ofstream::app);
	if(!fout.is_open()){
		return;
	}
	fout << value;

	fout.close();	
}

void pushRecords(std::vector<int>& chemps){
	std::ifstream inputFile(ADDRESS);

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            int num;
            while (iss >> num) {
                chemps.push_back(num);
            }
        }
        inputFile.close();
    } else {
		return;
    }

}