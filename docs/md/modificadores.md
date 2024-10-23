# Modificadores

## 1. change_timezone()
Altera a timezone da instância atual.

#### Assinatura:

```c++
void change_timezone();
```

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 14, 30, 45, -3);
string isoString = dt.to_ISO_string();  // "2024-10-23T17:30:45.000Z"
  
dt.change_timezone(0);
isoString = dt.to_string();  // "2024-10-23 17:30:45"

```

## 2. to_UTC()
Retorna um novo objeto DateTime no formato UTC

#### Assinatura:

```c++
DateTime to_UTC() const;
```

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 14, 30, 45, -3);
string dateString = dt.to_UTC();  // "23/10/2024 14:30:45" -> "23/10/2024 17:30:45"
```


<a href="index.md">Voltar ao início</a>