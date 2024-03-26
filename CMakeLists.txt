# CMakeList.txt : projet CMake pour 2ALGO, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

# Activez Rechargement à chaud pour les compilateurs MSVC si cela est pris en charge.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("2ALGO")

# Ajoutez une source à l'exécutable de ce projet.
include_directories("include")

add_executable (2ALGO "2ALGO.cpp" "linkedlist.cpp" "node.cpp" "stack.cpp" "queue.cpp"  )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2ALGO PROPERTY CXX_STANDARD 20)
endif()