cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)


set(mega.build.mcu atmega2560)
set(mega.upload.protocol wiring)
set(mega.upload.speed 115200)


set(COMMON_CPPS
        Util.cpp
        FixBug.c
        ArrayAutoSize.cpp
        Sensor.cpp
        Led.cpp
        Chain.cpp
        ChainElement.cpp
        CommunicationService.cpp
        Lcd.cpp
        Reveille.cpp
        )
set(COMMON_HS
        ArrayAutoSize.h
        Util.h
        Sensor.h
        Led.h
        Chain.h
        ChainElement.h
        CommunicationService.h
        Lcd.h
        Reveille.h
        )
set(COMMON_LIB
        )
set(PROJECT_BOARD mega)
set(PORT COM8)

set(INC_PATH     "./include")
set(LIB_DIR_PATH "./lib")
# Lib include
set(LIB_SRC_FILES)
set(LIB_INC_PATH)
file(GLOB LIBRARIES "${LIB_DIR_PATH}/*")
foreach(libdir ${LIBRARIES})
    set(subdir ${libdir}/src)
    file(GLOB_RECURSE lib_files "${subdir}/*.cpp"
            "${subdir}/*.cc"
            "${subdir}/*.c"
            "${subdir}/*.cxx"
            "${subdir}/*.S"
            "${subdir}/*.s"
            "${subdir}/*.sx"
            "${subdir}/*.asm")
    if(IS_DIRECTORY ${subdir})
        list(APPEND LIB_INC_PATH  "${subdir}")
    endif()
    list(APPEND LIB_SRC_FILES "${lib_files}")
endforeach()

include_directories(${INC_PATH} ${LIB_INC_PATH})

## ==================== ALL TEST : BEGIN ====================
#FOREACH(TESTNAME "ComB1" "ComB2" "MatriceLed" "Moteur" "UltraSon" "Debug")
#    # -------------------- MarvinTest : BEGIN --------------------
#    set(PROJECT_NAME_TEST MarvinTest${TESTNAME})
#    project(${PROJECT_NAME_TEST})
#
#    print_board_list()
#    #### Uncomment below additional settings as needed.
#    set(${PROJECT_NAME_TEST}_SRCS test${TESTNAME}.cpp ${COMMON_CPPS})
#    set(${PROJECT_NAME_TEST}_HDRS ${COMMON_HS})
#    set(${PROJECT_NAME_TEST}_BOARD ${PROJECT_BOARD})
#    set(${PROJECT_NAME_TEST}_PORT ${PORT})
#    set(${PROJECT_NAME_TEST}_ARDLIBS ${COMMON_LIB})
#
#    generate_arduino_firmware(${PROJECT_NAME_TEST})
#    # -------------------- MarvinTest : END --------------------
#ENDFOREACH()
## ==================== ALL TEST : END ====================

# ==================== Reveil : BEGIN ====================
set(PROJECT_NAME REVEIL)
project(${PROJECT_NAME})

#### Uncomment below additional settings as needed.
set(${CMAKE_PROJECT_NAME}_SRCS main.cpp ${COMMON_CPPS} ${LIB_SRC_FILES})
message("SRC FILES : ${CMAKE_PROJECT_NAME}_SRCS main.cpp ${COMMON_CPPS};${LIB_SRC_FILES}")
set(${CMAKE_PROJECT_NAME}_HDRS ${COMMON_HS})
set(${CMAKE_PROJECT_NAME}_BOARD ${PROJECT_BOARD})
set(${CMAKE_PROJECT_NAME}_PORT ${PORT})
set(${CMAKE_PROJECT_NAME}_ARDLIBS ${COMMON_LIB} )

generate_arduino_firmware(${CMAKE_PROJECT_NAME})
# ==================== Reveil : END ====================


