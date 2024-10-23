# A classe DateTime
A classe DateTime foi projetada para fornecer funcionalidades robustas de manipulação e comparação de datas e horários. Ela permite a criação de objetos que representam um momento no tempo, oferecendo métodos para realizar operações como soma e subtração de diferentes unidades de tempo (segundos, minutos, horas, dias, meses e anos), além de comparações entre diferentes datas.

```c++
DateTime date(2024, 10, 23)
date.SumDays(10)
std::cout << "Data após soma de 10 dias: " << date << std::endl;
```

## Funcionalidades principais
- Construtores flexíveis: Permite a criação de um objeto DateTime com diferentes níveis de precisão (apenas data ou data e hora completas).
- Operações de tempo: Métodos para adicionar ou subtrair unidades de tempo (segundos, minutos, horas, dias, meses e anos).
- Conversão de formato: Capacidade de converter o objeto para uma string amigável (ToString()) ou para o formato ISO padrão (ToISOString()).
- Comparações: Métodos para verificar se uma data é anterior, posterior ou igual a outra (isBefore(), isAfter(), isEqual()).
- Suporte a ano bissexto: A classe lida corretamente com anos bissextos ao calcular a diferença de datas ou realizar operações de soma e subtração.
- Conversão para UTC: A classe suporta a conversão de horários locais para o horário universal coordenado (UTC) com o método toUTC().
- Operador de inserção (<<): Sobrecarga do operador << para facilitar a exibição do objeto DateTime diretamente no fluxo de saída (como std::cout).

## Exemplo de uso
A classe DateTime oferece uma solução prática e eficaz para trabalhar com datas e horários em C++, permitindo operações simples e avançadas de manipulação de tempo com suporte completo a anos bissexto

```c++
DateTime dt1(15, 10, 2024, 12, 30, 45, 0);
DateTime dt2(16, 10, 2024, 13, 45);

// Comparação de datas
if (dt1.is_before(dt2)) {
    std::cout << dt1 << " é anterior a " << dt2 << std::endl;
}

// Soma de tempo
dt1.sum_days(10);
std::cout << "Nova data: " << dt1.to_string() << std::endl;
```

## Documentação

<a href="constructors.md">Construtores</a>
<a href="comparacoes.md">Comparações</a>
<a href="acessos.md">Acessos</a>
<a href="soma.md">Somas</a>
<a href="sub.md">Subtrações</a>
<a href="conversoes.md">Conversões</a>
<a href="operadores.md">Operadores</a>