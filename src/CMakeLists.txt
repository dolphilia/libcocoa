set(LIBCOCOA_SOURCES
    common/objc_utils.c
    appkit/application.c
    appkit/window.c
    appkit/view.c
    appkit/button.c
    appkit/alert.c
    appkit/menu.c
)

add_library(libcocoa STATIC ${LIBCOCOA_SOURCES})

target_include_directories(libcocoa
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(libcocoa
    "-framework Cocoa"
    "-lobjc"
)

set_target_properties(libcocoa PROPERTIES
    OUTPUT_NAME "cocoa"
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)