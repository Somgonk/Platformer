#include <iostream>
#include "GLFW/glfw3.h"

int main()
{
    if (!glfwInit())
    {
        return -1;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
