/**
 * @file DateTime.h
 * @brief Classe DateTime para manipulação de datas e horas.
 */

#include <iostream>
#include <string>

#ifndef DATETIME
#define DATETIME

using namespace std;

#include <iostream>
#include <string>

using namespace std;

/**
 * @class DateTime
 * @brief Classe para representar e manipular datas e horários.
 */
class DateTime {
private:
    int days_per_month[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    /**
     * @brief Compara a data atual com outra data fornecida.
     * @param dt Outro objeto DateTime para comparação.
     * @return Resultado da comparação como string.
     */
    string CompareThisDate(DateTime dt);

    /**
     * @brief Valida os componentes da data e hora.
     * @param d Dia.
     * @param m Mês.
     * @param y Ano.
     * @param h Horas.
     * @param min Minutos.
     * @param s Segundos.
     */
    void ValidateTime(int d, int m, int y, int h, int min, int s);

    /**
     * @brief Retorna o mês a partir do número de dias e ano.
     * @param days Número de dias.
     * @param currentYear Ano atual.
     * @return Mês correspondente.
     */
    int MonthFromDays(int days, int currentYear);

    /**
     * @brief Retorna a data a partir do número de dias e ano.
     * @param days Número de dias.
     * @param currentYear Ano atual.
     * @return Dia do mês correspondente.
     */
    int GetDateByDays(int days, int currentYear);

    /**
     * @brief Verifica se o ano é bissexto.
     * @param year Ano a ser verificado.
     * @return 1 se for bissexto, 0 caso contrário.
     */
    int isLeapYear(int year) const;

public:
    int day,       ///< Dia do mês.
        month,     ///< Mês do ano.
        year,      ///< Ano.
        hours,     ///< Hora do dia.
        minutes,   ///< Minutos.
        timestamp, ///< Timestamp (opcional).
        seconds;   ///< Segundos.

    /* CONSTRUCTORS */
    
    /**
     * @brief Construtor padrão.
     */
    DateTime();

    /**
     * @brief Construtor com dia, mês e ano.
     * @param d Dia.
     * @param m Mês.
     * @param y Ano.
     */
    DateTime(int d, int m, int y);

    /**
     * @brief Construtor com dia, mês, ano e horas.
     * @param d Dia.
     * @param m Mês.
     * @param y Ano.
     * @param h Horas.
     */
    DateTime(int d, int m, int y, int h);

    /**
     * @brief Construtor com dia, mês, ano, horas e minutos.
     * @param d Dia.
     * @param m Mês.
     * @param y Ano.
     * @param h Horas.
     * @param min Minutos.
     */
    DateTime(int d, int m, int y, int h, int min);

    /**
     * @brief Construtor completo com todos os parâmetros.
     * @param d Dia.
     * @param m Mês.
     * @param y Ano.
     * @param h Horas.
     * @param min Minutos.
     * @param s Segundos.
     * @param ts Timestamp.
     */
    DateTime(int d, int m, int y, int h, int min, int s, int ts);

    /* COMPARISONS */

    /**
     * @brief Verifica se a data atual é posterior a outra data.
     * @param dt Outro objeto DateTime para comparação.
     * @return true se for posterior, false caso contrário.
     */
    bool isAfter(DateTime dt);

    /**
     * @brief Verifica se a data atual é igual a outra data.
     * @param dt Outro objeto DateTime para comparação.
     * @return true se for igual, false caso contrário.
     */
    bool isEqual(DateTime dt);

    /**
     * @brief Verifica se a data atual é anterior a outra data.
     * @param dt Outro objeto DateTime para comparação.
     * @return true se for anterior, false caso contrário.
     */
    bool isBefore(DateTime dt);

    /* CONVERSIONS */

    /**
     * @brief Converte a data para string.
     * @return Representação em string da data.
     */
    string ToString() const;

    /**
     * @brief Converte a data para o formato ISO.
     * @return Data no formato ISO como string.
     */
    string ToISOString() const;

    /**
     * @brief Converte a data para UTC.
     * @return Objeto DateTime correspondente no UTC.
     */
    DateTime toUTC();

    /**
     * @brief Altera o timestamp da data.
     * @param ts Novo timestamp.
     */
    void ChangeTimeStamp(int ts);

    /* DATE OPERATIONS */

    /**
     * @brief Soma segundos à data.
     * @param s Segundos a serem somados.
     */
    void SumSeconds(int s);

    /**
     * @brief Soma minutos à data.
     * @param min Minutos a serem somados.
     */
    void SumMinutes(int min);

    /**
     * @brief Soma horas à data.
     * @param h Horas a serem somadas.
     */
    void SumHours(int h);

    /**
     * @brief Soma dias à data.
     * @param d Dias a serem somados.
     */
    void SumDays(int d);

    /**
     * @brief Soma meses à data.
     * @param m Meses a serem somados.
     */
    void SumMonths(int m);

    /**
     * @brief Soma anos à data.
     * @param y Anos a serem somados.
     */
    void SumYears(int y);

    /* SUBTRACTIONS */

    /**
     * @brief Subtrai segundos da data.
     * @param s Segundos a serem subtraídos.
     */
    void SubtractSeconds(int s);

    /**
     * @brief Subtrai minutos da data.
     * @param min Minutos a serem subtraídos.
     */
    void SubtractMinutes(int min);

    /**
     * @brief Subtrai horas da data.
     * @param h Horas a serem subtraídas.
     */
    void SubtractHours(int h);

    /**
     * @brief Subtrai dias da data.
     * @param d Dias a serem subtraídos.
     */
    void SubtractDays(int d);

    /**
     * @brief Subtrai meses da data.
     * @param m Meses a serem subtraídos.
     */
    void SubtractMonths(int m);

    /**
     * @brief Subtrai anos da data.
     * @param y Anos a serem subtraídos.
     */
    void SubtractYears(int y);

    /* ANOTHER METHODS */

    /**
     * @brief Obtém o ano completo da data.
     * @return Ano como inteiro.
     */
    int GetFullYear() const;

    /**
     * @brief Obtém o mês da data.
     * @return Mês como inteiro.
     */
    int GetMonth() const;

    /**
     * @brief Obtém o dia da data.
     * @return Dia como inteiro.
     */
    int GetDate() const;

    /**
     * @brief Obtém as horas da data.
     * @return Horas como inteiro.
     */
    int GetHours() const;

    /**
     * @brief Obtém os minutos da data.
     * @return Minutos como inteiro.
     */
    int GetMinutes() const;

    /**
     * @brief Obtém os segundos da data.
     * @return Segundos como inteiro.
     */
    int GetSeconds() const;

    /**
     * @brief Obtém o dia do ano.
     * @return Dia do ano como inteiro.
     */
    int GetDayOfTheYear() const;

    /**
     * @brief Sobrecarga do operador de inserção (<<) para imprimir a data.
     * @param os Stream de saída.
     * @param date Objeto DateTime a ser impresso.
     * @return Stream de saída modificado.
     */
    friend std::ostream& operator<<(std::ostream& os, const DateTime& date) {
        os << date.ToString();
        return os;
    }
};

#endif