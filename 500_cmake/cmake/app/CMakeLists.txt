set (EXE_SOURCES main.cpp)

add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})

# executable에 library 링크
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})
