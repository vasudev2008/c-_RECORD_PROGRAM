#include <iostream>
#include <cstring>
#include <chrono>
#include <utility>
using namespace std;
using namespace chrono;
class String {
    char* data=nullptr; size_t length=0;
public:
    explicit String(const char* str=""){length=strlen(str);data=new char[length+1];strcpy(data,str);}
    String(const String& other):length(other.length){data=new char[length+1];strcpy(data,other.data);}
    String(String&& other) noexcept:data(other.data),length(other.length){other.data=nullptr;other.length=0;}
    String& operator=(const String& other){if(this!=&other){char* copy=new char[other.length+1];strcpy(copy,other.data);delete[] data;data=copy;length=other.length;}return *this;}
    String& operator=(String&& other) noexcept{if(this!=&other){delete[] data;data=other.data;length=other.length;other.data=nullptr;other.length=0;}return *this;}
    ~String(){delete[] data;}
    void display()const{if(data)cout<<data;}
};
template<typename T> String createString(T&& value){return String(std::forward<T>(value));}
int main(){
    const int SIZE=100000;
    String original("This is a resource-heavy string used to demonstrate copy and move semantics in C++.");
    auto startCopy=high_resolution_clock::now();for(int i=0;i<SIZE;i++){String copy=original;(void)copy;}auto endCopy=high_resolution_clock::now();
    auto startMove=high_resolution_clock::now();for(int i=0;i<SIZE;i++){String temp("This is a resource-heavy string used for move semantics.");String moved=std::move(temp);(void)moved;}auto endMove=high_resolution_clock::now();
    String forwarded=createString("Perfect Forwarding Example");cout<<"Perfect Forwarding Result: ";forwarded.display();cout<<'\n';
    cout<<"\nCopy Operation Time: "<<duration_cast<milliseconds>(endCopy-startCopy).count()<<" milliseconds\n";
    cout<<"Move Operation Time: "<<duration_cast<milliseconds>(endMove-startMove).count()<<" milliseconds\n";
}
