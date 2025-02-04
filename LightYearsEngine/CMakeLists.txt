add_library(${LIGHT_YEARS_ENGINE_TARGET_NAME} STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
)

target_include_directories(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW FALSE
    )
FetchContent_MakeAvailable(SFML)

target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC SFML::Graphics)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC SFML::Window)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC SFML::System)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC SFML::Audio)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:${LIB_NAME}>
	$<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibToTarget(SFML::Graphics ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(SFML::Window ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(SFML::System ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(SFML::Audio ${LIGHT_YEARS_ENGINE_TARGET_NAME})