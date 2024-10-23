#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <omp.h>
#include <cstdlib>
#include <csignal>

bool decrypt(std::string input_file, std::string output_file, std::string passphrase);

int main() 
{
    std::ifstream file("dictionary.txt");
    std::vector<std::string> dictionary;
    std::string line;

    while (std::getline(file, line)) {
        dictionary.push_back(line);
    }

    std::string input_file = "archive.pdf.gpg";
    std::string output_file = "archive.pdf";
    std::string passphrase;
    bool found = false;

    double start_time = omp_get_wtime();

    omp_set_num_threads(8); // Set number of threads
    #pragma omp parallel for shared(found, passphrase)
    for(int i = 0; i < dictionary.size(); i++) {
        if(!found) {
            if(decrypt(input_file, output_file, dictionary[i])) {
                #pragma omp critical
                {
                    found = true;
                    passphrase = dictionary[i];
                }
            }
        }
    }
    double end_time = omp_get_wtime();

    if (found) {
        std::cout << "Passphrase: " << passphrase << std::endl;
    } else {
        std::cout << "Passphrase not found." << std::endl;
    }    
    std::cout << "Time: " << (end_time - start_time) / 3600 << " hours" << std::endl; 

    return 0;
}

bool decrypt(std::string input_file, std::string output_file, std::string passphrase) 
{
    std::string command = "gpg --batch --yes --passphrase " + passphrase + " -o " + output_file + " -d " + input_file;
    //std::string command_sil = "gpg --batch --yes --quiet --passphrase " + passphrase + " -o " + output_file + " -d " + input_file + " > /dev/null 2>&1";

    int status = system(command.c_str());
    if(status == 0) {
        return true;
    }
    return false;
}