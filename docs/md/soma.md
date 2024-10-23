# Operações de soma

- `void sum_seconds(int s)`: Adiciona segundos à data.
- `void sum_minutes(int min)`: Adiciona minutos à data.
- `void sum_hours(int h)`: Adiciona horas à data.
- `void sum_days(int d)`: Adiciona dias à data.
- `void sum_months(int m)`: Adiciona meses à data.
- `void sum_years(int y)`: Adiciona anos à data.

**É possível acessar e modificar todos os valores de data manualmente, porém pode comprometer a integridade da data/hora.**

## Somar segundos
#### Assinatura:

```c++
void DateTime::sum_seconds(int seconds); // seconds > 0
```

#### Parâmetros:

- `seconds`: O número de segundos a ser adicionado. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.sum_seconds(25);
```


## Somar minutos
#### Assinatura:

```c++
void DateTime::sum_minutes(int minutes); // minutes > 0
```

#### Parâmetros:

- `minutes`: O número de minutos a ser adicionado. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.sum_minutes(5);
```

## Somar horas
#### Assinatura:

```c++
void DateTime::sum_hours(int hours); // hours > 0
```

#### Parâmetros:

- `hours`: O número de horas a ser adicionado. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.sum_hours(5);
```

## Somar dias

#### Assinatura:

```c++
void DateTime::sum_days(int days); // days > 0
```

#### Parâmetros:

- `days`: O número de dias a ser adicionado. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.sum_days(5);
```

## Somar meses

#### Assinatura:

```c++
void DateTime::sum_months(int months); // months > 0
```

#### Parâmetros:

- `months`: O número de meses a ser adicionado. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.sum_months(5);
```

## Somar anos

#### Assinatura:

```c++
void DateTime::sum_years(int years); // years > 0
```

#### Parâmetros:

- `years`: O número de anos a ser adicionado. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.sum_years(5);
```


<a href="index.md">Voltar ao início</a>