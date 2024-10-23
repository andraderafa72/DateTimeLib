# Construtores

## 1. DateTime()
Construtor padrão. Inicializa um objeto DateTimevazio.

#### Assinatura:

```c++
DateTime();
```

#### Exemplo:

```c++
DateTime dt;
```

## 2. DateTime(int year, int month, int day)
Constrói um objeto DateTime a partir de uma data específica (dia, mês e ano).

#### Assinatura:

```c++
DateTime(int year, int month, int day);
```

#### Parâmetros:

- `year`: O ano. Deve ser maior que 0.
- `month`: O mês do ano. Deve ser maior que 0 e menor ou igual a 12.
- `day`: O dia do mês. Deve ser maior que 0 e válido para o mês especificado.

#### Exemplo:

```c++
DateTime dt(2024, 10, 23);  // 23 de outubro de 2024
```

## 3. DateTime(int year, int month, int day, int hours)
Constrói um objeto DateTime a partir de uma data e hora específicas.

#### Assinatura:

```c++
DateTime(int year, int month, int day, int hours);
```

#### Parâmetros:

- `year`: O ano. Deve ser maior que 0.
- `month`: O mês do ano. Deve ser maior que 0 e menor ou igual a 12.
- `day`: O dia do mês. Deve ser maior que 0.
- `hours`: As horas do dia. Deve ser maior ou igual a 0 e menor que 24.

#### Exemplo:

```c++
DateTime dt(2024, 10, 23, 14);  // 23 de outubro de 2024, 14:00
```

## 4. DateTime(int year, int month, int day, int hours, int minutes)
Constrói um objeto DateTime a partir de uma data e hora específicas, incluindo minutos.

#### Assinatura:

```c++
DateTime(int year, int month, int day, int hours, int minutes);
```

#### Parâmetros:

- `year`: O ano. Deve ser maior que 0.
- `month`: O mês do ano. Deve ser maior que 0 e menor ou igual a 12.
- `day`: O dia do mês. Deve ser maior que 0.
- `hours`: As horas do dia. Deve ser maior ou igual a 0 e menor que 24.
- `minutes`: Os minutos da hora. Deve ser maior ou igual a 0 e menor que 60.

#### Exemplo:

```c++
DateTime dt(2024, 10, 23, 14, 30);  // 23 de outubro de 2024, 14:30
```

## 5. DateTime(int year, int month, int day, int hours, int minutes, int seconds)
Constrói um objeto DateTime completo, especificando dia, mês, ano, hora, minutos e segundos.

#### Assinatura:

```c++
DateTime(int year, int month, int day, int hours, int minutes, int seconds);
```

#### Parâmetros:

- `year`: O ano. Deve ser maior que 0.
- `month`: O mês do ano. Deve ser maior que 0 e menor ou igual a 12.
- `day`: O dia do mês. Deve ser maior que 0 e menor ou igual a 31.
- `hours`: As horas do dia. Deve ser maior ou igual a 0 e menor que 24.
- `minutes`: Os minutos da hora. Deve ser maior ou igual a 0 e menor que 60.
- `seconds`: Os segundos do minuto. Deve ser maior ou igual a 0 e menor que 60.

#### Exemplo:

```c++
DateTime dt(2024, 10, 23, 14, 30, 45);
```

## 6. DateTime(int year, int month, int day, int hours, int minutes, int seconds, int timezone)
Constrói um objeto DateTime completo, especificando dia, mês, ano, hora, minutos, segundos e um timezone.

#### Assinatura:

```c++
DateTime(int year, int month, int day, int hours, int minutes, int seconds, int timezone);
```

#### Parâmetros:

- `year`: O ano. Deve ser maior que 0.
- `month`: O mês do ano. Deve ser maior que 0 e menor ou igual a 12.
- `day`: O dia do mês. Deve ser maior que 0.
- `hours`: As horas do dia. Deve ser maior ou igual a 0 e menor que 24.
- `minutes`: Os minutos da hora. Deve ser maior ou igual a 0 e menor que 60.
- `seconds`: Os segundos do minuto. Deve ser maior ou igual a 0 e menor que 60.
- `timezone`: Um valor inteiro representando o timezone. Deve ser maior ou igual a -12 e menor ou igual a 12.

#### Exemplo:

```c++
DateTime dt(2024, 10, 23, 14, 30, 45, -3);```
