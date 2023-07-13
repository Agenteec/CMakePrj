# CMakeList.txt: проект CMake для CMakePrj; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
# Проверка операционной системы
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  # Добавьте дополнительные действия, которые должны выполняться только на Linux
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMakePrj")
find_package(jsoncpp CONFIG REQUIRED)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakePrj "CMakePrj.cpp"  "include/Header1.h" "source.cpp")
# Указание пути к заголовочным файлам
target_include_directories(CMakePrj PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(CMakePrj PRIVATE jsoncpp_lib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakePrj PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
