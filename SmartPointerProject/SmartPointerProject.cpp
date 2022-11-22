#include <iostream>
#include "SmartPointerShare.h"
#include "SmartPointerUnique.h"

class Parent
{
public:
    Parent()
    {
        std::cout << "Parent construct\n";
    };
    virtual ~Parent() 
    {
        std::cout << "Parent destruct\n";
    };

    void Print()
    {
        std::cout << "Hello world";
    }
};

class Child : public Parent
{
public:
    Child()
    {
        std::cout << "Child construct\n";
    }
    ~Child()
    {
        std::cout << "Child destruct\n";
    }
};

int main()
{
    /*SmartPointerShare<Parent> smartPtr(new Parent());
    SmartPointerShare<Parent> sptr2(smartPtr);
    SmartPointerShare<Parent> sptr3;

    sptr3 = sptr2;

    std::cout << smartPtr.Count() << " " << sptr2.Count() << " " << sptr3.Count() << "\n";*/

    //smartPtr->Print();

    SmartPointerUnique<Parent> uptr1(new Parent());

    std::cout << "uptr1 " << ((uptr1.IsNull()) ? "Null" : "Not Null") << "\n";

    SmartPointerUnique<Parent> uptr2(uptr1);

    std::cout << "uptr1 " << ((uptr1.IsNull()) ? "Null" : "Not Null") << "\n";
    std::cout << "uptr2 " << ((uptr2.IsNull()) ? "Null" : "Not Null") << "\n";

    SmartPointerUnique<Parent> uptr3;
    uptr3 = uptr2;

    std::cout << "uptr2 " << ((uptr2.IsNull()) ? "Null" : "Not Null") << "\n";
    std::cout << "uptr3 " << ((uptr3.IsNull()) ? "Null" : "Not Null") << "\n";

    return 0;
}
