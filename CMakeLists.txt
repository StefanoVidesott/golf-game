cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

# set(SFML_STATIC_LIBRARIES TRUE)

# target_link_libraries(main PRIVATE
#     SFML::Graphics
#     SFML::Audio
#     pthread
#     opengl
#     freetype
#     jpeg
#     flac
#     openal
#     vorbisfile
#     vorbis
#     vorbisenc
# )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp include/scenes/scene.cpp include/core/scene_manager.cpp include/entities/components/sprite_component.cpp include/entities/entity.cpp include/core/resource_manager.cpp include/scenes/test_scene.cpp include/core/application.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio)
