# gis-operator

References:

1. AO official site: https://vulkan-tutorial.com/
2. KhronosGroup Docs: https://github.com/KhronosGroup/Vulkan-Docs
3. AO Handbook: https://github.com/Overv/VulkanTutorial
   ```
VulkanProject/
├── CMakeLists.txt                # Project build configuration file (for CMake)
├── build/                        # Directory for build artifacts
├── src/                          # Source code for the project
│   ├── main.cpp                  # Entry point of the application
│   ├── renderer/                 # Code related to rendering (Vulkan specific)
│   │   ├── VulkanRenderer.cpp    # Implementation of Vulkan renderer
│   │   ├── VulkanRenderer.h      # Vulkan renderer interface
│   │   ├── VulkanSwapChain.cpp   # Swap chain handling
│   │   ├── VulkanSwapChain.h     # Swap chain interface
│   │   ├── VulkanUtils.cpp       # Vulkan utility functions (e.g., debug layers, validation)
│   │   └── VulkanUtils.h         # Vulkan utility header
│   ├── engine/                   # Higher level engine code (scene management, input, etc.)
│   │   ├── Engine.cpp            # Core engine logic
│   │   ├── Engine.h              # Engine interface
│   │   ├── Scene.cpp             # Scene management
│   │   └── Scene.h               # Scene interface
│   ├── input/                    # Input handling (keyboard, mouse, etc.)
│   │   ├── InputManager.cpp      # Input handling implementation
│   │   └── InputManager.h        # Input manager interface
│   └── utils/                    # Utility code (file loading, math, etc.)
│       ├── FileUtils.cpp         # File-related utilities
│       ├── FileUtils.h           # File utilities header
│       ├── MathUtils.cpp         # Math-related utilities (e.g., matrices, vectors)
│       └── MathUtils.h           # Math utilities header
├── shaders/                      # Folder for shaders (GLSL, HLSL, etc.)
│   ├── shader.vert               # Vertex shader
│   ├── shader.frag               # Fragment shader
│   └── shader.spv                # Precompiled shader file (for Vulkan)
├── assets/                       # Folder for asset files (textures, models, etc.)
│   ├── textures/                 # Texture assets
│   └── models/                   # 3D model assets
├── external/                     # External libraries and dependencies (e.g., GLFW, GLM)
│   ├── glfw/                     # GLFW code (if building from source)
│   ├── glm/                      # GLM math library (if building from source)
│   └── vk_sdk/                   # Vulkan SDK (if needed as a submodule)
├── CMake/                        # CMake module files (optional)
│   └── FindVulkan.cmake          # CMake helper script to locate Vulkan SDK
├── .gitignore                    # Git ignore file to exclude build files, etc.
└── README.md                     # Project documentation (basic instructions)
```
