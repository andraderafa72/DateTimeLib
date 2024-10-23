# Métodos de Conversão para String

Os métodos de conversão para string da classe DateTime permitem representar a data/hora em formatos legíveis, como string padrão e ISO 8601.

## 1. to_string()
Converte a instância de DateTime para uma string no formato dd/MM/yyyy hh:mm:ss.

#### Assinatura:

```c++
string to_string() const;
```

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
string dateString = dt.to_string();  // "23/10/2024 14:30:45"
```

## 2. to_ISO_string()
Converte a instância de DateTime para uma string no formato ISO 8601 (yyyy-MM-ddThh:mm:ss.000Z).

#### Assinatura:

```c++
string to_ISO_string() const;
```

#### Exemplo:

```c++
DateTime date(2024, 10, 23, 8, 15, 30);
string isoString = dt.to_ISO_string();  // "2024-10-23T14:30:45.000Z"
```

<a href="index.md">Voltar ao início</a>