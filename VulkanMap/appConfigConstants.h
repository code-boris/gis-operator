// Constants.h

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.h>

#include <cstdint>
#include <vector>

namespace AppConfigConstants {
    constexpr uint32_t WIDTH = 800;
    constexpr uint32_t HEIGHT = 600;

    const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
    };

    const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };
}

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

#endif