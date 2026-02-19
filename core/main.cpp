#include <iostream>

void runGeneratedTest();
void runRandomImageTest();

int main()
{
    std::cout<<"Choose the test to run:" << std::endl;
    std::cout<<"1. Generated test" << std::endl;
    std::cout<<"2. RandomImage test" << std::endl;

    int choice;
    std::cin>>choice;
    if(choice == 1)
    {
        runGeneratedTest();
    }
    else if(choice == 2)
    {
        runRandomImageTest();
    }
    return 0;
}
