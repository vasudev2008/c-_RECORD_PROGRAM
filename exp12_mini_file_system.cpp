#include <iostream>
#include <fstream>
#include <cstring>
#include <new>
using namespace std;
template<typename T> class CustomAllocator {
public:
    using value_type=T;
    CustomAllocator()=default;
    template<typename U> CustomAllocator(const CustomAllocator<U>&){}
    T* allocate(size_t n){cout<<"Allocating memory for "<<n<<" object(s)\n";return static_cast<T*>(::operator new(n*sizeof(T)));}
    void deallocate(T* p,size_t){cout<<"Deallocating memory\n";::operator delete(p);}
};
struct FileRecord {char fileName[50];int fileSize;};
void addFile(){FileRecord file{};cout<<"Enter File Name: ";cin.width(sizeof(file.fileName));cin>>file.fileName;cout<<"Enter File Size (KB): ";if(!(cin>>file.fileSize)||file.fileSize<0){cin.clear();cin.ignore(10000,'\n');cout<<"Invalid file size.\n";return;}ofstream outFile("filesystem.dat",ios::binary|ios::app);if(outFile){outFile.write(reinterpret_cast<const char*>(&file),sizeof(file));cout<<"File record added successfully.\n";}else cout<<"Unable to open file.\n";}
void displayFiles(){ifstream inFile("filesystem.dat",ios::binary);if(!inFile){cout<<"No file records found.\n";return;}FileRecord file{};cout<<"\n--- File System Records ---\n";while(inFile.read(reinterpret_cast<char*>(&file),sizeof(file)))cout<<"File Name : "<<file.fileName<<"\nFile Size : "<<file.fileSize<<" KB\n--------------------------\n";}
int main(){int choice;do{cout<<"\nMINI FILE SYSTEM SIMULATOR\n1. Add File\n2. Display Files\n3. Exit\nEnter your choice: ";if(!(cin>>choice)){cin.clear();cin.ignore(10000,'\n');cout<<"Invalid input.\n";continue;}switch(choice){case 1:addFile();break;case 2:displayFiles();break;case 3:cout<<"Exiting File System Simulator...\n";break;default:cout<<"Invalid choice.\n";}}while(choice!=3);}
