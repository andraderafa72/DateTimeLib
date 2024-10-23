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
    string compare_this_date(DateTime dt);

    /**
     * @brief Valida os componentes da data e hora.
     * @param d Dia.
     * @param m Mês.
     * @param y Ano.
     * @param h Horas.
     * @param min Minutos.
     * @param s Segundos.
     */
    void validate_time(int d, int m, int y, int h, int min, int s);

    /**
     * @brief Retorna o mês a partir do número de dias e ano.
     * @param days Número de dias.
     * @param currentYear Ano atual.
     * @return Mês correspondente.
     */
    int month_from_days(int days, int currentYear);

    /**
     * @brief Retorna a data a partir do número de dias e ano.
     * @param days Número de dias.
     * @param currentYear Ano atual.
     * @return Dia do mês correspondente.
     */
    int get_date_by_days(int days, int currentYear);

    /**
     * @brief Verifica se o ano é bissexto.
     * @param year Ano a ser verificado.
     * @return 1 se for bissexto, 0 caso contrário.
     */
    int is_leap_year(int year) const;

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
    bool is_after(DateTime dt);

    /**
     * @brief Verifica se a data atual é igual a outra data.
     * @param dt Outro objeto DateTime para comparação.
     * @return true se for igual, false caso contrário.
     */
    bool is_equal(DateTime dt);

    /**
     * @brief Verifica se a data atual é anterior a outra data.
     * @param dt Outro objeto DateTime para comparação.
     * @return true se for anterior, false caso contrário.
     */
    bool is_before(DateTime dt);

    /* CONVERSIONS */

    /**
     * @brief Converte a data para string.
     * @return Representação em string da data.
     */
    string to_string() const;

    /**
     * @brief Converte a data para o formato ISO.
     * @return Data no formato ISO como string.
     */
    string to_ISO_string() const;

    /**
     * @brief Converte a data para UTC.
     * @return Objeto DateTime correspondente no UTC.
     */
    DateTime to_UTC();

    /**
     * @brief Altera o timestamp da data.
     * @param ts Novo timestamp.
     */
    void change_time_stamp(int ts);

    /* DATE OPERATIONS */

    /**
     * @brief Soma segundos à data.
     * @param s Segundos a serem somados (s > 0).
     */
    void sum_seconds(int s);

    /**
     * @brief Soma minutos à data.
     * @param min Minutos a serem somados (min > 0).
     */
    void sum_minutes(int min);

    /**
     * @brief Soma horas à data.
     * @param h Horas a serem somadas (h > 0).
     */
    void sum_hours(int h);

    /**
     * @brief Soma dias à data.
     * @param d Dias a serem somados (d > 0).
     */
    void sum_days(int d);

    /**
     * @brief Soma meses à data.
     * @param m Meses a serem somados (m > 0).
     */
    void sum_months(int m);

    /**
     * @brief Soma anos à data.
     * @param y Anos a serem somados (y > 0).
     */ 
    void sum_years(int y);

    /* SUBTRACTIONS */

    /**
     * @brief Subtrai segundos da data.
     * @param s Segundos a serem subtraídos (s > 0).
     */
    void subtract_seconds(int s);

    /**
     * @brief Subtrai minutos da data.
     * @param min Minutos a serem subtraídos (min > 0).
     */
    void subtract_minutes(int min);

    /**
     * @brief Subtrai horas da data.
     * @param h Horas a serem subtraídas (h > 0).
     */
    void subtract_hours(int h);

    /**
     * @brief Subtrai dias da data.
     * @param d Dias a serem subtraídos (d > 0).
     */
    void subtract_days(int d);

    /**
     * @brief Subtrai meses da data.
     * @param m Meses a serem subtraídos (m > 0).
     */
    void subtract_months(int m);

    /**
     * @brief Subtrai anos da data.
     * @param y Anos a serem subtraídos (y > 0).
     */
    void subtract_years(int y);

    /* ANOTHER METHODS */

    /**
     * @brief Obtém o ano completo da data.
     * @return Ano como inteiro.
     */
    int get_full_year() const;

    /**
     * @brief Obtém o mês da data.
     * @return Mês como inteiro.
     */
    int get_month() const;

    /**
     * @brief Obtém o dia da data.
     * @return Dia como inteiro.
     */
    int get_date() const;

    /**
     * @brief Obtém as horas da data.
     * @return Horas como inteiro.
     */
    int get_hours() const;

    /**
     * @brief Obtém os minutos da data.
     * @return Minutos como inteiro.
     */
    int get_minutes() const;

    /**
     * @brief Obtém os segundos da data.
     * @return Segundos como inteiro.
     */
    int get_seconds() const;

    /**
     * @brief Obtém o dia do ano.
     * @return Dia do ano como inteiro.
     */
    int get_day_of_the_year() const;

    /**
     * @brief Sobrecarga do operador de inserção (<<) para imprimir a data.
     * @param os Stream de saída.
     * @param date Objeto DateTime a ser impresso.
     * @return Stream de saída modificado.
     */
    friend std::ostream& operator<<(std::ostream& os, const DateTime& date) {
        os << date.to_string();
        return os;
    }
};

#endif