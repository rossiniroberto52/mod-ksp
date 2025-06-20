cmake_minimum_required(VERSION 3.10)

message("Status: Configuring projeto...")
project(KSP_MOD_CALC_OF_ROCKET_LAUCH VERSION 1.0.0)
add_library(_gravity_calc gravity_calc.h main.cpp)
add_executable(mod_teste main.cpp)
message("Status: Configuração do projeto concluída.")