cmake_minimum_required(VERSION 3.10)

project(saga)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Download Android NDK if not present
set(NDK_DIR "${CMAKE_SOURCE_DIR}/ndk")
set(NDK_EXTRACT_DIR "${NDK_DIR}/android-ndk-r8e")
set(NDK_ARCHIVE "${NDK_DIR}/android-ndk-r8e-linux-x86_64.tar.bz2")
set(NDK_URL "https://dl.google.com/android/ndk/android-ndk-r8e-linux-x86_64.tar.bz2")

if(NOT EXISTS "${NDK_EXTRACT_DIR}")
    file(MAKE_DIRECTORY "${NDK_DIR}")

    if(NOT EXISTS "${NDK_ARCHIVE}")
        message(STATUS "Downloading Android NDK r8e...")
        file(DOWNLOAD "${NDK_URL}" "${NDK_ARCHIVE}"
            SHOW_PROGRESS
            STATUS download_status)
        list(GET download_status 0 download_code)
        if(NOT download_code EQUAL 0)
            message(FATAL_ERROR "Failed to download NDK: ${download_status}")
        endif()
    endif()

    message(STATUS "Extracting Android NDK r8e...")
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E tar xjf "${NDK_ARCHIVE}"
        WORKING_DIRECTORY "${NDK_DIR}"
        RESULT_VARIABLE extract_result)
    if(NOT extract_result EQUAL 0)
        message(FATAL_ERROR "Failed to extract NDK")
    endif()

    file(REMOVE "${NDK_ARCHIVE}")
    message(STATUS "Android NDK r8e ready")
endif()

set(CMAKE_C_COMPILER "${CMAKE_SOURCE_DIR}/ndk/android-ndk-r8e/toolchains/x86-4.7/prebuilt/linux-x86_64/bin/i686-linux-android-gcc")
set(CMAKE_CXX_COMPILER "${CMAKE_SOURCE_DIR}/ndk/android-ndk-r8e/toolchains/x86-4.7/prebuilt/linux-x86_64/bin/i686-linux-android-g++")
set(CMAKE_SYSROOT "${CMAKE_SOURCE_DIR}/ndk/android-ndk-r8e/platforms/android-9/arch-x86")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# disable --dependency-file argument on ld which is too old to support it
set(CMAKE_LINK_DEPENDS_NO_SHARED ON)

set(SAGA_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/batman.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nu2api.saga/numath/nuvec.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nu2api.saga/numath/nufloat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nu2api.saga/nufile/nufile.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nu2api.saga/nufile/nufile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nu2api.saga/nuthread/nuthread.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nu2api.saga/numath/numtx.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nu2api.saga/numath/nutrig_gen.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nu2api.saga/nucore/nustring_c.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nu2api.saga/nucore/nutime.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nu2api.saga/numath/nutrig.cpp
)

set(SAGA_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_executable(saga ${SAGA_SOURCE_FILES})

set_target_properties(saga PROPERTIES ENABLE_EXPORTS TRUE)

target_include_directories(saga PUBLIC ${SAGA_INCLUDE_DIRS})
