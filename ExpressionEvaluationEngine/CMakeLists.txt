cmake_minimum_required(VERSION 3.10)

# --------------------------------------------------
# Project definition
# --------------------------------------------------
project(ExpressionEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------
# 1. Find Java & JNI
# --------------------------------------------------
find_package(Java REQUIRED)
find_package(JNI REQUIRED)

include(UseJava)

# --------------------------------------------------
# 2. C Math Kernel (STATIC, PIC enabled)
# --------------------------------------------------
add_library(math_kernel STATIC
    c/math_kernel.c
)

target_include_directories(math_kernel PUBLIC c)

set_target_properties(math_kernel PROPERTIES POSITION_INDEPENDENT_CODE ON)

# --------------------------------------------------
# 3. C++ Expression Engine (STATIC, PIC enabled)
# --------------------------------------------------
add_library(expression_engine STATIC
    cpp/expression_engine.cpp
)

target_include_directories(expression_engine PUBLIC cpp)
target_link_libraries(expression_engine PRIVATE math_kernel)
set_target_properties(expression_engine PROPERTIES POSITION_INDEPENDENT_CODE ON)

# --------------------------------------------------
# 4. Generate JNI Headers BEFORE compiling JNI library
# --------------------------------------------------
set(JNI_HEADERS_DIR ${CMAKE_CURRENT_BINARY_DIR}/jni_headers)
file(MAKE_DIRECTORY ${JNI_HEADERS_DIR})

set(JAVA_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/java/ExpressionApp.java)

# Custom command to generate ExpressionApp.h
add_custom_command(
    OUTPUT ${JNI_HEADERS_DIR}/ExpressionApp.h
    COMMAND ${Java_JAVAC_EXECUTABLE} -h ${JNI_HEADERS_DIR} ${JAVA_SOURCE_FILES}
    DEPENDS ${JAVA_SOURCE_FILES}
    COMMENT "Generating JNI headers for ExpressionApp"
)

# Custom target to make header generation a build step
add_custom_target(generate_jni_headers ALL
    DEPENDS ${JNI_HEADERS_DIR}/ExpressionApp.h
)

# --------------------------------------------------
# 5. JNI Shared Library (C++ <-> Java bridge)
# --------------------------------------------------
add_library(exprengine SHARED
    jni/ExpressionJNI.cpp
)

target_include_directories(exprengine
    PRIVATE
        ${JNI_INCLUDE_DIRS}
        cpp
        c
        ${JNI_HEADERS_DIR}  # Include generated header
)

target_link_libraries(exprengine
    PRIVATE
        expression_engine
        math_kernel
        ${JNI_LIBRARIES}
)

# Ensure JNI library is compiled AFTER headers
add_dependencies(exprengine generate_jni_headers)

# Set shared library name
set_target_properties(exprengine PROPERTIES OUTPUT_NAME "exprengine")

# --------------------------------------------------
# 6. Java Application Jar
# --------------------------------------------------
add_jar(ExpressionApp
    SOURCES ${JAVA_SOURCE_FILES}
    ENTRY_POINT ExpressionApp
)

# --------------------------------------------------
# 7. Convenience target to run the app
# --------------------------------------------------
add_custom_target(run
    COMMAND ${Java_JAVA_EXECUTABLE}
            -Djava.library.path=$<TARGET_FILE_DIR:exprengine>
            -jar ExpressionApp.jar
    DEPENDS exprengine ExpressionApp
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
