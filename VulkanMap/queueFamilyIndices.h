#ifndef QUEUE_FAMILY_INDICES_H
#define QUEUE_FAMILY_INDICES_H

#include <cstdint>  // For uint32_t
#include <optional>

// A structure to hold indices for Vulkan queue families.
struct QueueFamilyIndices {
    // Optional to store the index of the graphics queue family.
    std::optional<uint32_t> graphicsFamily;

    // Function to check if the queue family index is valid (i.e., it has a value).
    bool isComplete() const {
        return graphicsFamily.has_value();
    }
};

#endif // QUEUE_FAMILY_INDICES_H
