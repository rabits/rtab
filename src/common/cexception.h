#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include <iostream>

#ifdef CONFIG_DEBUG
#   define EXCEPTION(message)       Common::CException(message, __FUNCTION__, __FILE__, __LINE__) ///< Hard exception
#else
#   define EXCEPTION(message)       Common::CException(message, __FUNCTION__)                     ///< Simple exception
#endif

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
        CException(const std::string &description, const std::string &source);

        /** @brief Extended constructor for CONFIG_DEBUG mode
         *
         * @param description
         * @param source
         * @param file
         * @param line
         */
        CException(const std::string &description, const std::string &source, const char* file, long line);

        /** @brief Default destructor
         */
        ~CException() throw() {}


        /** @brief Get formatted description with line number etc...
         *
         */
        const std::string& fullDescription() const;

        /** @brief Get function name
         *
         * @return const std::string&
         */
        inline const std::string& source() const { return m_source; }

        /** @brief Get file path
         *
         * @return const std::string&
         */
        inline const std::string& file() const { return m_file; }

        /** @brief Get line number
         *
         * @return long
         */
        inline long               line() const { return m_line; }

        /** @brief Get description
         *
         * @return const std::string&
         */
        inline const std::string& description() const { return m_description; }

        /** @brief Override std::exception::what()
         *
         * @return const char *
         */
        inline const char*        what() const throw() { return fullDescription().c_str(); }

    private:
        std::string          m_source;          ///< Function name
        std::string          m_file;            ///< File path
        std::string          m_description;     ///< Description message
        long                 m_line;            ///< Line number
        mutable std::string  m_fullDescription; ///< Full Description message
    };
}
#endif // CEXCEPTION_H
