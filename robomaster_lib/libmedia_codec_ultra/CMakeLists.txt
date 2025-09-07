cmake_minimum_required(VERSION 3.5)
project (robomaster_media_codec_ultra)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output)

set(PYBIND11_PYTHON_VERSION 3)
add_subdirectory(pybind11)

pybind11_add_module(libmedia_codec_ultra src/media_codec.cpp)

IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	SET(OPUS_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/src/opus-share/include")
	SET(OPUS_LIBRARIES "${CMAKE_SOURCE_DIR}/src/opus-share/lib/opus.lib")
	SET(FFMPEG_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/src/ffmpeg-win64/include")
	SET(FFMPEG_LIBRARIES_PATH "${CMAKE_SOURCE_DIR}/src/ffmpeg-win64/lib")
	target_link_libraries(libmedia_codec_ultra PRIVATE
			${FFMPEG_LIBRARIES_PATH}/avcodec.lib
			${FFMPEG_LIBRARIES_PATH}/swscale.lib
			${FFMPEG_LIBRARIES_PATH}/avutil.lib
			${OPUS_LIBRARIES})
	target_include_directories(libmedia_codec_ultra PRIVATE
			${FFMPEG_INCLUDE_DIRS}
			${OPUS_INCLUDE_DIRS})

ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")  # macOS
    # Homebrew ffmpeg@4 路径
    set(FFMPEG_DIR "/opt/homebrew/opt/ffmpeg@4")

    set(FFMPEG_INCLUDE_DIRS "${FFMPEG_DIR}/include")
    set(FFMPEG_LIBRARIES "${FFMPEG_DIR}/lib/libavcodec.dylib"
                         "${FFMPEG_DIR}/lib/libavutil.dylib"
                         "${FFMPEG_DIR}/lib/libswscale.dylib"
                         "${FFMPEG_DIR}/lib/libswresample.dylib")

    set(OPUS_INCLUDE_DIRS "/opt/homebrew/include")
    set(OPUS_LIBRARIES "/opt/homebrew/lib/libopus.dylib")

    target_include_directories(libmedia_codec_ultra PRIVATE ${FFMPEG_INCLUDE_DIRS} ${OPUS_INCLUDE_DIRS})
    target_link_libraries(libmedia_codec_ultra PRIVATE ${FFMPEG_LIBRARIES} ${OPUS_LIBRARIES})

ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Linux")   # Jetson / Ubuntu
    # Ubuntu 默认路径
    set(FFMPEG_INCLUDE_DIRS "/usr/include")
    set(FFMPEG_LIBRARIES "/usr/lib/aarch64-linux-gnu/libavcodec.so"
                         "/usr/lib/aarch64-linux-gnu/libavutil.so"
                         "/usr/lib/aarch64-linux-gnu/libswscale.so"
                         "/usr/lib/aarch64-linux-gnu/libswresample.so")

    set(OPUS_INCLUDE_DIRS "/usr/include/opus")
    set(OPUS_LIBRARIES "/usr/lib/aarch64-linux-gnu/libopus.so")

    target_include_directories(libmedia_codec_ultra PRIVATE ${FFMPEG_INCLUDE_DIRS} ${OPUS_INCLUDE_DIRS})
    target_link_libraries(libmedia_codec_ultra PRIVATE ${FFMPEG_LIBRARIES} ${OPUS_LIBRARIES})
ENDIF()

set_target_properties(libmedia_codec_ultra PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../
)