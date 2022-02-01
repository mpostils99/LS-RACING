cmake_minimum_required(VERSION 3.15)
project(Proyecto C)

set(CMAKE_C_STANDARD 11)
set(ALLEGRO_DIR "C:\\MinGW")
include_directories(${ALLEGRO_DIR}/include)
link_directories(${ALLEGRO_DIR}/lib)

add_executable(Proyecto main.c LS_Allegro.c LS_Allegro.h carregarFitxers.c carregarFitxers.h configuracioCotxe.c configuracioCotxe.h sortedlist.c sortedlist.h menu.c menu.h grafics.h grafics.c bidirectionalist.c bidirectionalist.h)

target_link_libraries(Proyecto -lmingw32 -lallegro-5.0.10-monolith-md-debug)