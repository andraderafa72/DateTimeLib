# Operador de Inserção << da Classe DateTime
A classe DateTime sobrecarrega o operador de inserção << para facilitar a exibição de instâncias da classe em streams de saída, como std::cout. Este operador permite que o objeto DateTime seja convertido diretamente em uma representação string formatada, tornando a exibição de datas e horas mais intuitiva e conveniente.

#### Assinatura:

```c++
friend std::ostream& operator<<(std::ostream& os, const DateTime& date);
```

#### Descrição:
O operador << formata a saída do objeto DateTime como uma string no formato dd/MM/yyyy hh:mm:ss, onde:

- `dd`: Dia do mês, com dois dígitos (exemplo: 01, 02, ..., 31).
- `MM`: Mês do ano, com dois dígitos (exemplo: 01, 02, ..., 12).
- `yyyy`: Ano, com quatro dígitos.
- `hh`: Hora do dia, com dois dígitos (exemplo: 00, 01, ..., 23).
- `mm`: Minutos, com dois dígitos (exemplo: 00, 01, ..., 59).
- `ss`: Segundos, com dois dígitos (exemplo: 00, 01, ..., 59).

#### Exemplo de Uso:

```c++
#include <iostream>

int main() {
    DateTime date(23, 10, 2024, 14, 30, 45);
    
    // Saída: "Data e Hora: 23/10/2024 14:30:45"
    std::cout << "Data e Hora: " << date << std::endl;
    
    return 0;
}
```

#### Implementação:

```c++
friend std::ostream& operator<<(std::ostream& os, const DateTime& date) {
    os << date.to_string();  // Usa o método ToString para obter a representação da data
    return os;
}
```


<a href="index.md">Voltar ao início</a>