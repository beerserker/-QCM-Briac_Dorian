cmake_minimum_required(VERSION 3.0.0)
project(Projet_QCM VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(model)

add_executable(Projet_QCM main.cpp)

target_link_libraries(Projet_QCM model)

target_include_directories(Projet_QCM PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/model")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
