//TEST CODE

#include <volk.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_vulkan.h>

#include <iostream>

int main()
{
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    std::cout << "ImGui version: " << ImGui::GetVersion() << '\n';

    if (volkInitialize() != VK_SUCCESS)
    {
        std::cerr << "Failed to initialize Vulkan.\n";
        return 1;
    }

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW.\n";
        return 1;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    GLFWwindow* window = glfwCreateWindow(
        1280,
        720,
        "Vulkan Renderer",
        nullptr,
        nullptr
    );

    if (!window)
    {
        glfwTerminate();
        return 1;
    }

    glm::vec3 testVector(1.0f, 2.0f, 3.0f);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    ImGui::DestroyContext();
    return 0;
}