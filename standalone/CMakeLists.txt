cmake_minimum_required(VERSION 3.10)
project(StandaloneWindow)

set(SOURCES standalone_window.c)

add_executable(StandaloneWindow ${SOURCES})

# C言語の標準を設定
set_target_properties(StandaloneWindow PROPERTIES
        C_STANDARD 99
        C_STANDARD_REQUIRED YES
)

# 必要なフレームワークとライブラリをリンク
target_link_libraries(StandaloneWindow
        "-framework Cocoa"
        "-lobjc"
)