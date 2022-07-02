# agbr/cmake/FileBaseList.cmake
macro(FileBaseList fullPath pattern baseList)
    file(GLOB fullNameList ${fullPath}${pattern})
    foreach (fullName ${fullNameList})
        # delete directories prefix
        STRING(REGEX REPLACE "${fullPath}" "" base ${fullName})
        # delete .ext
        STRING(REGEX REPLACE "\\..*" "" base ${base})
        list(APPEND ${baseList} "${base}")
    endforeach (fullName)
endmacro(FileBaseList)