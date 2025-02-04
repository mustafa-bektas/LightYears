add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/include/gameFramework/GameApplication.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp
)

target_include_directories(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW FALSE
    )
FetchContent_MakeAvailable(SFML)

target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC ${LIGHT_YEARS_ENGINE_TARGET_NAME})


function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_directory
	$<TARGET_FILE_DIR:${LIB_NAME}>
	$<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibDirToTarget(${LIGHT_YEARS_ENGINE_TARGET_NAME} ${LIGHT_YEARS_GAME_TARGET_NAME})
