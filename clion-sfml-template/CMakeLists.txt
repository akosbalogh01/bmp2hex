cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

include_directories("C:/Dev/MSYS2/mingw64/include/")
link_directories(C:/Dev/MSYS2/mingw64/lib/)
add_definitions(-DSFML_STATIC)
add_executable(${PROJECT_NAME} main.cpp)

set(SFML_LIBS sfml-system)
set(SFML_LIBS ${SFML_LIBS} sfml-window)
set(SFML_LIBS ${SFML_LIBS} sfml-graphics)
set(SFML_LIBS ${SFML_LIBS} sfml-network)
set(SFML_LIBS ${SFML_LIBS} sfml-audio)

set(SFML_DEPS ws2_32)
set(SFML_DEPS ${SFML_DEPS} ogg)
set(SFML_DEPS ${SFML_DEPS} vorbis)
set(SFML_DEPS ${SFML_DEPS} vorbisfile)
set(SFML_DEPS ${SFML_DEPS} vorbisenc)
set(SFML_DEPS ${SFML_DEPS} flac)
set(SFML_DEPS ${SFML_DEPS} openal)
set(SFML_DEPS ${SFML_DEPS} gdi32)
set(SFML_DEPS ${SFML_DEPS} winmm)
set(SFML_DEPS ${SFML_DEPS} freetype)
set(SFML_DEPS ${SFML_DEPS} opengl32)

target_link_libraries(${PROJECT_NAME} ${SFML_DEPS} ${SFML_LIBS})