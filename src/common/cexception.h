#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include <QString>

/** @brief Specialised functions
 */
namespace Common
{
    /** @brief Common simple Exception
     *
     * Usage:
     * @code
     * throw EXCEPTION("message"); //replaced to throw Common::CException(message, __FUNC__ ...) and need constructor by CONFIG_DEBUG
     * @endcode
     */
    class CException
        : public std::exception
    {
    public:
        /** @brief Default constructor
         *
         * @param description
         * @param source
         */
        CException(const QString &description, const QString &source);

        /** @brief Extended constructor for CONFIG_DEBUG mode
         *
         * @param description
         * @param source
         * @param file
         * @param line
         */
        CException(const QString &description, const QString &source, const char* file, quint32 line);

        /** @brief Default destructor
         */
        ~CException() throw() {}


        /** @brief Get formatted description with line number etc...
         *
         */
        inline const QString& fullDescription() const { return m_full_description; }

        /** @brief Get function name
         *
         * @return const QString&
         */
        inline const QString& source() const { return m_source; }

        /** @brief Get file path
         *
         * @return const QString&
         */
        inline const QString& file() const { return m_file; }

        /** @brief Get line number
         *
         * @return long
         */
        inline long           line() const { return m_line; }

        /** @brief Get description
         *
         * @return const QString&
         */
        inline const QString& description() const { return m_description; }

        /** @brief Override std::exception::what()
         *
         * @return const char *
         */
        inline const char*    what() const throw() { return m_full_description.toUtf8().constData(); }

    private:
        QString          m_source;           ///< Function name
        QString          m_file;             ///< File path
        QString          m_description;      ///< Description message
        long             m_line;             ///< Line number
        mutable QString  m_full_description; ///< Full Description message
    };
}
#endif // CEXCEPTION_H
