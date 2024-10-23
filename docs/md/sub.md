# Operações de subtração:
- `void subtract_seconds(int s)`: Subtrai segundos da data.
- `void subtract_minutes(int min)`: Subtrai minutos da data.
- `void subtract_hours(int h)`: Subtrai horas da data.
- `void subtract_days(int d)`: Subtrai dias da data.
- `void subtract_months(int m)`: Subtrai meses da data.
- `void subtract_years(int y)`: Subtrai anos da data.

**É possível acessar e modificar todos os valores de data manualmente, porém pode comprometer a integridade da data/hora.**

## Subtrair segundos

#### Assinatura:

```c++
void DateTime::subtract_seconds(int seconds); // seconds > 0
```

#### Parâmetros:

- `seconds`: O número de segundos a ser subtraído. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.subtract_seconds(25);
```

## Subtrair minutos

#### Assinatura:

```c++
void DateTime::subtract_minutes(int minutes); // minutes > 0
```

#### Parâmetros:

- `minutes`: O número de minutos a ser subtraído. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.subtract_minutes(5);
```

## Subtrair horas

#### Assinatura:

```c++
void DateTime::subtract_hours(int hours); // hours > 0
```

#### Parâmetros:

- `hours`: O número de horas a ser subtraído. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.subtract_hours(5);
```

## Subtrair dias

#### Assinatura:

```c++
void DateTime::subtract_days(int days); // days > 0
```

#### Parâmetros:

- `days`: O número de dias a ser subtraído. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.subtract_days(5);
```

## Subtrair meses

#### Assinatura:

```c++
void DateTime::subtract_months(int months); // months > 0
```

#### Parâmetros:

- `months`: O número de meses a ser subtraído. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.subtract_months(5);

## Subtrair anos

#### Assinatura:

```c++
void DateTime::subtract_years(int years); // years > 0
```
#### Parâmetros:

- `years`: O número de anos a ser subtraído. Deve ser maior que 0.

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
date.subtract_years(5);
```


<a href="index.md">Voltar ao início</a>