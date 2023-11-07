add_executable(${EXECUTABLE_NAME} main.cpp)

# executable에 library 링크
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})
