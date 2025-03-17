list(APPEND SOURCES ${CMAKE_SOURCE_DIR}/code/src/image/BlimDecoder.cpp)
list(APPEND SOURCES ${CMAKE_SOURCE_DIR}/code/src/image/BlimEncoder.cpp)
list(APPEND SOURCES ${CMAKE_SOURCE_DIR}/code/src/image/Image.cpp)
list(APPEND SOURCES ${CMAKE_SOURCE_DIR}/code/src/image/ImageIO.cpp)
set(SOURCES "${SOURCES}" PARENT_SCOPE)

#list(APPEND INCLUDES ${CMAKE_SOURCE_DIR}/code/libs/oiio)
#set(INCLUDES "${INCLUDES}" PARENT_SCOPE)

#list(APPEND LINKS ${CMAKE_SOURCE_DIR}/code/libs/oiio/libOpenImageIO.so.3.0)
#list(APPEND LINKS ${CMAKE_SOURCE_DIR}/code/libs/oiio/libOpenImageIO_Util.so.3.0)
#list(APPEND LINKS ${CMAKE_SOURCE_DIR}/code/libs/bitIO/libbitIO.so)
#set(LINKS "${LINKS}" PARENT_SCOPE)
