link_libraries(AmuseCore)

add_executable(Operation
	"Operation.cpp"
)
add_executable(Print
	"Print.cpp"
)

target_link_libraries(Operation
	PRIVATE
		AmuseCore
)