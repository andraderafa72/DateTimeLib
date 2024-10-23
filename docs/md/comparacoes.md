# Comparações
A classe DateTime oferece métodos poderosos para comparar diferentes instâncias de data e hora. Essas comparações permitem determinar se uma data/hora é anterior, posterior ou igual a outra. 

A classe DateTime fornece três métodos principais para comparar duas datas:
- is_before
- is_equal
- is_after

## 1. `is_before()`
Este método verifica se a instância atual de DateTime é anterior a outra instância fornecida.

Assinatura:

```c++
bool is_before(DateTime dt);
```

#### Parâmetro:

dt: Um objeto DateTime com o qual a data atual será comparada.

#### Retorno:

- `true`: Se a data/hora da instância atual for anterior à data/hora passada como argumento.
- `false`: Caso contrário.

#### Exemplo:

```c++
DateTime dt1(2024, 10, 23, 12, 30);
DateTime dt2(2024, 10, 24, 15, 45);

if (dt1.is_before(dt2)) {
    std::cout << "dt1 é anterior a dt2" << std::endl;
}
```

----

## 2. is_after()
Este método verifica se a instância atual de DateTime é posterior a outra instância fornecida.

Assinatura:

Copy
bool is_after(DateTime dt);
Parâmetro:

dt: Um objeto DateTime com o qual a data atual será comparada.

#### Retorno:

- `true`: Se a data/hora da instância atual for posterior à data/hora passada como argumento.
- `false`: Caso contrário.

#### Exemplo:

```c++
DateTime dt1(2024, 10, 23, 12, 30);
DateTime dt2(2024, 10, 22, 15, 45);

if (dt1.is_after(dt2)) {
    std::cout << "dt1 é posterior a dt2" << std::endl;
}
```

## 3. `is_equal()`
Este método verifica se a instância atual de DateTime é exatamente igual a outra instância fornecida. Para que duas datas sejam consideradas iguais, todas as unidades de tempo (ano, mês, dia, hora, minuto, segundo) devem ser idênticas.

Assinatura:

```c++
bool is_equal(DateTime dt);
```

#### Parâmetro:

- `dt`: Um objeto DateTime com o qual a data atual será comparada.

#### Retorno:

- `true`: Se a data/hora da instância atual for exatamente igual à data/hora passada como argumento.
- `false`: Caso contrário.

Exemplo:

```c++
DateTime dt1(2024, 10, 23, 12, 30, 45);
DateTime dt2(2024, 10, 23, 12, 30, 45);

if (dt1.is_equal(dt2)) {
    std::cout << "As duas datas são iguais" << std::endl;
}
```

----

## Uso Geral
Esses métodos são particularmente úteis em várias situações, como:

Verificar se um evento está agendado antes ou depois de uma data específica.

Comparar timestamps para ordenação ou validação de dados.

Garantir que duas instâncias de DateTime representam exatamente o mesmo momento no tempo.

### Exemplo Combinado:
Um exemplo de uso combinando as três comparações:

```c++
DateTime dt1(2024, 10, 23, 12, 30);
DateTime dt2(2024, 10, 24, 12, 30);

if (dt1.is_before(dt2)) {
    std::cout << "dt1 é anterior a dt2" << std::endl;
} else if (dt1.is_after(dt2)) {
    std::cout << "dt1 é posterior a dt2" << std::endl;
} else if (dt1.is_equal(dt2)) {
    std::cout << "As duas datas são iguais" << std::endl;
}
```