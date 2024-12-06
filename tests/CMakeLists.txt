# Adiciona o executável de teste
add_executable(my_tests
    test_date_time.cpp
)

# Liga o Google Test e a biblioteca a ser testada ao executável
target_link_libraries(my_tests
    gtest
    gtest_main
    date_time_lib
)

# Inclui diretórios de headers
target_include_directories(my_tests PRIVATE ${CMAKE_SOURCE_DIR}/source)

# Adiciona os testes para serem executados com "ctest"
enable_testing()
add_test(NAME MyTests COMMAND my_tests)
