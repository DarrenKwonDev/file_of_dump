# https://cmake.org/cmake/help/latest/command/function.html
# custom cmake functions
function(add_git_submodule dir)
    find_package(Git REQUIRED)

    if (NOT EXISTS ${CMAKE_SOURCE_DIR}/${dir}/CMakeLists.txt)
        execute_process(COMMAND ${GIT_EXECUTABLE}
            submodule update --init --recursive -- ${CMAKE_SOURCE_DIR}/${dir}
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            )
    endif()

    # add subdirectory will fail if CMakeLists.txt does not exist
    if (EXISTS ${CMAKE_SOURCE_DIR}/${dir}/CMakeLists.txt)
        message("Adding: ${CMAKE_SOURCE_DIR}/${dir}")
        add_subdirectory(${dir})
    else()
        message(FATAL_ERROR "Failed to find ${CMAKE_SOURCE_DIR}/${dir} submodule. Please run 'git submodule update --init --recursive' to fetch submodules.")
    endif()

endfunction(add_git_submodule)