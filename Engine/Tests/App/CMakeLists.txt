link_libraries(AmuseApp)
link_libraries(AmuseCore)

add_executable(Windowing
	"Windowing.cpp"
)
add_executable(PlatformDetection
	"PlatformDetection.cpp"
)

target_link_libraries(Windowing
	PRIVATE
		AmuseApp
		AmuseCore
)

target_link_libraries(PlatformDetection
		PRIVATE
		AmuseApp
		AmuseCore
)