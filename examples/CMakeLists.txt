add_executable(minimal_window minimal_window.c)
target_link_libraries(minimal_window libcocoa "-framework Cocoa" "-lobjc")

add_executable(simple_window simple_window.c)
target_link_libraries(simple_window libcocoa "-framework Cocoa" "-lobjc")

add_executable(button_example button_example.c)
target_link_libraries(button_example libcocoa "-framework Cocoa" "-lobjc")