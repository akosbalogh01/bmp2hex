# iniparser library

minimal C++ library for handling initializer files

(see: https://en.wikipedia.org/wiki/INI_file)

# usage

create a 2D linked list data structure of sections and keys from an ini file,  
using the load function, or the constructor of an inifile,  
function arguments are the file's relative or physical path

reading values is done with a public method of the inifile class,  
from the specified section and key id

saving a modified data structure can be achieved by the save methods,  
either to the file path of the originally loaded file,  
or to a new file  

the destructor automatically saves the data structure to last used path  

# documentation

inifile object public methods:  
void load(const std::string& filepath);  
// loads inifile from specified path  
// throws exception if file is not found  

void save();  
// saves inifile to last used path  

void save(const std::string& filepath) const;  
// saves inifile to specified path  

const std::string& filepath() const;  
// returns last used filepath  

const std::string& value(const std::string& sectionid, const std::string& keyid) const;  
// returns value of specified key in specified section  
// throws exceptions if the section or key is not found  

// the following functions are self explanatory, refer to their implementation for futher information  
// if anything fails, exceptions are thrown  
void addSection(const std::string&);  
void modSectionID(const std::string&, const std::string&);  
void delSection(const std::string&);  
void addKey(const std::string&, const std::string&, const std::string&);  
void modKeyID(const std::string&, const std::string&, const std::string&);  
void modKeyValue(const std::string&, const std::string&, const std::string&);  
void delKey(const std::string&, const std::string&);  

# compiler

g++ 4.9.2, std=c++11  

# notes

traversing the list and building the data structure may take a considerable amount of time,  
the intented usage is to read the values once, and store them in variables of the appropriate context.
could be updated to use smart pointers
