# Projeto DateTime

## Descrição
O projeto `DateTime` é uma implementação de uma classe em C++ que fornece funcionalidades para manipulação de datas e horas. A classe permite a criação, comparação, formatação e operação com datas, facilitando a gestão de informações temporais em aplicações.

## Funcionalidades
- Criação de objetos de data e hora.
- Comparações entre diferentes instâncias de `DateTime`.
- Conversão de instâncias para strings em formatos legíveis e padronizados.
- Manipulação de datas através da adição e subtração de unidades de tempo (segundos, minutos, horas, dias, meses e anos).

## Documentação
A documentação completa do projeto está disponível nas seguintes fontes:

- **Doxygen**: [Documentação Doxygen](https://andraderafa72.github.io/DateTimeLib/html/)  
  Esta documentação fornece detalhes sobre a implementação e a utilização da classe, incluindo informações sobre cada método e seus parâmetros.

- **GitBook**: [Documentação GitBook](https://rafaels-organization-19.gitbook.io/datetime-lib)  
  Aqui, você encontrará um guia abrangente sobre a classe `DateTime`, incluindo exemplos de uso e explicações dos métodos disponíveis.

- **Mardown**: [Pasta Docs](https://github.com/andraderafa72/DateTimeLib/tree/main/docs/md/index.md)  
  Aqui, você encontrará um guia abrangente sobre a classe `DateTime`, incluindo exemplos de uso e explicações dos métodos disponíveis.

## Requisitos
- C++11 ou superior

## Uso


Inclua os arquivos `DateTime.cpp` e `DateTime.h` da pasta [source](https://github.com/andraderafa72/DateTimeLib/tree/main/source) em seu projeto e referencie o `DateTime.cpp` em seu processo de compilação.

### Exemplo com `cmake`:

#### Arquivo `CMakeLists.txt`:

```cmake
add_executable(DateTimeLib
    "DateTime.cpp"
    # Arquivos do seu projeto
    "main.cpp"
)
``` 

#### Utilização:

```c++
#include "path/to/DateTime.h"

/// ...

DateTime create_date() {
  return DateTime(2024, 10, 23); // 23/10/2024 00:00:00
}
```

