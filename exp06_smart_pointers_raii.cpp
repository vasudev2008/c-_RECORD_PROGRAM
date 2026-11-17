#include <iostream>
#include <memory>
using namespace std;
class Resource {
public:
    Resource(){cout<<"Resource acquired\n";}
    ~Resource(){cout<<"Resource released\n";}
    void use(){cout<<"Resource is being used\n";}
};
class MySmartPointer {
    Resource* ptr;
public:
    explicit MySmartPointer(Resource* p):ptr(p){}
    ~MySmartPointer(){delete ptr; cout<<"Manual smart pointer destroyed\n";}
    Resource* operator->(){return ptr;}
    MySmartPointer(const MySmartPointer&)=delete;
    MySmartPointer& operator=(const MySmartPointer&)=delete;
};
int main(){
    cout<<"----- Manual RAII Smart Pointer -----\n";
    {MySmartPointer p(new Resource()); p->use();}
    cout<<"\n----- unique_ptr -----\n";
    {unique_ptr<Resource> p=make_unique<Resource>(); p->use();}
    cout<<"\n----- shared_ptr -----\n";
    {shared_ptr<Resource> p1=make_shared<Resource>(); shared_ptr<Resource> p2=p1; p1->use(); cout<<"Shared Pointer Count: "<<p1.use_count()<<'\n';}
    cout<<"\nProgram completed successfully.\n";
}
