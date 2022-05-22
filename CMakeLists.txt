# minimum CMake version required
cmake_minimum_required(VERSION 3.15)
# Project name, version and description
project(bowot VERSION 1.0 DESCRIPTION "A discord bot")

# Add DPP as dependency
add_subdirectory(libs/DPP)
add_subdirectory(libs/cpp-dotenv)
# in the `libs/` directory

# Create an executable
add_executable(${PROJECT_NAME}
        src/main.cpp
        # your others files...
        include/hash.hpp include/commands/commands.h include/commands/Flan.hpp)

# Linking libraries
target_link_libraries(${PROJECT_NAME}
        dpp
        cpp_dotenv
        )

# Specify includes
target_include_directories(${PROJECT_NAME} PRIVATE
        libs/DPP/include
        )

# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17 # or 20 if you want something more recent
        CXX_STANDARD_REQUIRED ON
        )
