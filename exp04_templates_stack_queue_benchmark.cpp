#include <iostream>
#include <stack>
#include <queue>
#include <chrono>
#include <stdexcept>
using namespace std;
using namespace chrono;

template<class T> class MyStack {
    T data[10000]; int topIndex=-1;
public:
    void push(T value) { if(topIndex<9999) data[++topIndex]=value; }
    void pop() { if(topIndex>=0) --topIndex; }
};
template<class T> class MyQueue {
    T data[10000]; int frontIndex=0, rearIndex=-1;
public:
    void enqueue(T value) { if(rearIndex<9999) data[++rearIndex]=value; }
    void dequeue() { if(frontIndex<=rearIndex) ++frontIndex; }
};
template<class F> long long benchmark(F operation) {
    auto start=high_resolution_clock::now(); operation(); auto end=high_resolution_clock::now();
    return duration_cast<microseconds>(end-start).count();
}
int main() {
    const int N=10000;
    auto customStackTime=benchmark([&]{MyStack<int> s; for(int i=0;i<N;i++)s.push(i); for(int i=0;i<N;i++)s.pop();});
    auto stlStackTime=benchmark([&]{stack<int> s; for(int i=0;i<N;i++)s.push(i); for(int i=0;i<N;i++)s.pop();});
    auto customQueueTime=benchmark([&]{MyQueue<int> q; for(int i=0;i<N;i++)q.enqueue(i); for(int i=0;i<N;i++)q.dequeue();});
    auto stlQueueTime=benchmark([&]{queue<int> q; for(int i=0;i<N;i++)q.push(i); for(int i=0;i<N;i++)q.pop();});
    cout<<"Custom Stack Time: "<<customStackTime<<" microseconds\n";
    cout<<"STL Stack Time: "<<stlStackTime<<" microseconds\n";
    cout<<"Custom Queue Time: "<<customQueueTime<<" microseconds\n";
    cout<<"STL Queue Time: "<<stlQueueTime<<" microseconds\n";
}
