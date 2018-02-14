macro(CONVERT_TO_GBA NAME)
	add_custom_command(TARGET ${NAME}
	                   POST_BUILD
	                   COMMAND ${CMAKE_OBJCOPY}
	                   ARGS -O binary ${NAME} ${NAME}.gba
	                   COMMAND ${GBAFIX} ${PROJECT_BINARY_DIR}/${NAME}.gba
	                   COMMENT "${NAME} -> ${NAME}.gba"
	)
	set_directory_properties(PROPERTIES
	                         ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_BINARY_DIR}/${NAME}.gba
	)
endmacro(CONVERT_TO_GBA)

