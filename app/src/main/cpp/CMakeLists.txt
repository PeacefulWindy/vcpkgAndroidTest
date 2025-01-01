cmake_minimum_required(VERSION 3.22.1)

if (ANDROID_ABI MATCHES "arm64-v8a")
        set(VCPKG_TARGET_TRIPLET "arm64-android" CACHE STRING "" FORCE)
elseif(ANDROID_ABI MATCHES "x86_64")
        set(VCPKG_TARGET_TRIPLET "x64-android" CACHE STRING "" FORCE)
endif()
string(REPLACE "\\" "/" ANDROID_NDK_HOME $ENV{ANDROID_NDK_HOME})
set(VCPKG_ROOT "${CMAKE_SOURCE_DIR}/../../../../vcpkg")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_CHAINLOAD_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/toolchains/android.cmake")

project("myapplication")

find_package(fmt CONFIG REQUIRED)
if(fmt_FOUND)
        message("fmt found!")
else ()
        message("fmt not found!")
endif ()

add_library(${CMAKE_PROJECT_NAME} SHARED
        native-lib.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        log
        fmt::fmt
        )
