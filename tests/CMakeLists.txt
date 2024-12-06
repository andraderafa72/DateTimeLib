# Adiciona o executável de teste
add_executable(date_time_tests
    test_date_time.cpp
)

# Liga o Google Test e a biblioteca a ser testada ao executável
target_link_libraries(date_time_tests
    gtest
    gtest_main
    date_time
)

# Inclui diretórios de headers
target_include_directories(date_time_tests PRIVATE ${CMAKE_SOURCE_DIR}/source)

# Adiciona os testes para serem executados com "ctest"
enable_testing()
add_test(NAME DateTimeTests COMMAND date_time_tests)
