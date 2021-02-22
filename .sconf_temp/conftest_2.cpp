
#include <vector>
#include <memory>

struct A {
   A(int a) : _a(a) {}
   int _a;
};

int main(int argc, char* argv[]) {
   std::shared_ptr<A> myA(new A(1));
   std::vector<int> vec;
   vec.assign(10, myA->_a);
   for(auto& x : vec) {
      x += 10;
   }
   return 0;
}