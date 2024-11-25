// SwapChainSupportDetails.h
#ifndef SWAP_CHAIN_SUPPORT_DETAILS_H
#define SWAP_CHAIN_SUPPORT_DETAILS_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdint> 
#include <optional>
#include <vector>

struct SwapChainSupportDetails {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;

    bool isComplete() const {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

#endif // SWAP_CHAIN_SUPPORT_DETAILS_H
