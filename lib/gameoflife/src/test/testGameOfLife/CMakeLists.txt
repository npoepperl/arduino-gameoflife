SET(MODULE_NAME gtestRunner)

file(GLOB MODULE_SOURCECES
    "*.h"
    "*.cpp")

ADD_EXECUTABLE(${MODULE_NAME} ${MODULE_SOURCECES})
    
TARGET_LINK_LIBRARIES(${MODULE_NAME}
    GameOfLife
    libgtest
    libgmock)