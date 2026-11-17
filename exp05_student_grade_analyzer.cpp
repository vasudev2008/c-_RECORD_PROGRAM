#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
struct Student { string name; int mark; char grade=' '; };
int main() {
    vector<Student> students={{"Arun",85},{"Bala",72},{"Kumar",91},{"Ravi",65}};
    sort(students.begin(),students.end(),[](const Student& a,const Student& b){return a.mark>b.mark;});
    transform(students.begin(),students.end(),students.begin(),[](Student s){
        if(s.mark>=90)s.grade='A'; else if(s.mark>=75)s.grade='B'; else if(s.mark>=50)s.grade='C'; else s.grade='F'; return s;
    });
    auto it=find_if(students.begin(),students.end(),[](const Student& s){return s.mark>80;});
    int total=accumulate(students.begin(),students.end(),0,[](int sum,const Student& s){return sum+s.mark;});
    cout<<"Student Grade Analyzer\n---------------------\nName\tMark\tGrade\n";
    for(const auto& s:students) cout<<s.name<<'\t'<<s.mark<<'\t'<<s.grade<<'\n';
    if(it!=students.end()) cout<<"\nFirst student scoring above 80: "<<it->name<<'\n';
    cout<<"Total Marks: "<<total<<"\nAverage Mark: "<<fixed<<setprecision(2)<<static_cast<double>(total)/students.size()<<'\n';
}
