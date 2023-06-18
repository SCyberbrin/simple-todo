#include<string>
#include <iostream>

bool askUser(std::string question, const char * trueChar = "y", const char * falseChar = "n")
{
    std::string anser;
    
    while (true)
    {
        std::cout << question << " [" << trueChar << "/" << falseChar << "] ";
        std::getline(std::cin, anser);

        if (anser == trueChar)
        {
            return true;
        } else if (anser == falseChar)
        {
            return false;
        }

        std::cout << "Wrong anser!" << std::endl;
    }
    

}