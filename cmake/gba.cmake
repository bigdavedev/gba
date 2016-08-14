if(NOT GBAFIX)
	message(STATUS "Looking for gbafix...")
	find_program(GBAFIX gbafix ${DEVKITPRO_ROOT}/bin)
	if(GBAFIX)
		message(STATUS "Looking for gbafix: ${GBAFIX} - found")
	else(GBAFIX)
		message(FATAL_ERROR "Looking for gbafix: ${GBAFIX} - not found")
	endif(GBAFIX)
endif(NOT GBAFIX)

macro(CONVERT_TO_GBA NAME)
	add_custom_command(TARGET ${NAME}
	                   POST_BUILD
	                   COMMAND ${CMAKE_OBJCOPY}
	                   ARGS -O binary ${NAME} ${NAME}.gba
					   COMMAND ${GBAFIX} ${CMAKE_BINARY_DIR}/${NAME}.gba
	                   COMMENT "${NAME} -> ${NAME}.gba")
	set_directory_properties(PROPERTIES
		ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_BINARY_DIR}/${NAME}.gba)
endmacro(CONVERT_TO_GBA)

